/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:02:10 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/10 14:45:49 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	init_image(t_data *data, int i)
{
	printf("# init_image i = [%i]\n", i); // dev
	printf("### img_h = %i\n", data->images[0].img_height); // dev
	//print_img(data); // dev
	ft_putstr(&data->scene[0][2], 1); // dev
	ft_putstr("test", 1); // dev

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

bool	init_images(t_data *data)
{
	int	i;
	char *path;

	i = 0;
	while (i < 4)
	{
		path = malloc(sizeof(char) * (ft_strlen(data->scene[i])));
		if (init_image(data, i))
			return (1); // Doit etre return 1 mais la fonction au dessus bug
	}
	return (0);
}