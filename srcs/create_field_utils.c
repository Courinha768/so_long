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

t_field	define_field_img(void *mlx)
{
	t_field	field;

	field.background.img = create_img(mlx, "sprites/background.xpm");
	field.corner_bl.img = create_img(mlx, "sprites/corner_bl.xpm");
	field.corner_br.img = create_img(mlx, "sprites/corner_br.xpm");
	field.corner_il.img = create_img(mlx, "sprites/corner_il.xpm");
	field.corner_ir.img = create_img(mlx, "sprites/corner_ir.xpm");
	field.corner_tl.img = create_img(mlx, "sprites/corner_tl.xpm");
	field.corner_tr.img = create_img(mlx, "sprites/corner_tr.xpm");
	field.edge_bot.img = create_img(mlx, "sprites/edge_bot.xpm");
	field.edge_side.img = create_img(mlx, "sprites/edge_side.xpm");
	field.edge_top.img = create_img(mlx, "sprites/edge_top.xpm");
	field.grass1.img = create_img(mlx, "sprites/grass_1.xpm");
	field.grass2.img = create_img(mlx, "sprites/grass_2.xpm");
	field.grass3.img = create_img(mlx, "sprites/grass_3.xpm");
	field.grass4.img = create_img(mlx, "sprites/grass_4.xpm");
	field.key.img = create_img(mlx, "sprites/key.xpm");
	return (field);
}

int	w(char c)
{
	return (c == 49);
}
