/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:13:34 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/01 10:30:18 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	rgb_value(char *str)
{
	int i;

	i = 0;
	return (0);
}

int	rgb_format(char *str)
{
	int	i;
	int	digit_row;

	digit_row = 0;
	i = 0;
	while (str[i])
	{
		if (is_digit(str[i]))
			digit_row++;
		else if (str[i] == ',' && digit_row == 0)
			return (1);
		else if (str[i] == ',')
			digit_row = 0;
		if (digit_row > 3)
			return (1);
		i++;
	}
	return (0);
}

int	count_comma(char *str)
{
	int i;
	int	comma;

	comma = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (1);
	return (0);
}