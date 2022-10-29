/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:08:51 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/29 18:16:16 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_grass(char **map, t_vars mlx, t_field imgs)
{
	int	x;
	int	y;
	int	k;

	x = -1;
	k = 0;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] != 49)
			{
				if (k % 2)
					put_img(mlx, imgs.grass3.img, x * 32, y * 32);
				else if (k % 3)
					put_img(mlx, imgs.grass2.img, x * 32, y * 32);
				else if (k % 5)
					put_img(mlx, imgs.grass4.img, x * 32, y * 32);
				else
					put_img(mlx, imgs.grass1.img, x * 32, y * 32);
				k++;
			}
		}
	}
}

void	outside_borders(char **map, t_vars mlx, t_field imgs, t_loc loc)
{
	int	x;
	int	y;

	x = loc.x;
	y = loc.y;
	if (x > 0 && !w(map[x - 1][y]))
		put_img(mlx, imgs.edge_bot.img, x * 32, y * 32);
	if (map[x][y + 2] && !w(map[x][y + 1]) && map[x][y + 1])
		put_img(mlx, imgs.edge_side.img, x * 32, y * 32 + 24);
	if (y > 0 && !w(map[x][y - 1]))
		put_img(mlx, imgs.edge_side.img, x * 32, y * 32);
	if (map[x + 1])
	{
		if (!w(map[x + 1][y]))
			put_img(mlx, imgs.edge_top.img, x * 32 + 24, y * 32);
		if (!w(map[x + 1][y + 1]) && w(map[x][y + 1]) && w(map[x + 1][y]))
			put_img(mlx, imgs.corner_tl.img, x * 32 + 24, y * 32 + 24);
		if (y > 0)
			if (!w(map[x + 1][y - 1]) && w(map[x + 1][y]) && w(map[x][y - 1]))
				put_img(mlx, imgs.corner_tr.img, x * 32 + 24, y * 32);
	}
	if (x > 0)
	{
		if (!w(map[x - 1][y + 1]) && w(map[x - 1][y]) && w(map[x][y + 1]))
			put_img(mlx, imgs.corner_bl.img, x * 32, y * 32 + 24);
		if (y > 0)
			if (!w(map[x - 1][y - 1]) && w(map[x - 1][y]) && w(map[x][y - 1]))
				put_img(mlx, imgs.corner_br.img, x * 32, y * 32);
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
			put_img(mlx, imgs.corner_tl.img, x * 32, y * 32);
		if (!w(map[x - 1][y]) && !w(map[x][y + 1]))
			put_img(mlx, imgs.corner_tr.img, x * 32, y * 32 + 24);
	}
	if (map[x + 1])
	{
		if (!w(map[x + 1][y]) && !w(map[x][y - 1]))
			put_img(mlx, imgs.corner_il.img, x * 32 + 24, y * 32);
		if (!w(map[x + 1][y]) && !w(map[x][y + 1]))
			put_img(mlx, imgs.corner_ir.img, x * 32 + 24, y * 32 + 24);
	}
}

void	put_borders(char **map, t_vars mlx, t_field imgs)
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

t_field	create_field(char **map, t_vars mlx)
{
	t_field	img;

	img = define_field_img(mlx.mlx);
	put_img(mlx, img.background.img, 1, 1);
	put_grass(map, mlx, img);
	put_borders(map, mlx, img);
	return (img);
}
