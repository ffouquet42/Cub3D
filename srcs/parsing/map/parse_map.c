/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/16 21:00:01 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	bool	is_map_closed(t_scene *scene, int x, int y)
{
	(void)x;
	(void)y;
	// protect : if(scene->scene[scene->map->o_pos_y][scene->map->o_pos_x])
	if (scene->scene[scene->map->o_pos_y][scene->map->o_pos_x] != '1')
		return (false);
	else if (scene->scene[scene->map->o_pos_y][scene->map->o_pos_x] == 'T')
		return (true);
	if (!scene->map->f_o)
	{
		scene->map->f_o |= 1;
		scene->scene[scene->map->o_pos_y][scene->map->o_pos_x] = 'T';
	}
	else 
		scene->scene[scene->map->o_pos_y][scene->map->o_pos_x] = 'x';
	
	// if ()
	is_map_closed(scene,scene->map->o_pos_x++,scene->map->o_pos_y);
	is_map_closed(scene,scene->map->o_pos_x,scene->map->o_pos_y--);
	is_map_closed(scene,scene->map->o_pos_x--,scene->map->o_pos_y);
	is_map_closed(scene,scene->map->o_pos_x,scene->map->o_pos_y++);
	return (false);
}

static inline bool	find_valid_map(t_scene *scene)
{
	scene->map->o_pos_y = INFOS_LEN - 1;
	while(scene->scene[++scene->map->o_pos_y])
	{
		scene->map->o_pos_x = -1;
		while(scene->scene[scene->map->o_pos_y][++scene->map->o_pos_x])
		{
			printf("pos y:%i\n",scene->map->o_pos_y );
			printf("pos x:%i\n",scene->map->o_pos_x );
			if (is_map_closed(scene,scene->map->o_pos_x,scene->map->o_pos_y))
				return (EXIT_SUCCESS);
			printf("pos y:%i\n",scene->map->o_pos_y );
			printf("pos x:%i\n",scene->map->o_pos_x );
			print_map(scene->scene, 5);
			// else 		// verif if need, verif if the scene is changeg even the area is not closed
				//reset map
		}
	}
	return (EXIT_FAILURE);
}

static	inline	void	get_size_map(t_scene *scene) 
{
	int 	i;
	int 	len;
	
	i = INFOS_LEN;
	while (scene->scene[i++])
	{
		len = ft_strlen(scene->scene[i]);
		if (len > scene->map->width)
			scene->map->width = len - 1;
	}
	scene->map->height = scene->height - INFOS_LEN;
}

bool	parse_map(t_data *data)
{
	get_size_map(data->scene); // not util
	if (!find_valid_map(data->scene))
		return (EXIT_FAILURE);
	printf("ouiiiiiiiiiiiiiiiiiiiiii");
	// are_char_valid 
	// get_player_pos dans are_char_valid
	return (EXIT_SUCCESS);
}
