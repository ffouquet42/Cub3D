/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:44 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/27 19:30:55 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	clean_nl_scene(t_data *data)
{
	int		i; // uint, if f2_scene ok, not more than 6 lines 
	int		j;

	i = 0;
	while (data->f2_scene[i])
	{
		j = 0;
		while (data->f2_scene[i][j])
		{
			if (data->f2_scene[i][j] == '\n' || data->f2_scene[i][j] == '\r')
				data->f2_scene[i][j] = '\0';
			j++;
		}
		i++;
	}
}

bool	init_image(t_data *data, int i)
{
	int	verif_wpi;
	int	verif_hpi;

	data->images[i].mlx_img = mlx_xpm_file_to_image(data->mlx,
			&data->f2_scene[i][2], &data->images[i].img_width,
			&data->images[i].img_height);
	if (!data->images[i].mlx_img)
		return (1);
	verif_wpi = data->images[0].img_width;
	verif_hpi = data->images[0].img_height;
	if (verif_wpi != data->images[i].img_width
		|| verif_hpi != data->images[i].img_height)
		return (1);
	// data->images[i].add = mlx_get_data_addr(data->images[i].mlx_img,
	// 		&data->images[i].bpp, &data->images[i].rowlen,
	// 		&data->images[i].end);
	// if (!data->images[i].add)
	// 	return (1);
	return (0);
}

bool	init_images(t_data *data)
{
	//uint16_t if more than 256 textures 
	uint8_t	i; 
	
	i = 0;
	clean_nl_scene(data);
	while (i < NB_IMAGES) // not modular, change by (init_images)
	{
		if (init_image(data, i))
			return (1);
		mlx_put_image_to_window(data->mlx, data->win, &data->images[i], i * 50 , i * 50);
		i++;
	}
	return (0);
}

bool	init_data(t_data *data)
{
	// t_image	image;
	
	// image = (t_image){0};
	// data->img = &image;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (data->error->error_g |= ERROR_INIT_MLX, 1);
	if (init_images(data))
		return (data->error->error_g |= ERROR_INIT_IMG, 1);
	return (0);
}

// bool	init_struct(t_data *data)
// {
// 	// data->error = (t_error *)malloc(sizeof(t_error));
// 	// if (!data->error)
// 	// 	return (1);
// 	// ft_memset(data->error, 0, sizeof(t_error));
// 	data->game = (t_game *)malloc(sizeof(t_game));
// 	if (!data->game)
// 		return (1);
// 	ft_memset(data->game, 0, sizeof(t_game));
// 	data->ray = (t_raycast *)malloc(sizeof(t_raycast));
// 	if (!data->ray)
// 		return (1);
// 	ft_memset(data->ray, 0, sizeof(t_raycast));
// 	data->img = (t_image *)malloc(sizeof(t_image));
// 	if (!data->img)
// 		return (1);
// 	ft_memset(data->img, 0, sizeof(t_image));
// 	return (0);
// }
