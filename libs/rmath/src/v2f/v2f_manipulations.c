/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_manipulations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/19 08:07:36 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v2f.h"

float		v2f_length(t_vector2f vector)
{
	return ((float)sqrt(vector.x * vector.x + vector.y * vector.y));
}

float		v2f_dot(t_vector2f v1, t_vector2f v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

t_vector2f	v2f_normalized(t_vector2f vector)
{
	float length;

	length = v2f_length(vector);
	vector.x /= length;
	vector.y /= length;
	return (vector);
}

void		v2f_normalize(t_vector2f *vector)
{
	float length;

	length = v2f_length(*vector);
	vector->x /= length;
	vector->y /= length;
}

t_vector2f	v2f_rotate(t_vector2f vector, float angle)
{
	float rad;
	float cosf;
	float sinf;

	rad = angle * PI / 180.0f;
	cosf = (float)cos(rad);
	sinf = (float)sin(rad);
	vector.x = vector.x * cosf - vector.y * sinf;
	vector.y = vector.x * sinf + vector.y * cosf;
	return (vector);
}
