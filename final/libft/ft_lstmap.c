/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:30:39 by delin             #+#    #+#             */
/*   Updated: 2018/04/28 16:31:26 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *h;
	t_list *tmp;

	if (f && lst)
	{
		tmp = f(lst);
		h = tmp;
		while (lst->next)
		{
			lst = lst->next;
			if (!(tmp->next = f(lst)))
				return (NULL);
			tmp = tmp->next;
		}
		return (h);
	}
	return (NULL);
}
