/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:20:44 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/15 20:21:21 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_delete_list(t_list **list)
{
	t_list	*current;
	t_list	*tmp;

	current = (*list);
	if ((*list))
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
