/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:11:17 by delin             #+#    #+#             */
/*   Updated: 2018/04/29 09:02:28 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)malloc(size);
	if (tmp)
	{
		i = 0;
		while (i < size)
			tmp[i++] = '\0';
	}
	return (tmp);
}
