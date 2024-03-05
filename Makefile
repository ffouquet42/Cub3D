CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g3 -I ./include -I./mlx_linux # -g -MMD
MLX			=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME		=	cub3D

SRCS		=	srcs/main.c								\
				srcs/init/init_data.c					\
				srcs/init/init_game.c					\
				srcs/parsing/parsing.c					\
				srcs/parsing/scene/scene.c				\
				srcs/parsing/infos/infos.c				\
				srcs/parsing/infos/parse_infos.c		\
				srcs/parsing/infos/image.c				\
				srcs/parsing/infos/rgb.c				\
				srcs/parsing/map/map.c					\
				srcs/parsing/map/parse_map.c			\
				srcs/parsing/map/wall.c					\
				srcs/exec/game_management.c				\
				srcs/exec/move.c						\
				srcs/exec/rotate.c						\
				srcs/exec/raycasting.c					\
				srcs/exec/check_hit.c					\
				srcs/exec/draw/draw.c					\
				srcs/utils/libft.c						\
				srcs/utils/parsing_utils/infos_utils.c	\
				srcs/utils/parsing_utilslib_memory.c	\
				srcs/utils/parsing_utilsprint.c			\
				srcs/utils/parsing_utilsscene_utils.c	\
				srcs/utils/parsing_utilsget_next_line.c	\
				srcs/utils/exec_utils/draw_utils.c		\
				srcs/utils/free.c						\

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