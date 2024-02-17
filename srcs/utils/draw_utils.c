/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:47:32 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/17 23:58:06 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > WIN_HEIGHT - 1 || x < 0 || x > WIN_WIDTH - 1)
		return ;
	dst = img->add + (y * img->rowlen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}