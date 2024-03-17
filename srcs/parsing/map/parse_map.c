/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/17 18:07:55 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	bool	is_map_closed(t_scene *scene, int x, int y)
{
	// protect : if(scene->scene[scene->map->o_pos_y][scene->map->o_pos_x])
	if (scene->scene[y][x] != '0')
		return (false);
	else if (scene->scene[y][x] == 'T')
		return (true);
	else 
		scene->scene[y][x] = 'x';
	// if ()
	is_map_closed(scene,scene->map->o_pos_x++,scene->map->o_pos_y);
	is_map_closed(scene,scene->map->o_pos_x,scene->map->o_pos_y--);
	is_map_closed(scene,scene->map->o_pos_x--,scene->map->o_pos_y);
	is_map_closed(scene,scene->map->o_pos_x,scene->map->o_pos_y++);
	return (false);
}

static  bool	find_valid_map(t_scene *scene)
{
	uint8_t x;
	uint8_t y;
	
	y = INFOS_LEN - 1;
	while (scene->scene[++y])
	{
		x = -1;
		while(scene->scene[y][++x])
			get_player_pos(scene, x ,y);
	}
	
	return (EXIT_FAILURE);
}

bool	parse_map(t_data *data)
{
	if (!find_valid_map(data->scene))
		return (EXIT_FAILURE);
	printf("ouiiiiiiiiiiiiiiiiiiiiii");
	// are_char_valid 
	// get_player_pos dans are_char_valid
	return (EXIT_SUCCESS);
}
