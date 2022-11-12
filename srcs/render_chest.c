/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:02:08 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/09 20:02:10 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	define_chest_imgs(t_all *all)
{
	void	*mlx;

	mlx = all->mlx.mlx;
	all->chest.chest_o.img = create_img(mlx, "sprites/chest_o.xpm");
	all->chest.chest_c.img = create_img(mlx, "sprites/chest_c.xpm");
}

void	place_exit(t_all *all)
{
	int	x;
	int	y;

	define_chest_imgs(all);
	x = 0;
	while (all->map[++x])
	{
		y = 0;
		while (all->map[x][++y])
		{
			if (all->map[x][y] == 69)
			{
				put_img(all, all->chest.chest_c.img, 32 * x, 32 * y);
				all->chest.x = x * 32 - 16;
				all->chest.y = y * 32;
			}
		}
	}
}
