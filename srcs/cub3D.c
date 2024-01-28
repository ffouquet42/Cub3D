/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/28 12:24:42 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (init_data(&data))
		return (ft_putstr(E_INIT_DATA, 2), 1);
	if (parsing(argc, argv, &data))
		return (1);
	
	// mettre les Error en rouge
	// finir les structs
	// finir les frees pour les structs
	// parsing
	// free mlx

	return (0);
}