/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:44 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/29 18:16:45 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	define_player_imgs(t_all *all)
{
	void	*mlx;

	mlx = all->mlx.mlx;
	all->player.player.img = create_img(mlx, "sprites/player.xpm");
}

void	render_player(t_all *all)
{
	int			x;
	int			y;

	x = 0;
	define_player_imgs(all);
	while (all->map[++x])
	{
		y = 0;
		while (all->map[x][++y])
		{
			if (all->map[x][y] == 80)
			{
				all->player.x = x;
				all ->player.y = y;
				put_img(all, all->player.player.img, 32 * x, 32 * y);
			}
		}
	}
}
