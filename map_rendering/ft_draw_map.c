/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:06:13 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 20:28:27 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"
#include "../includes/map_checking.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_draw_components(t_mapdets *dets)
{
	int	x;
	int	y;
	int	arr[2];

	y = 0;
	arr[0] = 0;
	while (y < (*dets).width * 40)
	{
		x = 0;
		arr[1] = 0;
		while (x < (*dets).lenght * 40)
		{
			ft_put_image(&(*dets), x, y, arr);
			x += 40;
			arr[1]++;
		}
		y += 40;
		arr[0]++;
	}
	return (0);
}

static int	ft_render_next_frame(t_mapdets *dets)
{
	ft_draw_components(&(*dets));
	return (0);
}

static int	key_hook(int key_code, t_mapdets *dets)
{
	(*dets).x = (*dets).playercoords[1] * 40;
	(*dets).y = (*dets).playercoords[0] * 40;
	if (key_code == 13 && !ft_collision(&(*dets), (*dets).playercoords[0] - 1,
			(*dets).playercoords[1]))
		ft_move_player(&(*dets), 0, 1);
	if (key_code == 1 && !ft_collision(&(*dets), (*dets).playercoords[0] + 1,
			(*dets).playercoords[1]))
		ft_move_player(&(*dets), 0, -1);
	if (key_code == 0 && !ft_collision(&(*dets), (*dets).playercoords[0],
			(*dets).playercoords[1] - 1))
		ft_move_player(&(*dets), 1, 1);
	if (key_code == 2 && !ft_collision(&(*dets), (*dets).playercoords[0],
			(*dets).playercoords[1] + 1))
		ft_move_player(&(*dets), 1, -1);
	if (key_code == 53)
		ft_close_game(&(*dets));
	ft_print_moves(&(*dets));
	return (0);
}

static void	ft_place_window(t_mapdets *dets)
{
	(*dets).t_data.mlx = mlx_init();
	if (!(*dets).t_data.mlx)
	{
		write(1, "Error\nmlx couldn't be initialised.\n", 35);
		exit(-1);
	}
	(*dets).t_data.win = mlx_new_window((*dets).t_data.mlx, (*dets).lenght * 40,
			(*dets).width * 40, "so_long");
	if (!(*dets).t_data.win)
	{
		write(1, "Error\nWindow couldn't be created.\n", 34);
		exit(-1);
	}
}

void	ft_draw_map(t_mapdets *dets)
{
	ft_place_window(&(*dets));
	ft_get_path(&(*dets));
	mlx_hook((*dets).t_data.win, 17, 0, ft_close_game, &(*dets));
	mlx_key_hook((*dets).t_data.win, key_hook, &(*dets));
	mlx_loop_hook((*dets).t_data.mlx, ft_render_next_frame, &(*dets));
	mlx_loop((*dets).t_data.mlx);
}
