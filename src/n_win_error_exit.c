/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_win_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:40:38 by obarais           #+#    #+#             */
/*   Updated: 2025/01/27 10:32:35 by obarais          ###   ########.fr       */
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

void	move_dirction_0(t_data *data, int i)
{
	if (data->player && (i == UP || i == W))
	{
		move_dirction(data, 2);
		mlx_put_image_to_window(data->mlx, data->win, data->exit, (*data).x,
			(*data).y - 60);
	}
	else if (data->player && (i == DOWN || i == S))
	{
		move_dirction(data, 1);
		mlx_put_image_to_window(data->mlx, data->win, data->exit, (*data).x,
			(*data).y + 60);
	}
	else if (data->player && (i == LEFT || i == A))
	{
		move_dirction(data, 4);
		mlx_put_image_to_window(data->mlx, data->win, data->exit, (*data).x
			- 60, (*data).y);
	}
	else if (data->player && (i == RIGHT || i == D))
	{
		move_dirction(data, 3);
		mlx_put_image_to_window(data->mlx, data->win, data->exit, (*data).x
			+ 60, (*data).y);
	}
}
