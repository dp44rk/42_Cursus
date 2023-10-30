# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpark <dpark@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:58:14 by dpark             #+#    #+#              #
#    Updated: 2022/11/25 20:02:06 by dpark            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
FRAEMWORKS = -lmlx -framework OpenGL -framework AppKit -framework OpenGL
INC_LINK = -I ./

SRC = fdf.c bresenham.c draw_line.c ft_atoi_base.c \
	ft_split.c  get_next_line.c isometric.c parse.c utils1.c utils2.c

RM = rm -f
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(FRAEMWORKS) $(INC_LINK) -o $(NAME) $(OBJ) 

%.o : %.c
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re