/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_ESC.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:38 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/29 18:16:40 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_win(t_all *all)
{
	free_map(all->map);
	mlx_destroy_window(all.mlx.mlx, all.mlx.win);
	exit(1);
}
