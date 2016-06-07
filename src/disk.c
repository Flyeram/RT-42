#include "raytracer.h"

int			disk_intersect(t_ray *ray, t_object *obj, float *t)
{
	float		old_t;
	t_vector3f	dist;
	t_vector3f point;

	old_t = *t;
	if (plane_intersect(ray, obj, t))
	{
		point = v3f_add(ray->start, v3f_mul_float(ray->dir, *t));
		dist = v3f_sub(point, obj->position);
		if (v3f_dot(dist, dist) <= POW2(obj->radius))
			return (1);
		else
		{
			*t = old_t;
			return (0);
		}
	}
	else
		return (0);
}

void		disk_init(t_object *obj)
{
	obj->intersect = disk_intersect;
	obj->normal = plane_calculate_normal;
}
