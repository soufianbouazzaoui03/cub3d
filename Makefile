# -*- MakeFile -*-

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = parsing.c get_next_line.c get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)
HEADER = cub3d.h
NAME = cub3D

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) libft/libft.a

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all