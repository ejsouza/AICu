# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 15:47:00 by esouza            #+#    #+#              #
#    Updated: 2019/02/26 15:36:04 by esouza           ###   ########.fr        #
#    Updated: 2018/02/03 17:12:42 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

CFLAGS = -Wall -Werror -Wextra

CC = gcc -Iincludes/aicu.h

SRC_DIR = srcs

OBJ_DIR = objs

INCLUDES = includes

SRCS = main.c check_buff.c ft_atoi.c ft_check_arg.c ft_isdigit.c ft_memchr.c \
	   ft_memdel.c ft_memmove.c ft_play.c ft_putchar.c ft_putstr.c ft_strcat.c \
	   ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strsub.c \
	   get_next_line.c ft_strat.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS:%.o=$(OBJ_DIR)/%.o) Makefile
	@$(CC) -o $@ $(OBJS:%.o=$(OBJ_DIR)/%.o)
	@echo "\033[32m=== Execution terminated compilation successful ==="

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(srcs) -c $< -o $@
	@echo "\033[35m         === Creating object files ==="

all: $(NAME)

clean:
	@rm -f $(OBJS:%.o=$(OBJ_DIR)/%.o)
	@echo "\033[33m        === All object files deleted ==="

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m         === Executable file deleted ==="

re: fclean all
