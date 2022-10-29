#include "../includes/so_long.h"

t_chest	define_chest_imgs(void *mlx)
{
	t_chest	c;

	c.chest_o.img = create_img(mlx, "sprites/chest_o.xpm");
	c.chest_c.img = create_img(mlx, "sprites/chest_c.xpm");
	return (c);
}

t_chest place_exit(char **map, t_vars mlx)
{
	int	x;
	int	y;
	t_chest c;

	c = define_chest_imgs(mlx.mlx);
	x = 0;
	while (map[++x])
	{
		y = 0;
		while (map[x][++y])
			if (map[x][y] == 69)
				put_img(mlx, c.chest_c.img, 32 * x, 32 * y);
				//for the open use 32 * x - 18
	}
	return (c);
}
