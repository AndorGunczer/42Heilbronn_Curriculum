# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 14:00:18 by agunczer          #+#    #+#              #
#    Updated: 2021/07/02 13:15:37 by agunczer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_detertype.c ft_printf.c ft_puthexlower_fd.c ft_puthexupper_fd.c ft_puthexpointer_fd.c ft_putunsnbr_fd.c \
		ft_flaghandle.c ft_spechandle.c ft_widthcounter.c ft_itoa_long.c ft_deterprec.c ft_handletype.c
NAME = libftprintf.a

all: ${NAME}
	
${NAME}: ${SRC}
	gcc -c $^
	ar -rc libftprintf.a *.o

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all