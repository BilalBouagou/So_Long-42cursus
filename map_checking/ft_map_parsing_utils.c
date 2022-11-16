/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:47:13 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/16 02:15:45 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"

/*
** struct initiator function
*/

void	ft_init_struct(t_mapdets *dets)
{
	(*dets).width = 0;
	(*dets).lenght = 0;
	(*dets).playercoords[0] = 0;
	(*dets).playercoords[1] = 0;
	(*dets).exitcoords[0] = 0;
	(*dets).exitcoords[1] = 0;
	(*dets).c = NULL;
	(*dets).n = 0;
}

/*
** re-allocating the old dets.c element
*/

int	**allocate(int **new_coords, t_mapdets dets)
{
	int	i;

	i = -1;
	new_coords = (int **)malloc(dets.n * sizeof(int *));
	if (!new_coords)
		return (NULL);
	while (++i < dets.n)
	{
		new_coords[i] = (int *)malloc(2);
		if (!new_coords[i])
		{
			while (--i > 0)
				free (new_coords[i]);
			free (new_coords);
			return (NULL);
		}
	}
	return (new_coords);
}

/*
** storing the new coords of the collectible.
*/

int	**ft_update_coords(t_mapdets dets, int x, int y, int collectsnum)
{
	int	**new_coords;
	int	i;

	i = -1;
	new_coords = allocate(new_coords, dets);
	if (!new_coords)
		return (NULL);
	while (++i < dets.n - 1)
	{
		new_coords[i][0] = dets.c[i][0];
		new_coords[i][1] = dets.c[i][1];
	}
	new_coords[i][0] = x;
	new_coords[i][1] = y;
	if (dets.c)
		free (dets.c);
	return (new_coords);
}
