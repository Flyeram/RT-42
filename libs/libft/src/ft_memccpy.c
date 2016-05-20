/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/27 05:07:32 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t s_bytes)
{
	while (s_bytes > 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		(dst)++;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dst);
		(src)++;
		s_bytes--;
	}
	return (NULL);
}
