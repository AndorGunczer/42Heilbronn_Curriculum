# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 09:35:06 by agunczer          #+#    #+#              #
#    Updated: 2021/11/05 14:21:40 by agunczer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
    ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
    ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
    ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
    ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstclear.c ft_lstiter.c ft_atoi_l.c ft_lstdel.c
OBJ = ${SRC:.c=.o}
NAME = libft.a

.PHONY: all bonus
all: ${NAME}

${NAME}: ${SRC}
	${CC} ${CC_FLAGS} -c ${SRC}
	ar -rc libft.a ${OBJ}

bonus:
	${CC} ${CC_FLAGS} -c ${BNS}
	ar -rc ${NAME} *.o

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
.PHONY: all clean fclean re test
