/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/01 19:40:36 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static	bool	check_rgb(char *rgb, t_data *data, int fc)
{
	if (only_digit_or_comma(&rgb[1]) || count_comma(&rgb[1])
		|| rgb_format(&rgb[1]) || rgb_value(&rgb[1], data, fc))
		return (1);
	return (0);
}

static	bool	path_is_xpm(char *path)
{
	int	i;

	i = ft_strlen(path) - 5; 
	if (path[i] != '.' || path[i + 1] != 'x'
		|| path[i + 2] != 'p' || path[i + 3] != 'm')
		return (1);
	return (0);
}

static	bool	is_valid_infos(t_data *data)
{
	if ((data->infos[0][0] != 'N' && data->infos[0][1] != 'O')
		|| (data->infos[1][0] != 'S' && data->infos[1][1] != 'O')
		|| (data->infos[2][0] != 'W' && data->infos[2][1] != 'E')
		|| (data->infos[3][0] != 'E' && data->infos[3][1] != 'A')
		|| (data->infos[4][0] != 'F') || (data->infos[5][0] != 'C'))
		return (data->error->error_g |= ERROR_SORT_S, false);
	return (true);
}

bool	parse_infos(t_data *data)
{
	int	i;
	int	fc;

	i = 0;

	if(!is_valid_infos(data))
		return(EXIT_FAILURE);

	// fct parse image 
	while (i < NB_IMAGES) //++i
	{
		if (path_is_xpm(data->infos[i]))
			return (data->error->error_g |= ERROR_XPM, EXIT_FAILURE);
		i++;
	}
	fc = 0;
	//parse color fct 
	while (i < INFOS_LEN)
	{
		if (check_rgb(data->infos[i], data, fc))
			return (data->error->error_g |= ERROR_RGB, EXIT_FAILURE);
		i++;
		fc++;
	}
	return (EXIT_SUCCESS);
}
