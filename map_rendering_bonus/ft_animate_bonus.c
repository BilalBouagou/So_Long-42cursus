/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:24:39 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 16:51:30 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/rendering.h"

void	ft_animate_player(t_mapdets *dets, int x, int y)
{
	if ((*dets).i == 0)
	{
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.b_img, (*dets).x, (*dets).y);
		ft_put_player(&(*dets), x, y, 0);
	}
	else if ((*dets).i == 1)
	{
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.b_img, (*dets).x, (*dets).y);
		ft_put_player(&(*dets), x, y, 1);
	}
	else if ((*dets).i == 3)
	{
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.b_img, (*dets).x, (*dets).y);
		ft_put_player(&(*dets), x, y, 2);
	}
	else if ((*dets).i == 2)
	{
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.b_img, (*dets).x, (*dets).y);
		ft_put_player(&(*dets), x, y, 3);
	}
}

void	ft_put_player(t_mapdets *dets, int x, int y, int flag)
{
	if (flag == 0)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.p_img, x + 10, y);
	else if (flag == 1)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.p1_img, x + 10, y);
	else if (flag == 2)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.p2_img, x + 10, y);
	else if (flag == 3)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.p3_img, x + 10, y);
}

void	ft_animate_collectible(t_mapdets *dets, int x, int y)
{
	if ((*dets).j == 0)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.c1_img, x, y);
	else if ((*dets).j == 5)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.c2_img, x, y);
	else if ((*dets).j == 10)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.c3_img, x, y);
	else if ((*dets).j == 15)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.c4_img, x, y);
	else if ((*dets).j == 20)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.c5_img, x, y);
	else if ((*dets).j == 25)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.c6_img, x, y);
	else if ((*dets).j == 30)
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.c7_img, x, y);
	else if ((*dets).j > 30)
		(*dets).j = -1;
}

void	ft_place_enemies(t_mapdets *dets, int x, int y)
{
	mlx_put_image_to_window((*dets).t_data.mlx,
		(*dets).t_data.win, (*dets).t_data.b_img, x, y);
	mlx_put_image_to_window((*dets).t_data.mlx,
		(*dets).t_data.win, (*dets).t_data.gud_img, x, y);
}
