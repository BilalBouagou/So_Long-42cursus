/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:47:13 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 19:12:52 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"

/*
** norminette is a hoe
*/

void	ft_insert(int arr[][2], int a, int b)
{
	(*arr)[0] = a;
	(*arr)[1] = b;
}

/*
** re-allocating the old dets.c element
*/

static void	ft_free_it(t_mapdets *dets, int collectsnum)
{
	int	i;

	i = collectsnum - 1;
	while (i >= 0)
	{
		free ((*dets).c[i]);
		i--;
	}
	free ((*dets).c);
}

static int	**allocate(int **new_coords, int collectsnum)
{
	int	i;

	i = -1;
	new_coords = (int **)malloc(collectsnum * sizeof(int *));
	if (!new_coords)
		return (NULL);
	while (++i < collectsnum)
	{
		new_coords[i] = (int *)malloc(2 * sizeof(int));
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

int	**ft_update_coords(t_mapdets *dets, int x, int y, int collectsnum)
{
	int	**new_coords;
	int	i;

	i = -1;
	new_coords = NULL;
	new_coords = allocate(new_coords, collectsnum + 1);
	if (!new_coords)
		return (NULL);
	while (++i < collectsnum)
	{
		new_coords[i][0] = (*dets).c[i][0];
		new_coords[i][1] = (*dets).c[i][1];
	}
	new_coords[i][0] = x;
	new_coords[i][1] = y;
	if ((*dets).c)
		ft_free_it(&(*dets), collectsnum);
	return (new_coords);
}
