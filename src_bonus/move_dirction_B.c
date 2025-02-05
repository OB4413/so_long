/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dirction_B.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:30:51 by obarais           #+#    #+#             */
/*   Updated: 2025/02/05 16:25:14 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	the_rest(t_data *data, int i)
{
	if (data->anwlp && i == 3)
	{
		data->x -= 60;
		data->inlophok = 'W';
		mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).x
			+ 60, (*data).y);
	}
	else if (data->anwlp && i == 4)
	{
		data->x += 60;
		data->inlophok = 'W';
		mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).x
			- 60, (*data).y);
	}
}

int	move_dirction(t_data *data, int i)
{
	if (data->anwlp && i == 1)
	{
		data->y -= 60;
		data->inlophok = 'W';
		mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).x,
			(*data).y + 60);
	}
	else if (data->anwlp && i == 2)
	{
		data->y += 60;
		data->inlophok = 'W';
		mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).x,
			(*data).y - 60);
	}
	the_rest(data, i);
	mlx_put_image_to_window(data->mlx, data->win, data->wall, 60, 0);
	data->count_move++;
	data->m = ft_itoa(data->count_move);
	mlx_string_put(data->mlx, data->win, 60, 34, 0x00000000, data->m);
	mlx_string_put(data->mlx, data->win, 61, 34, 0x00000000, data->m);
	mlx_string_put(data->mlx, data->win, 62, 34, 0x00000000, data->m);
	mlx_string_put(data->mlx, data->win, 60, 35, 0x00000000, data->m);
	mlx_string_put(data->mlx, data->win, 61, 35, 0x00000000, data->m);
	mlx_string_put(data->mlx, data->win, 62, 35, 0x00000000, data->m);
	return (free(data->m), 0);
}
