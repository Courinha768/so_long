/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:01:38 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/16 17:24:24 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	correct_char(char **map)
{
	int		i;
	int		j;
	int		j_limit;

	j_limit = ft_strlen(map[0]) - 2;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!not_token(map[i][j]))
				return (1);
			if ((i == 0 || j == 0 || j == j_limit || !map[i + 1]))
				if (j != j_limit + 1 && map[i][j] != 49)
					return (1);
		}
	}
	return (0);
}

int	correct_nbr_c(char **map)
{
	int		i;
	int		j;
	int		flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (correct_nbr_c2(map, i, j))
				return (1);
			if (map[i][j] == 67)
				flag = 1;
		}
	}
	if (at_least_one(map))
		return (1);
	if (!flag)
		return (1);
	return (0);
}

int	verify_map(char	*file_name)
{
	char	**map;

	map = define_map(file_name);
	if (linelen(map) || correct_char(map) || correct_nbr_c(map))
		return (free_map(map));
	free_map(map);
	return (0);
}

int	verify_name(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i] && file[i] != 46)
		i++;
	i++;
	if (file[i] != 98 || file[i + 1] != 101 || file[i + 2] != 114)
		return (2);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (3);
	close(fd);
	return (0);
}

int	verify(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (verify_name(av[1]))
		return (verify_name(av[1]));
	if (verify_map(av[1]))
		return (4);
	if (is_possible(av[1]))
		return (5);
	return (0);
}
