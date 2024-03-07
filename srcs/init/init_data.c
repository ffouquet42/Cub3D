/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:44 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/07 20:11:01 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


// bool	init_image(t_data *data, int i)
// {

// 	data->images[i].mlx_img = mlx_xpm_file_to_image(data->mlx,
// 			&data->infos[i][2], &data->images[i].img_width,
// 			&data->images[i].img_height);
// 	if (!data->images[i].mlx_img)
// 		return (1);
// 	if (data->images[0].img_width != data->images[i].img_width
// 		|| data->images[0].img_height != data->images[i].img_height)
// 		return (1);
// 	// data->images[i].add = mlx_get_data_addr(data->images[i].mlx_img,
// 	// 		&data->images[i].bpp, &data->images[i].rowlen,
// 	// 		&data->images[i].end);
// 	// if (!data->images[i].add)
// 	// 	return (1);
// 	return (0);
// }

// bool	init_images(t_data *data)
// {
// 	//uint16_t if more than 255 textures 
// 	uint8_t	i; 
	
// 	i = 0;
// 	// clean_nl_scene(data);
// 	while (i < NB_IMAGES) // not modular, change by (init_images)
// 	{
// 		if (init_image(data, i))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// bool	init_data(t_data *data)
// { 
// 	if (init_images(data))
// 		return (data->error->error_g |= ERROR_INIT_IMG, 1);
// 	return (0);
// }
