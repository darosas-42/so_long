/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:09:17 by drosas-n          #+#    #+#             */
/*   Updated: 2024/08/28 17:09:18 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	create_image2(t_game *g)
{
	if (!g->t_s || !g->t_m || !g->t_p1 || !g->t_pu
		|| !g->t_pl || !g->t_pr || !g->t_c
		|| !g->t_e1 || !g->t_e2 || !g->i_s || !g->i_m || !g->i_p1
		|| !g->i_pu || !g->i_pl || !g->i_pr || !g->i_c || !g->i_e1 || !g->i_e2
		|| !g->i_n1 || !g->i_n2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	clean_textures(t_game *g)
{
	mlx_delete_texture(g->t_s);
	mlx_delete_texture(g->t_m);
	mlx_delete_texture(g->t_p1);
	mlx_delete_texture(g->t_pu);
	mlx_delete_texture(g->t_pl);
	mlx_delete_texture(g->t_pr);
	mlx_delete_texture(g->t_c);
	mlx_delete_texture(g->t_e1);
	mlx_delete_texture(g->t_e2);
	mlx_delete_texture(g->t_n1);
	mlx_delete_texture(g->t_n2);
}

int	create_image(t_game *g)
{
	g->t_s = mlx_load_png("./sprites/s.png");
	g->t_m = mlx_load_png("./sprites/m.png");
	g->t_p1 = mlx_load_png("./sprites/p1.png");
	g->t_pu = mlx_load_png("./sprites/pu.png");
	g->t_pl = mlx_load_png("./sprites/pl.png");
	g->t_pr = mlx_load_png("./sprites/pr.png");
	g->t_c = mlx_load_png("./sprites/c.png");
	g->t_e1 = mlx_load_png("./sprites/e1.png");
	g->t_e2 = mlx_load_png("./sprites/e2.png");
	g->t_n1 = mlx_load_png("./sprites/n1.png");
	g->t_n2 = mlx_load_png("./sprites/n2.png");
	g->i_s = mlx_texture_to_image(g->mlx, g->t_s);
	g->i_m = mlx_texture_to_image(g->mlx, g->t_m);
	g->i_p1 = mlx_texture_to_image(g->mlx, g->t_p1);
	g->i_pu = mlx_texture_to_image(g->mlx, g->t_pu);
	g->i_pl = mlx_texture_to_image(g->mlx, g->t_pl);
	g->i_pr = mlx_texture_to_image(g->mlx, g->t_pr);
	g->i_c = mlx_texture_to_image(g->mlx, g->t_c);
	g->i_e1 = mlx_texture_to_image(g->mlx, g->t_e1);
	g->i_e2 = mlx_texture_to_image(g->mlx, g->t_e2);
	g->i_n1 = mlx_texture_to_image(g->mlx, g->t_n1);
	g->i_n2 = mlx_texture_to_image(g->mlx, g->t_n2);
	if (create_image2(g) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (clean_textures(g), EXIT_SUCCESS);
}

void	init_game(t_game *g)
{
	while (g->map[++g->z])
	{
		g->i = -1;
		while (g->map[g->z][++g->i])
		{
			if (g->map[g->z][g->i] == 'P' || g->map[g->z][g->i] == 'C'
				|| g->map[g->z][g->i] == 'E' || g->map[g->z][g->i] == 'N')
				mlx_image_to_window(g->mlx, g->i_s, g->i * 50, g->z * 50);
			if (g->map[g->z][g->i] == '1')
				mlx_image_to_window(g->mlx, g->i_m, g->i * 50, g->z * 50);
			if (g->map[g->z][g->i] == '0')
				mlx_image_to_window(g->mlx, g->i_s, g->i * 50, g->z * 50);
			if (g->map[g->z][g->i] == 'P')
				mlx_image_to_window(g->mlx, g->i_p1, g->i * 50, g->z * 50);
			if (g->map[g->z][g->i] == 'C')
				mlx_image_to_window(g->mlx, g->i_c, g->i * 50, g->z * 50);
			if (g->map[g->z][g->i] == 'E')
				mlx_image_to_window(g->mlx, g->i_e1, g->i * 50, g->z * 50);
			if (g->map[g->z][g->i] == 'N')
				mlx_image_to_window(g->mlx, g->i_n1, g->i * 50, g->z * 50);
		}
	}
}
