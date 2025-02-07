/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:43:23 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 10:49:32 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images_b(t_data *data)
{
	int	x;
	int	y;

	data->wall = mlx_xpm_file_to_image(data->mlx, "src/textures/wall.xpm", &x,
			&y);
	data->floor = mlx_xpm_file_to_image(data->mlx, "src/textures/floor.xpm", &x,
			&y);
	ft_load_images_anse(x, y, data);
	ft_load_images_anwle(x, y, data);
	ft_load_images_andp(x, y, data);
	ft_load_images_anep(x, y, data);
	ft_load_images_wlp(x, y, data);
	ft_load_images_wp(x, y, data);
	ft_load_images_cion(x, y, data);
	data->exit = mlx_xpm_file_to_image(data->mlx, "src/textures/exit.xpm", &x,
			&y);
	data->moves = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/moves.xpm", &x, &y);
	if (!data->wall || !data->floor || !data->ancion || !data->exit
		|| !data->anwp || !data->anwlp || !data->anep || !data->andp
		|| !data->anwle)
	{
		printf("Error: Failed to load images\n");
		free_resources_b(data);
		exit(1);
	}
}

void	init_xypc(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->i * 2)
	{
		data->xyancion[i] = -1;
		data->xyancion[i + 1] = -1;
		i += 2;
	}
	i = 0;
	while (i < data->j * 2)
	{
		data->xye[i] = -1;
		data->xye[i + 1] = -1;
		i += 2;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data.num = 0;
	data.count_move = 0;
	if (ac != 2 || ft_check_path(av[1]))
		return (1);
	data.map = ft_char_map(av[1], &data);
	check_map_b(data.map, &data);
	postion_player(data.map, &data);
	data.str = ft_char_map(av[1], &data);
	ft_check_flood(data.x / 60, data.y / 60, &data);
	free_map(data.str);
	ft_count_coin_enemy(data.map, &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_resources_b(&data),
			ft_printf("Error: Failed to init mlx\n"), 1);
	data.win = opne_windows(&data);
	if (!data.win)
		return (free_resources_b(&data),
			ft_printf("Error: Failed to open window\n"), 1);
	load_images_b(&data);
	data.xyancion = malloc(sizeof(int) * data.i * 2);
	data.xye = malloc(sizeof(int) * data.j * 2);
	data.inlophok = 'S';
	init_xypc(&data);
	ft_draw_map_b(&data, av[1]);
	mlx_key_hook(data.win, handle_keypress_b, &data);
	mlx_hook(data.win, 17, 0, close_window_b, &data);
	mlx_loop(data.mlx);
	return (0);
}
