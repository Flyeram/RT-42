#include "raytracer.h"

int			cylinder_intersect(t_ray *ray, t_object *obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		det;
	t_vector3f dist;

	dist = v3f_sub(ray->start, obj->position);
	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = (2 * (ray->dir.x * dist.x)) + (2 * (ray->dir.z * dist.z));
	c = (dist.x * dist.x + dist.z * dist.z) - (obj->radius * obj->radius);
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

t_vector3f	cylinder_calculate_normal(t_ray *r, t_ray_hit *h)
{
	(void)r;
	return (v3f_normalized(v3f_add((t_vector3f) { h->point.x, 0, h->point.z },
			v3f_negative((t_vector3f) { h->object->position.x,
										0,
										h->object->position.z }))));
}

void		cylinder_init(t_object *obj)
{
	obj->intersect = &cylinder_intersect;
	obj->calculate_normal = &cylinder_calculate_normal;
}
