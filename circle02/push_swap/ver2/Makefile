# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpark <dpark@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 07:53:24 by dpark             #+#    #+#              #
#    Updated: 2022/11/26 08:44:19 by dpark            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC_DIR = ./src/
SRC2_DIR = ./bonus/

SRC_FILES = answer_print.c \
			check.c \
			double_q.c \
			exit.c \
			final_proc.c \
			free.c \
			libft_atoi.c \
			libft_lst.c \
			libft_utils.c \
			parse.c \
			parse2.c \
			push_swap.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			set_command.c \
			swap.c \
			t_args_init.c \

SRC2_FILES = checker_bonus.c \
			checker_utils_bonus.c \
			exit_bonus.c \
			free_bonus.c \
			gnl_utils_bonus.c \
			gnl_bonus.c \
			libft_atoi_bonus.c \
			libft_lst_bonus.c \
			libft_utils_bonus.c \
			parse_bonus.c \
			parse2_bonus.c \
			push_bonus.c \
			reverse_rotate_bonus.c \
			rotate_bonus.c \
			swap_bonus.c \
			t_args_init_bonus.c
			
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRCS2 = $(addprefix $(SRC2_DIR), $(SRC2_FILES))

SRC_OBJ = $(SRCS:.c=.o)
SRC2_OBJ = $(SRCS2:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_OBJ)

$(CHECKER): $(SRC2_OBJ)
	$(CC) $(CFLAGS) $(INC_LINK) -o $(CHECKER) $(SRC2_OBJ)

clean:
	$(RM) $(SRC_OBJ) $(SRC2_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
