/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:44 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 15:48:37 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// void	init_data_2(t_data *data)
// {

	// data->rotation_speed = ROTSPEED;

	// data->movespeed = MOVESPEED;
// }

bool	clean_nl_scene(t_data *data)  
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	while (i < 4)
	{
		len = ft_strlen(data->f2_scene[i]); // Faire un f3_scene ?
		dest = malloc(sizeof(char) * (len));
		if (!dest)
			return (1); // gerer le retour 
		j = 0;
		while (j < len)
		{
			dest[j] = data->f2_scene[i][j];
			j++;
		}
		dest[j] = '\0';
		data->f2_scene[i] = dest; // leaks juste trouver ou free f2_scene du coup pas free dest
		i++;
	}
	return (0);
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
	// print_scene(data->f2_scene);
	// clean_nl_scene(data);
	// print_scene(data->f2_scene);
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
