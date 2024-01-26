/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:39:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/26 10:05:10 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include "errors.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


//**********************************************//
//					DEFINES						//
//**********************************************//


//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_mini // minimap ?
{
	
}			t_mini;

typedef struct s_ray
{
	
}			t_ray;

typedef struct s_game
{
	
}			t_game;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			window_x;
	int			window_y;
	t_game		*game;
	t_ray		*ray;
	t_mini		*mini;
}			t_data;


//**********************************************//
//					PROTOTYPES					//
//**********************************************//

//---------------   cub3D.c   ---------------//
int		main(int argc, char **argv);


//**********************************************//
//					PARSING						//
//**********************************************//

//**********************************************//
//					INIT						//
//**********************************************//

//---------------   init_data.c   ---------------//
int		init_data(t_data *data);
void	init_data_2(t_data *data);

//---------------   init_mlx.c   ---------------//
int		init_mlx(t_data *data);


//**********************************************//
//					UTILS						//
//**********************************************//

//---------------   exit.c   ---------------//
void 	exit_1(t_data *data);

//**********************************************//
//					LIBFT						//
//**********************************************//

//---------------   ft_putstr.c   ---------------//
void	ft_putstr(char *str);

//**********************************************//
//					EXEC						//
//**********************************************//


#endif