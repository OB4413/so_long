/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_win_error_exit_B.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:40:38 by obarais           #+#    #+#             */
/*   Updated: 2025/02/01 12:54:42 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*opne_windows(t_data *data)
{
	void	*mlx;

	mlx = mlx_new_window(data->mlx, data->win_width * 60, data->win_height * 60,
			"so_long");
	return (mlx);
}

static void	help_help_check_coin_exit_b(t_data *data, int keycode)
{
	if (data->map[data->y / 60][data->x / 60 - 1] == 'E' && (keycode == LEFT
			|| keycode == A))
	{
		if (data->num == data->i)
		{
			printf("you win!");
			free_resources_b(data);
			exit(0);
		}
		ft_printf("Error:\nwa si rak mzal mklitych l7am kamlo\n");
	}
	else if (data->map[data->y / 60][data->x / 60 + 1] == 'E'
		&& (keycode == RIGHT || keycode == D))
	{
		if (data->num == data->i)
		{
			printf("you win!");
			free_resources_b(data);
			exit(0);
		}
		ft_printf("Error:\nwa si rak mzal mklitych l7am kamlo\n");
	}
}

void	help_check_coin_exit_b(t_data *data, int keycode)
{
	if (data->map[data->y / 60 - 1][data->x / 60] == 'E' && (keycode == UP
			|| keycode == W))
	{
		if (data->num == data->i)
		{
			printf("you win!");
			free_resources_b(data);
			exit(0);
		}
		ft_printf("Error:\nwa si rak mzal mklitych l7am kamlo\n");
	}
	else if (data->map[data->y / 60 + 1][data->x / 60] == 'E'
		&& (keycode == DOWN || keycode == S))
	{
		if (data->num == data->i)
		{
			printf("you win!");
			free_resources_b(data);
			exit(0);
		}
		ft_printf("Error:\nwa si rak mzal mklitych l7am kamlo\n");
	}
	else
		help_help_check_coin_exit_b(data, keycode);
}
