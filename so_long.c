/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:43:23 by obarais           #+#    #+#             */
/*   Updated: 2025/01/15 21:50:17 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(t_data *data)
{
    int x, y;

    data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &x, &y);
    data->floor = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm", &x, &y);
    data->player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &x, &y);
    data->coin = mlx_xpm_file_to_image(data->mlx, "textures/meat.xpm", &x, &y);

    if (!data->wall || !data->floor || !data->player)
    {
        printf("Error: Failed to load images\n");
        exit(1);
    }
}

void draw_map(t_data *data, const char *map_path)
{
    int fd = open(map_path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error: Failed to open map file\n");
        exit(1);
    }

    char buffer[2];
    int i = 1;
    int x = 0;
    int y = 0;

    while ((i = read(fd, buffer, 1)) > 0)
    {
        buffer[1] = '\0';
        if (buffer[0] == '1')
            mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
        else if (buffer[0] == '0')
            mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
        else if (buffer[0] == 'P')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
            data->player_x = x;
            data->player_y = y;
        }
        else if (buffer[0] == 'C')
            mlx_put_image_to_window(data->mlx, data->win, data->coin, x, y);
        else if (buffer[0] == '\n')
        {
            y += 40;
            x = -40;
        }
        x += 40;
    }

    close(fd);
}

int main(int ac, char **av)
{
    t_data  data;
    (void)ac;
    (void)av;

    data.mlx = mlx_init();
    if (!data.mlx)
    {
        printf("Error: Failed to initialize MiniLibX\n");
        return (1);
    }
    
    data.win = opne_windows(&data);
    if (!data.win)
    {
        printf("Error: Failed to create window\n");
        return (1);
    }

    load_images(&data);
    draw_map(&data, "map.ber");
    data.map = ft_char_map(data.win_height);
    
    mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    
    mlx_loop(data.mlx);
    
    return (0);
}
