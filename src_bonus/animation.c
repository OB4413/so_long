/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:36 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 10:25:35 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	animathin_coin(t_data *data)
{
	static int	i = 0;
	static int	j = 0;

	if (i == 7)
		i = 0;
	while (j < (data->i * 2))
	{
		if (data->xyancion[j] != -1 && data->xyancion[j + 1] != -1)
			mlx_put_image_to_window(data->mlx, data->win, data->ancion[i], data->xyancion[j], data->xyancion[j + 1]);
		j += 2;
	}
	j = 0;
	i++;
}

int	animathin_help(t_data *data)
{
	static int  h = 1;
	static int	k = 0;
	static int	l = 0;
	static int	t = 1;
	static int 	m = 0;
	static int	n = 0;

	animathin_coin(data);
	if (t == 3)
	{
		t = 0;
		n++;
	}
	if (n == 4)
	{
		while (n == 4 && m < (data->j * 2))
		{
			mlx_put_image_to_window(data->mlx, data->win, data->floor, data->xye[m], data->xye[m + 1]);
			ft_move_enemy(data, m);
			m += 2;
		}
		n = 0;
	}
	m = 0;
	while (m < (data->j * 2))
	{
		
		mlx_put_image_to_window(data->mlx, data->win, data->anse[t], data->xye[m], data->xye[m + 1]);
		m += 2;
	}
	usleep(2000);
	m = 0;
	t++;

	if (data->inlophok == 'S')
	{
		usleep(100000);
		mlx_put_image_to_window(data->mlx, data->win, data->anwp[h], data->x, data->y);
		if (h == 6)
			h = 0;
		h++;
		k = 0;
		l = 0;
	}
	else if (data->inlophok == 'W')
	{
		usleep(50000);
		mlx_put_image_to_window(data->mlx, data->win, data->anwlp[k], data->x, data->y);
		if (k == 9)
		{
			data->inlophok = 'S';
			k = 0;
		}
		k++;
		h = 0;
		l = 0;
	}
	else if (data->inlophok == 'E')
	{
		usleep(100000);
		mlx_put_image_to_window(data->mlx, data->win, data->anep[l], data->x, data->y);
		if (l == 8)
		{
			data->inlophok = 'S';
			l = 0;
		}
		l++;
		k = 0;
		h = 0;
	}
	return (0);
}

void	animation(t_data *data, char buffer, int x, int y)
{
    static int j = 0;
	static int k = 0;
    
    if (buffer == 'P' || buffer == 'C' || buffer == 'U')
	{
		if (buffer == 'P' && x != -1 && y != -1)
			mlx_put_image_to_window(data->mlx, data->win, data->anwp[0], x, y);
		if (buffer == 'C' && x != -1 && y != -1)
		{
			data->xyancion[j] = x;
			data->xyancion[j + 1] = y;
			mlx_put_image_to_window(data->mlx, data->win, data->ancion[0], x, y);
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
