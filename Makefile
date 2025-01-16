NAME = so_long

SOURCES = so_long.c move_closewin.c new_windows.c check_map.c read_map_to_ckek_wall.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

libmlx = minilibx-linux/libmlx_Linux.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(libmlx) $(NAME) clean

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(libmlx) -lXext -lX11 -lm

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(libmlx):
	make -C minilibx-linux

clean:
	rm -f $(OBJECTS)
	make clean -C minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJECTS)

.PHONY: all clean fclean re