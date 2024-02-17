/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:46:34 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/17 23:31:56 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_camera(t_data *data, t_raycast *ray, int x)
{
	ray->camera = 2 * x / (double)WIN_WIDTH - 1;
	ray->diray_x = data->game->player_or_x + data->game->plane_x * ray->camera;
	ray->diray_y = data->game->player_or_y + data->game->plane_y * ray->camera;
	ray->map_x = (int)data->game->player_pos_x;
	ray->map_y = (int)data->game->player_pos_y;
	if (ray->diray_x != 0)
		ray->delta_dist_x = fabs(1 / ray->diray_x);
	else
		ray->delta_dist_x = INT_MAX;
	if (ray->diray_y != 0)
		ray->delta_dist_y = fabs(1 / ray->diray_y);
	else
		ray->delta_dist_y = INT_MAX;
}

void	set_side_dist(t_data *data, t_raycast *ray)
{
	if (ray->diray_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->game->player_pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - data->game->player_pos_x)
			* ray->delta_dist_x;
	}
	if (ray->diray_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->game->player_pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - data->game->player_pos_y)
			* ray->delta_dist_y;
	}
}

void	init_cast_img(t_data *data)
{
	data->img = 
	data->img->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img->mlx_img)
		end_of_prog(data, 2);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img,
			&(data->img->bpp), &(data->img->rowlen),
			&(data->img->end));
}

void	raycast(t_data *data)
{
	int		x;

	x = 0;
	init_cast_img(data);
	while (x < WIN_WIDTH)
	{
		set_camera(data, data->ray, x);
		set_side_dist(data, data->ray);
		draw_textures(data, data->ray, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->mlx_img);
}