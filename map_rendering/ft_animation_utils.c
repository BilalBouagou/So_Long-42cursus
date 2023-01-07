/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:29:51 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 20:28:03 by bbouagou         ###   ########.fr       */
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

void	ft_get_animation_path(t_mapdets *dets)
{
	ft_get_player_animation_path(&(*dets));
}
