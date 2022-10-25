#include "../includes/so_long.h"

int	sl_strlen_v(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	char		**map;
	int			i;
	t_all		all;
	
	if (ac != 2)
		return (0);
	map = define_map(av[1]);
	all.mlx.mlx = mlx_init();
	all.mlx.win = mlx_new_window(all.mlx.mlx, (ft_strlen(map[0]) - 1) * 32, sl_strlen_v(map) * 32, "so_long");
	all.field = create_field(map, all.mlx);
	all.player = place_player(map, all.mlx);
	mlx_key_hook(all.mlx.win, key_hook, &all);
	mlx_loop(all.mlx.mlx);
	i = -1;
	while (map[++i])
		free(map[i]);
	free((void *)map);
}