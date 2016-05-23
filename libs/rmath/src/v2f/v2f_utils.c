/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:44:49 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:47:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v2f.h"

t_vector2f	*v2f_new_cpy(t_vector2f *src)
{
	return (v2f_new(src->x, src->y));
}

t_vector2f	v2f_lerp(t_vector2f v1, t_vector2f v2, float l)
{
	t_vector2f tmp;

	tmp = v2f_sub(v2, v1);
	tmp.x *= l;
	tmp.y *= l;
	tmp = v2f_add(tmp, v1);
	return (tmp);
}

t_vector2f	v2f_negative(t_vector2f v)
{
	return ((t_vector2f) { -v.x, -v.y });
}
