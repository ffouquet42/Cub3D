/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:13:34 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/04 03:11:23 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

// static	bool	correct_rgb_value(t_data *data)
// {
// 	int	rgb;

// 	rgb = 0;
// 	while (rgb < 3)
// 	{
// 		if (data->rgb_floor[rgb] < 0 || data->rgb_floor[rgb] > 255)
// 			return (data->error->error_g |= ERROR_RGB, 1);
// 		rgb++;
// 	}
// 	rgb = 0;
// 	while (rgb < 3)
// 	{
// 		if (data->rgb_ceiling[rgb] < 0 || data->rgb_ceiling[rgb] > 255)
// 			return (data->error->error_g |= ERROR_RGB, 1);
// 		rgb++;
// 	}
// 	return (0);
// }

// static	bool	rgb_value(char *str)
// {
// 	int	i;
// 	int	rgb;
// 	int	loop;

// 	i = 0;
// 	rgb = 0;
// 	loop = 0;
// 	while (loop < 3)
// 	{
//
// 			data->rgb_floor[rgb] = ft_atoi(&str[i]);
// 	
// 			data->rgb_ceiling[rgb] = ft_atoi(&str[i]);
// 		while (is_digit(str[i]))
// 			i++;
// 		if (str[i] == ',')
// 			i++;
// 		rgb++;
// 		loop++;
// 	}
// 	if (correct_rgb_value(data))
// 		return (1);
// 	return (0);
// }

bool are_rgbs_valid(char *rgbs)
{
    uint8_t i;
    
    i = 0;
    while(rgbs[++i])
    {
        if (!is_digit(rgbs[i]) && rgbs[i] != ',' && rgbs[i] != '\n') //only_digit_or_commas
            return (false);
        else if (is_digit(rgbs[i]))
            data->rgb->digit_row++;
        else if (rgbs[i] == "," && data->rgb->digit_row != 0)
        {
            data->rgb->commas++;
            data->rgb->digit_row = 0;
        }
        else
            return (false);
        if (data->rgb->digit_row > 3)                                          //not more than 3 digit in a row
			return (false);
    }
    if (data->rgb->commas != 2)                                                //only_two_commas
		return (false);
    return(true);
}

