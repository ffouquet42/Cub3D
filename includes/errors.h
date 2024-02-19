/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:17:50 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/19 18:43:13 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdint.h>

/*Struct errors*/

typedef struct s_error
{
	uint16_t	error_g;
}				t_error;

# define COLOR_RESET   "\x1b[0m"
# define COLOR_RED     "\x1b[31m"

# define ERROR_ARG				0x1
# define ERROR_FILE				0x2
# define ERROR_CUB				0x4
# define ERROR_EMPTY			0x8
# define ERROR_EMPTY_LINE		0x10
# define ERROR_SCENE			0X20
# define ERROR_MAP				0X40
# define ERROR_RM_MAP			0x80
# define ERROR_SORT_S			0x100
# define ERROR_CHAR				0x200
# define ERROR_START			0x400
# define ERROR_WALL				0x800
# define ERROR_XPM				0x1000
# define ERROR_RGB				0x2000
# define ERROR_INIT_MLX			0x4000
# define ERROR_INIT_IMG			0x8000
# define ERROR_MLX_WIN			0x10000
# define ERROR_POS				0x20000
# define ERROR_MALLOC			0x40000

# define E_PARS_ARGS "Error\nNeed a single argument, a .cub map.\n"
# define E_PARS_FILE "Error\nOPEN FAILURE. Need an existing file.\n"
# define E_PARS_CUB "Error\nInvalid file format/ Invalid path. Need a .cub map.\n"
# define E_EMPTY_MAP "Error\nInformation is missing or the map is too small\n"
# define E_EMPTY_LINE "Error\nThere are one or more empty lines on the map\n"
# define E_GET_SCENE "Error\nGet scene failed.\n"
# define E_GET_MAP "Error\nGet map failed.\n"
# define E_RM_MAP "Error\nRemove map from scene failed.\n"
# define E_SORT_SCE "Error\nSort scene failed.\n"
# define E_MAP_CHAR "Error\nInvalid char for map.\n"
# define E_ONE_START "Error\nNeed one start position.\n"
# define E_CLO_WALL "Error\nMap must be closed by walls.\n"
# define E_NO_XPM "Error\nNeed .xpm files for textures.\n"
# define E_RGB "Error\nInvalid RGB values.\n"
# define E_INIT_MLX "Error\nInit mlx failed.\n"
# define E_INIT_IMG "Error\nInit images failed.\n"
# define E_MLX_WIN "Error\nmlx new window failed.\n"
# define E_GET_P_POS "Error\nGet player pos failed.\n"
# define E_MALLOC_FAIL "Error\nA malloc have failed.\n"
# define E_INIT_DATA "Error\nInit data failed.\n"

#endif