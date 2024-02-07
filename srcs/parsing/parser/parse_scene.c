/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/07 14:21:27 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	check_rgb(char *rgb, t_data *data, int fc)
{
	if (only_digit_or_comma(&rgb[1]) || count_comma(&rgb[1])
		|| rgb_format(&rgb[1]) || rgb_value(&rgb[1], data, fc))
		return (1);
	return (0);
}

int	path_is_xpm(char *path) // + check si valide
{
	int	i;
	i = ft_strlen(path) - 5; // changer si malloc ?
	if (path[i] != '.' || path[i + 1] != 'x' ||
		path[i + 2] != 'p' || path[i + 3] != 'm')
		return (1);
	return (0);
}

int	parse_scene(t_data *data)
{
	int	i;
	int	fc;

	i = 0;
	while (i < 4)
	{
		if (path_is_xpm(data->scene[i]))
			return (ft_putstr(E_NO_XPM, 2), 1);
		i++;
	}
	fc = 0;
	while (i < 6)
	{
		if (check_rgb(data->scene[i], data, fc))
			return (ft_putstr(E_RGB, 2), 1);
		i++;
		fc++;
	}
	return (0);
}