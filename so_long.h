/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:43:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/18 21:41:38 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ESC_KEY 65307
# define Up 65362
# define W 119
# define Down 65364
# define S 115
# define Left 65361
# define A 97
# define Right 65363
# define D 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
	void	*not_exit;
	int		player_x;
	int		player_y;
	// int coin_x;
	// int coin_y;
	// int wll_x;
	// int wll_y;
	char	**map;
	int		num;
	int		i;
	size_t	count_move;
}			t_data;

int			close_window(t_data *data);
int			handle_keypress(int keycode, t_data *data);
void		*opne_windows(t_data *data);
int			check_map(int win_heigth);
char		**ft_char_map(int win_heigth);
void		free_map(char **map);
void		free_resources(t_data *data);
int			ft_count_coin(char **map);

#endif