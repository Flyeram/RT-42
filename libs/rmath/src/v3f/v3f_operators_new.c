/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_operators_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:51:10 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath.h"

t_vector3f	*v3f_new(float x, float y, float z)
{
	t_vector3f	*ret;

	ret = (t_vector3f *)malloc(sizeof(t_vector3f));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

t_vector3f	*v3f_add_new(t_vector3f v1, t_vector3f v2)
{
	return (v3f_new(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector3f	*v3f_sub_new(t_vector3f v1, t_vector3f v2)
{
	return (v3f_new(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector3f	*v3f_mul_new(t_vector3f v1, t_vector3f v2)
{
	return (v3f_new(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

t_vector3f	*v3f_div_new(t_vector3f v1, t_vector3f v2)
{
	return (v3f_new(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z));
}
