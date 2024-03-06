/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:39:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/07 00:12:07 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include "errors.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <limits.h>

//**********************************************//
//					DEFINES						//
//**********************************************//

/* Max/Min value of the file desciptor*/
# define FD_MAX 1024
# define FD_MIN 0

/*Gnl Buffer*/
# define BUFFER_SIZE 100

/*Length of the desired scene*/ 
# define INFOS_LEN	6

/*Number of textures*/
# define NB_IMAGES	4

/*Format Rgb*/
# define RGB 		3
# define FLOOR		4
# define CEILING 	5
# define FORMAT_MIN 5
# define FORMAT_MAX 11

/*Windows size*/
# define WIN_WIDTH 	1920
# define WIN_HEIGHT 1080

/*Keycode*/
# define KEY_A 		97
# define KEY_D 		100
# define KEY_M 		109
# define KEY_S 		115
# define KEY_W 		119
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define KEY_SHIFT	65505

/*Speed*/
# define MOVESPEED	0.05
# define ROTSPEED	0.02

//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_raycast
{
	
}			t_raycast;

typedef struct s_key
{
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_right;
	int		key_left;
}			t_key;

typedef struct s_game
{
	t_key		*key;  
	t_raycast	*ray; 
	double		player_pos_x;
	double		player_pos_y;
	double		speed; 
	double		rotation_speed;
}			t_game;

typedef struct s_image
{
	void	*mlx_img;
	char	*add;
	int		bpp;
	int		rowlen;
	int		end;
	int		img_height;
	int		img_width;
}			t_image;

typedef struct s_rgb
{
	uint8_t	commas;
    uint8_t	digit_row;
	uint8_t	rgb_floor[RGB];
	uint8_t	rgb_ceiling[RGB];
}			t_rgb;

typedef struct s_map
{
	char	**map;
	double	p_pos_x;
	double	p_pos_y;
	int		height;
	int		width;
}			t_map;

typedef struct s_infos
{
	t_image		*img;
	t_image		images[NB_IMAGES];
	t_rgb		*rgb;
	char		**infos;
	uint8_t 	sort_index;
}			t_infos;

typedef struct s_scene
{
	t_infos		*infos;
	t_map 		*map;
	char		**scene;
	int			height;
}			t_scene;

typedef struct s_data
{
	t_error		*error;
	t_scene		*scene;
	t_game		*game;
	void		*mlx;
	void		*win;
}			t_data;

//**********************************************//
//					PROTOTYPES					//
//**********************************************//

//---------------   main.c   ------------------//

int		main(int argc, char **argv);

//**********************************************//
//					PARSING						//
//**********************************************//

//---------------   parsing.c   ----------------//

bool	parsing(int argc, char **argv, t_data *data);

//---------------   scene.c   ------------------//

bool	parse_scene(char **scene_path, t_data *data);
void	clean_nl_scene(t_data *data);

//---------------   infos.c   ------------------//

bool	get_infos(t_data *data);

//---------------   parse_infos.c   --------------//

bool	parse_infos(t_data *data);

//---------------   image.c   --------------------//

bool	parse_images(t_infos *infos);

//---------------   rgb.c   --------------------//

bool 	parse_colors(t_infos *infos);

//---------------   map.c   --------------//

bool	get_map(t_data *data);

//---------------   parse_map.c   --------------//

bool	parse_map(t_data *data);
bool	char_is_in_set(char c, char *set);

//---------------   wall.c   -------------------//

bool	closed_by_wall(t_data *data);
bool	no_void_around(t_data *data, char *charset);
bool	test_around(char **map, int y, int x, char *charset);

//**********************************************//
//					INIT						//
//**********************************************//

//---------------   init_data.c   --------------//

bool	init_data(t_data *data);
bool	init_images(t_data *data);
bool	init_image(t_data *data, int i);

void	get_player_pos(t_data *data);
void	set_first_orientation(t_data *data, char c);
void	set_first_orientation_two(t_data *data, char c);

//**********************************************//
//					EXEC						//
//**********************************************//

//---------------	game_management.c ----------//

bool	game_management(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		game_loop(t_data *data);

//---------------	move.c ----------//

void	move(t_data *data);

//---------------	rotate.c ----------//

void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	get_rotate_speed(t_data *data);

//---------------	raycasting.c ----------//

void	raycast(t_data *data);
void	cast_img_addr(t_data *data);
void	set_dist(t_data *data);
void	set_camera(t_data *data, int x);
void	check_hit(t_data *data);
void	check_hit_2(t_data *data);

//---------------	draw.c ----------//

void	draw_textures(t_data *data, int x);
void	pick_texture(t_data *data);
void	set_textures_variables(t_data *data, int x);
void	set_textures_variables_2(t_data *data);

//**********************************************//
//					UTILS						//
//**********************************************//

//---------------	libft.c			  ----------//

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void 	ft_swap(t_infos *infos, uint8_t index);
int		ft_atoi(const char *str);

//---------------	print.c			 ----------//

void	msg_error(t_error *error);
void	parsing_msg_error_2(t_error *error);

//---------------	scene_utils.c ----------//

int		scene_len(char *scene_path, t_data *data);
bool	is_line_empty(char *str);

//---------------   infos_utils.c   -------------------//

bool	is_path_xpm(char *path);
bool	is_digit(char c);

//---------------   infos_utils.c   -------------------//

bool	is_char_in_set(char c, char *set);

//---------------	draw_utils.c ----------//

void	ft_mlx_pixel_put(t_image *img, int x, int y, int color);
int		get_rgb(int *color);
int		get_color(t_data *data, int x, int y, int image);

//---------------   free.c   -------------------//

void	free_all(t_data *data);
int		quit_loop(t_data *data);

//---------------   get_next_line.c   ----------//

char	*get_next_line(int fd);
char	*merge_stash_and_buff(char *stash, char *buff);
char	*buff_to_stash(char *buff);
bool	search_newline(const char *buff);
char	*stash_to_line(char *stash, char *buf);

void print_map(char **map);

#endif