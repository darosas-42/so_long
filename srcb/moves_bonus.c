/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:09:10 by drosas-n          #+#    #+#             */
/*   Updated: 2024/08/28 17:09:11 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_to_collect(t_game *g, int x, int y, mlx_image_t *lime)
{
	mlx_image_to_window(g->mlx, g->i_s, g->player.x * 50, g->player.y * 50);
	if (g->map[g->player.y][g->player.x] == 'E')
		mlx_image_to_window(g->mlx, g->i_e1, g->player.x * 50,
			g->player.y * 50);
	g->player.x = x;
	g->player.y = y;
	g->map[g->player.y][g->player.x] = '0';
	mlx_image_to_window(g->mlx, g->i_s, g->player.x * 50, g->player.y * 50);
	mlx_image_to_window(g->mlx, lime, g->player.x * 50, g->player.y * 50);
	g->c_collect++;
	g->moves++;
	if (g->c_collect == g->c_collect_copy)
		mlx_image_to_window(g->mlx, g->i_e2, g->exit.x * 50,
			g->exit.y * 50);
	screen_counter(g);
}

static void	move_to_exit(t_game *g, int x, int y, mlx_image_t *lime)
{
	mlx_image_to_window(g->mlx, g->i_s, g->player.x * 50, g->player.y * 50);
	g->player.x = x;
	g->player.y = y;
	mlx_image_to_window(g->mlx, g->i_s, g->player.x * 50, g->player.y * 50);
	mlx_image_to_window(g->mlx, g->i_e1, g->player.x * 50, g->player.y * 50);
	mlx_image_to_window(g->mlx, lime, g->player.x * 50, g->player.y * 50);
	g->moves++;
	screen_counter(g);
}

static void	move_to_other(t_game *g, int x, int y, mlx_image_t *lime)
{
	mlx_image_to_window(g->mlx, g->i_s, g->player.x * 50, g->player.y * 50);
	if (g->map[g->player.y][g->player.x] == 'E')
		mlx_image_to_window(g->mlx, g->i_e1, g->player.x * 50,
			g->player.y * 50);
	g->player.x = x;
	g->player.y = y;
	mlx_image_to_window(g->mlx, lime, g->player.x * 50, g->player.y * 50);
	g->moves++;
	screen_counter(g);
}

void	moves(t_game *g, int x, int y, mlx_image_t *lime)
{
	if (g->map[y][x] == 'N')
		close_game(g);
	else if (g->map[y][x] == 'C')
		move_to_collect(g, x, y, lime);
	else if (g->map[y][x] == 'E' && g->c_collect == g->c_collect_copy)
		close_game(g);
	else if (g->map[y][x] == 'E')
		move_to_exit(g, x, y, lime);
	else if (g->map[y][x] != '1')
		move_to_other(g, x, y, lime);
	if (g->map[y][x] != '1')
	{
		if (g->enemy == 0)
			move_enemy2(g);
		else
			move_enemy(g);
	}
}

void	keyhook(mlx_key_data_t keydata, void *p)
{
	t_game	*g;

	g = (t_game *)p;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		moves(g, g->player.x, g->player.y - 1, g->i_pu);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		moves(g, g->player.x - 1, g->player.y, g->i_pl);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		moves(g, g->player.x, g->player.y + 1, g->i_p1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		moves(g, g->player.x + 1, g->player.y, g->i_pr);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(g);
}
