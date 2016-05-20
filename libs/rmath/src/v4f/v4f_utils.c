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

#include "rmath.h"

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

void		v4f_normalize(t_vector4f *vector)
{
	float length;

	length = v4f_length(*vector);
	vector->x /= length;
	vector->y /= length;
	vector->z /= length;
	vector->w /= length;
}
