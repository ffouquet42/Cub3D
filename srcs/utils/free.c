/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 16:36:39 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"



void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	free_map_scene(t_data *data) // fonctionne pour l'instant
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	if (data->f_scene)
		free(data->f_scene);
	if (data->f2_scene)
		free(data->f2_scene);
	i = 0;
	if(data->scene)
	{
		while (data->scene[i])
			free(data->scene[i++]);
		free(data->scene);
	}
}

void	free_scene(t_data *data)
{
	int	i;

	free(data->f_scene);
	free(data->f2_scene);
	i = 0;
	if(data->scene)
	{
		while (data->scene[i])
			free(data->scene[i++]);
		free(data->scene);
	}
}

void free_all(t_data *data)
{
	free_map(data);
	free_scene(data);
}

void	free_mlx(t_data *data)
{
	uint8_t i;

	i = 0;
	// if (data->map)
	// 	free_map(data);
	// if (data->win)
	// 	mlx_destroy_window(data->mlx, data->win);
	//boucle pour free les images 
	// if (data->mlx)
	// 	mlx_destroy_display(data->mlx);
	while(data->images[i].mlx_img)
	{
		if(data->images[i].mlx_img)
			mlx_destroy_image(data->mlx, data->images[i++].mlx_img);
	}
	if (data->mlx)
		free(data->mlx);
	exit(0);
}
