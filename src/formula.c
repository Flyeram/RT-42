/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			resolve_quadratic(float det, float a, float b, float *t)
{
	float		sqr;
	float		t_array[2];
	int			ret_value;

	ret_value = 0;
	sqr = sqrt(det);
	t_array[0] = (-b - sqr) / (2 * a);
	t_array[1] = (-b + sqr) / (2 * a);
	if (t_array[0] > 0.01f && (t_array[0] < *t))
	{
		*t = t_array[0];
		ret_value = 1;
	}
	if (t_array[1] > 0.01f && (t_array[1] < *t))
	{
		*t = t_array[1];
		ret_value = 1;
	}
	return (ret_value);
}
