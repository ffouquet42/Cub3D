/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:01:37 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/03 18:23:16 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	bool	sort_infos(t_data *data)
{
	uint8_t i; 
	 
	while (data->sort_index < INFOS_LEN)
	{
		i = data->sort_index;	
		if (data->infos[i][0] == 'N' && data->infos[i][1] == 'O')
			ft_swap(data, 0);
		else if (data->infos[i][0] == 'S' && data->infos[i][1] == 'O')
			ft_swap(data, 1);
		else if (data->infos[i][0] == 'W' && data->infos[i][1] == 'E')
			ft_swap(data, 2);
		else if (data->infos[i][0] == 'E' && data->infos[i][1] == 'A')
			ft_swap(data, 3);
		else if (data->infos[i][0] == 'F')
			ft_swap(data, 4);
		else if (data->infos[i][0] == 'C')
			ft_swap(data, 5);
		data->sort_index++;
	}
	data->infos[6] = NULL;
	return (EXIT_SUCCESS);
}

static	void	get_clean_infos(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < INFOS_LEN)
	{
		j = 0;
		k = 0;
		tmp = data->scene[i];
		while (tmp[j])
		{
			if (tmp[j] != ' ')
				data->scene[i][k++] = tmp[j++];
			else
				j++;
		}
		data->scene[i][k] = '\0';
		data->infos[i] = data->scene[i];
		i++;
	}
	data->infos[i] = NULL;
}

bool	get_infos(t_data *data)
{

	data->infos = malloc(sizeof(char *) * (7));
	if (!data->infos)
		return (data->error->error_g |= ERROR_MALLOC, EXIT_FAILURE);
	get_clean_infos(data);
	sort_infos(data);
	return (EXIT_SUCCESS);
}
