CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -I ./include -I./mlx_linux# -g -MMD -g3
MLX			=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME		=	cub3D

#CFLAGS		= 	-Wall -Wextra -Werror -g3 -I./srcs/includes

SRCS		=	srcs/cub3D.c						\
				srcs/init/init_data.c				\
				srcs/init/init_game.c				\
				srcs/init/init_images.c				\
				srcs/parsing/map.c					\
				srcs/parsing/parse_map.c			\
				srcs/parsing/parse_scene.c			\
				srcs/parsing/parsing.c				\
				srcs/parsing/rgb.c					\
				srcs/parsing/scene.c				\
				srcs/parsing/sort_scene.c			\
				srcs/parsing/wall.c					\
				srcs/utils/libft.c					\
				srcs/utils/print.c					\
				srcs/utils/digit.c					\
				srcs/utils/free.c					\
				srcs/utils/scene_utils.c			\
				srcs/utils/get_next_line.c			\

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C ./mlx_linux
			$(CC) -o $(NAME) $(SRCS) $(CFLAGS) $(MLX)

clean:
			$(RM) $(OBJS)

fclean:		clean
			make  clean -C ./mlx_linux
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re