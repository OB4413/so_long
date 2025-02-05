/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_2d_array_free_B.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:58:57 by obarais           #+#    #+#             */
/*   Updated: 2025/02/05 16:30:39 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	printf_error(int i)
{
	if (i == 1)
	{
		printf("Error: Map is invalid\n");
		exit(1);
	}
	else if (i == 2)
	{
		printf("Error: Failed to open map file\n");
		exit(1);
	}
	else if (i == 4)
	{
		printf("Error: Failed to allocate memory\n");
		exit(1);
	}
	else if (i == 5)
	{
		printf("Error: Invalid file path or extension\n");
		exit(1);
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
		printf_error(2);
	ft_len_map(av, data);
	lenmap = data->win_height;
	map = (char **)malloc(sizeof(char *) * (lenmap + 1));
	if (!map)
		printf_error(4);
	while (i < lenmap)
	{
		map[i] = get_next_line(fd);
		put_trmnation(map[i]);
		if (!map[i])
			printf_error(4);
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

void	free_resources_b(t_data *data)
{
	int	i;

	i = 0;
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->ancion)
	{
		while (data->ancion[i])
		{
			mlx_destroy_image(data->mlx, data->ancion[i]);
			i++;
		}
		free(data->ancion);
	}
	if (data->anwp)
	{
		i = 0;
		while (data->anwp[i])
		{
			mlx_destroy_image(data->mlx, data->anwp[i]);
			i++;
		}
		free(data->anwp);
	}
	if (data->anwlp)
	{
		i = 0;
		while (data->anwlp[i])
		{
			mlx_destroy_image(data->mlx, data->anwlp[i]);
			i++;
		}
		free(data->anwlp);
	}
	if (data->anep)
	{
		i = 0;
		while (data->anep[i])
		{
			mlx_destroy_image(data->mlx, data->anep[i]);
			i++;
		}
		free(data->anep);
	}
	if (data->andp)
	{
		i = 0;
		while (data->andp[i])
		{
			mlx_destroy_image(data->mlx, data->andp[i]);
			i++;
		}
		free(data->andp);
	}
	if (data->anwle)
	{
		i = 0;
		while (data->anwle[i])
		{
			mlx_destroy_image(data->mlx, data->anwle[i]);
			i++;
		}
		free(data->anwle);
	}
	if (data->anse)
	{
		i = 0;
		while (data->anse[i])
		{
			mlx_destroy_image(data->mlx, data->anse[i]);
			i++;
		}
		free(data->anse);
	}
	if (data->moves)
		mlx_destroy_image(data->mlx, data->moves);
	if (data->xyancion)
		free(data->xyancion);
	if (data->xye)
		free(data->xye);
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
