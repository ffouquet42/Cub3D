/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:36:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/05 11:10:44 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	closed_by_wall(t_data *data)
{
	int	i;
	printf("\n\n--- closed by wall start\n"); // dev
	i = 0;
	while (i < data->map_width)
	{
		if (data->map[0][i] != '1' && data->map[0][i] != ' ')
		{
			printf("map[0][%i] = %c\n", i, data->map[0][i]); // dev
			return (ft_putstr("return 1\n", 1), 1); // dev
		}
		i++;
	}
	return (ft_putstr("return 0\n", 1), 0); // dev
}

/*
check les 4 coter que des 1 ou ' '
remplir de A
check autour des A
reprendre celui de so long du coup ?
*/