# Color
Set_Color		=		\033[0m						# Text Reset
Red				=		\033[0;31m					# Red
Green			=		\033[0;32m					# Green

NAME			=		philosophers

SRCS			=		srcs/string.c \
						srcs/main.c \
						srcs/utils.c \
						srcs/philo.c \
						srcs/routine.c \
						srcs/time.c

OBJS			=		$(SRCS:.c=.o)

# LIB				=		@make -C ./libft

# CFLAGS			=		 -g -fsanitize=thread

.c.o			:
						@gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)			:		$(OBJS)
						@gcc $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) $(OBJS) -o $(NAME)
						@echo "$(Green)Philosophers has been created$(Set_Color)"

# lib				:
# 						$(LIB)
# 						@echo "$(Green)Libft has been created$(Set_Color)"

clean			:
						@rm -f $(OBJS)
						@echo "$(Red)Objects have been removed$(Set_Color)"

fclean			:		clean
						@rm -f $(NAME)
						@echo "$(Red)Philosophers has been removed$(Set_Color)"

all				:		$(NAME)

re				:		fclean all

.PHONY			:		clean fclean all re