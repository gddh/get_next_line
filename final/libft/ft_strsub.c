/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:58:03 by delin             #+#    #+#             */
/*   Updated: 2018/04/28 15:48:23 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp)
	{
		i = 0;
		while (len--)
			tmp[i++] = s[start++];
		tmp[i] = '\0';
	}
	return (tmp);
}
