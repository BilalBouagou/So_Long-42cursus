/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inject_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:44:19 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 16:00:23 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"
#include "../includes/map_checking.h"

static	void	ft_insert2(int *x, int *y, int a, int b)
{
	*y = a;
	*x = b;
}

static void	ft_inject(t_mapdets *dets, int y, int x, int **coords)
{
	if ((*dets).map[y - 1][x] == '0')
	{
		(*dets).map[y - 1][x] = 'M';
		ft_insert2(&(*coords)[1], &(*coords)[0], y - 1, x);
	}
	else if ((*dets).map[y + 1][x] == '0')
	{
		(*dets).map[y + 1][x] = 'M';
		ft_insert2(&(*coords)[1], &(*coords)[0], y + 1, x);
	}
	else if ((*dets).map[y][x - 1] == '0')
	{
		(*dets).map[y][x - 1] = 'M';
		ft_insert2(&(*coords)[1], &(*coords)[0], y, x - 1);
	}
	else if ((*dets).map[y][x + 1] == '0')
	{
		(*dets).map[y][x + 1] = 'M';
		ft_insert2(&(*coords)[1], &(*coords)[0], y, x + 1);
	}
}

/*
** screw it, spawn an enemy besides each collectible/exit,
** that way the map wont be flooded with enemies
** and it would be challenging a little.
*/

void	ft_inject_enemies(t_mapdets *dets)
{
	int	j;

	j = 0;
	(*dets).enemies = (int **)malloc((*dets).cnst_n * sizeof(int *));
	while (j < (*dets).cnst_n)
	{
		(*dets).enemies[j] = (int *)malloc(2 * sizeof(int));
		ft_inject(&(*dets), (*dets).c[j][0],
			(*dets).c[j][1], &(*dets).enemies[j]);
		j++;
	}
}
