/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:02:17 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/09 20:02:18 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	put_img(t_all *all, void *img, int y, int x)
{
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, img, x, y);
}

void	put_img2(t_vars mlx, void *img, int y, int x)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, x, y);
}

int	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free((void *)map);
	return (1);
}

int	sl_strlen_v(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
