/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:36 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 15:18:48 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	animathin_coin(t_data *data)
{
	static int	i = 0;
	static int	j = 0;

	if (i == 7)
		i = 0;
	while (j < (data->i * 2))
	{
		if (data->xyancion[j] != -1 && data->xyancion[j + 1] != -1)
			mlx_put_image_to_window(data->mlx, data->win, data->ancion[i],
				data->xyancion[j], data->xyancion[j + 1]);
		j += 2;
	}
	j = 0;
	i++;
}

static void	animathin_players(t_data *data)
{
	if (data->inlophok == 'S')
	{
		usleep(100000);
		mlx_put_image_to_window(data->mlx, data->win, data->anwp[data->h],
			data->x, data->y);
		if (data->h == 6)
			data->h = 0;
		data->h++;
		data->k = 0;
		data->l = 0;
	}
}

static void	animathin_playerw(t_data *data)
{
	if (data->inlophok == 'W')
	{
		usleep(50000);
		mlx_put_image_to_window(data->mlx, data->win, data->anwlp[data->k],
			data->x, data->y);
		if (data->k == 9)
		{
			data->inlophok = 'S';
			data->k = 0;
		}
		data->k++;
		data->h = 0;
		data->l = 0;
	}
}

int	animathin_help(t_data *data)
{
	animathin_coin(data);
	animathin_enemy(data);
	animathin_players(data);
	animathin_playerw(data);
	if (data->inlophok == 'E')
	{
		usleep(100000);
		mlx_put_image_to_window(data->mlx, data->win, data->anep[data->l],
			data->x, data->y);
		if (data->l == 8)
		{
			data->inlophok = 'S';
			data->l = 0;
		}
		data->l++;
		data->k = 0;
		data->h = 0;
	}
	return (0);
}

void	animation(t_data *data, char buffer, int x, int y)
{
	static int	j = 0;
	static int	k = 0;

	if (buffer == 'P' || buffer == 'C' || buffer == 'U')
	{
		if (buffer == 'P' && x != -1 && y != -1)
			mlx_put_image_to_window(data->mlx, data->win, data->anwp[0], x, y);
		if (buffer == 'C' && x != -1 && y != -1)
		{
			data->xyancion[j] = x;
			data->xyancion[j + 1] = y;
			mlx_put_image_to_window(data->mlx, data->win, data->ancion[0], x,
				y);
			j += 2;
		}
		if (buffer == 'U')
		{
			data->xye[k] = x;
			data->xye[k + 1] = y;
			mlx_put_image_to_window(data->mlx, data->win, data->anse[0], x, y);
			k += 2;
		}
		mlx_loop_hook(data->mlx, animathin_help, data);
	}
}
