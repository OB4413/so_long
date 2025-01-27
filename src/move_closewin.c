/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_closewin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/27 12:11:26 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	if (data->win)
		free_resources(data);
	return (0);
}

void	check_coin_exit(t_data *data, int keycode)
{
	if (data->map[data->y / 60][data->x / 60] == 'C')
	{
		data->num++;
		data->map[data->y / 60][data->x / 60] = '0';
	}
	help_check_coin_exit(data, keycode);
}

static void	help_handle_keypress(int keycode, t_data *data)
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

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	check_coin_exit(data, keycode);
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
		help_handle_keypress(keycode, data);
	return (0);
}
