# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:28:11 by agunczer          #+#    #+#              #
#    Updated: 2021/11/09 18:42:54 by agunczer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		push_swap

SRCS			=		sources/push_swap.c \
						sources/sort_big.c \
						sources/sort_small.c \
						sources/parse.c \
						sources/memory.c \
						sources/fill_stack.c \
						sources/error.c \
						instructions/pa.c \
						instructions/pb.c \
						instructions/ra.c \
						instructions/rb.c \
						instructions/rr.c \
						instructions/rra.c \
						instructions/rrb.c \
						instructions/rrr.c \
						instructions/sa.c \
						instructions/sb.c \
						instructions/ss.c \

OBJS			=		$(SRCS:.c=.o)

LIB				=		make -C sources/libft

CC				=		gcc

CFLAGS			=		-Wall -Wextra -Werror

RM				=		rm -f

$(NAME)			:		$(OBJS)
						$(LIB)
						$(CC) $(CFLAGS) $(OBJS) sources/libft/libft.a -o $(NAME)

lib				:
						$(LIB)

clean			:
						$(RM) $(OBJS)

fclean			:		clean
						$(RM) $(NAME)
						cd ./sources/libft && make fclean

all				:		$(NAME)

re				:		fclean all

.PHONY			:		clean fclean all re bonus