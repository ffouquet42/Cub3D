/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/16 13:58:18 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	check_rgb(char *rgb, t_data *data, int fc)
{
	if (only_digit_or_comma(&rgb[1]) || count_comma(&rgb[1])
		|| rgb_format(&rgb[1]) || rgb_value(&rgb[1], data, fc))
		return (1);
	return (0);
}

bool	path_is_xpm(char *path) //test 
{
	int	i;
	
	i = ft_strlen(path) - 5;
	if (path[i] != '.' || path[i + 1] != 'x' ||
		path[i + 2] != 'p' || path[i + 3] != 'm')
		return (1);
	return (0);
}

bool	parse_scene(t_data *data)
{
	int	i;
	int	fc;

	i = 0;
	while (i < 4)
	{
		if (path_is_xpm(data->f2_scene[i]))
			return (data->error->error_g |= ERROR_XPM, 1);
		i++;
	}
	fc = 0;
	while (i < 6)
	{
		if (check_rgb(data->f2_scene[i], data, fc))
			return (data->error->error_g |= ERROR_RGB, 1);
		i++;
		fc++;
	}
	return (0);
}