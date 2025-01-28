/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:43:23 by obarais           #+#    #+#             */
/*   Updated: 2025/01/28 15:28:18 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_load_images_cion(int x, int y, t_data *data)
{
	data->ancion = malloc(sizeof(void *) * 9);
	data->ancion[0] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures1/meatB1.xpm", &x, &y);
	data->ancion[1] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures1/meatB2.xpm", &x, &y);
	data->ancion[2] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures1/meatB3.xpm", &x, &y);
	data->ancion[3] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures1/meatB4.xpm", &x, &y);
	data->ancion[4] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures1/meatB5.xpm", &x, &y);
	data->ancion[5] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures1/meatB6.xpm", &x, &y);
	data->ancion[6] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures1/meatB7.xpm", &x, &y);
	data->ancion[7] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures1/meatB8.xpm", &x, &y);
	data->ancion[8] = NULL;
}

void	load_images_B(t_data *data)
{
	int	x;
	int	y;

	data->wall = mlx_xpm_file_to_image(data->mlx, "src/textures/wall.xpm", &x,
			&y);
	data->floor = mlx_xpm_file_to_image(data->mlx, "src/textures/floor.xpm", &x,
			&y);
	data->player = mlx_xpm_file_to_image(data->mlx, "src/textures/player.xpm",
			&x, &y);
	ft_load_images_cion(x, y, data);
	data->exit = mlx_xpm_file_to_image(data->mlx, "src/textures/exit.xpm", &x,
			&y);
	if (!data->wall || !data->floor || !data->player || !data->coin
		|| !data->exit)
	{
		free_resources(data);
		printf("Error: Failed to load images\n");
		exit(1);
	}
}

int draw_coin_B(t_data *data)
{
	static int i = 0;

	if (i == 7)
		i = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->ancion[i], data->cx, data->cy);
	i++;
	return (0);
}

int	finde_C(t_data *data)
{
	int i;
	int j;

	i = 0;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				data->cx = j * 60;
				data->cy = i * 60;
				mlx_loop_hook(data->mlx, draw_coin_B, data);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.num = 0;
	data.count_move = 0;
	if (ac != 2 || ft_check_path(av[1]))
		return (1);
	data.map = ft_char_map(av[1], &data);
	check_map(data.map, &data);
	data.i = ft_count_coin(data.map);
	postion_player(data.map, &data);
	data.str = ft_char_map(av[1], &data);
	ft_check_flood(data.x / 60, data.y / 60, &data);
	free_map(data.str);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error: Failed to init mlx\n"), 1);
	data.win = opne_windows(&data);
	if (!data.win)
		return (ft_printf("Error: Failed to open window\n"), 1);
	load_images_B(&data);
	ft_draw_map_B(&data, av[1]);
	mlx_hook(data.win, 2, 1L >> 0, handle_keypress_B, &data);
	mlx_hook(data.win, 17, 0, close_window_B, &data);
	mlx_loop_hook(data.mlx, finde_C, &data);
	mlx_loop(data.mlx);
	return (0);
}
