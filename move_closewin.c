/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_closewin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/15 21:49:40 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data)
{
    free_resources(data);
    return (0);
}

static  int move_dirction(t_data *data, int i)
{
    if(data->player && i == 1)
    {
        data->player_y -= 40;
        mlx_put_image_to_window(data->mlx, data->win, data->player, (*data).player_x , (*data).player_y);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).player_x , (*data).player_y + 40);
    }
    else if(data->player && i == 2)
    {
        data->player_y += 40;
        mlx_put_image_to_window(data->mlx, data->win, data->player, (*data).player_x, (*data).player_y);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).player_x, (*data).player_y - 40);
    }
    else if(data->player && i == 3)
    {
        data->player_x -= 40;
        mlx_put_image_to_window(data->mlx, data->win, data->player, (*data).player_x, (*data).player_y);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).player_x + 40, (*data).player_y);
    }
    else if(data->player && i == 4)
    {
        data->player_x += 40;
        mlx_put_image_to_window(data->mlx, data->win, data->player, (*data).player_x, (*data).player_y);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).player_x - 40, (*data).player_y);
    }
    return (0);
}

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == ESC_KEY)
        close_window(data);
    else if (keycode == Up || keycode == W)
    {
        if (data->map[data->player_y / 40 - 1][data->player_x / 40] != '1')
            move_dirction(data , 1);
    }
    else if (keycode == Down || keycode == S)
    {
        if (data->map[data->player_y / 40 + 1][data->player_x / 40] != '1')
            move_dirction(data , 2);
    }
    else if (keycode == Left || keycode == A)
    {
        if (data->map[data->player_y / 40][data->player_x / 40 - 1] != '1')
            move_dirction(data, 3);
    }
    else if (keycode == Right || keycode == D)
    {
        if (data->map[data->player_y / 40][data->player_x / 40 + 1] != '1')
            move_dirction(data, 4);
    }
    return (0);
}
