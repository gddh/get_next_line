/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:02:30 by delin             #+#    #+#             */
/*   Updated: 2018/04/29 12:50:23 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char) *
				(ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strcat(str, s2);
			return (str);
		}
	}
	if (s1)
		return (ft_strdup(s1));
	if (s2)
		return (ft_strdup(s2));
	return (NULL);
}
