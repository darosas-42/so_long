/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:09:39 by drosas-n          #+#    #+#             */
/*   Updated: 2025/06/02 17:36:40 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "MLX42.h"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	char			**map;
	int				y;
	int				x;
	int				i;
	int				j;
	int				z;
	int				moves;
	int				enemy;
	t_position		player;
	t_position		exit;
	int				c_player;
	int				c_exit;
	int				c_collect;
	int				c_collect_copy;
	int				c_exit_copy;
	char			**map_copy;
	mlx_texture_t	*t_s;
	mlx_image_t		*i_s;
	mlx_texture_t	*t_m;
	mlx_image_t		*i_m;
	mlx_texture_t	*t_p1;
	mlx_image_t		*i_p1;
	mlx_texture_t	*t_pu;
	mlx_image_t		*i_pu;
	mlx_texture_t	*t_pl;
	mlx_image_t		*i_pl;
	mlx_texture_t	*t_pr;
	mlx_image_t		*i_pr;
	mlx_texture_t	*t_e2;
	mlx_image_t		*i_e2;
	mlx_texture_t	*t_e1;
	mlx_image_t		*i_e1;
	mlx_texture_t	*t_c;
	mlx_image_t		*i_c;
	mlx_texture_t	*t_n2;
	mlx_image_t		*i_n2;
	mlx_texture_t	*t_n1;
	mlx_image_t		*i_n1;
	mlx_t			*mlx;
}	t_game;

void	init_struct(t_game *game);
int		read_map(char **argv, t_game *game);
void	free_all(t_game *game);
int		check_extension(char *aber);
int		lines_and_walls(t_game *game);
int		other_walls(t_game *game);
int		things(t_game *game);
void	flood_fill(t_game *game, t_position	player, t_position size);
int		valid_way(t_game *game);
int		create_image(t_game *g);
void	init_game(t_game *g);
void	close_game(void *p);
void	keyhook(mlx_key_data_t keydata, void *p);
void	screen_counter(t_game *game);
void	move_enemy(t_game *game);
void	move_enemy2(t_game *game);
#endif