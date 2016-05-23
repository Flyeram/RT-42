#include "raytracer.h"

t_light		*light_new(t_vector3f pos, t_vector3f color)
{
	t_light *lgt;

	lgt = malloc(sizeof(t_light));
	lgt->position = pos;
	lgt->intensity = color;
	return (lgt);
}

t_vector3f	light_get_diffuse(t_light *light, t_ray_hit *hit)
{
	float		angle;
	t_vector3f	light_vec;

	light_vec = v3f_normalized(v3f_sub(hit->point, light->position));
	angle = v3f_dot(hit->normal, v3f_negative(light_vec));
	if (angle <= 0)
		return ((t_vector3f) { 0.0f, 0.0f, 0.0f });
	else
		return (v3f_mul(hit->object->mat->diffuse,
						v3f_mul_float(light->intensity, angle)));

}

t_vector3f	light_get_specular(t_light *light, t_ray_hit *hit)
{
	t_vector3f	light_vec;
	t_vector3f	normal;
	float		dot;
	float		spec;

	light_vec = v3f_normalized(v3f_sub(hit->point, light->position));
	dot = -v3f_dot(light_vec, hit->normal);
	normal = v3f_mul_float(hit->normal, 2.0f * dot);
	spec = maxf(-v3f_dot(v3f_add(normal, light_vec), light_vec), 0);
	spec = powf(spec, 5);
	return (v3f_mul_float(hit->object->mat->specular, spec));
}
