/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 03:53:43 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath.h"

t_vector4f	v4f_add(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f){ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w });
}

t_vector4f	v4f_sub(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f){ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w });
}

t_vector4f	v4f_mul(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f){ v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w });
}

t_vector4f	v4f_div(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f){ v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w });
}

float		v4f_get_at(t_vector4f v, int index)
{
	return (((float *)&v)[index]);
}
