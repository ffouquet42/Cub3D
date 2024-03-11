/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:13:34 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/11 18:01:39 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static bool are_rgb_valid(char *rgb, uint8_t tab[RGB])
{
    uint8_t i;
	uint8_t j;
	uint8_t commas;
	int 	tmp;
	
    i = 0;
	commas = 0;
	while (rgb[++i])
	{
		j = 0;
		if ((!is_digit(rgb[i]) && rgb[i] != ',' && rgb[i] != '\n') 
				|| commas > 3)
			return (false); // error
		tmp = ft_atoi(&rgb[i]);
		while (is_digit(rgb[i++]))
			j++;
		i--;
		commas++;
		if (j == 0 || j > 3 || tmp < 0 || tmp > 255)
			return (false); //error
		else 
			tab[commas] = tmp;
	}
    return (true);
}

bool 	parse_rgb(t_infos *infos)
{
	if (!are_rgb_valid(infos->infos[FLOOR], infos->rgb->rgb_floor))
		return(EXIT_FAILURE);
    if (!are_rgb_valid(infos->infos[CEILING], infos->rgb->rgb_ceiling))
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
