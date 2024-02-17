/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:41:26 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/17 23:57:31 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_color(t_data *data, int x, int y, int image)
{
	(void)image;
	return (*(int *)(data->images[data->game->texture].add
		+ (y * data->images[data->game->texture].rowlen + x
			* (data->images[data->game->texture].bpp / 8))));
}

int	get_rgb(int *color)
{
	return (color[0] * 0x10000 + color[1] * 0x100 + color[2]);
}

void	set_textures_variables(t_data *data, t_raycast *ray, int x)
{
	(void)x;
	ray->wall_x = 0;
	ray->tex_pos = 0;
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0 || ray->draw_start > WIN_HEIGHT)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = data->game->player_pos_y + ray->ray_length * ray->diray_y;
	else
		ray->wall_x = data->game->player_pos_x + ray->ray_length * ray->diray_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x
			* (double)data->images[data->game->texture].img_width);
	if ((ray->side == 0 && ray->diray_x > 0)
		|| (ray->side == 1 && ray->diray_y < 0))
		ray->tex_x = data->images[data->game->texture].img_width
			- ray->tex_x - 1;
	ray->step = 1 * (double)data->images[data->game->texture].img_height
		/ ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT
			/ 2 + ray->line_height / 2) * ray->step;
}

void	pick_texture(t_data *cub, t_raycast *ray)
{
	if (ray->side == 0 && ray->diray_x < 0)
		cub->game->texture = 3;
	else if (ray->side == 0 && ray->diray_x > 0)
		cub->game->texture = 2;
	else if (ray->side == 1 && ray->diray_y < 0)
		cub->game->texture = 1;
	else if (ray->side == 1 && ray->diray_y > 0)
		cub->game->texture = 0;
}

void	draw_textures(t_data *data, t_raycast *ray, int x)
{
	int		i;

	pick_texture(data, data->ray);
	set_textures_variables(data, data->ray, x);
	i = ray->draw_start;
	while (i >= 0)
	{
		my_mlx_pixel_put(data->img, x, i, get_rgb(data->rgb_ceiling));
		i--;
	}
	i = ray->draw_start;
	while (i <= ray->draw_end)
	{
		my_mlx_pixel_put(data->img, x, i,
			get_color(data, ray->tex_x, ray->tex_pos, data->game->texture));
		ray->tex_pos += ray->step;
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		my_mlx_pixel_put(data->img, x, i, get_rgb(data->rgb_floor));
		i++;
	}
}