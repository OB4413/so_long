/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:40:38 by obarais           #+#    #+#             */
/*   Updated: 2025/01/18 21:51:09 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    *opne_windows(t_data *data)
{
    void *mlx;
    int win_width = 0;
    int win_height = 0;
    int fd;
    char *line;
    int i;

    fd = open("map.ber", O_RDONLY);
    if (fd < 0)
    {
        printf("Error: Failed to open map file\n");
        return (NULL);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        i = ft_strlen(line);
        if(i > win_width)
            win_width = i - 1;
        free(line);
        win_height++;
    }
    close(fd);
    data->win_width = win_width;
    data->win_height = win_height;
    mlx = mlx_new_window(data->mlx, data->win_width * 60, data->win_height * 60, "so_long");
    return (mlx);
}