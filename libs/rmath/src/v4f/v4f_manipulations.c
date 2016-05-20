/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_manipulations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:56:55 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath.h"

float		v4f_length(t_vector4f vector)
{
	return ((float)sqrt(vector.x * vector.x +
						vector.y * vector.y +
						vector.z * vector.z +
						vector.w * vector.w));
}

float		v4f_dot(t_vector4f v1, t_vector4f v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

t_vector4f	v4f_normalized(t_vector4f vector)
{
	float length;

	length = v4f_length(vector);
	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	vector.w /= length;
	return (vector);
}

t_vector4f	v4f_rotate(t_vector4f vector, float angle)
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

t_vector4f v4f_cross(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f) {	v1.y * v2.z - v1.z * v2.y,
							v1.z * v2.x - v1.x * v2.z,
							v1.x * v2.y - v1.y * v2.x,
							v1.y * v2.w - v1.w * v2.y });
}
