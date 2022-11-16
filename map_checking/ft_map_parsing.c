/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:56:36 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/16 02:15:49 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WARNING : CODE INCOMPLETE AND/OR DOESN'T MEET THE SUBJECT'S REQUIREMENTS!
*/

#include "../includes/map_checking.h"
#include "../includes/get_next_line.h"

/*
** getting the map's width
*/

int	ft_get_map_width(int fd, t_mapdets *dets)
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

char	**ft_check_dimensions(int fd, t_mapdets *dets)
{
	char			**map;
	int				index;

	(*dets).width = ft_get_map_width(fd, &(*dets));
	if ((*dets).width < 3)
		ft_dimensions_error_handeling(NULL, (*dets), -42);
	fd = open("maps/map.ber", O_RDONLY);
	index = -1;
	map = (char **)malloc((*dets).width * sizeof(char *));
	if (!map)
		ft_dimensions_error_handeling(NULL, (*dets), -43);
	while (++index < (*dets).width)
		map[index] = get_next_line(fd);
	(*dets).lenght = (int)ft_strlen(map[0]);
	if ((*dets).width == (int)ft_strlen(map[0]) || ft_strlen(map[0]) < 3)
		ft_dimensions_error_handeling(map, (*dets), -44);
	index = -1;
	while (++index < (*dets).width - 1)
		if (ft_strlen(map[index]) != ft_strlen(map[index + 1]))
			ft_dimensions_error_handeling(map, (*dets), -45);
	return (map);
}

/*
** checking if the map is trully surrounded by walls.
*/

int	ft_check_map_walls(char **map, t_mapdets dets)
{
	int	x;

	x = -1;
	while (++x < dets.lenght)
		if (map[0][x] != '1' || map[dets.width - 1][x] != '1')
			return (0);
	x = -1;
	while (++x < dets.width)
		if (map[x][0] != '1' || map[x][dets.lenght - 1] != '1')
			return (0);
	return (1);
}

/*
** checking the validity of the map's components and storing
** their coordinates.
*/

void	ft_check_map_components(char **map, t_mapdets *dets)
{
	int	i[2];

	i[0] = 0;
	while (++i[0] < (*dets).width - 1)
	{
		i[1] = 0;
		while (++i[1] < (*dets).lenght - 1)
		{
			if (map[i[0]][i[1]] == 'P' && !(*dets).playercoords[0])
			{
				(*dets).playercoords[0] = i[0];
				(*dets).playercoords[1] = i[1];
			}
			else if (map[i[0]][i[1]] == 'E' && !(*dets).exitcoords[0])
			{
				(*dets).exitcoords[0] = i[0];
				(*dets).exitcoords[1] = i[1];
			}
			else if (map[i[0]][i[1]] == 'C')
				(*dets).c = ft_update_coords((*dets), i[0], i[1], (*dets).n++);
			else if (map[i[0]][i[1]] != '0' && map[i[0]][i[1]] != '1')
				ft_components_misconfiguration_handeling(map[i[0]][i[1]]);
		}
	}
	ft_components_error_handeling((*dets));
}

/*
** map parsing init function.
*/

char	**ft_parse_map(int fd, char **map, t_mapdets *dets)
{
	map = ft_check_dimensions(fd, &(*dets));
	if (!ft_check_map_walls(map, (*dets)))
	{
		write(1, "Error\nIncorrect walls layout.\n", 30);
		exit (-46);
	}
	ft_check_map_components(map, &(*dets));
	return (map);
}
