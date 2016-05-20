/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextxarraychar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 03:48:50 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this function work exactly as ft_getnextxchar except it accept a t_array
** struct for exclusion char the length should be correct
** otherwise undetermined behaviour could happen
*/

#include "libft.h"

int		ft_getnextxarraychar(const char *s, t_array *c, int start, int move)
{
	size_t	i;

	if (c == NULL || s == NULL || c->array == NULL)
		return (-1);
	while (start >= 0)
	{
		i = 0;
		while (i < c->count)
		{
			if (((unsigned char *)c->array)[i] == s[start])
				break ;
			i++;
		}
		if (i >= c->count)
			break ;
		start += move;
	}
	return (start);
}
