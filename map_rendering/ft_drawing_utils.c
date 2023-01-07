/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:34 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 20:29:56 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

static void	ft_check_files(t_mapdets *dets)
{
	if (!(*dets).t_data.w_img || !(*dets).t_data.b_img
		|| !(*dets).t_data.e_img || !(*dets).t_data.p_img
		|| !(*dets).t_data.p1_img || !(*dets).t_data.p2_img
		|| !(*dets).t_data.p3_img || !(*dets).t_data.c1_img)
	{
		write(1, "Error\nFiles could not be loaded.\n", 33);
		ft_close_game(&(*dets));
	}
}

void	ft_get_path(t_mapdets *dets)
{
	(*dets).t_data.w_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/wall.xpm", &(*dets).t_data.w_width,
			&(*dets).t_data.w_lenght);
	(*dets).t_data.b_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/floor.xpm", &(*dets).t_data.b_width,
			&(*dets).t_data.b_lenght);
	(*dets).t_data.c1_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/C/0001.xpm", &(*dets).t_data.c1_width,
			&(*dets).t_data.c1_lenght);
	(*dets).t_data.e_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/exit.xpm", &(*dets).t_data.e_width,
			&(*dets).t_data.e_lenght);
	(*dets).t_data.gud_img = mlx_xpm_file_to_image((*dets).t_data.mlx,
			"./textures/ghost.xpm", &(*dets).t_data.gud_width,
			&(*dets).t_data.gud_lenght);
	ft_get_animation_path(&(*dets));
	ft_check_files(&(*dets));
}

void	ft_put_image(t_mapdets *dets, int x, int y, int arr[2])
{
	if ((*dets).map[arr[0]][arr[1]] == 'P')
	{
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.b_img, x, y);
		ft_animate_player(&(*dets), x, y);
	}
	else if ((*dets).map[arr[0]][arr[1]] == 'C')
	{
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.b_img, x, y);
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.c1_img, x, y);
	}
	else if ((*dets).map[arr[0]][arr[1]] == 'E')
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.e_img, x, y);
	else if ((*dets).map[arr[0]][arr[1]] == '0')
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.b_img, x, y);
	else
		mlx_put_image_to_window((*dets).t_data.mlx,
			(*dets).t_data.win, (*dets).t_data.w_img, x, y);
}

void	ft_print_moves(t_mapdets *dets)
{
	char	*string1;
	char	*string2;
	int		i;

	i = -1;
	string1 = ft_itoa((*dets).moves);
	string2 = ft_strjoin("Current Moves : ", string1);
	free (string1);
	while (string2[++i])
		write(1, &string2[i], 1);
	write(1, "\n", 1);
	free (string2);
}

int	ft_close_game(t_mapdets *dets)
{
	if ((*dets).t_data.win)
		mlx_destroy_window((*dets).t_data.mlx, (*dets).t_data.win);
	if ((*dets).t_data.mlx)
		free ((*dets).t_data.mlx);
	exit(0);
}
