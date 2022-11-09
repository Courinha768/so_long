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

void		start_game(char *map_name);

void		*create_img(void *mlx, char *path);
void		put_img(t_vars mlx, void *img, int y, int x);
void		free_map(char **map);

char		**define_map(char *file_name);

t_field		create_field(char **map, t_vars mlx);
t_field		define_field_img(void *mlx);
int			w(char c);


t_player	place_player(char **map, t_vars mlx);

int			key_hook(int keycode, t_all all);

void		destroy_win(t_all all);
void		destroy_player_imgs(t_all all);
void		destroy_field_imgs(t_all all);

t_chest 	place_exit(char **map, t_vars mlx);

int			verify(int ac, char **av);
int			verify_name(char *file);
int			verify_map(char	*file_name);

int	not_token(char	c);
int	linelen(char **map);

#endif
