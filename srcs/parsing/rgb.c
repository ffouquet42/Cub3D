/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:13:34 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 17:09:11 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


bool	correct_rgb_value(t_data *data)
{
	int	rgb; // uint 

	rgb = 0;
	while (rgb < 3)
	{
		if (data->rgb_floor[rgb] < 0 || data->rgb_floor[rgb] > 255)
			return (1); // msg error 
		rgb++;
	}
	rgb = 0;
	while (rgb < 3)
	{
		if (data->rgb_ceiling[rgb] < 0 || data->rgb_ceiling[rgb] > 255)
			return (1);  // msg error 
		rgb++;
	}
	return (0);
}

bool	rgb_value(char *str, t_data *data, int fc)
{
	int	i;
	int	rgb;
	int	loop;

	i = 0;
	rgb = 0;
	loop = 0;
	while (loop < 3)
	{ 
		if (fc == 0)
			data->rgb_floor[rgb] = ft_atoi(&str[i]); 
		else if (fc == 1)
			data->rgb_ceiling[rgb] = ft_atoi(&str[i]);
		while (is_digit(str[i]))
			i++;
		if (str[i] == ',')
			i++;
		rgb++;
		loop++;
	}
	if (correct_rgb_value(data))
		return (1); // message error ici
	return (0);
}

bool	rgb_format(char *str)  
{
	int	i;
	uint8_t	digit_row; //uint 

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

bool	count_comma(char *str) //utils digit
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