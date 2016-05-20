/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_operators_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:54:05 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath.h"

t_vector4f	*v4f_new(float x, float y, float z, float w)
{
	t_vector4f	*ret;

	ret = (t_vector4f *)malloc(sizeof(t_vector4f));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->w = w;
	return (ret);
}

t_vector4f	*v4f_add_new(t_vector4f v1, t_vector4f v2)
{
	return (v4f_new(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w));
}

t_vector4f	*v4f_sub_new(t_vector4f v1, t_vector4f v2)
{
	return (v4f_new(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w));
}

t_vector4f	*v4f_mul_new(t_vector4f v1, t_vector4f v2)
{
	return (v4f_new(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w));
}

t_vector4f	*v4f_div_new(t_vector4f v1, t_vector4f v2)
{
	return (v4f_new(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w));
}
