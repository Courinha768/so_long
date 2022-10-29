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

t_player	define_player_imgs(void *mlx)
{
	t_player	player;

	player.player_f.img = create_img(mlx, "sprites/player_f.xpm");
	player.player_l.img = create_img(mlx, "sprites/player_l.xpm");
	player.player_b.img = create_img(mlx, "sprites/player_b.xpm");
	player.player_r.img = create_img(mlx, "sprites/player_r.xpm");
	return (player);
}

t_player	place_player(char **map, t_vars mlx)
{
	int			x;
	int			y;
	t_player	player;

	x = 0;
	player = define_player_imgs(mlx.mlx);
	while (map[++x])
	{
		y = 0;
		while (map[x][++y])
			if (map[x][y] == 80)
				put_img(mlx, player.player_f.img, 32 * x - 18, 32 * y + 5);
	}
	return (player);
}
