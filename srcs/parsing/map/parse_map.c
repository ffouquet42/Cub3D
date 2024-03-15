/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/15 16:36:56 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"


static is_area_well_composed()
{
	are_rgbs_valid() // see commit
}


static inline bool is_closed_area(t_scene *scene)
{
	(void)scene;
	return (true);	
}

static inline bool	find_valid_area(t_scene *scene)
{
	int x;
	int y;

	y = INFOS_LEN - 1;
	while(scene->scene[++y])
	{
		x = -1;
		while(scene->scene[y][++x])
		{
			if (scene->scene[y][x] == '1')
			{	
				x++;
				// if (is_closed_area(scene))
				// 	return (EXIT_SUCCESS);
			}
		}
	}
	return (EXIT_SUCCESS);
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
	get_size_map(data->scene);
	if (!find_valid_area(data->scene))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
