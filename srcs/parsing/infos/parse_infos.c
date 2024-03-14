/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/14 09:10:41 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	inline	bool	are_identifers_valid(t_scene *scene)
{		
	return ((scene->scene[0][0] == 'N' && scene->scene[0][1] == 'O')
		&& (scene->scene[1][0] == 'S' && scene->scene[1][1] == 'O')
		&& (scene->scene[2][0] == 'W' && scene->scene[2][1] == 'E')
		&& (scene->scene[3][0] == 'E' && scene->scene[3][1] == 'A')
		&& (scene->scene[4][0] == 'F') && (scene->scene[5][0] == 'C')); 
}

bool	parse_infos(t_data *data)
{ 	
	if (get_infos(data->scene))
		return(data->error->error_g |= ERROR_SORT_S, EXIT_FAILURE); // bad error
	if (!are_identifers_valid(data->scene))
		return(data->error->error_g |= ERROR_SORT_S, EXIT_FAILURE);
	if (parse_images(data->scene))
		return(data->error->error_g |= ERROR_XPM, EXIT_FAILURE);
	if (parse_rgb(data->scene))
		return(data->error->error_g |= ERROR_RGB, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
