/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:58:12 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 22:27:41 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	**sort_scene_2(char **scene)
{
	char	**new_scene;
	int		i;

	new_scene = ft_calloc(sizeof(char *), 7);
	if (!new_scene)
		return (NULL);
	i = 0;
	while (scene[i])
	{
		if (!new_scene[0] && scene[i][0] == 'N' && scene[i][1] == 'O')
			new_scene[0] = scene[i];
		else if (!new_scene[1] && scene[i][0] == 'S' && scene[i][1] == 'O')
			new_scene[1] = scene[i];
		else if (!new_scene[2] && scene[i][0] == 'E' && scene[i][1] == 'A')
			new_scene[2] = scene[i];
		else if (!new_scene[3] && scene[i][0] == 'W' && scene[i][1] == 'E')
			new_scene[3] = scene[i];
		else if (!new_scene[4] && scene[i][0] == 'F')
			new_scene[4] = scene[i];
		else if (!new_scene[5] && scene[i][0] == 'C')
			new_scene[5] = scene[i];
		else
			return (free(new_scene), NULL);
		i++;
	}
	new_scene[6] = NULL;
	return (new_scene);
}

bool	sort_scene(t_data *data)
{
	data->f2_scene = sort_scene_2(data->f_scene);
	if (!data->f2_scene)
		return (data->error->error_g |= ERROR_SORT_S, 1);
	if ((data->f2_scene[0][0] != 'N' && data->f2_scene[0][1] != 'O')
		|| (data->f2_scene[1][0] != 'S' && data->f2_scene[1][1] != 'O')
		|| (data->f2_scene[2][0] != 'E' && data->f2_scene[2][1] != 'A')
		|| (data->f2_scene[3][0] != 'W' && data->f2_scene[3][1] != 'E')
		|| (data->f2_scene[4][0] != 'F') || (data->f2_scene[5][0] != 'C'))
		return (data->error->error_g |= ERROR_SORT_S, 1);
	return (0);
}
