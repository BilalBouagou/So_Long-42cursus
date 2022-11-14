/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:49:01 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/13 17:44:29 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKING_H
# define MAP_CHECKING_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

/*
** width == width of the map;
** lenght == lenght of the map;
** playercoords == coordinates of the player;
** exitcoords == coordinates of the exit;
** c = coordinates of all the collectibles;
** n == number of collectibles;
*/

typedef struct s_mapdets
{
	int	width;
	int	lenght;
	int	playercoords[2];
	int	exitcoords[2];
	int	**c;
	int	n;
}	t_mapdets;

char	**ft_parse_map(int fd, char **map, t_mapdets *dets);
int		**ft_update_coords(t_mapdets dim, int x, int y, int collectsnum);
void	ft_components_error_handeling(t_mapdets dets);
void	ft_components_misconfiguration_handeling(char tile);
void	ft_path_checking(char **map, t_mapdets dets);
void	ft_init_struct(t_mapdets *dim);
void	ft_init_checking(void);
void	ft_dimensions_error_handeling(char **map, t_mapdets dets, int flag);
#endif