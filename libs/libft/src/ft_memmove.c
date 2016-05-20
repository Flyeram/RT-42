/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/12/17 17:45:54 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** We have two patterns on this function, if src is bigger than dst,
** just memcpy it, otherwise copy from the end
*/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t s_bytes)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	if (dst == NULL || src == NULL)
		return (NULL);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_src <= ptr_dst)
	{
		ptr_dst += (s_bytes - 1);
		ptr_src += (s_bytes - 1);
		while (s_bytes > 0)
		{
			*ptr_dst = *ptr_src;
			(ptr_dst)--;
			(ptr_src)--;
			s_bytes--;
		}
	}
	else
		ft_memcpy(dst, src, s_bytes);
	return (dst);
}
