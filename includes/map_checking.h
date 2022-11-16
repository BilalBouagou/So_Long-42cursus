/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:49:01 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/15 22:06:32 by bbouagou         ###   ########.fr       */
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
# include <stdbool.h>
# include "libft.h"

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
int		ft_check_queue(t_list *queue, int x, int y, char **map);
int		ft_update_queue(t_list **h_targets, t_list **h_strtpos, t_list **queue);
void	ft_print_error_message(void);
t_list	*ft_acquire_starting_positions(t_mapdets dets);
t_list	*ft_acquire_targets(t_mapdets dets);
t_list	*ft_init_lists(t_list **h_targets, t_list **h_strtpos, t_list **queue,
			t_mapdets dets);
void	ft_free_lists(t_list **h_targets, t_list **h_strtpos, t_list **queue);
#endif