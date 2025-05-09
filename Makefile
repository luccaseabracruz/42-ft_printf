# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 13:01:08 by lseabra-          #+#    #+#              #
#    Updated: 2025/05/09 16:04:16 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
MKDIR_P = mkdir -p
RM = rm -f
RM_DIR = rm -rf
NAME = libftprintf.a
LIBFT_NAME = libft.a

SRC_BONUS_PATH = src_bonus
BUILD_BONUS_PATH = .build_bonus
LIBFT_PATH = libft/
LIBFT_ARCH = $(LIBFT_PATH)$(LIBFT_NAME)

SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH)/, ft_printf_bonus.c ft_printf_utils_bonus.c \
			ft_parse_bonus.c ft_print_c_bonus.c)
OBJS_BONUS = $(addprefix $(BUILD_BONUS_PATH)/, $(notdir $(SRCS_BONUS:.c=.o)))


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(LIBFT_ARCH) $(BUILD_BONUS_PATH) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)

$(BUILD_BONUS_PATH)/%.o: $(SRC_BONUS_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_BONUS_PATH):
	$(MKDIR_P) $(BUILD_BONUS_PATH)

$(LIBFT_ARCH):
	$(MAKE) -C $(LIBFT_PATH) bonus

clean:
	$(RM_DIR) $(BUILD_BONUS_PATH)
	$(MAKE) -C $(LIBFT_PATH) clean
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

bonus: all

test: all
	@$(CC) main.c $(SRCS_BONUS) $(LIBFT_ARCH) -g
	@./a.out

.PHONY: all clean fclean re