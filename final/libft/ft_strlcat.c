/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:20:57 by delin             #+#    #+#             */
/*   Updated: 2018/04/29 08:32:43 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i = i + 1;
	if (i < dstsize)
	{
		j = 0;
		while (i + j < dstsize - 1)
		{
			dst[i + j] = src[j];
			j = j + 1;
		}
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
