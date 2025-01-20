/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coin_E.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:41:37 by obarais           #+#    #+#             */
/*   Updated: 2025/01/20 21:24:45 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_count_coin(char **map)
{
    int i;
    int j;
    int k;

    j = 0;
    k = 0;
    while (map[j])
    {
        i = 0;
        while(map[j][i])
        {
            if(map[j][i] == 'C')
                k++;
            i++;
        }
        j++;
    }
    return (k);
}

int ft_count_exit(char **map)
{
    int i;
    int j;
    int k;

    j = 0;
    k = 0;
    while (map[j])
    {
        i = 0;
        while(map[j][i])
        {
            if(map[j][i] == 'E')
                k++;
            i++;
        }
        j++;
    }
    return (k);
}