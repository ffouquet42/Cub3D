/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:22:53 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/01 19:14:45 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	pos;

	i = 0;
	res = 0;
	pos = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * pos);
}

void ft_swap(t_data *data, uint8_t index) 
{
	if (index != data->sort_index)
	{
    	char *tmp;
		
		tmp = data->infos[index];
    	data->infos[index] = data->infos[data->sort_index];
    	data->infos[data->sort_index] = tmp;
		data->sort_index = -1;	
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
