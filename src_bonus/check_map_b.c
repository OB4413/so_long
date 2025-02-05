/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:35 by obarais           #+#    #+#             */
/*   Updated: 2025/02/05 10:26:03 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	help_conut_cpe(int *c, int *p, int *e, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				*c += 1;
			else if (map[j][i] == 'P')
				*p += 1;
			else if (map[j][i] == 'E')
				*e += 1;
			i++;
		}
		j++;
	}
}

static void	ft_count_cpe(char **map, t_data *data)
{
	int	c;
	int	p;
	int	e;

	c = 0;
	p = 0;
	e = 0;
	help_conut_cpe(&c, &p, &e, map);
	if (c < 1 || p != 1 || !(e == 1))
	{
		free_map(data->map);
		printf_error(1);
	}
}

static void	help_ckeck_wall(char **map, int i, int j, t_data *data)
{
	if (i == data->win_height - 1)
	{
		while (map[i][j])
		{
			if (map[i][j] != '1')
			{
				free_map(data->map);
				printf_error(1);
			}
			j++;
		}
	}
	else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
	{
		free_map(data->map);
		printf_error(1);
	}
}

static void	ft_check_wall(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0)
		{
			while (map[0][j])
			{
				if (map[0][j] != '1')
				{
					free_map(data->map);
					printf_error(1);
				}
				j++;
			}
		}
		help_ckeck_wall(map, i, j, data);
		i++;
	}
}

void	check_map_b(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	ft_count_cpe(map, data);
	ft_check_wall(map, data);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'U')
			{
				free_map(data->map);
				printf_error(1);
			}
			j++;
		}
		i++;
	}
}
