/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checking_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:52:24 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 20:17:01 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"

void	ft_print_error_message(void)
{
	write(1, "Error\nThere's no valid path in this map.\n", 41);
	write(1, "The player should be able to collect all the collectibles ", 58);
	write(1, "and then exit the map.\n", 23);
	exit(0);
}

int	ft_check_queue(t_list *queue, int x, int y, char **map)
{
	while (queue != NULL)
	{
		if ((queue->x == x && queue->y == y) || map[x][y] == '1'
			|| map[x][y] == 'E')
			return (0);
		queue = queue->next;
	}
	return (1);
}

int	ft_update_queue(t_list **h_targets, t_list **h_strtpos, t_list **queue)
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
	return (0);
}

/*
** function to check if we reached the target
*/

int	ft_check_tile(t_list *h_targets, t_list *queue)
{
	t_list	*last;

	last = ft_lstlast(queue);
	if (last->x == h_targets->x && last->y == h_targets->y)
		return (1);
	else
		return (0);
}

void	ft_free_lists(t_list **h_targets, t_list **h_strtpos, t_list **queue)
{
	ft_delete_list(&(*h_targets));
	ft_delete_list(&(*h_strtpos));
	ft_delete_list(&(*queue));
}
