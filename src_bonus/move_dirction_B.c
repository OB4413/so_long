/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dirction_B.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:30:51 by obarais           #+#    #+#             */
/*   Updated: 2025/01/30 21:10:43 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	the_rest(t_data *data, int i)
{
	if (data->player && i == 3)
	{
		data->x -= 60;
		mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).x
			+ 60, (*data).y);
	}
	else if (data->player && i == 4)
	{
		data->x += 60;
		mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).x
			- 60, (*data).y);
	}
	check_coin_exit_b(data, i);
}

int	move_dirction(t_data *data, int i)
{
	if (data->player && i == 1)
	{
		data->y -= 60;
		mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).x,
			(*data).y + 60);
	}
	else if (data->player && i == 2)
	{
		data->y += 60;
		mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).x,
			(*data).y - 60);
	}
	the_rest(data, i);
	data->inlophok = 'W';
	data->count_move++;
	ft_printf("Moves: %d\n", data->count_move);
	return (0);
}
