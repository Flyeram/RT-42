#include "raytracer.h"

int			cone_intersect(t_ray *ray, t_object *o, float *t)
{
	float		a;
	float		b;
	float		c;
	float		det;
	t_vector3f	d;

	d = v3f_sub(ray->start, o->position);
	a = pow(ray->dir.x, 2) - pow(ray->dir.y, 2) + pow(ray->dir.z, 2);
	b = ray->dir.x * d.x - ray->dir.y * d.y + ray->dir.z * d.z;
	c = pow(d.x, 2) + pow(d.z, 2) - pow(d.y, 2) + o->radius * o->radius;
	det = b * b - a * c;
	if (det < 0)
		return (0);
	det = sqrtf(det);
	if (det > 0)
		*t = minf((-b + det) / a, (-b - det) / a);
	else if (det == 0.0f)
		*t = -det;
	return (1);
}

t_vector3f	cone_calculate_normal(t_ray *r, t_ray_hit *h)
{
	(void)r;
	return (v3f_normalized(v3f_add(h->point,
									v3f_negative(h->object->position))));
}

void		cone_init(t_object *o)
{
	o->intersect = &cone_intersect;
	o->calculate_normal = &cone_calculate_normal;
}
