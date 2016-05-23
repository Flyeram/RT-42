/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:53:47 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 03:54:35 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v4f.h"

t_vector4f	*v4f_new_cpy(t_vector4f *src)
{
	return (v4f_new(src->x, src->y, src->z, src->w));
}

t_vector4f	v4f_lerp(t_vector4f v1, t_vector4f v2, float lerp_factor)
{
	t_vector4f tmp;

	tmp = v4f_sub(v2, v1);
	tmp.x *= lerp_factor;
	tmp.y *= lerp_factor;
	tmp.z *= lerp_factor;
	tmp.w *= lerp_factor;
	tmp = v4f_add(tmp, v1);
	return (tmp);
}

t_vector4f	v4f_negative(t_vector4f v)
{
	return ((t_vector4f) { -v.x, -v.y, -v.z, -v.w });
}

void		v4f_normalize(t_vector4f *vector)
{
	float length;

	length = v4f_length(*vector);
	vector->x /= length;
	vector->y /= length;
	vector->z /= length;
	vector->w /= length;
}

inline int	v4f_to_color(t_vector4f color)
{
	return (((unsigned char)(minf(color.w, 1.0f) * 255.0f) << 24) |
			((unsigned char)(minf(color.x, 1.0f) * 255.0f) << 16) |
			((unsigned char)(minf(color.y, 1.0f) * 255.0f) <<  8) |
			((unsigned char)(minf(color.z, 1.0f) * 255.0f)      ));
}
