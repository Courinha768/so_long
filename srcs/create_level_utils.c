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

void	*create_img(void *mlx, char *path)
{
	int		width;
	int		height;
	void	*img;

	width = 1;
	height = 1;
	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	return (img);
}

void	put_img(t_vars mlx, void *img, int y, int x)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, x, y);
}

t_field	define_img(void *mlx)
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
	return (field);
}

int	w(char c)
{
	return (c == 49);
}
