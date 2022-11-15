/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:54:24 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/15 03:02:57 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"
#include "../includes/libft.h"

void	ft_print_error_message(void)
{
	write(1, "Error\nThere's no valid path in this map.\n", 41);
	write(1, "The player should be able to collect all the collectibles ", 58);
	write(1, "and then exit the map.\n", 23);
	exit(-53);
}

/*
** up == x - 1;
** down == x + 1;
** right == y + 1;
** left == y - 1;
*/

/*
** TODO :
	check if the tile has a component on it and if so update the targets, the queue and the starting positions
*/

/*
** so fucking cursed.
*/

int	ft_check_adjacent_tiles(char **map, t_list **h_targets, t_list **h_strtpos, t_list **queue)
{
	if (ft_check_queue((*queue), (*queue)->x - 1, (*queue)->y, map))
	{
		ft_lstadd_back(&(*queue), ft_lstnew((*queue)->x - 1, (*queue)->y));
		if (ft_update_queue(&(*h_targets), &(*h_strtpos), &(*queue)))
			return (42);
	}
	if (ft_check_queue((*queue), (*queue)->x + 1, (*queue)->y, map))
	{
		ft_lstadd_back(&(*queue), ft_lstnew((*queue)->x + 1, (*queue)->y));
		if (ft_update_queue(&(*h_targets), &(*h_strtpos), &(*queue)))
			return (42);
	}
	if (ft_check_queue((*queue), (*queue)->x, (*queue)->y + 1, map))
	{
		ft_lstadd_back(&(*queue), ft_lstnew((*queue)->x, (*queue)->y + 1));
		if (ft_update_queue(&(*h_targets), &(*h_strtpos), &(*queue)))
			return (42);
	}
	if (ft_check_queue((*queue), (*queue)->x, (*queue)->y - 1, map))
	{
		ft_lstadd_back(&(*queue), ft_lstnew((*queue)->x, (*queue)->y - 1));
		if (ft_update_queue(&(*h_targets), &(*h_strtpos), &(*queue)))
			return (42);
	}
	if (!(*queue)->next)
		return (0);
	else
		return (1);
}

t_list	*ft_acquire_targets(t_mapdets dets)
{
	t_list	*h_targets;
	int		i;

	h_targets = ft_lstnew(dets.c[0][0], dets.c[0][1]);
	i = 0;
	while (++i < dets.n)
		ft_lstadd_back(&h_targets, ft_lstnew(dets.c[i][0], dets.c[i][1]));
	ft_lstadd_back(&h_targets, ft_lstnew(dets.exitcoords[0], dets.exitcoords[1]));
	return (h_targets);
}

t_list	*ft_acquire_starting_positions(t_mapdets dets)
{
	t_list	*h_strtpos;
	int		i;

	h_strtpos = ft_lstnew(dets.playercoords[0], dets.playercoords[1]);
	i = -1;
	while (++i < dets.n)
		ft_lstadd_back(&h_strtpos, ft_lstnew(dets.c[i][0], dets.c[i][1]));
	return (h_strtpos);
}

/*
** pathfinding algorithm takes an initial starting pos and
** a target, i need a way to store all my starting poss and
** targets, and i need to update them. 
*/

void	ft_path_checking(char **map, t_mapdets dets)
{
	t_list	*h_targets;
	t_list	*h_strtpos;
	t_list	*queue;
	t_list	*queue_index;
	int		flag;

	h_targets = ft_acquire_targets(dets);
	h_strtpos = ft_acquire_starting_positions(dets);
	queue = ft_lstnew(h_strtpos->x, h_strtpos->y);
	queue_index = queue;
	flag = 1;
	while (flag)
	{
		flag = ft_check_adjacent_tiles(map, &h_targets, &h_strtpos, &queue_index);
		if (!flag)
			ft_print_error_message();
		else if (flag == 42)
			return ;
		if (queue_index->next != NULL)
			queue_index = queue_index->next;
	}
}
