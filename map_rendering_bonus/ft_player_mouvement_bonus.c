/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_mouvement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:37:55 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 19:23:52 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

static void	ft_animation_ctl(int pos, int flag, t_mapdets *dets)
{
	if (pos == 0 && flag == 1)
		(*dets).i = 1;
	else if (pos == 0 && flag == -1)
		(*dets).i = 0;
	else if (pos == 1 && flag == 1)
		(*dets).i = 2;
	else if (pos == 1 && flag == -1)
		(*dets).i = 3;
}

void	ft_move_player(t_mapdets *dets, int pos, int sign)
{
	ft_animation_ctl(pos, sign, &(*dets));
	if (pos == 0)
	{
		if ((*dets).map[(*dets).playercoords[0] - (1 * sign)]
			[(*dets).playercoords[1]] == 'C')
			(*dets).n--;
		(*dets).map[(*dets).playercoords[0] - (1 * sign)]
		[(*dets).playercoords[1]] = 'P';
		(*dets).map[(*dets).playercoords[0]][(*dets).playercoords[1]] = '0';
		(*dets).playercoords[0] = (*dets).playercoords[0] - (1 * sign);
	}
	else if (pos == 1)
	{
		if ((*dets).map[(*dets).playercoords[0]]
			[(*dets).playercoords[1] - (1 * sign)] == 'C')
			(*dets).n--;
		(*dets).map[(*dets).playercoords[0]]
		[(*dets).playercoords[1] - (1 * sign)] = 'P';
		(*dets).map[(*dets).playercoords[0]][(*dets).playercoords[1]] = '0';
		(*dets).playercoords[1] = (*dets).playercoords[1] - (1 * sign);
	}
	(*dets).moves++;
}

int	ft_collision(t_mapdets *dets, int x, int y)
{
	if (((*dets).map[x][y] == 'E' && (*dets).n == 0))
	{
		write(1, "Game won, ez dub..huh?\n", 23);
		exit(0);
	}
	else if (((*dets).map[x][y] == 'E' && (*dets).n > 0))
		write(1, "You have to collect all the \
collectibles before exiting the map.\n", 65);
	else if ((*dets).map[x][y] == 'M')
	{
		write(1, "You have died (istg)\n", 21);
		exit(0);
	}
	if ((*dets).map[x][y] == '1' || ((*dets).map[x][y] == 'E' && (*dets).n > 0))
		return (1);
	return (0);
}
