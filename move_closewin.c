/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_closewin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:39 by obarais           #+#    #+#             */
/*   Updated: 2025/01/19 18:48:51 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data)
{
    if(data->win)
        free_resources(data);
    return (0);
}

static  int move_dirction(t_data *data, int i)
{
    if(data->player && i == 1)
    {
        data->player_y -= 60;
        mlx_put_image_to_window(data->mlx, data->win, data->player, (*data).player_x , (*data).player_y);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).player_x , (*data).player_y + 60);
        data->count_move++;
        printf("count_move = %zu\n", data->count_move);
    }
    else if(data->player && i == 2)
    {
        data->player_y += 60;
        mlx_put_image_to_window(data->mlx, data->win, data->player, (*data).player_x, (*data).player_y);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).player_x, (*data).player_y - 60);
        data->count_move++;
        printf("count_move = %zu\n", data->count_move);
    }
    else if(data->player && i == 3)
    {
        data->player_x -= 60;
        mlx_put_image_to_window(data->mlx, data->win, data->player, (*data).player_x, (*data).player_y);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).player_x + 60, (*data).player_y);
        data->count_move++;
        printf("count_move = %zu\n", data->count_move);
    }
    else if(data->player && i == 4)
    {
        data->player_x += 60;
        mlx_put_image_to_window(data->mlx, data->win, data->player, (*data).player_x, (*data).player_y);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, (*data).player_x - 60, (*data).player_y);
        data->count_move++;
        printf("count_move = %zu\n", data->count_move);
    }
    return (0);
}

static void move_dirction_0(t_data *data, int i)
{
    int j = 50000;
    if(data->player && i == 1)
    {
        while (j > 0)
        {
            mlx_put_image_to_window(data->mlx, data->win, data->not_exit, (*data).player_x, (*data).player_y);
            j--;
        }
        move_dirction(data, 1);
        mlx_put_image_to_window(data->mlx, data->win, data->not_exit, (*data).player_x, (*data).player_y + 60);
    }
    else if(data->player && i == 2)
    {
        while (j > 0)
        {
            mlx_put_image_to_window(data->mlx, data->win, data->not_exit, (*data).player_x, (*data).player_y);
            j--;
        }
        move_dirction(data, 2);
        mlx_put_image_to_window(data->mlx, data->win, data->exit, (*data).player_x, (*data).player_y - 60);
    }
    else if(data->player && i == 3)
    {
        while (j > 0)
        {
            mlx_put_image_to_window(data->mlx, data->win, data->not_exit, (*data).player_x, (*data).player_y);
            j--;
        }
        move_dirction(data, 3);
        mlx_put_image_to_window(data->mlx, data->win, data->exit, (*data).player_x + 60, (*data).player_y);
    }
    else if(data->player && i == 4)
    {
        while (j > 0)
        {
            mlx_put_image_to_window(data->mlx, data->win, data->not_exit, (*data).player_x, (*data).player_y);
            j--;
        }
        move_dirction(data, 4);
        mlx_put_image_to_window(data->mlx, data->win, data->exit, (*data).player_x - 60, (*data).player_y);
    }
}

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == ESC_KEY)
        close_window(data);
    else if (keycode == Up || keycode == W)
    {
        if (data->map[data->player_y / 60 - 1][data->player_x / 60] != '1')
            move_dirction(data , 1);
        if (data->map[data->player_y / 60][data->player_x / 60] == 'C')
        {
            data->num++;
            data->map[data->player_y / 60][data->player_x / 60] = '0';
        }
        if (data->map[data->player_y / 60][data->player_x / 60] == 'E')
        {
            if (data->num == data->i)
            {
                printf("you win!");
                free_resources(data);
                exit(0);
            }
            move_dirction_0(data, 2);
        }
    }
    else if (keycode == Down || keycode == S)
    {
        if (data->map[data->player_y / 60 + 1][data->player_x / 60] != '1')
            move_dirction(data , 2);
        if (data->map[data->player_y / 60][data->player_x / 60] == 'C')
        {
            data->num++;
            data->map[data->player_y / 60][data->player_x / 60] = '0';
        }
        if (data->map[data->player_y / 60][data->player_x / 60] == 'E')
        {
            if (data->num == data->i)
            {
                printf("you win!");
                free_resources(data);
                exit(0);
            }
            move_dirction_0(data, 1);
        }
    }
    else if (keycode == Left || keycode == A)
    {
        if (data->map[data->player_y / 60][data->player_x / 60 - 1] != '1')
            move_dirction(data, 3);
        if (data->map[data->player_y / 60][data->player_x / 60] == 'C')
        {
            data->num++;
            data->map[data->player_y / 60][data->player_x / 60] = '0';
        }
        if (data->map[data->player_y / 60 ][data->player_x / 60] == 'E')
        {
            if (data->num == data->i)
            {
                printf("you win!");
                free_resources(data);
                exit(0);
            }
            move_dirction_0(data, 4);
        }
    }
    else if (keycode == Right || keycode == D)
    {
        if (data->map[data->player_y / 60][data->player_x / 60 + 1] != '1')
            move_dirction(data, 4);
        if (data->map[data->player_y / 60][data->player_x / 60] == 'C')
        {
            data->num++;
            data->map[data->player_y / 60][data->player_x / 60] = '0';
        }
        if (data->map[data->player_y / 60 ][data->player_x / 60] == 'E')
        {
            
            if (data->num == data->i)
            {
                printf("you win!");
                free_resources(data);
                exit(0);
            }
            move_dirction_0(data, 3);
        }
    }
    return (0);
}
