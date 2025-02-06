/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:43:23 by obarais           #+#    #+#             */
/*   Updated: 2025/02/06 21:47:58 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_data *data)
{
	int	x;
	int	y;

	data->wall = mlx_xpm_file_to_image(data->mlx, "src/textures/wall.xpm", &x,
			&y);
	data->floor = mlx_xpm_file_to_image(data->mlx, "src/textures/floor.xpm", &x,
			&y);
	data->player = mlx_xpm_file_to_image(data->mlx, "src/textures/player.xpm",
			&x, &y);
	data->coin = mlx_xpm_file_to_image(data->mlx, "src/textures/meat.xpm", &x,
			&y);
	data->exit = mlx_xpm_file_to_image(data->mlx, "src/textures/exit.xpm", &x,
			&y);
	if (!data->wall || !data->floor || !data->player || !data->coin
		|| !data->exit)
	{
		printf("Error: Failed to load images\n");
		free_resources(data);
		exit(1);
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
	check_map(data.map, &data);
	postion_player(data.map, &data);
	data.str = ft_char_map(av[1], &data);
	ft_check_flood(data.x / 60, data.y / 60, &data);
	free_map(data.str);
	ft_count_coin_enemy(data.map, &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error: Failed to init mlx\n"), 1);
	data.win = opne_windows(&data);
	if (!data.win)
		return (ft_printf("Error: Failed to open window\n"), 1);
	load_images(&data);
	ft_draw_map(&data, av[1]);
	mlx_hook(data.win, 2, 1L >> 0, handle_keypress, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
