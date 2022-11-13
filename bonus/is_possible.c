/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:04:22 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/13 23:04:24 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_loc	get_entrance(char **map)
{
	int		i;
	int		j;
	t_loc	entrance;

	i = -1;
	j = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 80)
			{
				entrance.x = i;
				entrance.y = j;
				return (entrance);
			}
		}
	}
	entrance.x = -1;
	entrance.y = -1;
	return (entrance);
}

void	possibilities2(t_loc c, char **map, t_loc *poss, t_loc size)
{
	if (c.y <= 0)
		poss[2] = new_loc(-1, -1);
	else
	{
		if (is_passable(map[c.x][c.y - 1]))
			poss[2] = new_loc(c.x, c.y - 1);
		else
			poss[2] = new_loc(-1, -1);
	}
	if (c.y >= size.y - 1)
		poss[3] = new_loc(-1, -1);
	else
	{
		if (is_passable(map[c.x][c.y + 1]))
			poss[3] = new_loc(c.x, c.y + 1);
		else
			poss[3] = new_loc(-1, -1);
	}
}

void	possibilities(t_loc c, char **map, t_loc *poss, t_loc size)
{
	if (c.x >= size.x - 1)
		poss[0] = new_loc(-1, -1);
	else
	{
		if (is_passable(map[c.x + 1][c.y]))
			poss[0] = new_loc(c.x + 1, c.y);
		else
			poss[0] = new_loc(-1, -1);
	}
	if (c.x <= 0)
		poss[1] = new_loc(-1, -1);
	else
	{
		if (is_passable(map[c.x - 1][c.y]))
			poss[1] = new_loc(c.x - 1, c.y);
		else
			poss[1] = new_loc(-1, -1);
	}
	possibilities2(c, map, poss, size);
}

t_loc	solve(t_loc current, char **map, int lines, int columns)
{
	int		i;
	t_loc	poss[4];
	t_loc	answer;
	t_loc	size;

	size.x = lines;
	size.y = columns;
	if (current.x == -1)
		return (current);
	if (map[current.x][current.y] == 69)
		return (new_loc(-2, -2));
	map[current.x][current.y] = 42;
	possibilities(current, map, poss, size);
	i = -1;
	while (++i < 4)
	{
		answer = solve(poss[i], map, lines, columns);
		if (answer.x == -1)
			continue ;
		if (answer.x == -2)
			return (answer);
	}
	map[current.x][current.y] = 48;
	return (current);
}

int	is_possible(char *file_name)
{
	char	**map;
	t_loc	entrance_to_map;
	t_loc	exit_to_map;
	int		nlines;
	int		ncolumns;

	map = define_map(file_name);
	ncolumns = (ft_strlen(map[0]));
	nlines = sl_strlen_v(map);
	entrance_to_map = get_entrance(map);
	exit_to_map = solve(entrance_to_map, map, nlines, ncolumns);
	free_map(map);
	if (equals_loc(entrance_to_map, exit_to_map))
		return (1);
	return (0);
}
