/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:01:50 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/09 20:01:51 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	not_token(char c)
{
	return (c != 48 || c != 49 || c != 67 || c != 69 || c != 80);
}

int	linelen(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = -2;
	while (map[i + 1])
	{
		if (len != -2)
			if (len != (int)ft_strlen(map[i]))
				return (1);
		len = ft_strlen(map[i]);
		i++;
	}
	if (!(len - 1 == (int)ft_strlen(map[i]) || len == (int)ft_strlen(map[i])))
		return (1);
	return (0);
}

int	correct_nbr_c2(char **map, int i, int j)
{
	static int	flag[2];

	if (map[i][j] == 80 && !flag[0])
		flag[0] = 1;
	else if (map[i][j] == 80)
		return (1);
	if (map[i][j] == 69 && !flag[1])
		flag[1] = 1;
	else if (map[i][j] == 69)
		return (1);
	return (0);
}
