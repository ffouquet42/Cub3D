/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/14 06:47:42 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	inline	bool	are_chars_valid(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x]) 
		{
			if (!is_char_in_set(map->map[y][x], "01NSEW \n"))
				return (false);
			if (x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
			{
				if (map->map[y][x] != '1' && map->map[y][x] != ' ' 
						&& map->map[y][x] != '\n')
					return (false);
			}
			if (is_char_in_set(map->map[y][x], "0NSEW"))
				if (is_void_around(map, x, y, "01NSEW"))
					return (false);
			get_player_pos(map, x, y);
		}
	}
	return (map->pos == 1);
}

static	inline	bool	get_map(t_scene *scene)
{
	int 	i;
	int 	y;
	int 	len;
	
	i = INFOS_LEN;
	y = 0;
	scene->map->map = malloc(sizeof(char *) * (scene->height - 5)); //-INFOS_LEN + 1
	if (!scene->map)
		return (EXIT_FAILURE);
	while (scene->scene[i])
	{
		len = ft_strlen(scene->scene[i]);
		if (len > scene->map->width)
			scene->map->width = len - 1;
		scene->map->map[y++] = scene->scene[i++];
	}
	scene->map->map[y] = NULL;
	scene->map->height = scene->height - INFOS_LEN;
	return (EXIT_SUCCESS);
}

bool	parse_map(t_data *data)
{
	if (get_map(data->scene))
		return (data->error->error_g |= ERROR_MAP, EXIT_FAILURE);
	if (!are_chars_valid(data->scene->map))
		return (data->error->error_g |= ERROR_CHAR, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
