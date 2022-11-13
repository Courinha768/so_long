/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:26 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/29 18:16:27 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map(int fd, int lc, char **map)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		map = get_map(fd, (lc + 1), map);
	else if (!map)
		map = malloc(sizeof(char *) * (lc + 1));
	if (!map)
		return (NULL);
	map[lc] = line;
	return (map);
}

char	**define_map(char *file_name)
{
	char	**map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	map = get_map(fd, 0, NULL);
	close(fd);
	return (map);
}
