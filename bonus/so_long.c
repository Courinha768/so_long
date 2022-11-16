/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:49 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/16 17:57:17 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_error(int value)
{
	write(2, "ERROR\n", 6);
	if (value == 1)
		write(1, "wrong number of arguments\n", 26);
	else if (value == 2)
		write(1, "file extension should be .ber\n", 30);
	else if (value == 3)
		write(1, "given file doesn't exist\n", 26);
	else if (value == 4)
		write(1, "map not correctly contructed\n", 30);
	else if (value == 5)
		write(1, "this map is impossible\n", 24);
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
	all->complete = 0;
}

void	start_game(char **map)
{
	t_all	all;

	init_all(&all, map);
	render(&all);
	mlx_key_hook(all.mlx.win, key_hook, &all);
	mlx_hook(all.mlx.win, 17, 1L << 17, exit_game, &all);
	mlx_loop(all.mlx.mlx);
}

int	main(int ac, char **av)
{
	int		map_value;
	char	**map;

	map_value = verify(ac, av);
	if (map_value)
		return (print_error(map_value));
	map = define_map(av[1]);
	start_game(map);
	return (0);
}
