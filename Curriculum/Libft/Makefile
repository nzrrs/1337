NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = $(shell find . -name 'ft_*.c')
OBJS = $(SRCS:.c=.o)
CC = cc

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 
