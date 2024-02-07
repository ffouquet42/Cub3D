/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:02:10 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/07 14:20:00 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	init_image(t_data *data, int i)
{
	data->images[i].mlx_img = mlx_xpm_file_to_image(data->mlx,
		&data->scene[i][2], &data->images[i].img_width,
		&data->images[i].img_height);
	if (!data->images[i].mlx_img)
		return (1);
	data->images[i].addr = mlx_get_data_addr(data->images[i].mlx_img,
		&data->images[i].bpp, &data->images[i].rowlen,
		&data->images[i].end);
	return (0);
}

int	init_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (init_image(data, i))
			return (0); // Doit etre return 1 mais la fonction au dessus bug
	}
	return (0);
}