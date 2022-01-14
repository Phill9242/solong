/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:36:56 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 12:29:08 by phiolive         ###   ########.fr       */
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
	while (game.map->str[++i])
	{
		if (!(game.map->str[i] == '0' || game.map->str[i] == '1'
				|| game.map->str[i] == 'C' || game.map->str[i] == 'E'
				|| game.map->str[i] == 'P' || game.map->str[i] == '\n'))
		{
			printf ("ERROR\nInvalid Character!");
			printf ("Only 01CEO characters are accepted!\n");
			ft_exit (&game);
		}
		if (game.map->str[i] == 'P')
			game.elements->initial_position++;
		if (game.map->str[i] == 'E')
			game.elements->exit_count++;
		if (game.map->str[i] == 'C')
			game.elements->col_count++;
	}
}

void	ft_map_validate(t_mainstruct game)
{
	ft_read_map (game);
	ft_check_map (game);
	ft_is_rectangular (game);
	ft_free (game.map->map_pos);
	game.map->map_pos = ft_split (game.map->str, '\n');
	game.map->map_null = 1;
	if (!ft_check_if_is_surrounded_by_walls (game)
		|| game.map->str[0] != '1')
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
