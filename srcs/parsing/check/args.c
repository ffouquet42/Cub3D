/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:05:52 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/09 18:23:11 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	check_args(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) < 5)
		return (1);
	while (argv[1][i])
		i++;
	i -= 4;

	// is_cub
	
	if (argv[1][i] != '.' || argv[1][i + 1] != 'c' ||
		argv[1][i + 2] != 'u' || argv[1][i + 3] != 'b')
		return (1);
	return (0);
}