/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/04 03:44:01 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static bool 	parse_colors(t_data *data)
{
    t_rgb	rgb;
	int len;
    
    rgb = (t_rgb){0};
	data->rgb = &rgb;
	
	len = ft_strlen(data->infos[i]) - 1;
	if (len < 5 || len > 11)                                        //rgb max and min format
        return (EXIT_FAILURE);
	if (!are_rgbs_valid(data->infos[i]))
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}

static bool		parse_images(t_data *data) //not finised, verif that the path exist, is_path_valid, verif len, 
{
	uint8_t i;

	i = 0;
	
	while (i < NB_IMAGES)
	{
		if (!is_path_xpm(data->infos[i++]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static	bool	are_identifers_valid(t_data *data)
{		
	return ((data->infos[0][0] == 'N' && data->infos[0][1] == 'O')
		&& (data->infos[1][0] == 'S' && data->infos[1][1] == 'O')
		&& (data->infos[2][0] == 'W' && data->infos[2][1] == 'E')
		&& (data->infos[3][0] == 'E' && data->infos[3][1] == 'A')
		&& (data->infos[4][0] == 'F') && (data->infos[5][0] == 'C')); 
}

bool	parse_infos(t_data *data)
{ 	
	if (!are_identifers_valid(data))
		return(data->error->error_g |= ERROR_SORT_S, EXIT_FAILURE);
	else if (parse_images(data))
		return(data->error->error_g |= ERROR_XPM,EXIT_FAILURE);
	else if (parse_colors(data))
		return(data->error->error_g |= ERROR_RGB, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
