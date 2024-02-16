/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/16 16:11:06 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// void exit_all (t_data *data)
// {
// 	ft_putstr(E_INIT_MLX, 2);
// 	free_data(data);
// 	exit (1);
// }

void	free_data(t_data *data)
{
	free(data->raycast);
	free(data->game);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

// void	free_map_cpy(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 		free(map[i++]);
// 	free(map);
// }

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
	// if (data->map)
	// 	free_map(data);
	// if (data->mlx_win)
	// 	mlx_destroy_window(data->mlx, data->mlx_win);
	// if (data->wall_img)
	// 	mlx_destroy_image(data->mlx, data->wall_img);
	// if (data->coll_img)
	// 	mlx_destroy_image(data->mlx, data->coll_img);
	// if (data->ground_img)
	// 	mlx_destroy_image(data->mlx, data->ground_img);
	// if (data->player_img)
	// 	mlx_destroy_image(data->mlx, data->player_img);
	// if (data->exit_img)
	// 	mlx_destroy_image(data->mlx, data->exit_img);
	// if (data->mlx)
	// 	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	exit(0);
}

