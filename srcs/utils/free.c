/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/14 08:01:47 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void exit_game(t_data *data)
{
	ft_putstr(E_INIT_MLX, 2);
	free_data(data);
	exit (1);
}

// Je fait refaire entierement tout les free une fois que le parsing est nickel
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

void	free_scene(t_data *data)
{
	int	i;

	i = 0;
	while (data->scene[i])
		free(data->scene[i++]);
	free(data->scene);
}


// void	free_mlx(t_data *data)
// {
// 	if (data->map)
// 		free_map(data);
// 	if (data->mlx_win)
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 	if (data->wall_img)
// 		mlx_destroy_image(data->mlx, data->wall_img);
// 	if (data->coll_img)
// 		mlx_destroy_image(data->mlx, data->coll_img);
// 	if (data->ground_img)
// 		mlx_destroy_image(data->mlx, data->ground_img);
// 	if (data->player_img)
// 		mlx_destroy_image(data->mlx, data->player_img);
// 	if (data->exit_img)
// 		mlx_destroy_image(data->mlx, data->exit_img);
// 	if (data->mlx)
// 		mlx_destroy_display(data->mlx);
// 	if (data->mlx)
// 		free(data->mlx);
// 	exit(0);
// }

