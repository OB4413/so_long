/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:42:09 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 10:47:24 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_images_anse(int x, int y, t_data *data)
{
	data->anse = malloc(sizeof(void *) * 5);
	data->anse[0] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures7/se1.xpm", &x, &y);
	data->anse[1] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures7/se2.xpm", &x, &y);
	data->anse[2] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures7/se3.xpm", &x, &y);
	data->anse[3] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures7/se4.xpm", &x, &y);
	data->anse[4] = NULL;
}

void	ft_load_images_anwle(int x, int y, t_data *data)
{
	data->anwle = malloc(sizeof(void *) * 9);
	data->anwle[0] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/wle1.xpm", &x, &y);
	data->anwle[1] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/wle2.xpm", &x, &y);
	data->anwle[2] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/wle3.xpm", &x, &y);
	data->anwle[3] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/wle4.xpm", &x, &y);
	data->anwle[4] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/wle5.xpm", &x, &y);
	data->anwle[5] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/wle6.xpm", &x, &y);
	data->anwle[6] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/wle7.xpm", &x, &y);
	data->anwle[7] = mlx_xpm_file_to_image(data->mlx,
			"src_bonus/textures6/wle8.xpm", &x, &y);
	data->anwle[8] = NULL;
}

void	ft_load_images_anep(int x, int y, t_data *data)
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

void	ft_load_images_wp(int x, int y, t_data *data)
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

void	ft_load_images_cion(int x, int y, t_data *data)
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
