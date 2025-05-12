# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 13:01:08 by lseabra-          #+#    #+#              #
#    Updated: 2025/05/12 15:58:29 by lseabra-         ###   ########.fr        #
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

SRC_PATH = src
BUILD_PATH = build
LIBFT_PATH = libft/
LIBFT_ARCH = $(LIBFT_PATH)$(LIBFT_NAME)

SRCS = $(addprefix $(SRC_PATH)/, ft_printf.c ft_print_c.c ft_print_s.c \
		ft_printf_utils.c)
OBJS = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))

SRC_BONUS_PATH = src_bonus
SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH)/, ft_printf_bonus.c ft_printf_utils_bonus.c \
			ft_parse_bonus.c ft_print_c_bonus.c)
OBJS_BONUS = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS_BONUS:.c=.o)))


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(LIBFT_ARCH) $(BUILD_PATH) $(OBJS)
	make -C $(LIBFT_PATH) bonus
	cp $(LIBFT_PATH)/$(LIBFT_NAME) .
	mv $(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(SRC_BONUS_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)

$(LIBFT_ARCH):
	$(MAKE) -C $(LIBFT_PATH) bonus

clean:
	$(RM_DIR) $(BUILD_PATH)
	$(MAKE) -C $(LIBFT_PATH) clean
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

bonus: $(LIBFT_ARCH) $(BUILD_PATH) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)

test: all
	@$(CC) tests/test.c $(SRCS) $(LIBFT_ARCH) -g
	@./a.out

test_bonus: all
	@$(CC) tests/test_bonus.c $(SRCS_BONUS) $(LIBFT_ARCH) -g
	@./a.out

.PHONY: all clean fclean re