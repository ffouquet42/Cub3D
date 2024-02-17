/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:44 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 16:36:12 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


void	clean_nl_scene(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '\n' || data->map[i][j] == '\r')
				data->map[i][j] = '\0';
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
	if (verif_wpi != data->images[i].img_width || verif_hpi != data->images[i].img_height)
		return (1);
	return (0);
}

// data->images[i].addr = mlx_get_data_addr(data->images[i].mlx_img,
		// &data->images[i].bpp, &data->images[i].rowlen,
		// &data->images[i].end);

bool	init_images(t_data *data) // init image fonctionne
{
	int	i;

	i = 0;
	print_scene(data->f2_scene);
	clean_nl_scene(data);
	print_scene(data->f2_scene);
	while (i < 4)
	{
		if (init_image(data, i))
			return (1); // messge erreur 
		i++;
	}
	return (0);
}

// init la struct data
bool	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (data->error->error_g |= ERROR_INIT_MLX, 1);
	if (init_images(data))
		return (data->error->error_g |= ERROR_INIT_IMG, 1);
	return (0);
}
