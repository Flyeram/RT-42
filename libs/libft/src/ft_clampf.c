/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clampf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:01:42 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/27 04:16:02 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_clampf(float nb, float min, float max)
{
	if (nb >= min && nb <= max)
		return (nb);
	return (nb < min ? min : max);
}
