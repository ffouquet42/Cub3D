/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:17:50 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/29 09:13:08 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"

# define E_INIT_DATA COLOR_RED "Error\nInit data failed.\n" COLOR_RESET
# define E_INIT_MLX COLOR_RED "Error\nInit mlx failed.\n" COLOR_RESET
# define E_PARS_ARGS COLOR_RED "Error\nNeed a single argument, a .cub map.\n" COLOR_RESET
# define E_GET_SCENE COLOR_RED "Error\nGet scene failed.\n" COLOR_RESET
# define E_OPEN_FAIL COLOR_RED "Error\nOPEN FAILURE\n" COLOR_RESET

#endif