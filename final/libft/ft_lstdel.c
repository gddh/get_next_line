/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:00:46 by delin             #+#    #+#             */
/*   Updated: 2018/04/23 16:26:40 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp1;

	if (alst && *alst)
	{
		while (*alst)
		{
			tmp1 = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = tmp1;
		}
	}
}
