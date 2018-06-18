/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:43:16 by delin             #+#    #+#             */
/*   Updated: 2018/04/29 10:30:26 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*tmp;
	int		i;

	size = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			tmp[i] = s1[i];
			i = i + 1;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
