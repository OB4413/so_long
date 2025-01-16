/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:43 by obarais           #+#    #+#             */
/*   Updated: 2025/01/14 18:50:47 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(int win_heigth)
{
    int fd;
    char *line;
    int i;
    int j;

    fd = open("map.ber", O_RDONLY);
    i = 1;
    if (fd < 0)
    {
        printf("Error: Failed to open map file\n");
        return (0);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        j = 0;
        if (i == 1)
        {
            while (line[j] != '\n')
            {
                if (line[j] != '1')
                {
                    printf("Error: Invalid map\n");
                    return (1);
                }
                j++;
            }
        }
        else if (win_heigth == i)
        {
            while (line[j] != '\n' && line[j] != '\0')
            {
                if (line[j] != '1')
                {
                    printf("Error: Invalid map\n");
                    return (1);
                }
                j++;
            }
        }
        else
        {
            if (line[j] != '1')
            {
                printf("Error: Invalid map\n");
                return (1);
            }
            while (line[j] != '\n')
                j++;
            if (line[j - 1] != '1')
            {
                printf("Error: Invalid map\n");
                return (1);
            }
        }
        i++;
        free(line);
    }
    close(fd);
    return (0);
}
