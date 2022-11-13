/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possible_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:05:04 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/13 23:05:05 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	equals_loc(t_loc coord1, t_loc coord2)
{
	if ((coord1.x == coord2.x) && (coord1.y == coord2.y))
		return (1);
	return (0);
}

int	is_passable(char c)
{
	return (c == 48 || c == 69 || c == 67);
}

t_loc	new_loc(int x, int y)
{
	t_loc	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}
