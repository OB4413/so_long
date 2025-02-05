/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:17 by obarais           #+#    #+#             */
/*   Updated: 2025/02/05 10:27:33 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../src/so_long.h"
# include <unistd.h>

void	load_images_b(t_data *data);
void	free_resources_b(t_data *data);
void	put_trmnation(char *str);
void	printf_error(int i);
char	**ft_char_map(char *av, t_data *data);
void	free_map(char **map);
void	ft_draw_map_b(t_data *data, char *map);
int		close_window_b(t_data *data);
void	check_coin_exit_b(t_data *data);
int		handle_keypress_b(int keycode, t_data *data);
void	help_check_coin_exit_b(t_data *data, int keycode);
int		draw_coin_b(t_data *data);
void	animation(t_data *data, char buffer, int x, int y);
void	check_map_b(char **map, t_data *data);
void	ft_check_enemy(t_data *data);

#endif