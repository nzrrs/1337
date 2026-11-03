NAME = libftprintf.a
SRCS = $(wildcard *.c)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a 
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
CC = cc

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT) :
	make -C $(LIBFT_DIR)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean 
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : al	clean fclean re
