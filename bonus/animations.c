/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:35:15 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/16 21:35:53 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animation(t_all *all)
{
	static int	frames;
	int			nbr;

	frames++;
	if (frames == 100000 || frames == 200000 || frames == 300000)
	{
		nbr = frames / 100000;
		if (nbr % 3 == 1)
			mlx_string_put(all->mlx.mlx, all->mlx.win, \
			all->h_size / 2 - 15, 15, 1677786880, "ANIMATION");
		if (nbr % 3 == 2)
			mlx_string_put(all->mlx.mlx, all->mlx.win, \
			all->h_size / 2 - 15, 15, 1694433280, "ANIMATION");
		if (nbr % 3 == 0)
			mlx_string_put(all->mlx.mlx, all->mlx.win, \
			all->h_size / 2 - 15, 15, 1677721855, "ANIMATION");
		if (nbr == 3)
			frames = 0;
	}
	return (0);
}
