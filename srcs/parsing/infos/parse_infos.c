/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/16 16:25:02 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

bool	parse_infos(t_data *data)
{ 	
	if (!get_infos(data->scene))
		return(data->error->error_g |= ERROR_SORT_S, EXIT_FAILURE); // bad error
	if (parse_textures(data->scene))
		return(data->error->error_g |= ERROR_XPM, EXIT_FAILURE);
	if (parse_rgb(data->scene))
		return(data->error->error_g |= ERROR_RGB, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
