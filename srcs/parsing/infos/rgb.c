/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:13:34 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/16 16:27:13 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static inline	bool is_rgb_valid(char *rgb, uint8_t tab[RGB])
{
    uint8_t i;
	uint8_t j;
	uint8_t commas;
	int 	tmp;
	
    i = 0;
	commas = 0;
	while (rgb[++i])
	{
		if (commas > 2)
			return (false); 
		tmp = ft_atoi(&rgb[i]);
		j = 0;
		while (is_digit(rgb[i++]))
			j++;
		i--;
		if (j == 0 || j > 3 || tmp < 0 || tmp > 255 
			|| (rgb[i] != ',' && rgb[i] != '\n'))
			return (false); 
		else 
			tab[commas] = tmp;
		commas++;
	}
    return (true);
}

bool 	parse_rgb(t_scene *scene)
{
	if (!is_rgb_valid(scene->scene[FLOOR], scene->infos->rgb->rgb_floor)) // to much value in the rgb_floor
		return(EXIT_FAILURE);
    if (!is_rgb_valid(scene->scene[CEILING], scene->infos->rgb->rgb_ceiling))
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
