/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:13:35 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/16 17:59:16 by aappleto         ###   ########.fr       */
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
int		free_map(char **map);
int		sl_strlen_v(char **map);

int		verify(int ac, char **av);
int		verify_name(char *file);
int		verify_map(char	*file_name);
int		is_possible(char *file_name);

int		not_token(char c);
int		linelen(char **map);
int		correct_nbr_c2(char **map, int i, int j);
int		at_least_one(char **map);

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
int		exit_game(t_all *all);

char	**define_map(char *file_name);
char	**get_map(int fd, int lc, char **map);

void	define_chest_imgs(t_all *all);
void	place_exit(t_all *all);

int		is_possible(char *file_name);
t_loc	solve(t_loc current, char **map, int lines, int columns);
void	possibilities(t_loc c, char **map, t_loc *poss, t_loc size);
void	possibilities2(t_loc c, char **map, t_loc *poss, t_loc size);
t_loc	get_entrance(char **map);
t_loc	new_loc(int x, int y);
int		is_passable(char c);
int		equals_loc(t_loc coord1, t_loc coord2);

#endif
