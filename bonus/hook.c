/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:32 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/16 18:01:02 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_collectible(t_all *all, char d)
{
	if (d == 'u')
	{
		if (all->map[all->player.x - 1][all->player.y] == 'C')
		{
			all->collectible--;
			all->map[all->player.x - 1][all->player.y] = 48;
		}
	}
	if (d == 'd')
	{
		if (all->map[all->player.x + 1][all->player.y] == 'C')
		{
			all->collectible--;
			all->map[all->player.x + 1][all->player.y] = 48;
		}
	}
	is_collectible2(all, d);
}

void	is_collectible2(t_all *all, char d)
{
	if (d == 'l')
	{
		if (all->map[all->player.x][all->player.y - 1] == 'C')
		{
			all->collectible--;
			all->map[all->player.x][all->player.y - 1] = 48;
		}
	}
	if (d == 'r')
	{
		if (all->map[all->player.x][all->player.y + 1] == 'C')
		{
			all->collectible--;
			all->map[all->player.x][all->player.y + 1] = 48;
		}
	}
}

int	exit_game(t_all *all)
{
	free_map(all->map);
	mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	if (all->complete)
	{
		ft_putstr_fd("\n\033[1m\033[32mCongrats!\033[0m\nTotal moves = ", 1);
		ft_putnbr_fd(all->move_count + 1, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putstr_fd("\033[1m\033[31mGame Over!\033[0m \
Thank you for playing\n", 1);
	}
	exit(1);
	return (0);
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == ESCAPE)
		exit_game(all);
	if (keycode == UP || keycode == W)
		move_up(all);
	if (keycode == DOWN || keycode == S)
		move_down(all);
	if (keycode == LEFT || keycode == A)
		move_left(all);
	if (keycode == RIGHT || keycode == D)
		move_right(all);
	if (!all->collectible)
		put_img(all, all->chest.chest_o.img, all->chest.x, all->chest.y);
	return (0);
}
