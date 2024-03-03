/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/03 18:22:03 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static bool 	parse_colors(t_data *data)
{
	// printf("%c", data->infos[4][0]);
	// printf("%c",data->infos[5][0]);
	if (!is_only_digits_or_commas(data->infos[4]))
		printf("oui");
	if (!is_only_digits_or_commas(data->infos[5]))
		printf("non");
	return(0);

	// return (is_only_digits_or_commas(data->infos[4]) || count_comma(str)
	// 	|| rgb_format(str) || rgb_value(str));
}

static bool		parse_images(t_data *data) //not finised, verif that the path exist
{
	uint8_t i;

	i = 0;
	
	while (i < NB_IMAGES)
	{
		if (!is_path_xpm(data->infos[i++])) // test is_path_xpm
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static	bool	is_valid_infos(t_data *data)
{		
	return ((data->infos[0][0] == 'N' && data->infos[0][1] == 'O')
		&& (data->infos[1][0] == 'S' && data->infos[1][1] == 'O')
		&& (data->infos[2][0] == 'W' && data->infos[2][1] == 'E')
		&& (data->infos[3][0] == 'E' && data->infos[3][1] == 'A')
		&& (data->infos[4][0] == 'F') && (data->infos[5][0] == 'C')); 
}

bool	parse_infos(t_data *data)
{ 	
	if (!is_valid_infos(data))
		return(data->error->error_g |= ERROR_SORT_S, EXIT_FAILURE);
	else if (parse_images(data))
		return(data->error->error_g |= ERROR_XPM,EXIT_FAILURE);
	else if (parse_colors(data))
		return(data->error->error_g |= ERROR_RGB, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
