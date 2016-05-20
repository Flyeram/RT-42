/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 14:21:42 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_content(void *p, size_t s)
{
	(void)s;
	free(p);
}

void	ft_lstdel_nothing(void *p, size_t s)
{
	(void)s;
	(void)p;
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*next;

	elem = *alst;
	while (elem != NULL)
	{
		next = elem->next;
		ft_lstdelone(&elem, (*del));
		elem = next;
	}
	*alst = NULL;
}
