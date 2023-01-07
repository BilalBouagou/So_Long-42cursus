/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error_handeling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:55:46 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/05 22:23:15 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"

/*
** error handeling function for dimensions checking.
*/

void	ft_dimensions_error_handeling(t_mapdets dets, int flag)
{
	if (flag == -42)
	{
		write(1, "Error\nMap width is invalid.\n", 28);
		exit(0);
	}
	if (flag == -43)
	{
		perror("Error\n");
		exit(0);
	}
	if (flag == -44 || flag == -45)
	{
		while (--dets.width >= 0)
			free (dets.map[dets.width]);
		free (dets.map);
		if (flag == -44)
			write(1, "Error\nMap is not rectangular or map lenght invalid\n", 51);
		else
			write(1, "Error\nMap lenght is invalid.\n", 29);
		exit(0);
	}
}

/*
** error handeling function for components duplication and
** unrecognized components.
*/

void	ft_components_misconfiguration_handeling(char tile)
{
	if (tile == 'P')
	{
		write(1, "Error\nmultiple player starting position detected.\n", 50);
		exit(0);
	}
	else if (tile == 'E')
	{
		write(1, "Error\nmultiple exits detected.\n", 31);
		exit(0);
	}
	else
	{
		write(1, "Error\nmap can only consist of '1' 'E' 'C' 'P'.\n", 47);
		exit(0);
	}
}

/*
** error handeling function for missing components.
*/

void	ft_components_error_handeling(t_mapdets dets)
{
	if (!dets.n)
	{
		write(1, "Error\nMap error : missing collectibles.\n", 40);
		exit(0);
	}
	if (!dets.playercoords[0])
	{
		write(1, "Error\nMap error : missing player.\n", 34);
		exit(0);
	}
	if (!dets.exitcoords[0])
	{
		write(1, "Error\nMap error : missing exit.\n", 32);
		exit(0);
	}
}
