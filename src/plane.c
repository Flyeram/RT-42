/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			plane_intersect(t_ray *ray, t_object *obj, float *t)
{
	t_vector3f diff;
	float tmp;
	float scale_1;
	float scale_2;
	
	diff = v3f_sub(ray->start, obj->position);
	diff = v3f_mul_float(diff, -1);
	scale_1 = v3f_dot(obj->rotation, diff);
	scale_2 = v3f_dot(obj->rotation, ray->dir);
	if (scale_2 == 0)
		return (0);
	tmp = scale_1 / scale_2;
	if (tmp >= 0.01f)
	{
		*t = tmp;
		return (1);
	}
	return (0);
}

int			plane_calculate_normal(t_ray *r, t_ray_hit *h)
{
	float		dot;

	dot = v3f_dot(r->dir, h->object->rotation);
	if (dot < 0.01f)
		h->normal = v3f_mul_float(h->object->rotation, +1.00f);
	else
		h->normal = v3f_mul_float(h->object->rotation, -1.00f);
	return (1);
}

void		plane_init(t_object *obj)
{
	obj->intersect = &plane_intersect;
	obj->normal = &plane_calculate_normal;
}
