/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:10:43 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 20:24:16 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "map_checking.h"
# include <math.h>
# include <mlx.h>

/*
** Map drawing functions.
*/

void	ft_draw_map(t_mapdets *dets);
void	ft_get_path(t_mapdets *dets);
void	ft_move_player(t_mapdets *dets, int pos, int sign);
void	ft_put_image(t_mapdets *dets, int x, int y, int arr[2]);
int		ft_collision(t_mapdets *dets, int x, int y);
int		ft_close_game(t_mapdets *dets);

/*
** Animation funcitons.
*/

void	ft_get_animation_path(t_mapdets *dets);
void	ft_animate_player(t_mapdets *dets, int x, int y);
void	ft_animate_collectible(t_mapdets *dets, int x, int y);
void	ft_put_player(t_mapdets *dets, int x, int y, int flag);

/*
** Enemies handling functions.
*/

void	ft_inject_enemies(t_mapdets *dets);
void	ft_move_enemies(t_mapdets *dets);
void	ft_enemy_pos_ctl(t_mapdets *dets, int *x, int *y);
void	ft_place_enemies(t_mapdets *dets, int x, int y);

/*
** Printing moves.
*/

void	ft_put_moves(t_mapdets *dets, int flag);
void	ft_print_moves(t_mapdets *dets);

#endif