/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_to_ckek_wall.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:58:57 by obarais           #+#    #+#             */
/*   Updated: 2025/01/15 21:53:48 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **ft_char_map(int win_heigth)
{
    char **map;
    int i;
    int fd;
    
    fd = open("map.ber", O_RDONLY);
    i = 0;
    if (fd < 0)
    {
        printf("Error: Failed to open map file\n");
        exit(1);
    }
    map = (char **)malloc(sizeof(char *) * (win_heigth + 1));
    if (!map)
    {
        printf("Error: Failed to allocate memory for map\n");
        exit(1);
    }
    while (i < win_heigth)
    {
        map[i] = get_next_line(fd);
        if (!map[i])
        {
            printf("Error: Failed to read map file\n");
            exit(1);
        }
        i++;
    }
    get_next_line(fd);
    close(fd);
    map[i] = NULL;
    return (map);
}

void free_map(char **map)
{
    int i = 0;

    if (!map)
        return;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void free_resources(t_data *data)
{
    if (data->player)
    {
        mlx_destroy_image(data->mlx, data->player);
        data->player = NULL;
    }

    if (data->wall)
    {
        mlx_destroy_image(data->mlx, data->wall);
        data->wall = NULL;
    }

    if (data->floor)
    {
        mlx_destroy_image(data->mlx, data->floor);
        data->floor = NULL;
    }

    if (data->coin)
    {
        mlx_destroy_image(data->mlx, data->coin);
        data->coin = NULL;
    }

    if (data->map)
    {
        free_map(data->map);
        data->map = NULL;
    }

    if (data->win)
    {
        mlx_destroy_window(data->mlx, data->win);
        data->win = NULL;
    }

    // if (data->mlx)
    // {
    //     mlx_destroy_display(data->mlx);
    //     free(data->mlx);
    //     data->mlx = NULL;
    // }
}
