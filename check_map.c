/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:43 by obarais           #+#    #+#             */
/*   Updated: 2025/01/20 21:52:34 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_count_CPE(char **map)
{
	int	i;
	int	j;
	int	C;
	int	P;
	int	E;

	j = 0;
	C = 0;
	P = 0;
	E = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				C++;
			else if (map[j][i] == 'P')
				P++;
			else if (map[j][i] == 'E')
				E++;
			i++;
		}
		j++;
	}
	if (C < 1 || P != 1 || !(E == 1))
	{
		printf("Error: ++Map is invalid\n");
		exit(1);
	}
}

static void ft_check_wall(char **map, t_data *data)
{
    int i;
    int j;

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
                    printf("Error: ++Map is invalid\n");
                    exit(1);
                }
                j++;
            }
        }
        else if (i == data->win_height - 1)
        {
            while (map[i][j])
            {
                if (map[i][j] != '1')
                {
                    printf("Error: --Map is invalid\n");
                    exit(1);
                }
                j++;
            }
        }
        else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
        {
            printf("Error: ==Map is invalid\n");
            exit(1);
        }
        i++;
    }
}

static void ft_check_other(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E')
            {
                printf("Error: Map is invalid\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void	check_map(char **map, t_data *data)
{
	ft_count_CPE(map);
    ft_check_wall(map, data);
    ft_check_other(map);
}