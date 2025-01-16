/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:40:38 by obarais           #+#    #+#             */
/*   Updated: 2025/01/15 09:55:52 by obarais          ###   ########.fr       */
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
    if (check_map(win_height) == 1)
        return (NULL);
    data->win_width = win_width;
    data->win_height = win_height;
    mlx = mlx_new_window(data->mlx, data->win_width * 40, data->win_height * 40, "so_long");
    return (mlx);
}