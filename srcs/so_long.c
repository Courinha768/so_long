/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:49 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/29 18:16:50 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(char **map)
{
	t_all	all;

	init_all(&all, map);
	render(&all);
	mlx_key_hook(all.mlx.win, key_hook, &all);
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
