# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:18:40 by dpark             #+#    #+#              #
#    Updated: 2022/12/12 16:43:43 by dpark            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC_DIR = ./srcs/
SRC2_DIR = ./srcs/

SRC_FILES = action.c \
	initialize.c \
	philo.c \
	print.c \
	utils.c \

SRC_OBJ = $(SRC_FILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
