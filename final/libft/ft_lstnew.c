/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:00:32 by delin             #+#    #+#             */
/*   Updated: 2018/04/29 12:30:52 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	if (content == NULL)
		content_size = 0;
	if ((tmp = (t_list *)malloc(sizeof(t_list))))
	{
		tmp->next = NULL;
		if (!(tmp->content = malloc(content_size)))
			return (NULL);
		if (content_size == 0)
			tmp->content = NULL;
		else
			ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	return (tmp);
}
