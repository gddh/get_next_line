/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:35:05 by delin             #+#    #+#             */
/*   Updated: 2018/04/28 17:14:54 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_helper(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_helper(n * -1, fd);
	}
	else if (0 <= n && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_helper(n / 10, fd);
		ft_putnbr_helper(n % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_helper((long)n, fd);
}
