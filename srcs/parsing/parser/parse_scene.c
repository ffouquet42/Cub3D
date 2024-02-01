/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/01 09:02:37 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	path_is_xpm(char *path)
{
	int	i;
	i = ft_strlen(path) - 5;
	if (path[i] != '.' || path[i + 1] != 'x' ||
		path[i + 2] != 'p' || path[i + 3] != 'm')
		return (0);
	return (1);
}

int	parse_scene(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!path_is_xpm(data->scene[i]))
			return (ft_putstr(E_NO_XPM, 2), 1);
		i++;
	}
	while (i < 6)
	{
		//
		i++;
	}
	return (0);
}