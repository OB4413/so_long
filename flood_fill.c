/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:17:45 by obarais           #+#    #+#             */
/*   Updated: 2025/01/20 21:29:32 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(int x, int y, t_data *data)
{
    if (x < 0 || y < 0 || x >= data->win_width || y >= data->win_height || data->str[y][x] == '1')
        return ;
    data->str[y][x] = '1';
    ft_flood_fill(x + 1, y, data);
    ft_flood_fill(x - 1, y, data);
    ft_flood_fill(x, y + 1, data);
    ft_flood_fill(x, y - 1, data);
}

void    postion_player(char **map, t_data *data)
{
    int i = 0;
    int j = 0;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                data->player_x = j * 60;
                data->player_y = i * 60;
                return ;
            }
            j++;
        }
        i++;
    }
    printf("Error: Player not found\n");
    exit(1);
}

void    ft_check_flood(int x, int y, t_data *data)
{
    ft_flood_fill(x, y, data);
    if (ft_count_coin(data->str) != 0)
    {
        printf("Error: Map is invalid\n");
        exit(1);
    }
    if (ft_count_coin(data->str) != 0)
    {
        printf("Error: Map is invalid\n");
        exit(1);
    }
}