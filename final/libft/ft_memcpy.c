/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:43:16 by delin             #+#    #+#             */
/*   Updated: 2018/05/03 10:13:55 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned char *src;
	unsigned char *dest;

	src = (unsigned char *)from;
	dest = (unsigned char *)to;
	while (n > 0)
	{
		*dest = *src;
		dest = dest + 1;
		src = src + 1;
		n = n - 1;
	}
	return (void *)(to);
}
