/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:59:00 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 23:39:12 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map_checking.h"
#include "includes/rendering.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static void	ft_no_args(void)
{
	write(1, "Incorrect number of arguments\n", 30);
	exit(0);
}

static void	ft_fd_error(void)
{
	perror("Error\n");
	exit(-1);
}

static char	*ft_get_map(char *filename)
{
	if (!ft_strnstr(filename, ".ber", (size_t)ft_len(filename)))
	{
		write(1, "File has incorrect format.\n", 27);
		exit(0);
	}
	else
		return (ft_strjoin("maps/", filename));
}

static void	ft_init_struct(t_mapdets *dets)
{
	(*dets).width = 0;
	(*dets).lenght = 0;
	(*dets).playercoords[0] = 0;
	(*dets).playercoords[1] = 0;
	(*dets).exitcoords[0] = 0;
	(*dets).exitcoords[1] = 0;
	(*dets).c = NULL;
	(*dets).map = NULL;
	(*dets).n = 0;
	(*dets).cnst_n = 0;
	(*dets).i = 0;
	(*dets).j = 0;
	(*dets).x = 0;
	(*dets).y = 0;
	(*dets).g = 0;
	(*dets).gi = 0;
	(*dets).g_anim = 0;
	(*dets).moves = 0;
}

int	main(int argc, char **argv)
{
	int			fd;
	t_mapdets	dets;

	if (argc != 3)
		ft_no_args();
	ft_init_struct(&dets);
	dets.path = ft_get_map(argv[1]);
	fd = open(dets.path, O_RDONLY);
	if (fd < 0)
		ft_fd_error();
	ft_parse_map(fd, &dets);
	close(fd);
	free (dets.path);
	srand(time(NULL));
	if (*argv[2] == 'b')
		ft_inject_enemies(&dets);
	ft_path_checking(dets);
	ft_draw_map(&dets);
}
