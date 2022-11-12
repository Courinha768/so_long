/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_level_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:08:58 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/24 04:09:00 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	define_field_img(t_all *all)
{
	void	*mlx;

	mlx = all->mlx.mlx;
	all->field.background.img = create_img(mlx, "sprites/background.xpm");
	all->field.corner_bl.img = create_img(mlx, "sprites/corner_bl.xpm");
	all->field.corner_br.img = create_img(mlx, "sprites/corner_br.xpm");
	all->field.corner_il.img = create_img(mlx, "sprites/corner_il.xpm");
	all->field.corner_ir.img = create_img(mlx, "sprites/corner_ir.xpm");
	all->field.corner_tl.img = create_img(mlx, "sprites/corner_tl.xpm");
	all->field.corner_tr.img = create_img(mlx, "sprites/corner_tr.xpm");
	all->field.edge_bot.img = create_img(mlx, "sprites/edge_bot.xpm");
	all->field.edge_side.img = create_img(mlx, "sprites/edge_side.xpm");
	all->field.edge_top.img = create_img(mlx, "sprites/edge_top.xpm");
	all->field.grass1.img = create_img(mlx, "sprites/grass_1.xpm");
	all->field.grass2.img = create_img(mlx, "sprites/grass_2.xpm");
	all->field.grass3.img = create_img(mlx, "sprites/grass_3.xpm");
	all->field.grass4.img = create_img(mlx, "sprites/grass_4.xpm");
	all->field.key.img = create_img(mlx, "sprites/key.xpm");
}

int	w(char c)
{
	return (c == 49);
}

void	*chose_grass(t_all *all, int k)
{
	if (k % 2)
		return (all->field.grass3.img);
	else if (k % 3)
		return (all->field.grass2.img);
	else
		return (all->field.grass1.img);
}

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
