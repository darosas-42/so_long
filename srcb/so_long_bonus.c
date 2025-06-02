/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:09:28 by drosas-n          #+#    #+#             */
/*   Updated: 2025/06/02 18:00:24 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* void	ft_leaks(void)
{
	system("leaks -q so_long");
} */
/* atexit(ft_leaks); */

static int	check_map(t_game *game, char **argv)
{
	if (check_extension(argv[1]) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (read_map(argv, game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (lines_and_walls(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (other_walls(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (things(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (valid_way(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	if (argc != 2)
		return (ft_printf("Error\nEnter map\n"), EXIT_FAILURE);
	init_struct(game);
	if (check_map(game, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->mlx = mlx_init(game->x * 50, game->y * 50, "Escape", false);
	if (create_image(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	init_game(game);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_close_hook(game->mlx, &close_game, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free_all(game), EXIT_SUCCESS);
}
