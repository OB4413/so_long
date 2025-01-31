/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:36 by obarais           #+#    #+#             */
/*   Updated: 2025/01/31 09:43:25 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation(t_data *data, char buffer, int x, int y)
{
    static int j = 0;
    
    if (buffer == 'P' || buffer == 'C')
	{
		if (buffer == 'P' && x != -1 && y != -1)
			mlx_put_image_to_window(data->mlx, data->win, data->anwp[0], x, y);
		if (buffer == 'C' && x != -1 && y != -1)
		{
			data->xyancion[j] = x;
			data->xyancion[j + 1] = y;
			mlx_put_image_to_window(data->mlx, data->win, data->ancion[0], x, y);
			j += 2;
		}
	    mlx_loop_hook(data->mlx, draw_coin_b, data);
	}
}
