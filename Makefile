# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 13:01:08 by lseabra-          #+#    #+#              #
#    Updated: 2025/05/07 16:41:57 by lseabra-         ###   ########.fr        #
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
BUILD_PATH = .build
LIBFT_PATH = libft/
LIBFT_ARCH = $(LIBFT_PATH)$(LIBFT_NAME)

SRCS = $(addprefix $(SRC_PATH)/, ft_printf.c)
OBJS = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(LIBFT_ARCH) $(BUILD_PATH) $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
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

.PHONY: all clean fclean re