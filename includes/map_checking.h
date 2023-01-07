/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:49:01 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/06 19:02:34 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKING_H
# define MAP_CHECKING_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** width == width of the map;
** lenght == lenght of the map;
** playercoords == coordinates of the player;
** exitcoords == coordinates of the exit;
** c = coordinates of all the collectibles;
** n == number of collectibles;
*/

/*
** Center of the Univers.
*/

typedef struct s_mapdets
{
	int			width;
	int			lenght;
	int			playercoords[2];
	int			exitcoords[2];
	int			**c;
	int			**enemies;
	int			cnst_n;
	int			n;
	int			i;
	int			j;
	int			x;
	int			y;
	int			g;
	int			gi;
	int			g_anim;
	int			moves;
	char		**map;
	char		*path;
	struct		s_data
	{
		void	*mlx;
		void	*win;
		void	*p_img;
		void	*p1_img;
		void	*p2_img;
		void	*p3_img;
		void	*e_img;
		void	*c1_img;
		void	*c2_img;
		void	*c3_img;
		void	*c4_img;
		void	*c5_img;
		void	*c6_img;
		void	*c7_img;
		void	*w_img;
		void	*b_img;
		int		p_width;
		int		p1_width;
		int		p2_width;
		int		p3_width;
		int		p_lenght;
		int		p1_lenght;
		int		p2_lenght;
		int		p3_lenght;
		int		e_width;
		int		e_lenght;
		int		c1_width;
		int		c2_width;
		int		c3_width;
		int		c4_width;
		int		c5_width;
		int		c6_width;
		int		c7_width;
		int		c1_lenght;
		int		c2_lenght;
		int		c3_lenght;
		int		c4_lenght;
		int		c5_lenght;
		int		c6_lenght;
		int		c7_lenght;
		int		w_width;
		int		w_lenght;
		int		b_width;
		int		b_lenght;
		void	*gud_img;
		int		gud_width;
		int		gud_lenght;
	} t_data;
}				t_mapdets;

/*
** Map parsing functions.
*/

void			ft_parse_map(int fd, t_mapdets *dets);
void			ft_dimensions_error_handeling(t_mapdets dets, int flag);
void			ft_components_misconfiguration_handeling(char tile);
void			ft_components_error_handeling(t_mapdets dets);

/*
** Path checking functions.
*/

void			ft_insert(int arr[][2], int a, int b);
void			ft_print_error_message(void);
void			ft_free_lists(t_list **h_targets, t_list **h_strtpos,
					t_list **queue);
void			ft_path_checking(t_mapdets dets);
int				**ft_update_coords(t_mapdets *dets, int x, int y,
					int collectsnum);
int				ft_check_queue(t_list *queue, int x, int y, char **map);
int				ft_update_queue(t_list **h_targets, t_list **h_strtpos,
					t_list **queue);
int				ft_check_tile(t_list *h_targets, t_list *queue);

#endif