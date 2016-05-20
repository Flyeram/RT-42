/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findbyindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:44:28 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 08:19:24 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfindbyindex(t_list *list, int index)
{
	while (list != NULL && index > 0)
	{
		list = list->next;
		index--;
	}
	if (list != NULL)
		return (index != 0 ? NULL : list);
	return (NULL);
}
