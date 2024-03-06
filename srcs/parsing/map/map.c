/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:50:42 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/06 16:56:05 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void cpy_map(t_scene *scene) //maybe resize
{
	int 	i;
	int 	y;
	int 	len;
	
	i = INFOS_LEN;
	y = 0;
	while (scene->scene[i] && scene->scene[i] != '\n')
	{
		len = ft_strlen(scene->scene[i]);
		if (len > scene->map->width)
			scene->map->width = len;
		scene->map->map[y++] = scene->scene[i++];
	}
	scene->map->map[y] = NULL;
	scene->map->height = scene->height - INFOS_LEN;
}

bool	get_map(t_data *data)
{
	t_map	map;
	int		fd;
	
	map = (t_map){0};
	data->scene->map = &map;
	map.map = malloc(sizeof(char *) * (data->scene->height - 5)); //-INFOS_LEN + 1
	if (!map.map)
		return (data->error->error_g |= ERROR_MALLOC, EXIT_FAILURE);
	cpy_map(data->scene);
	// resize_map(&map);
	return (EXIT_SUCCESS);
}
