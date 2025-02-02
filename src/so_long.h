/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:43:39 by obarais           #+#    #+#             */
/*   Updated: 2025/02/02 11:32:53 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ESC_KEY 65307
# define UP 65362
# define W 119
# define DOWN 65364
# define S 115
# define LEFT 65361
# define A 97
# define RIGHT 65363
# define D 100

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	void		*wall;
	void		*floor;
	void		*player;
	void		*coin;
	void		**ancion;
	void		**anwp;
	void		**anwlp;
	void		**anep;
	void		**andp;
	void		**anwle;
	void		**anse;
	void		*exit;
	int			x;
	int			y;
	char		**map;
	char		**str;
	int			num;
	int			i;
	int			j;
	int			count_move;
	int			*xyancion;
	int			*xye;
	char		inlophok;
}				t_data;

int				close_window(t_data *data);
int				handle_keypress(int keycode, t_data *data);
void			*opne_windows(t_data *data);
void			check_map(char **map, t_data *data);
char			**ft_char_map(char *av, t_data *data);
void			free_map(char **map);
void			free_resources(t_data *data);
void				ft_count_coin_enemy(char **map, t_data *data);
int				ft_count_exit(char **map);
void			ft_len_map(char *av, t_data *data);
void			put_trmnation(char *str);
void			ft_check_flood(int x, int y, t_data *data);
void			ft_flood_fill(int x, int y, t_data *data);
void			postion_player(char **map, t_data *data);
void			*ft_check_path(char *path);
void			ft_draw_map(t_data *data, char *map);
void			check_coin_exit(t_data *data, int keycode);
int				move_dirction(t_data *data, int i);
void			help_check_coin_exit(t_data *data, int keycode);
void			prinft_error(int i);

#endif