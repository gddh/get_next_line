/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:32:49 by delin             #+#    #+#             */
/*   Updated: 2018/04/28 22:01:23 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	negative(int n, int *neg)
{
	long n_long;

	if (n < 0)
	{
		n_long = (long)n * -1;
		*neg = 1;
	}
	else
		n_long = (long)n;
	return (n_long);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*tmp;
	long	n_long;
	int		neg;

	neg = 0;
	n_long = negative(n, &neg);
	size = ft_getdigit(n) + neg;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp)
	{
		tmp[size] = '\0';
		if (n == 0)
			tmp[--size] = '0';
		while (n_long)
		{
			tmp[--size] = (n_long % 10) + '0';
			n_long = n_long / 10;
		}
		if (neg)
			tmp[--size] = '-';
	}
	return (tmp);
}
