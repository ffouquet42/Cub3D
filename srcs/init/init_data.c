/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:44 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/01 16:45:33 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	clean_nl_scene(t_data *data)
{
	uint8_t		i;
	int			j;

	i = 0;
	while (data->infos[i])
	{
		j = 0;
		while (data->infos[i][j])
		{
			if (data->infos[i][j] == '\n' || data->infos[i][j] == '\r')
				data->infos[i][j] = '\0';
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
			&data->infos[i][2], &data->images[i].img_width,
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
	clean_nl_scene(data); // call in other fct, end of parsing 
	while (i < NB_IMAGES) // not modular, change by (init_images)
	{
		if (init_image(data, i))
			return (1);
		i++;
	}
	return (0);
}

bool	init_data(t_data *data)
{
	get_player_pos(data); //recode with fct in parsing 
	data->mlx = mlx_init();
	if (!data->mlx)
		return (data->error->error_g |= ERROR_INIT_MLX, 1);
	if (init_images(data))
		return (data->error->error_g |= ERROR_INIT_IMG, 1);
	return (0);
}
