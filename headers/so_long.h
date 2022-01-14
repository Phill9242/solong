/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:24:57 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 14:33:11 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE 64

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_imgs
{
	void	*tree;
	int		tree_width;
	int		tree_height;
	void	*floor;
	int		floor_width;
	int		floor_height;
	void	*character;
	int		character_width;
	int		character_height;
	void	*exit_map;
	int		exit_map_width;
	int		exit_map_height;
	void	*col;
	int		col_width;
	int		col_height;
}	t_imgs;

typedef struct s_map_elements
{
	int	col_count;
	int	exit_count;
	int	initial_position;
	int	c_x;
	int	c_y;
}	t_map_elements;

typedef struct s_map
{
	int		vertical_size;
	int		horizontal_size;
	int		map_null;
	char	*str;
	char	**map_pos;
}	t_map;

typedef struct s_mainstruct
{
	void			*mlx;
	void			*window;
	t_map			*map;
	t_imgs			*imgs;
	t_map_elements	*elements;
}	t_mainstruct;

void	ft_createmap(t_mainstruct game);
void	ft_map_validate(t_mainstruct game);
int		ft_movement_utils(int key, void *pointer);
int		ft_check_if_is_surrounded_by_walls(t_mainstruct game);
void	ft_free_image(t_mainstruct game);
void	ft_free(void *ptr);
void	ft_free_map(t_mainstruct *game);
void	ft_set_imgs(t_mainstruct game);
void	ft_pos_player(t_mainstruct game);
void	ft_put_imgs(t_mainstruct game);
void	ft_read_map(t_mainstruct game);
void	ft_key_press(int key, t_mainstruct *game);
void	ft_check_map(t_mainstruct game);
void	ft_is_rectangular(t_mainstruct game);
void	ft_map_str(t_mainstruct game, char *map);
int		ft_exit(t_mainstruct *game);
void	ft_window_size(t_mainstruct game);
int		ft_reload(t_mainstruct *game);
void	ft_put_imgs2(t_mainstruct game);
void	ft_reload2(t_mainstruct *game);
#endif
