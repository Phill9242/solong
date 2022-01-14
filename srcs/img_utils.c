/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:36:53 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 14:41:05 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_imgs(t_mainstruct game)
{
	char	*xpm_img;

	xpm_img = "./imgs/tree.xpm";
	game.imgs->tree = mlx_xpm_file_to_image(game.mlx, xpm_img,
			&game.imgs->tree_width, &game.imgs->tree_height);
	xpm_img = "./imgs/floor.xpm";
	game.imgs->floor = mlx_xpm_file_to_image(game.mlx, xpm_img,
			&game.imgs->floor_width, &game.imgs->floor_height);
	xpm_img = "./imgs/character.xpm";
	game.imgs->character = mlx_xpm_file_to_image(game.mlx, xpm_img,
			&game.imgs->character_width, &game.imgs->character_height);
	xpm_img = "./imgs/exit_map.xpm";
	game.imgs->exit_map = mlx_xpm_file_to_image(game.mlx, xpm_img,
			&game.imgs->exit_map_width, &game.imgs->exit_map_height);
	xpm_img = "./imgs/collectable.xpm";
	game.imgs->col = mlx_xpm_file_to_image(game.mlx, xpm_img,
			&game.imgs->col_width, &game.imgs->col_height);
	return ;
}

void	ft_put_imgs(t_mainstruct game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game.map->vertical_size)
	{
		if (game.map->horizontal_size == x)
		{
			y++;
			x = -1;
		}
		else if (game.map->map_pos[y][x] == '1')
			mlx_put_image_to_window(game.mlx, game.window,
				game.imgs->tree, x * TILE, y * TILE);
		else if (game.map->map_pos[y][x] == '0')
			mlx_put_image_to_window(game.mlx, game.window,
				game.imgs->floor, x * TILE, y * TILE);
		else if (game.map->map_pos[y][x] == 'P')
			mlx_put_image_to_window(game.mlx, game.window, game.imgs->character,
				game.elements->c_x * TILE, game.elements->c_y * TILE);
		x++;
	}
	ft_put_imgs2(game);
}

void	ft_put_imgs2(t_mainstruct game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game.map->vertical_size)
	{
		if (game.map->horizontal_size == x)
		{
			y++;
			x = -1;
		}
		else if (game.map->map_pos[y][x] == 'E')
			mlx_put_image_to_window(game.mlx, game.window,
				game.imgs->exit_map, x * TILE, y * TILE);
		else if (game.map->map_pos[y][x] == 'C')
			mlx_put_image_to_window(game.mlx, game.window,
				game.imgs->col, x * TILE, y * TILE);
		x++;
	}
}

int	ft_reload(t_mainstruct *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (game->window == NULL)
		return (0);
	while (y < game->map->vertical_size)
	{
		if (game->map->horizontal_size == x)
		{
			y++;
			x = -1;
		}
		else if (game->map->map_pos[y][x] == '1')
			mlx_put_image_to_window(game->mlx, game->window,
				game->imgs->tree, x * TILE, y * TILE);
		else if (game->map->map_pos[y][x] == 'E')
			mlx_put_image_to_window(game->mlx, game->window,
				game->imgs->exit_map, x * TILE, y * TILE);
		x++;
	}
	ft_reload2(game);
	return (0);
}

void	ft_reload2(t_mainstruct *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map->vertical_size)
	{
		if (game->map->horizontal_size == x)
		{
			y++;
			x = -1;
		}
		else if (game->map->map_pos[y][x] == 'C')
			mlx_put_image_to_window(game->mlx, game->window,
				game->imgs->col, x * TILE, y * TILE);
		else if (game->map->map_pos[y][x] == '0'
			|| game->map->map_pos[y][x] == 'P')
			mlx_put_image_to_window(game->mlx, game->window,
				game->imgs->floor, x * TILE, y * TILE);
		x++;
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->character,
			game->elements->c_x * TILE, game->elements->c_y * TILE);
	}
}
