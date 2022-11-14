/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:22:52 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/11 08:49:38 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/*
** WARNING: THIS GET_NEXT_LINE IS MODIFIED.
** REFER TO THE ONE IN YOUR REPO INSTEAD!!!
*/

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n' && stash[i + 1] == '\0')
	{
		free (stash);
		return (NULL);
	}
	if (stash[i] != '\0')
	{
		new_stash = (char *)malloc(ft_get_lenght(stash) - i);
		if (new_stash == NULL)
			return (NULL);
		copy(new_stash, stash + i + 1, ft_get_lenght(stash) - i - 1);
		free (stash);
		return (new_stash);
	}
	free (stash);
	return (NULL);
}

char	*grab_line(char *stash)
{
	int		i;
	char	*menace;

	if (stash == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	menace = (char *)malloc(i + 1);
	if (menace == NULL)
		return (NULL);
	copy(menace, stash, i);
	return (menace);
}

char	*process_file(int fd, char *stash)
{
	char	*buff;
	ssize_t	bytes_read;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_get_nl(&stash[ft_get_lenght(stash) - bytes_read], '\n')
		&& bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if ((bytes_read == 0 && stash == NULL) || bytes_read < 0)
		{
			if (stash)
				free (stash);
			free (buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		stash = push_to_stash(stash, buff);
	}
	free (buff);
	return (stash);
}

/*
** Same thing as the mandatory code, the only difference is that there's
** an array of stashes, each one for a potential fd, each stash is passed
** by it's fd as an index.
*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = process_file(fd, stash);
	if (stash == NULL)
		return (NULL);
	return_line = grab_line(stash);
	stash = clean_stash(stash);
	return (return_line);
}
