/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:58:21 by obarais           #+#    #+#             */
/*   Updated: 2025/01/20 22:52:18 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_check_path(char *path)
{
    size_t	i;

    i = ft_strlen(path);
    i--;
    if (path[i] != 'r' || path[i - 1] != 'e' || path[i - 2] != 'b' || path[i - 3] != '.')
    {
        printf("Error: Invalid file extension\n");
        exit(1);
    }
    return (NULL);
}