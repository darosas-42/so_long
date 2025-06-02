/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:08:56 by drosas-n          #+#    #+#             */
/*   Updated: 2025/06/02 17:59:26 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_all(t_game *game)
{
	game->i = 0;
	if (game->map != NULL)
	{
		while (game->map[game->i] != NULL)
			free(game->map[game->i++]);
		free(game->map);
	}
	game->i = 0;
	if (game->map_copy != NULL)
	{
		while (game->map_copy[game->i] != NULL)
			free(game->map_copy[game->i++]);
		free(game->map_copy);
	}
	free(game);
}

void	flood_fill(t_game *game, t_position	player, t_position size)
{
	if (player.x >= size.x || player.y >= size.y || player.x < 0
		|| player.y < 0 || game->map_copy[player.y][player.x] == '1'
		|| game->map_copy[player.y][player.x] == '@'
		|| game->map_copy[player.y][player.x] == 'N')
		return ;
	if (game->map_copy[player.y][player.x] == 'C')
		game->c_collect_copy++;
	if (game->map_copy[player.y][player.x] == 'E')
	{
		game->c_exit_copy++;
		game->exit.x = player.x;
		game->exit.y = player.y;
	}
	game->map_copy[player.y][player.x] = '@';
	flood_fill(game, (t_position){player.x + 1, player.y}, size);
	flood_fill(game, (t_position){player.x - 1, player.y}, size);
	flood_fill(game, (t_position){player.x, player.y + 1}, size);
	flood_fill(game, (t_position){player.x, player.y - 1}, size);
}

int	valid_way(t_game *game)
{
	flood_fill(game, game->player, (t_position){game->x, game->y});
	if (game->c_collect_copy != game->c_collect
		|| game->c_exit != game->c_exit_copy)
		return (ft_printf("Error\nInvalid way\n"), EXIT_FAILURE);
	game->c_collect = 0;
	return (EXIT_SUCCESS);
}

void	close_game(void *p)
{
	t_game	*g;

	g = p;
	mlx_close_window(g->mlx);
}
