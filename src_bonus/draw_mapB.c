/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mapB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:00:39 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 10:39:42 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
