/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_t_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:48:27 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 16:56:10 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array		*ft_lst_to_t_array(t_list *lst, size_t size)
{
	int			i;
	t_array		*ret;
	void		**array;

	array = (void **)malloc(size * sizeof(void *));
	ret = ft_create_array(sizeof(void *));
	i = 0;
	while (lst != NULL)
	{
		array[i] = (*((void **)lst->content));
		lst = lst->next;
		i++;
	}
	ft_pushback_array(ret, array, size * sizeof(void **));
	free(array);
	return (ret);
}
