#include "so_long.h"

void	ft_pos_player(t_mainstruct game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game.map->vertical_size)
	{
		if (game.map->horizontal_size == x)
		{
			y++;
			x = 0;
		}
		else if (game.map->map_pos[y][x] == 'P')
		{
			game.elements->pos_char_x = x;
			game.elements->pos_char_y = y;
			return ;
		}
		x++;
	}
}

void	ft_check_map(t_mainstruct game)
{
	if (game.elements->collectables_count < 1
		|| game.elements->initial_position != 1
		|| game.elements->exit_count != 1)
	{
		printf ("ERROR\nYou need to follow this stricted rules:\n");
		printf("Your Map must have at least one collectable (C) \n");
		printf("Your Map must have ONE initial position (P) and one exit (E)\n");
		ft_exit (&game);
	}
	return ;
}

void	ft_is_rectangular (t_mainstruct game)
{
	int check_colluns;
	int i;

	check_colluns = 0;
	i = 0;
	while (game.map->map_str[i])
	{
		while (game.map->map_str[i] != '\n')
		{
			check_colluns++;
			i++;
		}
		if (!game.map->horizontal_size)
		{
			game.map->horizontal_size = i;
		}
		else if (game.map->horizontal_size != check_colluns)
		{
			printf ("ERROR\nThe map MUST be rectancular\n");
			ft_exit (&game);
		}
		i++;
		game.map->vertical_size++;
		check_colluns = 0;
	}
}

void	ft_map_str(t_mainstruct game, char *map)
{
	char	*map_str;
	int		read_size;
	int		fd;

	fd = open(map, O_RDONLY);
	map_str = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	read_size = read (fd, map_str, BUFFER_SIZE);
	while (read_size > 0)
	{
		map_str = ft_cpy_and_increase (map_str);
		read_size = read (fd, &map_str[ft_strlen(map_str)], BUFFER_SIZE);
	}
	MAPSTR = map_str;
	ft_window_size (game);
}

void ft_window_size (t_mainstruct game)
{
	int	i;

	i = 0;
	while (MAPSTR[++i])
	{
		if (MAPSTR[i] == '\n')
			MAP_Y++;
	}
 	i = 0;
	while (MAPSTR[i] && MAPSTR[i] == '1')
	{
		MAP_X++;
		i++;
	}
}
