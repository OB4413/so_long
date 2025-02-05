/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:58:21 by obarais           #+#    #+#             */
/*   Updated: 2025/02/05 10:18:47 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_check_path(char *path)
{
	size_t	i;
	int		j;

	i = ft_strlen(path);
	i--;
	if (path[0] == '.')
	{
		printf("Error: Invalid file path or extension\n");
		exit(1);
	}
	j = 0;
	while (path[j])
	{
		if (path[j] == '/')
		{
			if (path[j + 1] == '.' || (path[i] != 'r' || path[i - 1] != 'e' || path[i - 2] != 'b' || path[i- 3] != '.' || path[i - 4] == '/'))
			{
				printf("Error: Invalid file path or extension\n");
				exit(1);
			}
		}
		j++;
	}
	return (NULL);
}
