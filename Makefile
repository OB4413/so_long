NAME = so_long

SOURCES = so_long.c move_closewin.c new_windows.c check_map.c read_map_to_ckek_wall.c count_coin.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

libmlx = minilibx-linux/libmlx_Linux.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(libmlx) -lXext -lX11 -lm

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJECTS)

.PHONY: all clean fclean re