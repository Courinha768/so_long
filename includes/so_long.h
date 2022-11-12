/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:13:35 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/29 18:13:39 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "struct.h"
# include "define.h"
# include <mlx.h>

void	start_game(char **map);

int		print_error(int value);
int		count_collectible(char **map);
void	init_all(t_all *all, char **map);

void	*create_img(void *mlx, char *path);
void	put_img(t_all *all, void *img, int y, int x);
void	put_img2(t_vars mlx, void *img, int y, int x);
void	free_map(char **map);
int		sl_strlen_v(char **map);

int		verify(int ac, char **av);
int		verify_name(char *file);
int		verify_map(char	*file_name);

int		not_token(char c);
int		linelen(char **map);

void	render(t_all *all);
void	render_borders(char **map, t_vars mlx, t_field imgs);
void	inside_borders(char **map, t_vars mlx, t_field imgs, t_loc loc);
void	outside_borders(char **map, t_vars mlx, t_field imgs, t_loc loc);
void	render_grass(t_all *all);

void	define_field_img(t_all *all);
int		w(char c);
void	*chose_grass(t_all *all, int k);
void	outside_borders2(char **map, t_vars mlx, t_field imgs, t_loc loc);

void	define_player_imgs(t_all *all);
void	render_player(t_all *all);

void	move_up(t_all *all);
void	move_down(t_all *all);
void	move_left(t_all *all);
void	move_right(t_all *all);
void	update_mc(t_all *all);

int		key_hook(int keycode, t_all *all);
void	is_collectible(t_all *all, char d);
void	is_collectible2(t_all *all, char d);
void	exit_game(t_all *all);

char	**define_map(char *file_name);
char	**get_map(int fd, int lc, char **map);

void	define_chest_imgs(t_all *all);
void	place_exit(t_all *all);

#endif
