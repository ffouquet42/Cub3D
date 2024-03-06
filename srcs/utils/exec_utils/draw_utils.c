/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:47:32 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/06 02:15:17 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

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

void	ft_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > WIN_HEIGHT - 1 || x < 0 || x > WIN_WIDTH - 1)
		return ;
	dst = img->add + (y * img->rowlen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
