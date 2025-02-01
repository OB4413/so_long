/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coin_E.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:41:37 by obarais           #+#    #+#             */
/*   Updated: 2025/02/01 16:08:34 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_coin_enemy(char **map, t_data *data)
{
	int	i;
	int	j;
	int	k;
	int l;

	j = 0;
	k = 0;
	l = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				k++;
			if (map[j][i] == 'U')
				l++;
			i++;
		}
		j++;
	}
	data->i = k;
	data->j = l;
}

int	ft_count_exit(char **map)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				k++;
			i++;
		}
		j++;
	}
	return (k);
}
