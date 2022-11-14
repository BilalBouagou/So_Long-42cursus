/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:59:43 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/14 02:14:10 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"

void	ft_init_checking(void)
{
	int			fd;
	char		**map;
	t_mapdets	dets;

	ft_init_struct(&dets);
	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(-1);
	}
	map = ft_parse_map(fd, map, &dets);
	close(fd);
	ft_path_checking(map, dets);
}
