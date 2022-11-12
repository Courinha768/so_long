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
