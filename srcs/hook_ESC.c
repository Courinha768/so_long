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

void	destroy_field_imgs(t_all all)
{
	mlx_destroy_image(all.mlx.mlx, all.field.background.img);
	mlx_destroy_image(all.mlx.mlx, all.field.corner_bl.img);
	mlx_destroy_image(all.mlx.mlx, all.field.corner_br.img);
	mlx_destroy_image(all.mlx.mlx, all.field.corner_il.img);
	mlx_destroy_image(all.mlx.mlx, all.field.corner_ir.img);
	mlx_destroy_image(all.mlx.mlx, all.field.corner_tl.img);
	mlx_destroy_image(all.mlx.mlx, all.field.corner_tr.img);
	mlx_destroy_image(all.mlx.mlx, all.field.edge_bot.img);
	mlx_destroy_image(all.mlx.mlx, all.field.edge_side.img);
	mlx_destroy_image(all.mlx.mlx, all.field.edge_top.img);
	mlx_destroy_image(all.mlx.mlx, all.field.grass1.img);
	mlx_destroy_image(all.mlx.mlx, all.field.grass2.img);
	mlx_destroy_image(all.mlx.mlx, all.field.grass3.img);
	mlx_destroy_image(all.mlx.mlx, all.field.grass4.img);
}

void	destroy_player_imgs(t_all all)
{
	mlx_destroy_image(all.mlx.mlx, all.player.player_b.img);
	mlx_destroy_image(all.mlx.mlx, all.player.player_f.img);
	mlx_destroy_image(all.mlx.mlx, all.player.player_l.img);
	mlx_destroy_image(all.mlx.mlx, all.player.player_r.img);
}

void	destroy_win(t_all all)
{
	destroy_field_imgs(all);
	destroy_player_imgs(all);
	mlx_destroy_window(all.mlx.mlx, all.mlx.win);
	mlx_destroy_display(all.mlx.mlx);
	mlx_loop_end(all.mlx.mlx);
	free(all.mlx.mlx);
}
