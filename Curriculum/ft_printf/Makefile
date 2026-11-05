.PHONY : all clean fclean re

NAME = libftprintf.a

SRCS = $(shell find src -name "*.c")

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

