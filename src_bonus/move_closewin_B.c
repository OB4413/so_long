/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_closewin_B.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:39 by obarais           #+#    #+#             */
/*   Updated: 2025/02/04 15:13:14 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window_b(t_data *data)
{
	if (data->win)
		free_resources_b(data);
	return (0);
}

void	ft_check_enemy(t_data *data)
{
	int d;
	int n;

	d = 0;
	n = 0;
	if (data->map[data->y / 60][data->x / 60] == 'U')
	{
		while (d < 17)
		{
			n = 0;
			while (n < 30000)
			{
				mlx_put_image_to_window(data->mlx, data->win, data->andp[d], data->x, data->y);
				n++;
			}
			d++;
		}
		usleep(300000);
		printf("You lose\n");
		close_window_b(data);
	}
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
	data->map[data->y / 60][data->x / 60] = 'T';
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
	data->map[data->y / 60][data->x / 60] = 'T';
	return (0);
}
