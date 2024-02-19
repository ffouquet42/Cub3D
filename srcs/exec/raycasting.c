/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:46:34 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/19 17:17:08 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_camera(t_data *data, int x)
{
	data->ray->camera = 2 * x / (double)WIN_WIDTH - 1;
	data->ray->diray_x = data->game->player_or_x + data->game->plane_x * data->ray->camera;
	data->ray->diray_y = data->game->player_or_y + data->game->plane_y * data->ray->camera;
	data->ray->map_x = (int)data->game->player_pos_x;
	data->ray->map_y = (int)data->game->player_pos_y;
	if (data->ray->diray_x != 0)
		data->ray->delta_dist_x = fabs(1 / data->ray->diray_x);
	else
		data->ray->delta_dist_x = INT_MAX;
	if (data->ray->diray_y != 0)
		data->ray->delta_dist_y = fabs(1 / data->ray->diray_y);
	else
		data->ray->delta_dist_y = INT_MAX;
}

void	set_dist(t_data *data)
{
	if (data->ray->diray_x < 0)
	{
		data->ray->step_x = -1;
		data->ray->side_dist_x = (data->game->player_pos_x - data->ray->map_x)
			* data->ray->delta_dist_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->side_dist_x = (data->ray->map_x + 1 - data->game->player_pos_x)
			* data->ray->delta_dist_x;
	}
	if (data->ray->diray_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->side_dist_y = (data->game->player_pos_y - data->ray->map_y)
			* data->ray->delta_dist_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->side_dist_y = (data->ray->map_y + 1 - data->game->player_pos_y)
			* data->ray->delta_dist_y;
	}
}

void	cast_img_addr(t_data *data) 
{
	data->img->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img->mlx_img)
		free_all(data); 
	data->img->add = mlx_get_data_addr(data->img->mlx_img,
			&(data->img->bpp), &(data->img->rowlen),
			&(data->img->end));
	if (!data->img->add)
		free_all(data);
}

void	check_hit(t_data *data)
{
	data->ray->hit = 0;
	while (data->ray->hit == 0)
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side_dist_x += data->ray->delta_dist_x;
			data->ray->map_x += data->ray->step_x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->side_dist_y += data->ray->delta_dist_y;
			data->ray->map_y += data->ray->step_y;
			data->ray->side = 1;
		}
		if (data->map[data->ray->map_y][data->ray->map_x] == '1')
			data->ray->hit = 1;
	}
	if (data->ray->side == 0)
		data->ray->ray_length = data->ray->side_dist_x - data->ray->delta_dist_x;
	else
		data->ray->ray_length =data-> ray->side_dist_y - data->ray->delta_dist_y;
	if (data->ray->ray_length < 0.005)
		data->ray->ray_length = 0.005;
	data->ray->line_height = WIN_HEIGHT / (data->ray->ray_length);
}

void	raycast(t_data *data)
{
	int		x;

	x = 0;
	cast_img_addr(data);
	while (x < WIN_WIDTH)
	{
		set_camera(data, x);
		set_dist(data);
		check_hit(data);
		draw_textures(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->mlx_img);
}