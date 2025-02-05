/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:44:24 by obarais           #+#    #+#             */
/*   Updated: 2025/02/05 09:42:54 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	the_rest(int fd, char *line, int *j, int *k)
{
	int	i;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		put_trmnation(line);
		i = ft_strlen(line);
		if ((*j > i || i > *j) && *k != 0)
		{
			while (line != NULL)
			{
				free(line);
				line = get_next_line(fd);
			}
			close(fd);
			printf_error(1);
		}
		free(line);
		*j = i;
		*k = *k + 1;
	}
}

void	ft_len_map(char *av, t_data *data)
{
	int		fd;
	char	*line;
	int		j;
	int		k;

	j = 0;
	k = 0;
	line = NULL;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		printf_error(2);
	the_rest(fd, line, &j, &k);
	data->win_height = k;
	data->win_width = j;
	if (data->win_height > 17 || data->win_width > 32)
		printf_error(1);
	close(fd);
}
