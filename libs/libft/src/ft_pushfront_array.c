/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushfront_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:59:34 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/12 17:42:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	AN CRASH IF YOU TRY TO FREE SOMETHING THAT HAVE NOT BEEN ALLOCATED
**	ITS YOUR RESPONSABILITY TO CHANGE THE PARAMETER SHOULD_FREE IN CONSEQUENCE
*/

#include "libft.h"

void		ft_pushfront_array(t_array *array,
								void *value,
								size_t value_size)
{
	void *tmp;

	tmp = ft_memjoin(value,
			array->array,
			value_size,
			array->bytes_size);
	free(array->array);
	array->array = tmp;
	array->bytes_size += value_size;
	array->count += value_size / array->element_size;
}
