/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mapB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:00:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/27 16:43:59 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_coin_B(int x, int y, t_data *data)
{
	int i;

	i = 0;
	while (data->ancion[i])
	{
		mlx_put_image_to_window(data->mlx, data->win, data->ancion[i], x, y);
		i++;
	}
	i = 0;
	mlx_loop(data->mlx);
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
			draw_coin_B(x, y, data);
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
