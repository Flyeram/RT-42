/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int				ray_cast(t_ray *ray, t_ray_hit *hit, t_scene *scene)
{
	float		delta;
	float		min_delta;
	t_object	*selected;
	t_object	*iterator;

	selected = NULL;
	delta = ray->length;
	min_delta = delta;
	list_set_start(scene->objects);
	while ((iterator = list_next(scene->objects)))
		if (iterator->intersect(ray, iterator, &delta))
			if (delta < min_delta && ((min_delta = delta) > 0))
				selected = iterator;
	if (selected == NULL)
		return (0);
	if (hit != NULL)
	{
		hit->object = selected;
		hit->delta = min_delta;
		hit->point = v3f_add(ray->start, v3f_mul_float(ray->dir, hit->delta));
		return (hit->object->normal(ray, hit));
	}
	return (1);
}

t_vector2f		ray_get_uv(t_ray_hit *hit)
{
	t_vector3f	north;
	t_vector3f	equa;
	t_vector3f	dist;
	float		theta;
	float		phi;

	dist = v3f_normalized(v3f_sub(hit->point, hit->object->position));
	north = v3f_normalized(V3F_INIT(0, hit->object->radius, 0));
	equa = v3f_normalized(V3F_INIT(hit->object->radius, 0, 0));
	phi = acos(-v3f_dot(north, dist));
	theta = (acos(v3f_dot(dist, equa) / sin(phi))) / (2 * PI);
	if (v3f_dot(v3f_cross(north, equa), dist) <= 0)
		theta = 1 - theta;
	phi = phi / PI;
	return (V2F_INIT(theta, phi));
}
