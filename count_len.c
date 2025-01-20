/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:44:24 by obarais           #+#    #+#             */
/*   Updated: 2025/01/20 21:16:52 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_len_map(char *av, t_data *data)
{
    int fd;
    char *line;
    int i;
    int j = 0;
    int k = 0;

    fd = open(av, O_RDONLY);
    if (fd < 0)
    {
        printf("Error: Failed to open map file\n");
        exit(1);
    }
    while (((line = get_next_line(fd)) != NULL ))
    {
        put_trmnation(line);
        i = ft_strlen(line);
        if((j > i || i > j) && k != 0)
        {
            close(fd);
            printf("Error: Map is invalid \n");
            exit(1);
        }
        j = i;
        free(line);
        k++;
    }
    close(fd);
    data->win_width = j;
    data->win_height = k;
}
