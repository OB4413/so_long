NAME = so_long
BONUS = so_long_bonus

SOURCES = src/so_long.c src/move_dirction.c src/move_closewin.c src/n_win_error_exit.c src/check_map.c \
			src/creat_2d_array_free.c src/count_coin_E.c src/count_len.c src/flood_fill.c \
			src/check_path.c src/draw_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BSOURCES = src_bonus/so_long_B.c src_bonus/move_dirction_B.c src_bonus/move_closewin_B.c src_bonus/n_win_error_exit_B.c src_bonus/check_map_b.c src_bonus/animathin_enemy.c \
			src_bonus/creat_2d_array_free_B.c src/count_coin_E.c src/count_len.c src/flood_fill.c src_bonus/free_everything.c src_bonus/allocation_image.c \
			src/check_path.c src_bonus/draw_mapB.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src_bonus/animation.c src_bonus/ft_itoa.c \
			src_bonus/allocation_image1.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

libmlx = minilibx-linux/libmlx_Linux.a
print = ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(print) $(libmlx) -lXext -lX11 -lm

bonus: $(BONUS)

$(BONUS): $(BOBJECTS)
	$(CC) $(CFLAGS) $(BOBJECTS) -o $(BONUS) $(print) $(libmlx) -lXext -lX11 -lm

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(BOBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.SECONDARY: $(OBJECTS) $(BOBJECTS)

.PHONY: all bonus clean fclean re