/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/04 23:37:27 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	bool	are_identifers_valid(t_infos *infos)
{		
	return ((infos->infos[0][0] == 'N' && infos->infos[0][1] == 'O')
		&& (infos->infos[1][0] == 'S' && infos->infos[1][1] == 'O')
		&& (infos->infos[2][0] == 'W' && infos->infos[2][1] == 'E')
		&& (infos->infos[3][0] == 'E' && infos->infos[3][1] == 'A')
		&& (infos->infos[4][0] == 'F') && (infos->infos[5][0] == 'C')); 
}

bool	parse_infos(t_data *data)
{ 	
	if (!are_identifers_valid(data->scene->infos))
		return(data->error->error_g |= ERROR_SORT_S, EXIT_FAILURE);
	else if (parse_images(data->scene->infos))
		return(data->error->error_g |= ERROR_XPM,EXIT_FAILURE);
	else if (parse_colors(data->scene->infos))
		return(data->error->error_g |= ERROR_RGB, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
