/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:55:01 by bbouagou          #+#    #+#             */
/*   Updated: 2022/12/02 17:59:46 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	get_integer_lenght(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == INT_MIN)
	{
		n = 147483648;
		count += 2;
	}
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static	void	write_to_string(int n, char *s, int size)
{
	if (n == INT_MIN)
	{
		ft_strlcpy(s, "-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (size >= 0 && s[size] != '-')
	{
		if (n >= 10)
		{
			s[size] = n % 10 + '0';
			n /= 10;
		}
		else
			s[size] = n + '0';
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = get_integer_lenght(n) + 1;
	result = (char *)ft_calloc(size, sizeof(char));
	if (result == NULL)
		return (NULL);
	write_to_string(n, result, size - 2);
	result[size - 1] = '\0';
	return (result);
}
