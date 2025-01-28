/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mapB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:00:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/28 10:09:24 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw_coin_B(t_data *data)
{
	static int i;
	int j;

	i = 0;
	if (i == 7)
		i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 50000)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->ancion[i], data->cx, data->cy);
			j++;
		}
		i++;
	}
	return 0;
}

static void	the_rest_B(int fd, t_data *data, int x, int y)
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
		else if (buffer[0] == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
		else if (buffer[0] == 'C')
		{
			data->cx = x;
			data->cy = y;
			mlx_loop_hook(data->mlx, draw_coin_B, data);
		}
		else if (buffer[0] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
		else if (buffer[0] == '\n')
		{
			y += 60;
			x = -60;
		}
		x += 60;
	}
}

void	ft_draw_map_B(t_data *data, char *map)
{
	int		fd;
	int		x;
	int		y;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		prinft_error(2);
	x = 0;
	y = 0;
	the_rest_B(fd, data, x, y);
	close(fd);
}
