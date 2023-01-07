/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:54:24 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 20:16:27 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"
#include "../includes/libft.h"

/*
** how my path finding works is to basically search for a path between
** the player and a collectible and then from a collectible to another
** collectible... and from the last collectible to the exit.
** -------------------------------------------------------------------
** how this algorithm works (which is somewhat a Breadth-first search)
** is that it takes the starting position and then it checks the four
** adjacent tiles (up, down, left, right) and if they satisfy the
** conditions (which are the tile shouldn't be a wall or the tile
** shouldn't be already in the queue) they are added to the back
** of the queue, then it moves to the next element in the queue
** and repeats the same process.
** -------------------------------------------------------------------
** if the target is found 21 is found signaling that the lists should
** be updated (deleting the first strtpos and target because a path
** between them has been found), else 1 is returned signaling that
** the search should be continued (unless there's no next element
** in the queue which is checked in the main function).
*/

static int	ft_check_tiles(char **map, t_list **h_targets,
t_list **queue, t_list **o_queue)
{
	if (ft_check_queue((*o_queue), (*queue)->x - 1, (*queue)->y, map))
	{
		ft_lstadd_back(&(*o_queue), ft_lstnew((*queue)->x - 1, (*queue)->y));
		if (ft_check_tile((*h_targets), (*o_queue)))
			return (21);
	}
	if (ft_check_queue((*o_queue), (*queue)->x + 1, (*queue)->y, map))
	{
		ft_lstadd_back(&(*o_queue), ft_lstnew((*queue)->x + 1, (*queue)->y));
		if (ft_check_tile((*h_targets), (*o_queue)))
			return (21);
	}
	if (ft_check_queue((*o_queue), (*queue)->x, (*queue)->y + 1, map))
	{
		ft_lstadd_back(&(*o_queue), ft_lstnew((*queue)->x, (*queue)->y + 1));
		if (ft_check_tile((*h_targets), (*o_queue)))
			return (21);
	}
	if (ft_check_queue((*o_queue), (*queue)->x, (*queue)->y - 1, map))
	{
		ft_lstadd_back(&(*o_queue), ft_lstnew((*queue)->x, (*queue)->y - 1));
		if (ft_check_tile((*h_targets), (*o_queue)))
			return (21);
	}
	return (1);
}

/*
** storing targets in a list.
*/

static t_list	*ft_acquire_targets(t_mapdets dets)
{
	t_list	*h_targets;
	int		i;

	h_targets = ft_lstnew(dets.c[0][0], dets.c[0][1]);
	i = 0;
	while (++i < dets.n)
		ft_lstadd_back(&h_targets, ft_lstnew(dets.c[i][0], dets.c[i][1]));
	ft_lstadd_back(&h_targets,
		ft_lstnew(dets.playercoords[0], dets.playercoords[1]));
	return (h_targets);
}

/*
** storing starting positions in a list.
*/

static t_list	*ft_acquire_starting_positions(t_mapdets dets)
{
	t_list	*h_strtpos;
	int		i;

	h_strtpos = ft_lstnew(dets.exitcoords[0], dets.exitcoords[1]);
	i = -1;
	while (++i < dets.n)
		ft_lstadd_back(&h_strtpos, ft_lstnew(dets.c[i][0], dets.c[i][1]));
	return (h_strtpos);
}

/*
** lists init function
*/

static t_list	*ft_init_lists(t_list **h_targets, t_list **h_strtpos,
t_list **queue, t_mapdets dets)
{
	(*h_targets) = ft_acquire_targets(dets);
	(*h_strtpos) = ft_acquire_starting_positions(dets);
	(*queue) = ft_lstnew((*h_strtpos)->x, (*h_strtpos)->y);
	return ((*queue));
}

/*
** path finding main function.
** inits targets list (all of the collectibles and the exit),
** starting position's list (player & all collectibles) and
** the queue which starts off as the first element in the
** strtpos list.
** (algorithm description above.)
*/

void	ft_path_checking(t_mapdets dets)
{
	t_list	*h_targets;
	t_list	*h_strtpos;
	t_list	*queue;
	t_list	*queue_index;
	int		flag;

	queue_index = ft_init_lists(&h_targets, &h_strtpos, &queue, dets);
	flag = 1;
	while (flag)
	{
		flag = ft_check_tiles(dets.map, &h_targets, &queue_index, &queue);
		if (!queue_index->next)
			ft_print_error_message();
		else if (flag == 21)
		{
			if (ft_update_queue(&h_targets, &h_strtpos, &queue))
			{
				ft_free_lists(&h_targets, &h_strtpos, &queue);
				return ;
			}
			queue_index = queue;
		}
		else
			queue_index = queue_index->next;
	}
}
