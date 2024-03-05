/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:30:30 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/04 23:31:24 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

bool		parse_images(t_infos *infos) //not finised, verif that the path exist, is_path_valid, verif len, 
{
	uint8_t i;

	i = 0;
	
	while (i < NB_IMAGES)
	{
		if (!is_path_xpm(infos->infos[i++]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}