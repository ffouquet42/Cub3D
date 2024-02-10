/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:02:10 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/10 21:48:46 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	clean_nl_scene(t_data *data)  
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	while (i < 4)
	{
		len = ft_strlen(data->scene[i]) - 1;
		dest = malloc(sizeof(char) * (len));
		if (!dest)
			return (1);
		j = 0;
		while (j < len)
		{
			dest[j] = data->scene[i][j];
			j++;
		}
		dest[j] = '\0';
		data->scene[i] = dest;
		i++;
	}
	return (0);
}

bool	init_image(t_data *data, int i)
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

bool	init_images(t_data *data)
{
	int	i;

	i = 0;
	clean_nl_scene(data);
	while (i < 4)
	{
		if (init_image(data, i))
			return (1);
		i++;
	}
	return (0);
}
