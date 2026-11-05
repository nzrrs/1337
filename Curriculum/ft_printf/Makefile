.PHONY : all clean fclean re

NAME = libftprintf.a

SRCS =	./src/ft_handler.c ./src/helpers/ft_putnbr.c ./src/helpers/ft_putbase.c ./src/helpers/ft_putchar.c \
		./src/helpers/ft_putstr.c ./src/ft_printf.c ./src/handlers/ft_handle_char.c ./src/handlers/ft_handle_s.c \
		./src/handlers/ft_handle_x_min.c ./src/handlers/ft_handle_p.c ./src/handlers/ft_handle_u.c ./src/handlers/ft_handle_x_maj.c \
		./src/handlers/ft_handle_decimal.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes

CC = cc

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c includes/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean 
	rm -f $(NAME)

re : fclean all

