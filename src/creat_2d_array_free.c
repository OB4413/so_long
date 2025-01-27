/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_2d_array_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:58:57 by obarais           #+#    #+#             */
/*   Updated: 2025/01/26 18:08:52 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_trmnation(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
}

char	**ft_char_map(char *av, t_data *data)
{
	char	**map;
	int		i;
	int		fd;
	int		lenmap;

	fd = open(av, O_RDONLY);
	i = 0;
	if (fd < 0)
		exit(1);
	ft_len_map(av, data);
	lenmap = data->win_height;
	map = (char **)malloc(sizeof(char *) * (lenmap + 1));
	if (!map)
		exit(1);
	while (i < lenmap)
	{
		map[i] = get_next_line(fd);
		put_trmnation(map[i]);
		if (!map[i])
			exit(1);
		i++;
	}
	get_next_line(fd);
	map[i] = NULL;
	return (close(fd), map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_resources(t_data *data)
{
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->not_exit)
		mlx_destroy_image(data->mlx, data->not_exit);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->map)
		free_map(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
}
