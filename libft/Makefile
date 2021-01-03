# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 08:46:57 by mlebrun           #+#    #+#              #
#    Updated: 2020/12/01 06:56:23 by mlebrun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memccpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_isalpha.c \
ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
ft_lstmap.c

SRCS_ADDED = ft_putstr_bonus.c ft_putchar_bonus.c \


OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o} 

OBJS_ADDED = ${SRCS_ADDED:.c=.o}


CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

RM	= rm -rf


.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ${OBJS_ADDED}
			ar rc ${NAME} ${OBJS} ${OBJS_ADDED}
			ranlib ${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS} ${OBJS_ADDED}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS}
			ranlib ${NAME}

.PHONY:		all clean fclean re
