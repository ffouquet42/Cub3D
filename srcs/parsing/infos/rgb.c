/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:13:34 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/11 16:17:36 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

// static	void cpy_rgb(uint8_t tab[], char *rgb) 
// {
// 	uint8_t i;
// 	uint8_t j;
// 	char *tmp;
	
// 	i = 0;
// 	j = 0;	
	
// 	while ()
// 	while (rgb[i] != ",")
// 	{
// 		tmp[i] = rgb[i];
// 		i++;
// 	}
// }

static bool are_rgb_valid(char *rgb) //to test 
{
    uint8_t i;
	uint8_t j;
    int 	len;
	
    len = ft_strlen(rgb) - 1;
    if (len < FORMAT_MIN || len > FORMAT_MAX)
        return (false);
    i = 0;
	while (rgb[++i])
	{
		j = 0;
		// printf("lineB[%i] = [%c]\n", i,  rgb[i]);
		if (!is_digit(rgb[i]) && rgb[i] != ',' && rgb[i] != '\n')
			return (false);
		// printf("Where the error appear[%i] = [%c]\n", i,  rgb[i]);
		while (is_digit(rgb[i++]))
			j++;
		i--;
		printf("j = %i\n", j);
		printf("i = %i\n", i);
		// printf("lineA[%i] = [%c]\n", i,  rgb[i]);
		if (j == 0 || j > 3)
			return (false);
	}
    return (true);
}

bool 	parse_rgb(t_infos *infos)
{
	if (!are_rgb_valid(infos->infos[FLOOR]))
		return(EXIT_FAILURE);
	// cpy_rgb(rgb.rgb_floor, infos->infos[FLOOR]);
    // if (!are_rgb_valid(infos->infos[CEILING]))
	// 	return(EXIT_FAILURE);
	// cpy_rgb(rgb.rgb_ceiling, infos->infos[CEILING]);
	return(EXIT_SUCCESS);
}
