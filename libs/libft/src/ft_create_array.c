/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:48:12 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:43:30 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array			*ft_create_array(size_t element_size)
{
	t_array	*allocated;

	allocated = (t_array *)malloc(sizeof(t_array));
	allocated->element_size = element_size;
	allocated->array = NULL;
	allocated->count = 0;
	allocated->bytes_size = 0;
	return (allocated);
}
