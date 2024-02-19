/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:41:26 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/19 17:14:22 by mfeldman         ###   ########.fr       */
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

void	set_textures_variables(t_data *data, int x)
{
	(void)x;
	data->ray->wall_x = 0;
	data->ray->tex_pos = 0;
	data->ray->draw_start = WIN_HEIGHT / 2 - data->ray->line_height / 2;
	if (data->ray->draw_start < 0 || data->ray->draw_start > WIN_HEIGHT)
		data->ray->draw_start = 0;
	data->ray->draw_end = WIN_HEIGHT / 2 + data->ray->line_height / 2;
	if (data->ray->draw_end >= WIN_HEIGHT)
		data->ray->draw_end = WIN_HEIGHT - 1;
	if (data->ray->side == 0)
		data->ray->wall_x = data->game->player_pos_y + data->ray->ray_length * data->ray->diray_y;
	else
		data->ray->wall_x = data->game->player_pos_x + data->ray->ray_length * data->ray->diray_x;
	data->ray->wall_x -= floor(data->ray->wall_x);
	data->ray->tex_x = (int)(data->ray->wall_x * (double)data->images[data->game->texture].img_width);
	if ((data->ray->side == 0 && data->ray->diray_x > 0) || (data->ray->side == 1 && data->ray->diray_y < 0))
		data->ray->tex_x = data->images[data->game->texture].img_width - data->ray->tex_x - 1;
	data->ray->step = 1 * (double)data->images[data->game->texture].img_height / data->ray->line_height;
	data->ray->tex_pos = (data->ray->draw_start - WIN_HEIGHT / 2 + data->ray->line_height / 2) * data->ray->step;
}

void	pick_texture(t_data *data)
{
	if (data->ray->side == 0 && data->ray->diray_x < 0)
		data->game->texture = 2;
	else if (data->ray->side == 0 && data->ray->diray_x > 0)
		data->game->texture = 3;
	else if (data->ray->side == 1 && data->ray->diray_y < 0)
		data->game->texture = 0;
	else if (data->ray->side == 1 && data->ray->diray_y > 0)
		data->game->texture = 1;
}

void	draw_textures(t_data *data, int x)
{
	int		i;

	pick_texture(data);
	set_textures_variables(data, x);
	i = 0;
	while (i < data->ray->draw_start)
	{
		ft_mlx_pixel_put(data->img, x, i, get_rgb(data->rgb_ceiling));
		i++;
	}
	while (i < data->ray->draw_end)
	{
		ft_mlx_pixel_put(data->img, x, i,
			get_color(data, data->ray->tex_x, data->ray->tex_pos, data->game->texture));
		data->ray->tex_pos += data->ray->step;
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		ft_mlx_pixel_put(data->img, x, i, get_rgb(data->rgb_floor));
		i++;
	}
}