/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:17 by obarais           #+#    #+#             */
/*   Updated: 2025/01/28 16:29:39 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../src/so_long.h"

void	load_images_B(t_data *data);
void	free_resources(t_data *data);
void	put_trmnation(char *str);
void	prinft_error(int i);
char	**ft_char_map(char *av, t_data *data);
void	free_map(char **map);
void	ft_draw_map_B(t_data *data, char *map);
int		close_window_B(t_data *data);
void	check_coin_exit_B(t_data *data, int keycode);
int		handle_keypress_B(int keycode, t_data *data);
void	help_check_coin_exit_B(t_data *data, int keycode);
int		draw_coin_B(t_data *data);

#endif