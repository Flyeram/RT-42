/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternaries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 04:04:35 by bkabbas           #+#    #+#             */
/*   Updated: 2016/05/24 11:04:34 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_utils.h"

float	minf(float a, float b)
{
	return (a < b ? a : b);
}

int		mini(int a, int b)
{
	return (a > b ? a : b);
}

float	maxf(float a, float b)
{
	return (a > b ? a : b);
}

int		maxi(int a, int b)
{
	return (a < b ? a : b);
}
