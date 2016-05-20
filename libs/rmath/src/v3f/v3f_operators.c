/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:51:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath.h"

t_vector3f	v3f_add(t_vector3f v1, t_vector3f v2)
{
	return ((t_vector3f) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z });
}

t_vector3f	v3f_sub(t_vector3f v1, t_vector3f v2)
{
	return ((t_vector3f) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z });
}

t_vector3f	v3f_mul(t_vector3f v1, t_vector3f v2)
{
	return ((t_vector3f) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z });
}

t_vector3f	v3f_div(t_vector3f v1, t_vector3f v2)
{
	return ((t_vector3f) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z });
}
