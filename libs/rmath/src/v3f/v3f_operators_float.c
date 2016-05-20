/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_operators_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:46:16 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath.h"

t_vector3f	v3f_add_float(t_vector3f v1, float val)
{
	return ((t_vector3f) { v1.x + val, v1.y + val, v1.z + val });
}

t_vector3f	v3f_sub_float(t_vector3f v1, float val)
{
	return ((t_vector3f) { v1.x - val, v1.y - val, v1.z - val });
}

t_vector3f	v3f_mul_float(t_vector3f v1, float val)
{
	return ((t_vector3f) { v1.x * val, v1.y * val, v1.z * val });
}

t_vector3f	v3f_div_float(t_vector3f v1, float val)
{
	return ((t_vector3f) { v1.x / val, v1.y / val, v1.z / val });
}
