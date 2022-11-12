#include "../includes/so_long.h"

void	outside_borders2(char **map, t_vars mlx, t_field imgs, t_loc loc)
{
	int	x;
	int	y;

	x = loc.x;
	y = loc.y;
	if (!w(map[x - 1][y + 1]) && w(map[x - 1][y]) && w(map[x][y + 1]))
		put_img2(mlx, imgs.corner_bl.img, x * 32, y * 32 + 24);
	if (y > 0)
		if (!w(map[x - 1][y - 1]) && w(map[x - 1][y]) && w(map[x][y - 1]))
			put_img2(mlx, imgs.corner_br.img, x * 32, y * 32 - 10);
}

void	outside_borders(char **map, t_vars mlx, t_field imgs, t_loc loc)
{
	int	x;
	int	y;

	x = loc.x;
	y = loc.y;
	if (x > 0 && !w(map[x - 1][y]))
		put_img2(mlx, imgs.edge_bot.img, x * 32, y * 32);
	if (map[x][y + 2] && !w(map[x][y + 1]) && map[x][y + 1])
		put_img2(mlx, imgs.edge_side.img, x * 32, y * 32 + 24);
	if (y > 0 && !w(map[x][y - 1]))
		put_img2(mlx, imgs.edge_side.img, x * 32, y * 32);
	if (x > 0)
		outside_borders2(map, mlx, imgs, loc);
	if (map[x + 1])
	{
		if (!w(map[x + 1][y]))
			put_img2(mlx, imgs.edge_top.img, x * 32 + 24, y * 32);
		if (!w(map[x + 1][y + 1]) && w(map[x][y + 1]) && w(map[x + 1][y]))
			put_img2(mlx, imgs.corner_tl.img, x * 32 + 24, y * 32 + 24);
		if (y > 0)
			if (!w(map[x + 1][y - 1]) && w(map[x + 1][y]) && w(map[x][y - 1]))
				put_img2(mlx, imgs.corner_tr.img, x * 32 + 24, y * 32);
	}
}

void	inside_borders(char **map, t_vars mlx, t_field imgs, t_loc loc)
{
	int	x;
	int	y;

	x = loc.x;
	y = loc.y;
	if (x > 0)
	{
		if (!w(map[x - 1][y]) && !w(map[x][y - 1]))
			put_img2(mlx, imgs.corner_tl.img, x * 32, y * 32);
		if (!w(map[x - 1][y]) && !w(map[x][y + 1]))
			put_img2(mlx, imgs.corner_tr.img, x * 32, y * 32 + 24);
	}
	if (map[x + 1])
	{
		if (!w(map[x + 1][y]) && !w(map[x][y - 1]))
			put_img2(mlx, imgs.corner_il.img, x * 32 + 24, y * 32);
		if (!w(map[x + 1][y]) && !w(map[x][y + 1]))
			put_img2(mlx, imgs.corner_ir.img, x * 32 + 24, y * 32 + 24);
	}
}

void	render_borders(char **map, t_vars mlx, t_field imgs)
{
	t_loc	loc;

	loc.x = -1;
	while (map[++loc.x])
	{
		loc.y = -1;
		while (map[loc.x][++loc.y])
		{
			if (map[loc.x][loc.y] == 49)
			{
				outside_borders(map, mlx, imgs, loc);
				inside_borders(map, mlx, imgs, loc);
			}
		}
	}
}