/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error_handeling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:55:46 by bbouagou          #+#    #+#             */
/*   Updated: 2022/11/14 02:18:28 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_checking.h"

void	ft_dimensions_error_handeling(char **map, t_mapdets dets, int flag)
{
	if (flag == -42)
	{
		write(1, "Error\nMap width is invalid.\n", 28);
		exit(flag);
	}
	if (flag == -43)
	{
		perror("Error\nMalloc error ");
		exit(flag);
	}
	if (flag == -44 || flag == -45)
	{
		while (--dets.width >= 0)
			free (map[dets.width]);
		free (map);
		if (flag == -44)
			write(1, "Error\nMap is not rectangular or map lenght invalid\n", 51);
		else
			write(1, "Error\nMap lenght is invalid.\n", 29);
		exit(flag);
	}
}

void	ft_components_misconfiguration_handeling(char tile)
{
	if (tile == 'P')
	{
		write(1, "Error\nmultiple player starting position detected.\n", 50);
		exit(-47);
	}
	else if (tile == 'E')
	{
		write(1, "Error\nmultiple exits detected.\n", 31);
		exit(-48);
	}
	else
	{
		write(1, "Error\nmap can only consist of '1' 'E' 'C' 'P'.\n", 47);
		exit(-49);
	}
}

void	ft_components_error_handeling(t_mapdets dets)
{
	if (!dets.n)
	{
		write(1, "Error\nMap error : missing collectibles.\n", 40);
		exit(-50);
	}
	if (!dets.playercoords[0])
	{
		write(1, "Error\nMap error : missing player.\n", 34);
		exit(-51);
	}
	if (!dets.exitcoords[0])
	{
		write(1, "Error\nMap error : missing exit.\n", 32);
		exit(-52);
	}
}
