/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_closewin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/27 10:31:25 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	if (data->win)
		free_resources(data);
	return (0);
}

void	check_coin_exit(t_data *data, int i)
{
	if (data->map[data->y / 60][data->x / 60] == 'C')
	{
		data->num++;
		data->map[data->y / 60][data->x / 60] = '0';
	}
	if (data->map[data->y / 60][data->x / 60] == 'E')
	{
		if (data->num == data->i)
		{
			printf("you win!");
			free_resources(data);
			exit(0);
		}
		move_dirction_0(data, i);
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	else if (keycode == UP || keycode == W)
	{
		if (data->map[data->y / 60 - 1][data->x / 60] != '1')
			move_dirction(data, 1);
	}
	else if (keycode == DOWN || keycode == S)
	{
		if (data->map[data->y / 60 + 1][data->x / 60] != '1')
			move_dirction(data, 2);
	}
	else if (keycode == LEFT || keycode == A)
	{
		if (data->map[data->y / 60][data->x / 60 - 1] != '1')
			move_dirction(data, 3);
	}
	else if (keycode == RIGHT || keycode == D)
	{
		if (data->map[data->y / 60][data->x / 60 + 1] != '1')
			move_dirction(data, 4);
	}
	check_coin_exit(data, keycode);
	return (0);
}
