/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:01:38 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/09 20:01:40 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verify_map(char	*file_name)
{
	char	**map;
	int		i;
	int		j;
	int		j_limit;

	map = define_map(file_name);
	if (linelen(map))
		return (1);
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
	free_map(map);
	return (0);
}

int	verify_name(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != 46)
		i++;
	i++;
	if (file[i] != 98 || file[i + 1] != 101 || file[i + 2] != 114)
		return (1);
	return (0);
}

int	verify(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (verify_name(av[1]))
		return (2);
	if (verify_map(av[1]))
		return (3);
	return (0);
}
