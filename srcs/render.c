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

void	render_grass(t_all *all)
{
	int	x;
	int	y;
	int	k;

	x = -1;
	k = 0;
	while (all->map[++x])
	{
		y = -1;
		while (all->map[x][++y])
		{
			if (all->map[x][y] != 49)
			{
				put_img(all, chose_grass(all, k), x * 32, y * 32);
				if (all->map[x][y] == 67)
					put_img(all, all->field.key.img, x * 32, y * 32);
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

void	render(t_all *all)
{
	int	white;

	white = 16448250;
	define_field_img(all);
	put_img(all, all->field.background.img, 1, 1);
	render_borders(all->map, all->mlx, all->field);
	render_grass(all);
	place_exit(all);
	render_player(all);
	mlx_string_put(all->mlx.mlx, all->mlx.win, 6, 15, white, "MOVE COUNT : ");
}
