/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_win_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:40:38 by obarais           #+#    #+#             */
/*   Updated: 2025/01/27 11:01:59 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*opne_windows(t_data *data)
{
	void	*mlx;

	mlx = mlx_new_window(data->mlx, data->win_width * 60, data->win_height * 60,
			"so_long");
	return (mlx);
}

static void	help_help_check_coin_exit(t_data *data, int keycode)
{
	if (data->map[data->y / 60][data->x / 60 - 1] == 'E' && data->num == data->i
		&& (keycode == LEFT || keycode == A))
	{
		printf("you win!");
		free_resources(data);
		exit(0);
	}
	else if (data->map[data->y / 60][data->x / 60 + 1] == 'E'
		&& data->num == data->i && (keycode == RIGHT || keycode == D))
	{
		printf("you win!");
		free_resources(data);
		exit(0);
	}
}

void	help_check_coin_exit(t_data *data, int keycode)
{
	if (data->map[data->y / 60 - 1][data->x / 60] == 'E' && data->num == data->i
		&& (keycode == UP || keycode == W))
	{
		printf("you win!");
		free_resources(data);
		exit(0);
	}
	else if (data->map[data->y / 60 + 1][data->x / 60] == 'E'
		&& data->num == data->i && (keycode == DOWN || keycode == S))
	{
		printf("you win!");
		free_resources(data);
		exit(0);
	}
	help_help_check_coin_exit(data, keycode);
}
