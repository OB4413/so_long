/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_closewin_B.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/28 16:30:32 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window_B(t_data *data)
{
	if (data->win)
		free_resources(data);
	return (0);
}

void	check_coin_exit_B(t_data *data, int keycode)
{
	if (data->map[data->y / 60][data->x / 60] == 'C')
	{
		data->num++;
		data->map[data->y / 60][data->x / 60] = '0';
		data->cx = 0;
		data->cy = 0;
	}
	help_check_coin_exit_B(data, keycode);
}

static void	help_handle_keypress_B(int keycode, t_data *data)
{
	if (keycode == LEFT || keycode == A)
	{
		if (data->map[data->y / 60][data->x / 60 - 1] != '1'
			&& data->map[data->y / 60][data->x / 60 - 1] != 'E')
			move_dirction(data, 3);
	}
	else if (keycode == RIGHT || keycode == D)
	{
		if (data->map[data->y / 60][data->x / 60 + 1] != '1'
			&& data->map[data->y / 60][data->x / 60 + 1] != 'E')
			move_dirction(data, 4);
	}
}

int	handle_keypress_B(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window_B(data);
	check_coin_exit_B(data, keycode);
	if (keycode == UP || keycode == W)
	{
		if (data->map[data->y / 60 - 1][data->x / 60] != '1'
			&& data->map[data->y / 60 - 1][data->x / 60] != 'E')
			move_dirction(data, 1);
	}
	else if (keycode == DOWN || keycode == S)
	{
		if (data->map[data->y / 60 + 1][data->x / 60] != '1'
			&& data->map[data->y / 60 + 1][data->x / 60] != 'E')
			move_dirction(data, 2);
	}
	else
		help_handle_keypress_B(keycode, data);
	return (0);
}
