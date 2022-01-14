/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:36:53 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:36:54 by phil             ###   ########.fr       */
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
	game.imgs->collectables = mlx_xpm_file_to_image(game.mlx, xpm_img,
			&game.imgs->collectables_width, &game.imgs->collectables_height);
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
			mlx_put_image_to_window(MLX, WINDOW, TREE, x * TILE, y * TILE);
		else if (game.map->map_pos[y][x] == '0')
			mlx_put_image_to_window(MLX, WINDOW, FLOOR, x * TILE, y * TILE);
		else if (game.map->map_pos[y][x] == 'P')
			mlx_put_image_to_window(MLX, WINDOW, CHARACTER,
				POS_X * TILE, POS_Y * TILE);
		else if (game.map->map_pos[y][x] == 'E')
			mlx_put_image_to_window(MLX, WINDOW, EXIT_MAP, x * TILE, y * TILE);
		else if (game.map->map_pos[y][x] == 'C')
			mlx_put_image_to_window(MLX, WINDOW, COLLECT, x * TILE, y * TILE);
		x++;
	}
}

int ft_reload (t_mainstruct *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (game->window != NULL)
	{
		while (y < game->map->vertical_size)
		{
			if (game->map->horizontal_size == x)
			{
				y++;
				x = -1;
			}
			else if (game->map->map_pos[y][x] == '1')
				mlx_put_image_to_window(PMLX, PWINDOW, PTREE, x * TILE, y * TILE);
			else if (game->map->map_pos[y][x] == '0' || game->map->map_pos[y][x] == 'P')
				mlx_put_image_to_window(PMLX, PWINDOW, PFLOOR, x * TILE, y * TILE);
			else if (game->map->map_pos[y][x] == 'E')
				mlx_put_image_to_window(PMLX, PWINDOW, PEXIT_MAP, x * TILE, y * TILE);
			else if (game->map->map_pos[y][x] == 'C')
				mlx_put_image_to_window(PMLX, PWINDOW, PCOLLECT, x * TILE, y * TILE);
			x++;
			mlx_put_image_to_window(PMLX, PWINDOW, game->imgs->character,
			PPOS_X * TILE, PPOS_Y * TILE);
		}
	}
	return (0);
}
