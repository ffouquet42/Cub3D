/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/13 18:19:12 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// util??
char	**remove_map_from_scene(t_data *data)
{
	char	**new_scene;
	int		i;
	
	new_scene = ft_calloc(sizeof(char *), 7);
	if (!new_scene)
		return (NULL);
	i = -1;
	while (i++ < 5)
		new_scene[i] = ft_strdup(data->scene[i]);
	return (new_scene);
}

char	**clean_scene(char **scene) // plus tard, auusinon ca deforme des maps valide avec les espaces 
{ 
	char	*tmp;
	int 	i;
	int 	j;
	int 	k;

	i = 0;
	while (i < 6)
	{
		j = 0;
		k = 0;
		tmp = scene[i];
		while (tmp[j])
		{
			if (tmp[j] != ' ')
				scene[i][k++] = tmp[j++]; 
			else
				j++;
		}
		scene[i][k] = '\0';
		i++;
	}
	return (scene);
}

bool	line_is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
	return (0);
}

int		scene_len(char *scene_path, t_data *data)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (data->error->error_g |= ERROR_FILE, close (fd), -1); // close(fd)?
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (data->error->error_g |= ERROR_MALLOC, close (fd), 0); // Gerer ce retour // 
	while (line)
	{		
			if (!(line_is_empty(line)))
				len++;
			free(line);
			line = get_next_line(fd);
	}
	free(line);
	return (close(fd), len);
}

bool	get_scene(char *scene_path, t_data *data)
{
	char	*line;
	int		fd;
	int		i;
	
	data->scene_height = scene_len(scene_path, data);
	if (data->scene_height < 9) //6 + 3 lignes de map min
		return (data->error->error_g |= ERROR_EMPTY, 1); // peut etre test plus tard pour les 25 l
	
	fd = open(scene_path, O_RDONLY); // close à la fin, à test
	if (fd < 0 || fd > 1024)
		return (data->error->error_g |= ERROR_FILE, close (fd), 1); // close?
	data->scene = malloc(sizeof(char *) * (data->scene_height + 1) + 1);
	if (!data->scene)
		return (data->error->error_g |= ERROR_MALLOC, close(fd), 1);
	i = 0;
	line = get_next_line(fd); // protect??
	while (line) // fct pour la boucle (-25)
	{
		if (!line_is_empty(line))
		{
			printf("%d", i); 
			data->scene[i] = line;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	data->scene[i] = NULL;
	free(line);
	return (close(fd));
}
