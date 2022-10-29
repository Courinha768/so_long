/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:32 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/29 18:16:34 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_all all)
{
	printf("hello world");
	mlx_destroy_image(all.mlx.mlx, all.player.player_f.img);
}

int	key_hook(int keycode, t_all all)
{
	if (keycode == ESCAPE)
		destroy_win(all);
	if (keycode == W)
		move_up(all);
	printf("%d\n", keycode);
	return (0);
}
