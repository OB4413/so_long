/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:43:23 by obarais           #+#    #+#             */
/*   Updated: 2025/02/01 11:13:07 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	ft_load_images_andp(int x, int y, t_data *data)
{
	data->andp = malloc(sizeof(void *) * 19);
	data->andp[0] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead1.xpm", &x, &y);
	data->andp[1] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead2.xpm", &x, &y);
	data->andp[2] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead3.xpm", &x, &y);
	data->andp[3] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead4.xpm", &x, &y);
	data->andp[4] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead5.xpm", &x, &y);
	data->andp[5] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead6.xpm", &x, &y);
	data->andp[6] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead7.xpm", &x, &y);
	data->andp[7] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead8.xpm", &x, &y);
	data->andp[8] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead9.xpm", &x, &y);
	data->andp[9] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead10.xpm", &x, &y);
	data->andp[10] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead11.xpm", &x, &y);
	data->andp[11] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead12.xpm", &x, &y);
	data->andp[12] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead13.xpm", &x, &y);
	data->andp[13] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead14.xpm", &x, &y);
	data->andp[14] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead15.xpm", &x, &y);
	data->andp[15] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead16.xpm", &x, &y);
	data->andp[16] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead17.xpm", &x, &y);
	data->andp[17] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures5/dead18.xpm", &x, &y);
	data->andp[18] = NULL;
}

static void	ft_load_images_anep(int x, int y, t_data *data)
{
	data->anep = malloc(sizeof(void *) * 11);
	data->anep[0] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat1.xpm", &x, &y);
	data->anep[1] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat2.xpm", &x, &y);
	data->anep[2] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat3.xpm", &x, &y);
	data->anep[3] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat4.xpm", &x, &y);
	data->anep[4] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat5.xpm", &x, &y);
	data->anep[5] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat6.xpm", &x, &y);
	data->anep[6] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat7.xpm", &x, &y);
	data->anep[7] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat8.xpm", &x, &y);
	data->anep[8] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat9.xpm", &x, &y);
	data->anep[9] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures4/eat10.xpm", &x, &y);
	data->anep[10] = NULL;
}

static void	ft_load_images_wlp(int x, int y, t_data *data)
{
	data->anwlp = malloc(sizeof(void *) * 11);
	data->anwlp[0] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp1.xpm", &x, &y);
	data->anwlp[1] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp2.xpm", &x, &y);
	data->anwlp[2] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp3.xpm", &x, &y);
	data->anwlp[3] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp4.xpm", &x, &y);
	data->anwlp[4] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp5.xpm", &x, &y);
	data->anwlp[5] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp6.xpm", &x, &y);
	data->anwlp[6] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp7.xpm", &x, &y);
	data->anwlp[7] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp8.xpm", &x, &y);
	data->anwlp[8] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp9.xpm", &x, &y);
	data->anwlp[9] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures3/wlp10.xpm", &x, &y);
	data->anwlp[10] = NULL;
}

static void	ft_load_images_wp(int x, int y, t_data *data)
{
	data->anwp = malloc(sizeof(void *) * 8);
	data->anwp[0] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures2/wp1.xpm", &x, &y);
	data->anwp[1] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures2/wp2.xpm", &x, &y);
	data->anwp[2] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures2/wp3.xpm", &x, &y);
	data->anwp[3] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures2/wp4.xpm", &x, &y);
	data->anwp[4] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures2/wp5.xpm", &x, &y);
	data->anwp[5] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures2/wp6.xpm", &x, &y);
	data->anwp[6] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures2/wp7.xpm", &x, &y);
	data->anwp[7] = NULL;
}

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

void	load_images_b(t_data *data)
{
	int	x;
	int	y;

	data->wall = mlx_xpm_file_to_image(data->mlx, "src/textures/wall.xpm", &x,
			&y);
	data->floor = mlx_xpm_file_to_image(data->mlx, "src/textures/floor.xpm", &x,
			&y);
	ft_load_images_andp(x, y, data);
	ft_load_images_anep(x, y, data);
	ft_load_images_wlp(x, y, data);
	ft_load_images_wp(x, y, data);
	ft_load_images_cion(x, y, data);
	data->exit = mlx_xpm_file_to_image(data->mlx, "src/textures/exit.xpm", &x,
			&y);
	if (!data->wall || !data->floor || !data->player || !data->ancion
		|| !data->exit || !data->anwp || !data->anwlp)
	{
		free_resources_b(data);
		printf("Error: Failed to load images\n");
		exit(1);
	}
}

void	init_xypc(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->i * 2)
	{
		data->xyancion[i] = -1;
		data->xyancion[i + 1] = -1;
		i += 2;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data.num = 0;
	data.count_move = 0;
	// ft_int_pointer(&data);
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
		return (free_resources_b(&data), ft_printf("Error: Failed to init mlx\n"), 1);
	data.win = opne_windows(&data);
	if (!data.win)
		return (free_resources_b(&data), ft_printf("Error: Failed to open window\n"), 1);
	load_images_b(&data);
	data.xyancion = malloc(sizeof(int) * data.i * 2);
	data.inlophok = 'S';
	init_xypc(&data);
	ft_draw_map_b(&data, av[1]);
	mlx_hook(data.win, 2, 1L >> 0, handle_keypress_b, &data);
	mlx_hook(data.win, 17, 0, close_window_b, &data);
	mlx_loop(data.mlx);
	return (0);
}
