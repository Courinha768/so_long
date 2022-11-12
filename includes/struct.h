/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:13:46 by aappleto          #+#    #+#             */
/*   Updated: 2022/10/29 18:13:49 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_field {
	t_data	background;
	t_data	grass1;
	t_data	grass2;
	t_data	grass3;
	t_data	grass4;
	t_data	edge_top;
	t_data	edge_bot;
	t_data	edge_side;
	t_data	corner_tl;
	t_data	corner_tr;
	t_data	corner_bl;
	t_data	corner_br;
	t_data	corner_ir;
	t_data	corner_il;
	t_data	key;
}	t_field;

typedef struct s_player {
	t_data	player;
	int		x;
	int		y;
}	t_player;

typedef struct s_chest {
	t_data	chest_c;
	t_data	chest_o;
	int		x;
	int		y;
}	t_chest;

typedef struct s_all {
	t_player	player;
	t_field		field;
	t_vars		mlx;
	t_chest		chest;
	char		**map;
	int			collectible;
	int			move_count;
}	t_all;

typedef struct s_loc {
	int	x;
	int	y;
}	t_loc;

#endif
