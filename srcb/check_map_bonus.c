/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:08:32 by drosas-n          #+#    #+#             */
/*   Updated: 2025/06/02 17:59:11 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_extension(char *aber)
{
	int	i;

	i = ft_strlen(aber);
	if (aber[i - 1] == 'r' && aber[i - 2] == 'e'
		&& aber[i - 3] == 'b' && aber[i - 4] == '.')
		return (EXIT_SUCCESS);
	else
		return (ft_printf("Error\nInvalid extension.\n"), EXIT_FAILURE);
}

int	lines_and_walls(t_game *game)
{
	game->i = 0;
	game->j = ft_strlen(game->map[game->i]);
	while (game->map[game->i])
	{
		if (ft_strlen(game->map[game->i]) != (size_t)game->j)
			return (ft_printf("Error\nSize failure.\n"), EXIT_FAILURE);
		game->i++;
	}
	game->j = 0;
	while (game->map[game->j] != NULL)
	{
		game->i = 0;
		while (game->map[game->j][game->i])
		{
			if (game->map[0][game->i] != '1'
				|| game->map[game->y - 1][game->i] != '1')
			{
				return (ft_printf("Error\nWalls failure.\n"), EXIT_FAILURE);
			}
			game->i++;
		}
		game->j++;
	}
	return (EXIT_SUCCESS);
}

int	other_walls(t_game *game)
{
	game->i = 1;
	while (game->map[game->i] && game->i < game->y - 1)
	{
		if (game->map[game->i][0] != '1'
			|| game->map[game->i][game->x - 1] != '1')
		{
			return (ft_printf("Error\nWalls failure.\n"), EXIT_FAILURE);
		}
		game->i++;
	}
	return (EXIT_SUCCESS);
}

int	things(t_game *game)
{
	game->i = -1;
	while (game->map[++game->i])
	{
		game->j = -1;
		while (game->map[game->i][++game->j])
		{
			if (game->map[game->i][game->j] == 'P')
			{
				game->player.y = game->i;
				game->player.x = game->j;
				game->c_player++;
			}
			if (game->map[game->i][game->j] == 'E')
			{
				game->exit.y = game->i;
				game->exit.x = game->j;
				game->c_exit++;
			}
			if (game->map[game->i][game->j] == 'C')
				game->c_collect++;
		}
	}
	if (game->c_player != 1 || game->c_exit != 1 || game->c_collect < 1)
		return (ft_printf("Error\nInvalid elements.\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
