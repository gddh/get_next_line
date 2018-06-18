/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:10:28 by delin             #+#    #+#             */
/*   Updated: 2018/04/28 15:45:22 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*tmp;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	i = 0;
	len = ft_strlen(s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp)
	{
		while (i < len)
		{
			tmp[i] = (*f)(i, s[i]);
			i = i + 1;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
