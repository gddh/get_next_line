/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:18:30 by delin             #+#    #+#             */
/*   Updated: 2018/04/29 09:13:59 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tmp)
	{
		while (*s != '\0')
			tmp[i++] = (*f)(*s++);
		tmp[i] = '\0';
	}
	return (tmp);
}
