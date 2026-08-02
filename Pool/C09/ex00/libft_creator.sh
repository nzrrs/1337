#!/bin/sh

cc -c ft_putchar.c
cc -c ft_putstr.c
cc -c ft_strcmp.c
cc -c ft_strlen.c
cc -c ft_swap.c


ar rcs libft.a *.o
