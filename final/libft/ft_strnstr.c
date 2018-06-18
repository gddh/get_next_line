/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:47:32 by delin             #+#    #+#             */
/*   Updated: 2018/04/28 15:48:35 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return (char *)(haystack);
	j = 0;
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && j + i < len)
		{
			if (needle[i + 1] == '\0')
				return (char *)(haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
