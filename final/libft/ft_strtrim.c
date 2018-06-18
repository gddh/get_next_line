/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:38:06 by delin             #+#    #+#             */
/*   Updated: 2018/04/28 22:22:13 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end_i;
	char	*tmp;

	if (s)
	{
		while (*s != '\0' && (*s == '\t' || *s == '\n' || *s == ' '))
			s++;
		end_i = ft_strlen(s) - 1;
		while (end_i > 0 &&
				(s[end_i] == '\t' || s[end_i] == '\n' || s[end_i] == ' '))
			end_i--;
		end_i = end_i + 1;
		tmp = (char *)malloc(sizeof(char) * (end_i + 1));
		if (tmp)
		{
			ft_strncpy(tmp, s, sizeof(char) * end_i);
			tmp[end_i] = '\0';
		}
		return (tmp);
	}
	return (NULL);
}
