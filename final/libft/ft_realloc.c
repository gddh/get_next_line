/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:26:44 by delin             #+#    #+#             */
/*   Updated: 2018/05/05 08:30:48 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **ptr, size_t old_size, size_t new_size)
{
	char *tmp;

	if (new_size == 0)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if ((tmp = ft_strnew(sizeof(char) * new_size)))
	{
		if (*ptr)
		{
			if (old_size < new_size)
				ft_memcpy(tmp, *ptr, old_size);
			else
				ft_memcpy(tmp, *ptr, new_size);
			free(*ptr);
		}
		*ptr = tmp;
		return (tmp);
	}
	return (NULL);
}
