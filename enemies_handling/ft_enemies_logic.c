/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:32:01 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 16:01:04 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"
#include "../includes/map_checking.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
** best simple thing i can do here is to make the enemies pick a random direction
** and move in that direction until they encounter some sort of an obstacle
** (wall or collectilbe). if they encounter an obstacle, they choose another
** direction to walk towards it besides the direction that's being blocked.
**
** idk about enemies detecting the player, tons of work with little to no
** reward, but the idea YOU have in mind is that you check if the enemy
** and the player have a common coordinate, if so then you check the axis
** of that coordinate between the enemy and the player, if no obstacle
** was encountered, the enemy detects the player and starts moving towards
** him, else there was no detection and the enemy keeps on marching.
*/

/*
** 1 is up
** 2 is down
** 3 is left
** 4 is right
*/

static int	ft_enemies_logic(void)
{
	int	direction;

	direction = (rand() % (4 - 1 + 1) + 1);
	return (direction);
}

static int	ft_check_enemy_pos(t_mapdets *dets, int x, int y)
{
	if ((*dets).map[y][x] == 'P')
	{
		write(1, "You have died (istg)\n", 21);
		exit(1);
	}
	else if ((*dets).map[y][x] == '0')
		return (1);
	else
		return (0);
}

static void	ft_update_enemy_coords(t_mapdets *dets, int *x, int *y, int flag)
{
	if (flag == 1)
	{
		(*dets).map[*y - 1][*x] = 'M';
		(*dets).map[*y][*x] = '0';
		*y = *y - 1;
	}
	else if (flag == 2)
	{
		(*dets).map[*y + 1][*x] = 'M';
		(*dets).map[*y][*x] = '0';
		*y = *y + 1;
	}
	else if (flag == 3)
	{
		(*dets).map[*y][*x - 1] = 'M';
		(*dets).map[*y][*x] = '0';
		*x = *x - 1;
	}
	else if (flag == 4)
	{
		(*dets).map[*y][*x + 1] = 'M';
		(*dets).map[*y][*x] = '0';
		*x = *x + 1;
	}
}

static int	ft_change_enemy_pos(t_mapdets *dets, int *x, int *y)
{
	if ((*dets).g == 1)
	{
		if (ft_check_enemy_pos(&(*dets), *x, *y - 1))
			ft_update_enemy_coords(&(*dets), &(*x), &(*y), 1);
		return (1);
	}
	else if ((*dets).g == 2)
	{
		if (ft_check_enemy_pos(&(*dets), *x, *y + 1))
			ft_update_enemy_coords(&(*dets), &(*x), &(*y), 2);
		return (1);
	}
	else if ((*dets).g == 3)
	{
		if (ft_check_enemy_pos(&(*dets), *x - 1, *y))
			ft_update_enemy_coords(&(*dets), &(*x), &(*y), 3);
		return (1);
	}
	else if ((*dets).g == 4)
	{
		if (ft_check_enemy_pos(&(*dets), *x + 1, *y))
			ft_update_enemy_coords(&(*dets), &(*x), &(*y), 4);
		return (1);
	}
	return (0);
}

void	ft_enemy_pos_ctl(t_mapdets *dets, int *x, int *y)
{
	(*dets).g = ft_enemies_logic();
	while (!ft_change_enemy_pos(&(*dets), &(*x), &(*y)))
	{
		(*dets).g = ft_enemies_logic();
		if (ft_change_enemy_pos(&(*dets), &(*x), &(*y)))
			break ;
	}
}
