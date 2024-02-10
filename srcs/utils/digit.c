/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:26:27 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/10 14:53:24 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

bool	only_digit(char *str) // Verif si utiliser
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len - 1)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

bool	only_digit_or_comma(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len - 1)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',')
			return (1);
		i++;
	}
	return (0);
}