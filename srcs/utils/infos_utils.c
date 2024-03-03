/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:26:54 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/03 18:19:25 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_only_digits_or_commas(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]) || str[i] != ',')
			return (false);
		i++;
	}
	return (true);
}

bool	is_path_xpm(char *path)
{
	int	i;

	i = ft_strlen(path) - 5; 
	return (path[i] == '.' && path[i + 1] == 'x'
		&& path[i + 2] == 'p' && path[i + 3] == 'm');
}
