/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_operators_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:46:16 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v4f.h"

t_vector4f	v4f_add_float(t_vector4f v1, float val)
{
	return ((t_vector4f) { v1.x + val, v1.y + val, v1.z + val, v1.w + val });
}

t_vector4f	v4f_sub_float(t_vector4f v1, float val)
{
	return ((t_vector4f) { v1.x - val, v1.y - val, v1.z - val, v1.w - val });
}

t_vector4f	v4f_mul_float(t_vector4f v1, float val)
{
	return ((t_vector4f) { v1.x * val, v1.y * val, v1.z * val, v1.w * val });
}

t_vector4f	v4f_div_float(t_vector4f v1, float val)
{
	return ((t_vector4f) { v1.x / val, v1.y / val, v1.z / val, v1.w / val });
}
