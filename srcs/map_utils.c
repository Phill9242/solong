/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:36:56 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:36:57 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_createmap(t_mainstruct game)
{
	game.map->map_null = 0;
	ft_set_imgs (game);
	ft_map_validate (game);
	ft_pos_player (game);
	ft_put_imgs (game);
}

void	ft_read_map(t_mainstruct game)
{
	int	i;

	i = -1;
	while (MAPSTR[++i])
	{
		if (!(MAPSTR[i] == '0' || MAPSTR[i] == '1' || MAPSTR[i] == 'C'
				|| MAPSTR[i] == 'E' || MAPSTR[i] == 'P' || MAPSTR[i] == '\n'))
		{
			printf ("ERROR\nInvalid Character!");
			printf ("Only 01CEO characters are accepted!\n");
			ft_exit (&game);
		}
		if (MAPSTR[i] == 'P')
			game.elements->initial_position++;
		if (MAPSTR[i] == 'E')
			game.elements->exit_count++;
		if (MAPSTR[i] == 'C')
			game.elements->collectables_count++;
	}
}

void	ft_map_validate(t_mainstruct game)
{
	ft_read_map (game);
	ft_check_map (game);
	ft_is_rectangular (game);
	ft_free (game.map->map_pos);
	game.map->map_pos = ft_split (MAPSTR, '\n');
	game.map->map_null = 1;
	if (!ft_check_if_is_surrounded_by_walls (game))
	{
		printf ("ERROR\nThe map must be surrounded_by_walls!\n");
		ft_exit (&game);
	}
}

int	ft_check_if_is_surrounded_by_walls(t_mainstruct game)
{
	int	i;

	i = 0;
	while (game.map->map_pos[0][++i])
	{
		if (game.map->map_pos[0][i] != '1' ||
		game.map->map_pos[game.map->vertical_size - 1][i] != '1')
			return (0);
	}
	i = game.map->vertical_size;
	while (--i >= 0)
	{
		if (game.map->map_pos[i][0] != '1' ||
		game.map->map_pos[i][game.map->horizontal_size - 1] != '1')
			return (0);
	}
	return (1);
}
