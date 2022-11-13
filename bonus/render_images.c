/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:04:27 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/13 23:04:28 by aappleto         ###   ########.fr       */
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

void	define_chest_imgs(t_all *all)
{
	void	*mlx;

	mlx = all->mlx.mlx;
	all->chest.chest_o.img = create_img(mlx, "sprites/chest_o.xpm");
	all->chest.chest_c.img = create_img(mlx, "sprites/chest_c.xpm");
}

void	define_player_imgs(t_all *all)
{
	void	*mlx;

	mlx = all->mlx.mlx;
	all->player.player.img = create_img(mlx, "sprites/player.xpm");
}
