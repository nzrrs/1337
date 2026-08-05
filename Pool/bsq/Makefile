NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Iinclude

SRC_DIR = src
OBJ_DIR = obj

SRCS = fill_square.c free.c main.c output.c parser.c parser_utils.c \
       reader.c solver.c utils.c validator.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/bsq.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
