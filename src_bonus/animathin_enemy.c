/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animathin_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:50:52 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 15:23:52 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_move_enemy_help(t_data *data, int m, int i, int j)
{
	if (data->map[j + 1][i] == 'T')
	{
		data->map[j][i] = '0';
		data->xye[m + 1] += 60;
		data->map[data->xye[m + 1] / 60][data->xye[m] / 60] = 'U';
	}
	else if (data->map[j][i + 1] == 'T')
	{
		data->map[j][i] = '0';
		data->xye[m] += 60;
		data->map[data->xye[m + 1] / 60][data->xye[m] / 60] = 'U';
	}
}

void	ft_move_enemy(t_data *data, int m)
{
	int	i;
	int	j;

	i = data->xye[m] / 60;
	j = data->xye[m + 1] / 60;
	if (data->map[j - 1][i] == 'T')
	{
		data->map[j][i] = '0';
		data->xye[m + 1] -= 60;
		data->map[data->xye[m + 1] / 60][data->xye[m] / 60] = 'U';
	}
	else if (data->map[j][i - 1] == 'T')
	{
		data->map[j][i] = '0';
		data->xye[m] -= 60;
		data->map[data->xye[m + 1] / 60][data->xye[m] / 60] = 'U';
	}
	else
		ft_move_enemy_help(data, m, i, j);
	if (data->x == data->xye[m] && data->y == data->xye[m + 1])
		ft_check_enemy(data);
}

static void	animathin_enemy_help(t_data *data, int m, int t)
{
	while (m < (data->j * 2))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->anse[t],
			data->xye[m], data->xye[m + 1]);
		m += 2;
	}
}

void	animathin_enemy(t_data *data)
{
	static int	t = 1;
	static int	m = 0;
	static int	n = 0;

	if (t == 3)
	{
		t = 0;
		n++;
	}
	if (n == 2)
	{
		while (n == 2 && m < (data->j * 2))
		{
			mlx_put_image_to_window(data->mlx, data->win, data->floor,
				data->xye[m], data->xye[m + 1]);
			ft_move_enemy(data, m);
			m += 2;
		}
		n = 0;
	}
	m = 0;
	animathin_enemy_help(data, m, t);
	usleep(2000);
	m = 0;
	t++;
}
