/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:29:51 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 16:51:20 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

static void	ft_get_player_animation_path(t_mapdets *dets)
{
	(*dets).t_data.p_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/down.xpm", &(*dets).t_data.p_width,
			&(*dets).t_data.p_lenght);
	(*dets).t_data.p1_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/up.xpm", &(*dets).t_data.p1_width,
			&(*dets).t_data.p1_lenght);
	(*dets).t_data.p2_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/right.xpm", &(*dets).t_data.p2_width,
			&(*dets).t_data.p2_lenght);
	(*dets).t_data.p3_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/left.xpm", &(*dets).t_data.p3_width,
			&(*dets).t_data.p3_lenght);
}

static void	ft_get_collectible_animation_path(t_mapdets *dets)
{
	(*dets).t_data.c2_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/C/0002.xpm", &(*dets).t_data.c2_width,
			&(*dets).t_data.c2_lenght);
	(*dets).t_data.c3_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/C/0003.xpm", &(*dets).t_data.c3_width,
			&(*dets).t_data.c3_lenght);
	(*dets).t_data.c4_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/C/0004.xpm", &(*dets).t_data.c4_width,
			&(*dets).t_data.c4_lenght);
	(*dets).t_data.c5_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/C/0005.xpm", &(*dets).t_data.c5_width,
			&(*dets).t_data.c5_lenght);
	(*dets).t_data.c6_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/C/0006.xpm", &(*dets).t_data.c6_width,
			&(*dets).t_data.c6_lenght);
	(*dets).t_data.c7_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/C/0007.xpm", &(*dets).t_data.c7_width,
			&(*dets).t_data.c7_lenght);
}

void	ft_get_animation_path(t_mapdets *dets)
{
	ft_get_player_animation_path(&(*dets));
	ft_get_collectible_animation_path(&(*dets));
}
