/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:05:25 by phiolive          #+#    #+#             */
/*   Updated: 2022/01/14 14:06:47 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mainstruct	game;

	if (argc != 2)
	{
		printf ("Error\nExactly 2 arguments are expected!\n");
		exit (0);
	}
	game.imgs = ft_calloc(1, sizeof (t_imgs));
	game.map = ft_calloc(1, sizeof (t_map));
	game.elements = ft_calloc(1, sizeof (t_map_elements));
	game.mlx = mlx_init();
	ft_map_str(game, argv[1]);
	game.window = mlx_new_window(game.mlx, game.map->horizontal_size * TILE,
			game.map->vertical_size * TILE, "Repair Your Boat");
	game.map->vertical_size = 0;
	game.map->horizontal_size = 0;
	ft_createmap(game);
	mlx_key_hook (game.window, *ft_movement_utils, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, ft_exit, &game);
	mlx_loop_hook(game.mlx, &ft_reload, &game);
	mlx_loop(game.mlx);
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

int	ft_exit(t_mainstruct *game)
{
	mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
	ft_free_image (*game);
	if (game->map->map_null)
		ft_free_map (game);
	ft_free ((void *)game->imgs);
	if (game->map->str)
		ft_free ((void *)game->map->str);
	ft_free ((void *)game->map);
	ft_free ((void *)game->elements);
	ft_free ((void *)game->window);
	mlx_destroy_display(game->mlx);
	ft_free ((void *)game->mlx);
	exit (0);
}

void	ft_free_image(t_mainstruct game)
{
	if (game.imgs->floor != NULL)
		mlx_destroy_image(game.mlx, game.imgs->floor);
	if (game.imgs->tree != NULL)
		mlx_destroy_image(game.mlx, game.imgs->tree);
	if (game.imgs->col != NULL)
		mlx_destroy_image(game.mlx, game.imgs->col);
	if (game.imgs->character != NULL)
		mlx_destroy_image(game.mlx, game.imgs->character);
	if (game.imgs->exit_map != NULL)
		mlx_destroy_image(game.mlx, game.imgs->exit_map);
	return ;
}

void	ft_free_map(t_mainstruct *game)
{
	int	i;

	i = 0;
	while (i <= game->map->vertical_size)
	{
		ft_free(game->map->map_pos[i]);
		i++;
	}
	ft_free (game->map->map_pos);
	return ;
}
