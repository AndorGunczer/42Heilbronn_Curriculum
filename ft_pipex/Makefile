CC = gcc

NAME = pipex.a

FLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c ft_free_functions.c


all: $(NAME)

$(NAME): *.c
	Make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	gcc main.c ./libft/libft.a pipex.a -o pipex

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean $(NAME)
