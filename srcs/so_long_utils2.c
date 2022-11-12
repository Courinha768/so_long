/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:37:22 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/12 01:37:23 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_error(int value)
{
	write(2, "ERROR\n", 6);
	if (value == 1)
		write(2, "wrong number of arguments\n", 26);
	if (value == 2)
		write(2, "file extension should be .ber\n", 30);
	if (value == 3)
		write(2, "map is not constructed correctly\n", 33);
	return (0);
}

int	count_collectible(char **map)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	counter = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 67)
				counter++;
	}
	return (counter);
}

void	init_all(t_all *all, char **map)
{
	int		w_s[2];

	all->map = map;
	all->mlx.mlx = mlx_init();
	w_s[0] = (ft_strlen(all->map[0]) - 1) * 32;
	w_s[1] = sl_strlen_v(all->map) * 32 + 30;
	all->mlx.win = mlx_new_window(all->mlx.mlx, w_s[0], w_s[1], "So_long");
	all->move_count = 0;
	all->collectible = count_collectible(map);
}
