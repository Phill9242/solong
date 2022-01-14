/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:37:01 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 14:18:33 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_movement_utils(int key, void *pointer)
{
	t_mainstruct	*game;

	game = pointer;
	mlx_put_image_to_window(game->mlx, game->window, game->imgs->floor,
		game->elements->c_x * TILE, game->elements->c_y * TILE);
	ft_key_press (key, game);
	if (game->map->map_pos[game->elements->c_y][game->elements->c_x] == 'C')
	{
		game->map->map_pos[game->elements->c_y][game->elements->c_x] = '0';
		game->elements->col_count--;
	}
	if (game->map->map_pos[game->elements->c_y][game->elements->c_x] == 'E')
	{
		printf ("\n\nCONGRATULATIONS!\nYou Finished the game!\n\n");
		ft_exit(game);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->imgs->character,
		game->elements->c_x * TILE, game->elements->c_y * TILE);
	return (0);
}

void	ft_key_press(int key, t_mainstruct *game)
{
	int			y;
	int			x;
	static int	move = 0;

	x = game->elements->c_x;
	y = game->elements->c_y;
	if (key == 65307)
		ft_exit((t_mainstruct *) game);
	if (key == 100 && game->map->map_pos[y][x + 1] != '1' &&
		(game->map->map_pos[y][x + 1] != 'E' || !game->elements->col_count))
		game->elements->c_x++;
	else if (key == 97 && game->map->map_pos[y][x - 1] != '1' &&
		(game->map->map_pos[y][x - 1] != 'E' || !game->elements->col_count))
		game->elements->c_x--;
	else if (key == 119 && game->map->map_pos[y - 1][x] != '1' &&
		(game->map->map_pos[y - 1][x] != 'E' || !game->elements->col_count))
		game->elements->c_y--;
	else if (key == 115 && game->map->map_pos[y + 1][x] != '1' &&
		(game->map->map_pos[y + 1][x] != 'E' || !game->elements->col_count))
		game->elements->c_y++;
	if (x != game->elements->c_x || y != game->elements->c_y)
	{
		move++;
		printf ("MOVEMENT = %i\n", move);
	}
}
