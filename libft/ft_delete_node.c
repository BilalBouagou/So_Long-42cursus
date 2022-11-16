/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:19:53 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/15 21:45:39 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_delete_node(t_list **list)
{
	t_list	*tmp;

	if ((*list))
	{
		tmp = (*list);
		(*list) = (*list)->next;
		free (tmp);
	}
}
