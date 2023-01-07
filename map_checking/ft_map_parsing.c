/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:56:36 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 19:02:06 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WARNING : CODE INCOMPLETE AND/OR DOESN'T MEET THE SUBJECT'S REQUIREMENTS!
*/

#include "../includes/map_checking.h"

/*
** getting the map's width.
*/

static int	ft_get_map_width(int fd, t_mapdets *dets)
{
	char	buffer[11];
	ssize_t	bytes_read;
	int		i;

	bytes_read = 1;
	(*dets).width = 0;
	i = -1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, 10);
		if (bytes_read < 0)
			return (-1);
		buffer[bytes_read] = '\0';
		while (buffer[++i])
		{
			if (buffer[i] == '\n')
				(*dets).width++;
		}
		if (!bytes_read)
			(*dets).width++;
		i = -1;
	}
	close(fd);
	return ((*dets).width);
}

/*
** checking the validity of the map's dimensions and storing
** them in a struct.
*/

static void	ft_check_dimensions(int fd, t_mapdets *dets)
{
	int				index;

	(*dets).width = ft_get_map_width(fd, &(*dets));
	if ((*dets).width < 3)
		ft_dimensions_error_handeling((*dets), -42);
	fd = open((*dets).path, O_RDONLY);
	index = -1;
	(*dets).map = (char **)malloc((*dets).width * sizeof(char *));
	if (!(*dets).map)
		ft_dimensions_error_handeling((*dets), -43);
	while (++index < (*dets).width)
		(*dets).map[index] = get_next_line(fd);
	(*dets).lenght = (int)ft_len((*dets).map[0]);
	if ((*dets).width == ft_len((*dets).map[0]) || ft_len((*dets).map[0]) < 3)
		ft_dimensions_error_handeling((*dets), -44);
	index = -1;
	while (++index < (*dets).width - 1)
		if (ft_len((*dets).map[index]) != ft_len((*dets).map[index + 1]))
			ft_dimensions_error_handeling((*dets), -45);
}

/*
** checking if the map is trully surrounded by walls.
*/

static int	ft_check_map_walls(t_mapdets dets)
{
	int	x;

	x = -1;
	while (++x < dets.lenght)
		if (dets.map[0][x] != '1' || dets.map[dets.width - 1][x] != '1')
			return (0);
	x = -1;
	while (++x < dets.width)
		if (dets.map[x][0] != '1' || dets.map[x][dets.lenght - 1] != '1')
			return (0);
	return (1);
}

/*
** checking the validity of the map's components and storing
** their coordinates.
*/

/*
** NORMINETTE IS A HOE
*/

static void	ft_check_map_components(t_mapdets *dets)
{
	int	i[2];

	i[0] = 0;
	while (++i[0] < (*dets).width - 1)
	{
		i[1] = 0;
		while (++i[1] < (*dets).lenght - 1)
		{
			if ((*dets).map[i[0]][i[1]] == 'P' && !(*dets).playercoords[0])
				ft_insert(&(*dets).playercoords, i[0], i[1]);
			else if ((*dets).map[i[0]][i[1]] == 'E' && !(*dets).exitcoords[0])
				ft_insert(&(*dets).exitcoords, i[0], i[1]);
			else if ((*dets).map[i[0]][i[1]] == 'C')
				(*dets).c = ft_update_coords(&(*dets), i[0], i[1], (*dets).n++);
			else if ((*dets).map[i[0]][i[1]] != '0'
					&& (*dets).map[i[0]][i[1]] != '1')
				ft_components_misconfiguration_handeling(
					(*dets).map[i[0]][i[1]]);
		}
	}
	ft_components_error_handeling((*dets));
}

/*
** map parsing init function.
*/

void	ft_parse_map(int fd, t_mapdets *dets)
{
	ft_check_dimensions(fd, &(*dets));
	if (!ft_check_map_walls((*dets)))
	{
		write(1, "Error\nIncorrect walls layout.\n", 30);
		exit (-46);
	}
	ft_check_map_components(&(*dets));
	(*dets).cnst_n = (*dets).n;
	(*dets).x = (*dets).playercoords[1] * 40;
	(*dets).y = (*dets).playercoords[0] * 40;
}
