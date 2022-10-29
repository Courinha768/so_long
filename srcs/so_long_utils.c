#include "../includes/so_long.h"

void	*create_img(void *mlx, char *path)
{
	int		width;
	int		height;
	void	*img;

	width = 1;
	height = 1;
	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	return (img);
}

void	put_img(t_vars mlx, void *img, int y, int x)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, x, y);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free((void *)map);
}