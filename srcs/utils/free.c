/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/19 16:50:40 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	quit_loop(t_data *data) 
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	free_scene(t_data *data)
{
	int	i;
	i = 0;
	if (data->scene)
	{
		while (data->scene[i])
			free(data->scene[i++]);
		free(data->scene);
	}
}

void	free_mlx(t_data *data)
{
	uint8_t i;

	i = 0;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	while (i < 4)
	{
		if (data->images[i].mlx_img)
			mlx_destroy_image(data->mlx, data->images[i].mlx_img);
		i++;
	}
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
}

void	free_all(t_data *data) 
{
	if (data->map)
		free_map(data);
	if(data->scene)
		free_scene(data);
	if (data->f_scene)
		free(data->f_scene);
	if (data->f2_scene)
		free(data->f2_scene);
	if (data->error)
		free(data->error);
	if (data->game)
		free(data->game);
	if (data->img)
		free(data->img);
	if (data->ray)
		free(data->ray);
	free_mlx(data);
	if (data)
		free(data);
	exit(0);
}

