#include "../../includes/cub3D.h"

void print_map(char **map)
{
	int i = 0;
	while(map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}