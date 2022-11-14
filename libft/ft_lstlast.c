/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:53:27 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/10 17:46:29 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*rtrnlist;

	current = lst;
	rtrnlist = current;
	while (current != NULL)
	{
		rtrnlist = current;
		current = current->next;
	}
	return (rtrnlist);
}
