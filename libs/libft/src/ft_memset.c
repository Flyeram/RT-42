/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:54:56 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/21 18:02:40 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PERSONAL NOTE : DO NO USE TO INITIALIZE ANYTHING ELSE THAN SINGLE BYTE$
** DATA TYPE, IT WOULD FAIL SINCE WE CAST THE INT IN UNSIGNED CHAR$
** Set the value 'c' to the first 'len' bytes in the memory space pointed by
** 'b'.
*/

static void	ft_memsetblock(long *ptr, unsigned long cccc, size_t *len)
{
	unsigned long	*p;
	size_t			size;
	size_t			nlen;

	p = (unsigned long *)(*ptr);
	nlen = *len;
	size = 8 * 8;
	while (nlen >= size)
	{
		p[0] = cccc;
		p[1] = cccc;
		p[2] = cccc;
		p[3] = cccc;
		p[4] = cccc;
		p[5] = cccc;
		p[6] = cccc;
		p[7] = cccc;
		p += 8;
		nlen -= size;
	}
	*ptr = (long)p;
	*len = nlen;
}

void		*ft_memset(void *b, int c, size_t len)
{
	long int			ptr;
	unsigned long int	cccc;

	ptr = (long int)b;
	cccc = (unsigned char)c;
	cccc |= cccc << 24 | cccc << 16 | cccc << 8;
	cccc |= cccc << 32;
	while (len && ptr % 8 != 0)
	{
		*((unsigned char *)ptr++) = (unsigned char)c;
		--len;
	}
	if (len >= 8 * 8)
		ft_memsetblock(&ptr, cccc, &len);
	while (len >= 8)
	{
		((unsigned long *)ptr)[0] = cccc;
		ptr += 8;
		len -= 8;
	}
	while (len--)
		*((unsigned char *)ptr++) = (unsigned char)c;
	return (b);
}
