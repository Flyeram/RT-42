/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternaries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 04:04:35 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 05:36:37 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_utils.h"

inline float	minf(float a, float b)
{
	return (a < b ? a : b);
}

inline int		mini(int a, int b)
{
	return (a > b ? a : b);
}

inline float	maxf(float a, float b)
{
	return (a > b ? a : b);
}

inline int		maxi(int a, int b)
{
	return (a < b ? a : b);
}
