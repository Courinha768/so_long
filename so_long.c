#include "so_long.h"

void define_map(char *file_name, int **map)
{
	char	*line;
	int		fd;
	int		x;
	int		y;
	int		size;

	fd = open(file_name, O_RDONLY);
	x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			map[x] = (int *)ft_calloc(sizeof(int), size + 1);
			break ;
		}
		size = ft_strlen(line);
		map[x] = (int *)ft_calloc(sizeof(int), ft_strlen(line) + 1);		
		y = -1;
		while (line[++y])
		{
			if (line[y] > 65)
				map[x][y] = line[y] - 64;
			else
				map[x][y] = line[y] - 47;
			//1 = empty space | 2 = wall | 3 = C | 5 = E | 16 = P
		}
		map[x][y] = 0;
		free(line);
		x++;
	}
}

int	main(int ac, char **av)
{
	void		*mlx;
	void		*mlx_win;
	int			*map[33];
	t_player	player;
	t_data		box;


	
	define_map("map01.ber", map);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 512, 512, "so_long");

	create_field(map, mlx, mlx_win);

	mlx_loop(mlx);
}