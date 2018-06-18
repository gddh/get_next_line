/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:39:08 by delin             #+#    #+#             */
/*   Updated: 2018/04/29 11:58:33 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		fill_arr(char **ptr, char const *s, char c)
{
	char	*w_ptr;
	int		i;

	i = 0;
	w_ptr = NULL;
	while (s && s[i] != '\0')
	{
		if (ft_wordbegins(s, i, c))
		{
			w_ptr = (char *)malloc(sizeof(char) * (ft_wordlen(s, i, c) + 1));
			if (!w_ptr)
				return (0);
			*ptr++ = w_ptr;
		}
		if (s[i] != c)
			*w_ptr++ = s[i];
		if (s[i] == c && w_ptr != NULL)
			*w_ptr = '\0';
		i = i + 1;
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		complete;
	int		size;

	if (!c || ft_numwords(s, c) < 0)
		return (NULL);
	size = ft_numwords(s, c);
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (ptr)
	{
		complete = fill_arr(ptr, s, c);
		ptr[size] = (char *)malloc(sizeof(NULL));
		if (!complete || !ptr[size])
			return (NULL);
		ptr[size] = NULL;
	}
	return (ptr);
}
