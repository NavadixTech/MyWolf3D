##
## EPITECH PROJECT, 2025
## new_wolf
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

SRC = $(wildcard src/**/*.c src/*.c)
OBJ = $(SRC:.c=.o)
NAME = wolf3d

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all