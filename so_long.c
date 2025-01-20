/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:43:23 by obarais           #+#    #+#             */
/*   Updated: 2025/01/20 22:47:15 by obarais          ###   ########.fr       */
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
    data->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm", &x, &y);
    data->not_exit = mlx_xpm_file_to_image(data->mlx, "textures/not_exit.xpm", &x, &y);

    if (!data->wall || !data->floor || !data->player || !data->coin || !data->exit)
    {
        printf("Error: Failed to load images\n");
        exit(1);
    }
}

void draw_map(t_data *data,char *map)
{
    int fd = open(map, O_RDONLY);
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
            mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
        else if (buffer[0] == 'C')
            mlx_put_image_to_window(data->mlx, data->win, data->coin, x, y);
        else if (buffer[0] == 'E')
            mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
        else if (buffer[0] == '\n')
        {
            y += 60;
            x = -60;
        }
        x += 60;
    }

    close(fd);
}

int main(int ac, char **av)
{
    t_data  data;
    data.num = 0;
    data.count_move = 0;
    
    if (ac != 2 || ft_check_path(av[1]))
    {
        printf("Error: Invalid number of arguments\n");
        return (1);
    }
    data.map = ft_char_map(av[1], &data);
    check_map(data.map, &data);
    data.i = ft_count_coin(data.map);
    postion_player(data.map, &data);
    data.str = ft_char_map(av[1], &data);
    ft_check_flood(data.player_x / 60, data.player_y / 60, &data);
    free_map(data.str);
    
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
    draw_map(&data, av[1]);
    
    mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    
    mlx_loop(data.mlx);
    
    return (0);
}
