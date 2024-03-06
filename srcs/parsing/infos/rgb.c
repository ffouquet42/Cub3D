/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:13:34 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/06 16:57:03 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	void cpy_rgbs(t_rgb *rgb)
{
	uint8_t i;

	i = 0;
	while (i < RGB)
	{
		
	}
	
}

static bool are_rgb_valid(char *rgb)
{
    uint8_t i;
    int 	len;
    char	*tmp;

    len = ft_strlen(rgb);
    if (len < FORMAT_MIN || len > FORMAT_MAX)                           //rgb max and min format
        return (EXIT_FAILURE);
    i = 0;
    while (!is_digit(rgb[++i]))
        tmp[i] = rgb[i];
    if (i == 1)
        
        if (rgb[i] == ",")
			i++;
    }
    if (data->rgb->commas != 2)                                 //only_two_commas
		return (false);
    return (true);
}

bool 	parse_colors(t_infos *infos)
{
    t_rgb	rgb;
    
    rgb = (t_rgb){0};
	infos->rgb = &rgb;

	if (!are_rgb_valid(infos->infos[FLOOR]))
		return(EXIT_FAILURE);
    if (!are_rgb_valid(infos->infos[CEILING]))
		return(EXIT_FAILURE);
	if (cpy_rgbs(rgb))
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
