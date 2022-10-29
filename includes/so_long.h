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

//so_long.c
void		start_game(char *map_name);

//so_long_utils.c
void		*create_img(void *mlx, char *path);
void		put_img(t_vars mlx, void *img, int y, int x);
void		free_map(char **map);

//create_map.c
char		**define_map(char *file_name);

//create_field
t_field		create_field(char **map, t_vars mlx);
t_field		define_field_img(void *mlx);
int			w(char c);


//place_player.c
t_player	place_player(char **map, t_vars mlx);

//hook.c
int			key_hook(int keycode, t_all all);

//hook_ESC.c
void		destroy_win(t_all all);
void		destroy_player_imgs(t_all all);
void		destroy_field_imgs(t_all all);

//place_exit.c
t_chest 	place_exit(char **map, t_vars mlx);

#endif
