/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delrange_at_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:46:20 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/12 17:48:15 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delrange_at_array(t_array *array, int start, int end)
{
	void	*tmp;
	int		diff;

	diff = end - start;
	if (start > 0)
		tmp = ft_memjoin(array->array,
						array->array + (array->element_size * end),
						array->element_size * start,
						array->bytes_size -
						(end * array->element_size));
	else
		tmp = ft_memjoin(NULL,
						array->array + (array->element_size * end),
						0,
						array->bytes_size -
						(end * array->element_size));
	free(array->array);
	array->array = tmp;
	array->bytes_size -= (array->element_size * diff);
	array->count -= diff;
}
