/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:58:12 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/10 14:16:21 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	all_identifiants(t_data *data)
{
	if (!data->e_scene->no)
		return (1);
	if (!data->e_scene->so)
		return (1);
	if (!data->e_scene->ea)
		return (1);
	if (!data->e_scene->we)
		return (1);
	if (!data->e_scene->f)
		return (1);
	if (!data->e_scene->c)
		return (1);
	return (0);
}

char	**sort_scene(t_data *data)
{
	char	**new_scene;
	int		i;

	new_scene = ft_calloc(sizeof(char *), 7);
	if (!new_scene)
		return (NULL);
	i = 0;
	while (data->scene[i])
	{
		if (data->scene[i][0] == 'N' && data->scene[i][1] == 'O')
		{
			new_scene[0] = data->scene[i];
			data->e_scene->no = 1;
		}
		else if (data->scene[i][0] == 'S' && data->scene[i][1] == 'O')
		{
			new_scene[1] = data->scene[i];
			data->e_scene->so = 1;
		}
		else if (data->scene[i][0] == 'E' && data->scene[i][1] == 'A')
		{
			new_scene[2] = data->scene[i];
			data->e_scene->ea = 1;
		}
		else if (data->scene[i][0] == 'W' && data->scene[i][1] == 'E')
		{
			new_scene[3] = data->scene[i];
			data->e_scene->we = 1;
		}
		else if (data->scene[i][0] == 'F')
		{
			new_scene[4] = data->scene[i];
			data->e_scene->f = 1;
		}
		else if (data->scene[i][0] == 'C')
		{
			new_scene[5] = data->scene[i];
			data->e_scene->c = 1;
		}
		i++;
	}
	new_scene[6] = NULL;
	if (all_identifiants(data))
		return (NULL);
	return (new_scene);
}