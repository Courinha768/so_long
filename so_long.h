#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>

typedef	struct	s_mlx {
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_field {
	t_data	background;
	t_data	grass1;
	t_data	grass2;
	t_data	edge_top;
	t_data	edge_bot;
	t_data	edge_side;
	t_data	corner_tl;
	t_data	corner_tr;
	t_data	corner_bl;
	t_data	corner_br;
	t_data	corner_ir;
	t_data	corner_il;
}	t_field;

typedef struct	s_player {
	t_data	player_front;
	t_data	player_back;
	t_data	player_left;
	t_data	player_right;
}	t_player;

void	define_map(char *file_name, int **map);

void	create_field(int **map, void *mlx, void *mlx_win);
void	put_grass(int **map, void *mlx, void *mlx_win, t_field imgs);
void	put_borders(int **map, void *mlx, void *mlx_win, t_field imgs);
void	outside_borders(int **map, void *mlx, void *mlx_win, t_field imgs, int x, int y);
void	inside_borders(int **map, void *mlx, void *mlx_win, t_field imgs, int x, int y);

t_field	define_img(void *mlx);
void	put_img(void *mlx, void *mlx_win, void *img, int x, int y);
void	*create_img(void *mlx, char *file_name);

#endif