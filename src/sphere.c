#include "raytracer.h"

int			sphere_intersect(t_ray *ray, t_object *obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		det;
	t_vector3f	dist;

	dist = v3f_sub(ray->start, obj->position);
	a = v3f_dot(ray->dir, ray->dir);
	b = 2 * v3f_dot(ray->dir, dist);
	c = v3f_dot(dist, dist) - obj->radius * obj->radius;
	det = (b * b) - (4 * a * c);
	if (det < 0)
		return (0);
	det = sqrtf(det);
	if (det > 0)
		*t = minf((-b + det) / (2 * a), (-b - det) / (2 * a));
	else
		*t = -det;
	if (*t < 0.0f)
		return (0);
	return (1);
}

t_vector3f	sphere_calculate_normal(t_ray *r, t_ray_hit *h)
{
	(void)r;
	return (v3f_div_float(v3f_sub(h->point, h->object->position), h->object->radius));
}

void		sphere_init(t_object *obj)
{
	obj->intersect = &sphere_intersect;
	obj->calculate_normal = &sphere_calculate_normal;
}
