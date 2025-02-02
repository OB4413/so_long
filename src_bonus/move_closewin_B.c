/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_closewin_B.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:39 by obarais           #+#    #+#             */
/*   Updated: 2025/02/02 12:14:40 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window_b(t_data *data)
{
	if (data->win)
		free_resources_b(data);
	return (0);
}

static void	ft_check_enemy(t_data *data)
{
	if (data->map[data->y / 60][data->x / 60] == 'U')
		data->inlophok = 'D';
}


void	check_coin_exit_b(t_data *data)
{
	int	i;

	i = 0;
	if (data->map[data->y / 60][data->x / 60] == 'C')
	{
		data->inlophok = 'E';
		data->num++;
		data->map[data->y / 60][data->x / 60] = '0';
		while (i < data->i * 2)
		{
			if (data->xyancion[i] == data->x && data->xyancion[i
				+ 1] == data->y)
			{
				data->xyancion[i] = -1;
				data->xyancion[i + 1] = -1;
			}
			i += 2;
		}
	}
	else
		ft_check_enemy(data);
}

static void	help_handle_keypress_b(int keycode, t_data *data)
{
	if (keycode == LEFT || keycode == A)
	{
		help_check_coin_exit_b(data, keycode);
		if (data->map[data->y / 60][data->x / 60 - 1] != '1'
			&& data->map[data->y / 60][data->x / 60 - 1] != 'E')
			move_dirction(data, 3);
		check_coin_exit_b(data);
	}
	else if (keycode == RIGHT || keycode == D)
	{
		help_check_coin_exit_b(data, keycode);
		if (data->map[data->y / 60][data->x / 60 + 1] != '1'
			&& data->map[data->y / 60][data->x / 60 + 1] != 'E')
			move_dirction(data, 4);
		check_coin_exit_b(data);
	}
}

int	handle_keypress_b(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window_b(data);
	if (keycode == UP || keycode == W)
	{
		help_check_coin_exit_b(data, keycode);
		if (data->map[data->y / 60 - 1][data->x / 60] != '1'
			&& data->map[data->y / 60 - 1][data->x / 60] != 'E')
			move_dirction(data, 1);
		check_coin_exit_b(data);
	}
	else if (keycode == DOWN || keycode == S)
	{
		help_check_coin_exit_b(data, keycode);
		if (data->map[data->y / 60 + 1][data->x / 60] != '1'
			&& data->map[data->y / 60 + 1][data->x / 60] != 'E')
			move_dirction(data, 2);
		check_coin_exit_b(data);
	}
	else
		help_handle_keypress_b(keycode, data);
	return (0);
}
