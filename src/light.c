/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_light			*light_new(t_vector3f pos, t_vector3f color)
{
	t_light *lgt;

	lgt = malloc(sizeof(t_light));
	lgt->position = pos;
	lgt->intensity = color;
	return (lgt);
}

int				light_is_eligible(t_light *light, t_ray_hit *hit, float *t)
{
	t_vector3f dist;

	dist = v3f_sub(light->position, hit->point);
	if (v3f_dot(hit->normal, dist) <= 0.01f || (*t = sqrt(v3f_dot(dist, dist))) <= 0.01f)
		return (0);
	return (1);
}

t_vector3f		light_get_ambiant(t_light *light, t_ray_hit *hit, float coef)
{
	t_vector3f	color;

	color = v3f_mul(hit->object->mat->diffuse, calculate_texture_color(hit));
	return (v3f_mul_float(v3f_mul(color, light->intensity), 0.2f * coef));
}

t_vector3f		light_get_diffuse(t_light *light, t_ray *photon, t_ray_hit *hit)
{
	t_vector3f	color;
	float		lambert;

	color = v3f_mul(hit->object->mat->diffuse, calculate_texture_color(hit));
	lambert = v3f_dot(photon->dir, hit->normal);
	return (v3f_mul_float(v3f_mul(color, light->intensity), lambert));
}

t_vector3f		light_get_specular(t_light *light, t_ray *ray, t_ray *photon, t_ray_hit *hit)
{
	t_vector3f	dir;
	float		factor;

	dir = v3f_mul_float(hit->normal, 2 * v3f_dot(hit->normal, photon->dir));
	dir = v3f_sub(dir, photon->dir);
	factor = pow(v3f_dot(dir, ray->dir), 20);
	return (v3f_mul_float(light->intensity, 0.6f * factor));
}
