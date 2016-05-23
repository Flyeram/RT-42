#include "raytracer.h"

int			plane_intersect(t_ray *ray, t_object *obj, float *t)
{
	float		dir_val;

	dir_val = v3f_dot(obj->data, ray->dir);
	if (dir_val == 0)
		return (0);
	*t = -(v3f_dot(obj->data, v3f_sub(ray->start, obj->position)) / dir_val);
	if (*t < 0.0f)
		return (0);
	return (1);

}

t_vector3f	plane_calculate_normal(t_ray *r, t_ray_hit *h)
{
	if (v3f_dot(h->object->data, r->dir) < 0)
		return (h->object->data);
	else
		return (v3f_negative(h->object->data));
}

void		plane_init(t_object *obj)
{
	obj->intersect = &plane_intersect;
	obj->calculate_normal = &plane_calculate_normal;
}
