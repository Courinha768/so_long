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
	char	**mapc;
	int		fd;

	fd = open(file_name, O_RDONLY);
	mapc = get_map(fd, 0, NULL);
	return (mapc);
}