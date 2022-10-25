#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "struct.h"
# include "define.h"
# include <mlx.h>

int			sl_strlen_v(char **map);

char		**get_map(int fd, int lc, char **map);
char		**define_map(char *file_name);

void		put_grass(char **map, t_vars mlx, t_field imgs);
void		outside_borders(char **map, t_vars mlx, t_field imgs, t_loc loc);
void		inside_borders(char **map, t_vars mlx, t_field imgs, t_loc loc);
void		put_borders(char **map, t_vars mlx, t_field imgs);
t_field		create_field(char **map, t_vars mlx);

t_player	place_player(char **map, t_vars mlx);
t_player	define_player_imgs(void *mlx);

int			key_hook(int keycode, t_all all);

void		destroy_win(t_all all);
void		destroy_player_imgs(t_all all);
void		destroy_field_imgs(t_all all);
int			w(char c);

void		*create_img(void *mlx, char *file_name);
void		put_img(t_vars mlx, void *img, int x, int y);
t_field		define_img(void *mlx);

#endif