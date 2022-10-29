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

int	sl_strlen_v(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	start_game(char *map_name)
{
	char		**map;
	t_all		all;

	map = define_map(map_name);
	all.mlx.mlx = mlx_init();
	all.mlx.win = mlx_new_window(all.mlx.mlx, (ft_strlen(map[0]) - 1) * 32, sl_strlen_v(map) * 32, "so_long");
	all.field = create_field(map, all.mlx);
	all.player = place_player(map, all.mlx);
	all.chest = place_exit(map, all.mlx);
	mlx_loop(all.mlx.mlx);
	free_map(map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	//verify_map
	start_game(av[1]);
	return (0);
}
