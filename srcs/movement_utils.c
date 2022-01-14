#include "so_long.h"

int	ft_movement_utils(int key, void *pointer)
{
	t_mainstruct	*game;

	game = pointer;
	mlx_put_image_to_window(game->mlx, game->window, game->imgs->floor,
		PPOS_X * TILE, PPOS_Y * TILE);
	ft_key_press (key, game);
	if (MAP[PPOS_Y][PPOS_X] == 'C')
	{
		MAP[PPOS_Y][PPOS_X] = '0';
		game->elements->collectables_count--;
	}
	if (MAP[PPOS_Y][PPOS_X] == 'E')
	{
		printf ("\n\nCONGRATULATIONS!\nYou Finished the game!\n\n");
		ft_exit(game);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->imgs->character,
		PPOS_X * TILE, PPOS_Y * TILE);
	return (0);
}

void	ft_key_press(int key, t_mainstruct *game)
{
	int			y;
	int			x;
	static int	move = 0;

	x = PPOS_X;
	y = PPOS_Y;
	if (key == 65307)
		ft_exit((t_mainstruct *) game);
	if (key == 100 && MAP[PPOS_Y][PPOS_X + 1] != '1' &&
		(MAP[PPOS_Y][PPOS_X + 1] != 'E' || !game->elements->collectables_count))
		PPOS_X++;
	else if (key == 97 && MAP[PPOS_Y][PPOS_X - 1] != '1' &&
		(MAP[PPOS_Y][PPOS_X - 1] != 'E' || !game->elements->collectables_count))
		PPOS_X--;
	else if (key == 119 && MAP[PPOS_Y - 1][PPOS_X] != '1' &&
		(MAP[PPOS_Y - 1][PPOS_X] != 'E' || !game->elements->collectables_count))
		PPOS_Y--;
	else if (key == 115 && MAP[PPOS_Y + 1][PPOS_X] != '1' &&
		(MAP[PPOS_Y + 1][PPOS_X] != 'E' || !game->elements->collectables_count))
		PPOS_Y++;
	if (x != PPOS_X || y != PPOS_Y)
	{
		move++;
		printf ("MOVEMENT = %i\n", move);
	}
}
