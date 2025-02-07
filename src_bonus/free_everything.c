/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:07:13 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 09:25:18 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_help1(t_data *data)
{
	int	i;

	i = 0;
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->ancion)
	{
		while (data->ancion[i])
		{
			mlx_destroy_image(data->mlx, data->ancion[i]);
			i++;
		}
		free(data->ancion);
	}
	if (data->anwp)
	{
		i = 0;
		while (data->anwp[i])
		{
			mlx_destroy_image(data->mlx, data->anwp[i]);
			i++;
		}
		free(data->anwp);
	}
}

static void	free_help2(t_data *data)
{
	int	i;

	i = 0;
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->anwlp)
	{
		i = 0;
		while (data->anwlp[i])
		{
			mlx_destroy_image(data->mlx, data->anwlp[i]);
			i++;
		}
		free(data->anwlp);
	}
	if (data->anep)
	{
		i = 0;
		while (data->anep[i])
		{
			mlx_destroy_image(data->mlx, data->anep[i]);
			i++;
		}
		free(data->anep);
	}
}

static void	free_help3(t_data *data)
{
	int	i;

	i = 0;
	if (data->andp)
	{
		i = 0;
		while (data->andp[i])
		{
			mlx_destroy_image(data->mlx, data->andp[i]);
			i++;
		}
		free(data->andp);
	}
	if (data->anwle)
	{
		i = 0;
		while (data->anwle[i])
		{
			mlx_destroy_image(data->mlx, data->anwle[i]);
			i++;
		}
		free(data->anwle);
	}
	if (data->moves)
		mlx_destroy_image(data->mlx, data->moves);
}

static void	free_help4(t_data *data)
{
	int	i;

	i = 0;
	if (data->anse)
	{
		i = 0;
		while (data->anse[i])
		{
			mlx_destroy_image(data->mlx, data->anse[i]);
			i++;
		}
		free(data->anse);
	}
	if (data->xyancion)
		free(data->xyancion);
	if (data->xye)
		free(data->xye);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->map)
		free_map(data->map);
}

void	free_resources_b(t_data *data)
{
	free_help1(data);
	free_help2(data);
	free_help3(data);
	free_help4(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
}
