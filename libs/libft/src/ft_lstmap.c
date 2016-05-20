/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/27 01:32:13 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *allocated_list;
	t_list *iterator;

	allocated_list = (*f)(lst);
	iterator = allocated_list;
	lst = lst->next;
	while (lst != NULL)
	{
		iterator->next = (*f)(lst);
		iterator = iterator->next;
		lst = lst->next;
	}
	return (allocated_list);
}
