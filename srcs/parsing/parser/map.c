/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:50:42 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/31 12:13:08 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

char	**get_map(char **scene)
{
	char	**map;
	int		i;
	int		j;
	int		x;

	i = 6;
	j = 0;
	x = 0;
	while (scene[i++])
		j++;
	map = malloc(sizeof(char *) * (j + 1));
	if (!map)
		return (NULL);
	i = 6;
	while (scene[i])
		map[x++] = scene[i++]; // strdup ?
	map[x] = NULL;
	return (map);
}