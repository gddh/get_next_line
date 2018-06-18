/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:07:04 by delin             #+#    #+#             */
/*   Updated: 2018/04/28 16:45:23 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_helper(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_helper(n * -1);
	}
	else if (0 <= n && n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_helper(n / 10);
		ft_putnbr_helper(n % 10);
	}
}

void		ft_putnbr(int n)
{
	ft_putnbr_helper((long)n);
}
