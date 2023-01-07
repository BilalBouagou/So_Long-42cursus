/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:23:04 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/01 15:12:16 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"
#include "../includes/rendering.h"

void	ft_move_enemies(t_mapdets *dets)
{
	int	i;

	i = 0;
	while (i < (*dets).cnst_n)
	{
		ft_enemy_pos_ctl(&(*dets),
			&(*dets).enemies[i][1], &(*dets).enemies[i][0]);
		i++;
	}
}
