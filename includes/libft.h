/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:47:11 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/14 21:19:31 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

/*
** Pathfinding structure :
** x = x coordinate of a point.
** y = y coordinate of a point.
** distance = distance of that point from the target.
** next = the next point in the list.
*/

typedef struct s_list
{
	int		x;
	int		y;
	int		distance;
	void	*next;
}		t_list;

/*
** Declarations of various functions concerning
** the manipulation of coordinates linked list.
*/

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int x, int y);

/*
** Helper functions from libft.
*/

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif