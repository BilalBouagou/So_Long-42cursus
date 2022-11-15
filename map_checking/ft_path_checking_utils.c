/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checking_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:52:24 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/15 03:22:24 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"

int	ft_check_queue(t_list *queue, int x, int y, char **map)
{
	while (queue != NULL)
	{
		if ((queue->x == x && queue->y == y) || map[x][y] == '1')
			return (0);
		queue = queue->next;
	}
	return (1);
}

void	ft_delete_node(t_list **list)
{
	if ((*list))
	{
		t_list	*tmp;
		(*list) = (*list)->next;
		free (tmp);
	}
}

void	ft_delete_list(t_list **list)
{
	t_list	*current;
	t_list	*tmp;

	current = (*list);
	if (list)
	{
		while (current)
		{
			tmp = current;
			current = current->next;
			free (tmp);
		}
		(*list) = NULL;
	}
}

int	ft_update_queue(t_list **h_targets, t_list **h_strtpos, t_list **queue)
{
	t_list	*last;
	t_list	*tmp;

	last = ft_lstlast((*queue));
	if (last->x == (*h_targets)->x && last->y == (*h_targets)->y)
	{
		if ((*h_targets)->next == NULL)
			return (1);
		else
		{
			ft_delete_node(&(*h_targets));
			ft_delete_node(&(*h_strtpos));
			ft_delete_list(&(*queue));
			(*queue) = ft_lstnew((*h_strtpos)->x, (*h_strtpos)->y);
		}
	}
	return (0);
}
