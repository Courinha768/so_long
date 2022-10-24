/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:08:51 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/24 04:08:53 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_grass(int **map, void *mlx, void *mlx_win, t_field imgs)
{
	int	x;
	int	y;

	x = 0;
	while (map[x][0])
	{
		y = -1;
		while (map[0][++y])
			if (map[x][y] != 2)
				put_img(mlx, mlx_win, imgs.grass1.img, x * 32, y * 32);
		x++;
	}
}

void	outside_borders(int **map, void *mlx, void *mlx_win, t_field imgs, int x, int y)
{
	if (map[x][y + 1] == 1)
		put_img(mlx, mlx_win, imgs.edge_top.img, x * 32, y * 32 + 24);
	if (map[x][y - 1] == 1)
		put_img(mlx, mlx_win, imgs.edge_bot.img, x * 32, y * 32);
	if (map[x + 1][y] == 1)
		put_img(mlx, mlx_win, imgs.edge_side.img, x * 32 + 24, y * 32);
	if (map[x - 1][y] == 1)
		put_img(mlx, mlx_win, imgs.edge_side.img, x * 32, y * 32);
	if (map[x + 1][y] == 2 && map[x][y + 1] == 2 && map[x + 1][y + 1] == 1)
		put_img(mlx, mlx_win, imgs.corner_tl.img, x * 32 + 24, y * 32 + 24);
	if (map[x - 1][y] == 2 && map[x][y + 1] == 2 && map[x - 1][y + 1] == 1)
		put_img(mlx, mlx_win, imgs.corner_tr.img, x * 32, y * 32 + 24);
	if (map[x + 1][y] == 2 && map[x][y - 1] == 2 && map[x + 1][y - 1] == 1)
		put_img(mlx, mlx_win, imgs.corner_bl.img, x * 32 + 24, y * 32);
	if (map[x - 1][y] == 2 && map[x][y - 1] == 2 && map[x - 1][y - 1] == 1)
		put_img(mlx, mlx_win, imgs.corner_br.img, x * 32, y * 32);
}

void	inside_borders(int **map, void *mlx, void *mlx_win, t_field imgs, int x, int y)
{
	if (map[x - 1][y] == 1 && map[x][y - 1] == 1)
		put_img(mlx, mlx_win, imgs.corner_tl.img, x * 32, y * 32);
	if (map[x - 1][y] == 1 && map[x][y + 1] == 1)
		put_img(mlx, mlx_win, imgs.corner_il.img, x * 32, y * 32 + 24);
	if (map[x + 1][y] == 1 && map[x][y - 1] == 1)
		put_img(mlx, mlx_win, imgs.corner_tr.img, x * 32 + 24, y * 32);
	if (map[x + 1][y] == 1 && map[x][y + 1] == 1)
		put_img(mlx, mlx_win, imgs.corner_ir.img, x * 32 + 24, y * 32 + 24);
}

void	put_borders(int **map, void *mlx, void *mlx_win, t_field imgs)
{
	int	x;
	int	y;

	x = 0;
	while (map[x][0])
	{
		y = -1;
		while (map[0][++y])
		{
			if (map[x][y] == 2)
			{
				outside_borders(map, mlx, mlx_win, imgs, x, y);
				inside_borders(map, mlx, mlx_win, imgs, x, y);
			}
		}
		x++;
	}
}

void	create_field(int **map, void *mlx, void *mlx_win)
{
	t_field	imgs;

	imgs = define_img(mlx);
	mlx_put_image_to_window(mlx, mlx_win, imgs.background.img, 1, 1);
	put_grass(map, mlx, mlx_win, imgs);
	put_borders(map, mlx, mlx_win, imgs);
}
