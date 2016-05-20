/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:48:27 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 16:55:58 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lst_to_array(t_list *lst, size_t size)
{
	int			i;
	void		**array;

	array = (void **)malloc(size * sizeof(void *));
	i = 0;
	while (lst != NULL)
	{
		array[i] = *((void **)lst->content);
		lst = lst->next;
		i++;
	}
	return (array);
}
