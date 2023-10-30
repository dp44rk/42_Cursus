# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 17:11:06 by hyeonjan          #+#    #+#              #
#    Updated: 2023/03/06 17:11:09 by hyeonjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC_DIR = ./src

PARSER_NAME = element_check.c file_check.c line_check.c object_check.c parser_utils.c
PARSER_DIR = /parser
PARSER = $(addprefix $(SRC_DIR)$(PARSER_DIR)/, $(PARSER_NAME))

SCENE_NAME = object_create.c scene.c
SCENE_DIR = /scene
SCENE = $(addprefix $(SRC_DIR)$(SCENE_DIR)/, $(SCENE_NAME))

TRACE_HIT_NAME = hit.c hit_cylinder.c hit_plane.c hit_sphere.c normal.c hit_cone.c
TRACE_HIT_DIR = /trace/hit
TRACE_HIT = $(addprefix $(SRC_DIR)$(TRACE_HIT_DIR)/, $(TRACE_HIT_NAME))

TRACE_RAY_NAME = is_in_shadow.c phong_lighting.c ray.c
TRACE_RAY_DIR = /trace/ray
TRACE_RAY = $(addprefix $(SRC_DIR)$(TRACE_RAY_DIR)/, $(TRACE_RAY_NAME))

UTILS_NAME = draw_image.c ft_2d_char_arr.c ft_alert1.c ft_atod.c ft_exit.c \
			ft_split.c gnl.c object_utils.c on_mlx_hook.c render.c utils1.c utils2.c \
			vec3_utils.c vec3_utils2.c vec3_utils3.c vec3_utils4.c
UTILS_DIR = /utils
UTILS = $(addprefix $(SRC_DIR)$(UTILS_DIR)/, $(UTILS_NAME))

MAIN_NAME = main.c
MAIN_DIR = /
MAIN = $(addprefix $(SRC_DIR)$(MAIN_DIR), $(MAIN_NAME))

SRCS = $(PARSER) $(SCENE) $(TRACE_HIT) $(TRACE_RAY) $(UTILS) $(MAIN)

OBJS = $(SRCS:.c=.o)

INCLUDE = -I ./include

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $? $(CFLAGS) $(MLX_FLAG) -o $@
	@echo "\033[47;30m* $(NAME) was created *\033[0m"

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

bonus : all

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
