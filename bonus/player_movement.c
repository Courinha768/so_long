/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:37:05 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/16 21:34:21 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_mc(t_all *all)
{
	void	*mlx;
	void	*win;
	char	*str1;
	char	*str2;

	mlx = all->mlx.mlx;
	win = all->mlx.win;
	str1 = ft_itoa(all->move_count - 1);
	str2 = ft_itoa(all->move_count);
	mlx_string_put(mlx, win, 82, 15, 2763306, str1);
	mlx_string_put(mlx, win, 82, 15, 16448250, str2);
	free(str1);
	free(str2);
}

void	move_up(t_all *all)
{
	if (!w(all->map[all->player.x - 1][all->player.y]))
	{
		is_collectible(all, 'u');
		if (all->map[all->player.x - 1][all->player.y] == 65)
			exit_game(all);
		if (all->map[all->player.x - 1][all->player.y] == 69)
		{
			if (!all->collectible)
			{
				all->complete = 1;
				exit_game(all);
			}
		}
		else
		{
			put_img(all, all->field.grass2.img,
				all->player.x * 32, all->player.y * 32);
			put_img(all, all->player.player.img,
				(all->player.x - 1) * 32, all->player.y * 32);
			all->player.x--;
			all->move_count++;
		}
		update_mc(all);
	}
}

void	move_down(t_all *all)
{
	if (!w(all->map[all->player.x + 1][all->player.y]))
	{
		is_collectible(all, 'd');
		if (all->map[all->player.x + 1][all->player.y] == 65)
			exit_game(all);
		if (all->map[all->player.x + 1][all->player.y] == 69)
		{
			if (!all->collectible)
			{
				all->complete = 1;
				exit_game(all);
			}
		}
		else
		{
			put_img(all, all->field.grass2.img,
				all->player.x * 32, all->player.y * 32);
			put_img(all, all->player.player.img,
				(all->player.x + 1) * 32, all->player.y * 32);
			all->player.x++;
			all->move_count++;
		}
		update_mc(all);
	}
}

void	move_left(t_all *all)
{
	if (!w(all->map[all->player.x][all->player.y - 1]))
	{
		is_collectible(all, 'l');
		if (all->map[all->player.x][all->player.y - 1] == 65)
			exit_game(all);
		if (all->map[all->player.x][all->player.y - 1] == 69)
		{
			if (!all->collectible)
			{
				all->complete = 1;
				exit_game(all);
			}
		}
		else
		{
			put_img(all, all->field.grass2.img,
				all->player.x * 32, all->player.y * 32);
			put_img(all, all->player.player2.img,
				all->player.x * 32, (all->player.y - 1) * 32);
			all->player.y--;
			all->move_count++;
		}
		update_mc(all);
	}
}

void	move_right(t_all *all)
{
	if (!w(all->map[all->player.x][all->player.y + 1]))
	{
		is_collectible(all, 'r');
		if (all->map[all->player.x][all->player.y + 1] == 65)
			exit_game(all);
		if (all->map[all->player.x][all->player.y + 1] == 69)
		{
			if (!all->collectible)
			{
				all->complete = 1;
				exit_game(all);
			}
		}
		else
		{
			put_img(all, all->field.grass2.img,
				all->player.x * 32, all->player.y * 32);
			put_img(all, all->player.player.img,
				all->player.x * 32, (all->player.y + 1) * 32);
			all->player.y++;
			all->move_count++;
		}
		update_mc(all);
	}
}
