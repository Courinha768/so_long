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
