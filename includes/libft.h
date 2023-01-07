/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:47:11 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/03 13:26:00 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>

/*
** Pathfinding structure :
** x = x coordinate of a point.
** y = y coordinate of a point.
** next = the next point in the list.
*/

typedef struct s_list
{
	int		x;
	int		y;
	void	*next;
}			t_list;

/*
** Declarations of various functions concerning
** the manipulation of coordinates linked list.
*/

int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_delete_node(t_list **list);
void		ft_delete_list(t_list **list);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int x, int y);

/*
** Helper functions from libft.
*/

char		*ft_strchr(const char *s, int c);
int			ft_len(const char *s);
char		*ft_itoa(int n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif