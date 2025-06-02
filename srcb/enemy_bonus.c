/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:08:48 by drosas-n          #+#    #+#             */
/*   Updated: 2025/06/02 17:46:55 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	screen_counter(t_game *game)
{
	char	*screen;

	screen = ft_itoa(game->moves);
	mlx_image_to_window(game->mlx, game->i_m, 0, 0);
	mlx_put_string(game->mlx, screen, 15, 15);
	free(screen);
}

void	move_enemy2(t_game *game)
{
	game->i = 0;
	while (game->map[game->i])
	{
		game->z = 0;
		while (game->map[game->i][game->z])
		{
			if (game->map[game->i][game->z] == 'N')
			{
				mlx_image_to_window(game->mlx, game->i_s,
					game->z * 50, game->i * 50);
				mlx_image_to_window(game->mlx, game->i_n2,
					game->z * 50, game->i * 50);
			}
			game->z++;
		}
		game->i++;
	}
	game->enemy = 1;
}

void	move_enemy(t_game *game)
{
	game->i = 0;
	while (game->map[game->i])
	{
		game->z = 0;
		while (game->map[game->i][game->z])
		{
			if (game->map[game->i][game->z] == 'N')
			{
				mlx_image_to_window(game->mlx, game->i_s,
					game->z * 50, game->i * 50);
				mlx_image_to_window(game->mlx, game->i_n1,
					game->z * 50, game->i * 50);
			}
			game->z++;
		}
		game->i++;
	}
	game->enemy = 0;
}
