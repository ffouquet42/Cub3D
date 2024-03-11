/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/11 18:51:58 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	inline	bool	are_chars_valid(t_map *map)
{
	int	y;
	int	x;
	int	pos;

	y = 0;
	pos = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (!is_char_in_set(map->map[y][x], "01NSEW \n"))
				return (false);
			else if (is_char_in_set(map->map[y][x], "NSEW"))  //get_player_pos utils, 
			{
				pos++;
				map->p_pos_x = (double)x + 0.5;
				map->p_pos_y = (double)y + 0.5;
			}
			x++;
		}
		y++;
	}
	return (pos == 1);
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
			scene->map->width = len;
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
	// if (is_closed_by_wall(&map))
	// 	return (data->error->error_g |= ERROR_WALL, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
