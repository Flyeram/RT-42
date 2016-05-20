/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_operators_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:47:40 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath.h"

t_vector2f	*v2f_new(float x, float y)
{
	t_vector2f	*ret;

	ret = (t_vector2f *)malloc(sizeof(t_vector2f));
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_vector2f	*v2f_add_new(t_vector2f v1, t_vector2f v2)
{
	return (v2f_new(v1.x + v2.x, v1.y + v2.y));
}

t_vector2f	*v2f_sub_new(t_vector2f v1, t_vector2f v2)
{
	return (v2f_new(v1.x - v2.x, v1.y - v2.y));
}

t_vector2f	*v2f_mul_new(t_vector2f v1, t_vector2f v2)
{
	return (v2f_new(v1.x * v2.x, v1.y * v2.y));
}

t_vector2f	*v2f_div_new(t_vector2f v1, t_vector2f v2)
{
	return (v2f_new(v1.x / v2.x, v1.y / v2.y));
}
