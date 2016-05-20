/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_at_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:47:53 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/12 17:46:20 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_at_array(t_array *array, int index)
{
	void	*tmp;

	tmp = ft_memjoin(array->array,
				array->array + array->element_size
				* index + array->element_size,
				array->element_size * index,
				array->bytes_size -
				(index * array->element_size));
	free(array->array);
	array->array = tmp;
	array->bytes_size -= array->element_size;
	array->count--;
}
