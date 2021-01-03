# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 19:40:00 by mlebrun           #+#    #+#              #
#    Updated: 2021/01/03 12:41:05 by mlebrun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_UTILS = srcs/main.c srcs/hook/hook.c srcs/player/player.c srcs/utils/utils.c \
srcs/raycasting.c

SRCS_INIT = srcs/init/init.c srcs/init/init_2.c srcs/init/init_3.c \

SRCS_FREE = srcs/free/free.c srcs/free/free_2.c \

SRCS_PARSE = srcs/parse/parse.c srcs/parse/parse_map.c \
srcs/parse/parse_map_2.c srcs/parse/parse_map_3.c srcs/parse/parse_elem.c \
srcs/parse/parse_elem_2.c srcs/parse/parse_elem_3.c srcs/parse/parse_elem_4.c \
srcs/parse/parse_elem_5.c srcs/parse/parse_elem_6.c srcs/parse/parse_utils.c \

SRCS_DRAW = srcs/draw/draw_text.c srcs/draw/draw_text_2.c \
srcs/draw/draw_text_3.c srcs/draw/draw_sprite.c srcs/draw/draw_sprite_2.c \
srcs/draw/draw_sprite_3.c srcs/draw/draw_sprite_4.c srcs/draw/draw.c \
srcs/draw/draw_2.c srcs/draw/draw_map.c
SRCS_GNF = getnextline/get_next_line.c getnextline/get_next_line_utils.c \

SRCS_RC = srcs/raycasting/raycasting_1.c srcs/raycasting/raycasting_2.c \
srcs/raycasting/raycasting_3.c srcs/raycasting/raycasting_4.c \
srcs/raycasting/raycasting_5.c srcs/raycasting/raycasting_6.c \

SRCS_SPRITE = srcs/sprite/sprite.c srcs/sprite/sprite_2.c \
srcs/sprite/sprite_3.c 

SRCS_SAVE = srcs/save/save.c srcs/save/save_2.c srcs/save/save_3.c \

SRCS_CUB = ${SRCS_DRAW} ${SRCS_INIT} ${SRCS_FREE} ${SRCS_SAVE} ${SRCS_PARSE} ${SRCS_SPRITE} ${SRCS_RC} ${SRCS_UTILS}


OBJS_UTILS = ${SRCS_UTILS:.c=.o}
OBJS_DRAW = ${SRCS_DRAW:.c=.o}
OBJS_RC = ${SRCS_RC:.c=.o}
OBJS_SPRITE = ${SRCS_SPRITE:.c=.o}
OBJS_SAVE = ${SRCS_SAVE:.c=.o}
OBJS_PARSE = ${SRCS_PARSE:.c=.o}
OBJS_FREE = ${SRCS_FREE:.c=.o}
OBJS_INIT = ${SRCS_INIT:.c=.o}
OBJS_GNF = ${SRCS_GNF:.c=.o}

OBJS_CUB = ${OBJS_DRAW} ${OBJS_INIT} ${OBJS_FREE} ${OBJS_SAVE} ${OBJS_PARSE} ${OBJS_SPRITE} ${OBJS_RC} ${OBJS_UTILS}
CC = clang
CFLAGS = -Wall -Werror -Wextra  -I includes/ -I libft/ -I getnextline/ -D BUFFER_SIZE=1 -g3 -fsanitize=address
MLX_FLAG = -L./minilibx-linux -lbsd -lmlx -lXext -lX11 -lm -g3 -fsanitize=address
NAME = Cub3D
LIB_NAME = libft_GNL.a
RM	= rm -rf

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS_CUB} ${OBJS_GNF} 
			make -C libft/
			make -C minilibx-linux/
			mv libft/libft.a ${LIB_NAME}
			ar rc ${LIB_NAME} ${OBJS_GNF}
			ranlib ${LIB_NAME}
			${CC} -o ${NAME} ${OBJS_CUB} ${CFLAGS} -L. -lft_GNL ${MLX_FLAG}

clean:
			make -C libft/ -f Makefile clean
			make -C minilibx-linux/ -f Makefile clean
			${RM} ${OBJS_CUB} ${OBJS_GNF}

fclean:		clean
			make -C libft/ -f Makefile fclean
			${RM} ${NAME}
			${RM} ${LIB_NAME}


bonus:		${NAME}

re:			fclean all
