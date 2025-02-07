/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_image1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:48:48 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 10:53:56 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_load_images_andp_help(int x, int y, t_data *data)
{
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

void	ft_load_images_andp(int x, int y, t_data *data)
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
	ft_load_images_andp_help(x, y, data);
}

void	ft_load_images_wlp(int x, int y, t_data *data)
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
