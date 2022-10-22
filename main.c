#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int 	width;
	int 	height;
	t_data  img;

	width = 2;
	height = 2;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 512, 512, "so_long");
	mlx_pixel_put(mlx, mlx_win, 50, 50, 0x00FF0000);
	img.img = mlx_xpm_file_to_image(mlx, "sprites/player_front.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 256, 256);
	mlx_loop(mlx);
}