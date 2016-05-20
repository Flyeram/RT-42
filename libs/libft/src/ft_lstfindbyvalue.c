/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindbyvalue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:44:28 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/27 23:58:32 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfindbyvalue(t_list *list, t_list *to_find)
{
	if (to_find == NULL || list == NULL)
		return (NULL);
	while (list != NULL)
	{
		if (list->content_size != to_find->content_size)
		{
			list = list->next;
			continue ;
		}
		if (ft_memcmp(list->content, to_find->content, list->content_size) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}
