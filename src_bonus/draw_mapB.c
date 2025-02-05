/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mapB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:00:39 by obarais           #+#    #+#             */
/*   Updated: 2025/02/05 16:00:28 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


static void ft_move_enemy(t_data *data, int m)
{
	int i = data->xye[m] / 60;
	int j = data->xye[m + 1] / 60;

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
	else if (data->map[j + 1][i] == 'T')
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
	if (data->x == data->xye[m] && data->y == data->xye[m + 1])
		ft_check_enemy(data);
}


int	draw_coin_b(t_data *data)
{
	static int	i = 1;
	static int	j = 0;
	static int  h = 1;
	static int	k = 0;
	static int	l = 0;
	static int	t = 1;
	static int 	m = 0;
	static int	n = 0;

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

static void	the_rest_b(int fd, t_data *data, int x, int y)
{
	char	buffer[2];
	int		i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, 1);
		buffer[1] = '\0';
		if (buffer[0] == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
		else if (buffer[0] == '0')
			mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
		animation(data, buffer[0], x, y);
		if (buffer[0] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
		else if (buffer[0] == '\n')
		{
			y += 60;
			x = -60;
		}
		x += 60;
	}
}

void	ft_draw_map_b(t_data *data, char *map)
{
	int	fd;
	int	x;
	int	y;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		printf_error(2);
	x = 0;
	y = 0;
	the_rest_b(fd, data, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->moves, 0, 0);
	close(fd);
}
