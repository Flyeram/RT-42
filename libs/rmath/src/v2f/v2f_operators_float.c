/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_operators_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:46:16 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v2f.h"

t_vector2f	v2f_add_float(t_vector2f v1, float val)
{
	return ((t_vector2f) { v1.x + val, v1.y + val });
}

t_vector2f	v2f_sub_float(t_vector2f v1, float val)
{
	return ((t_vector2f) { v1.x - val, v1.y - val });
}

t_vector2f	v2f_mul_float(t_vector2f v1, float val)
{
	return ((t_vector2f) { v1.x * val, v1.y * val });
}

t_vector2f	v2f_div_float(t_vector2f v1, float val)
{
	return ((t_vector2f) { v1.x / val, v1.y / val });
}
