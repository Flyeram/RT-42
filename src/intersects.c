#include "raytracer.h"
#include <stdio.h>

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

int			cone_intersect(t_ray *ray, t_object *obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		det;
	t_vector3f	dist;

	dist = v3f_sub(ray->start, obj->position);
	a = pow(cos(obj->radius), 2) *
		pow((ray->dir.x + ray->dir.z), 2) -
		pow(sin(obj->radius), 2) *
		pow(ray->dir.y, 2);

	b = 2 * pow(cos(obj->radius), 2) *
			(ray->dir.x * dist.x) +
			(ray->dir.z * dist.z) -
			2 * pow(sin(obj->radius), 2) *
			ray->dir.y * dist.y;
	c = pow(cos(obj->radius), 2) *
		pow(dist.x + dist.z, 2) -
		pow(sin(obj->radius), 2) *
		pow(dist.y, 2);
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

t_vector3f	cone_calculate_normal(t_ray *r, t_ray_hit *h)
{
	(void)r;
	return (v3f_normalized(v3f_add(h->point, v3f_negative(h->object->position))));
}

t_vector3f	cylinder_calculate_normal(t_ray *r, t_ray_hit *h)
{
	(void)r;
	return (v3f_normalized(v3f_add((t_vector3f) { h->point.x, 0, h->point.z },
								v3f_negative((t_vector3f) { h->object->position.x, 0, h->object->position.z }))));
}

t_vector3f	plane_calculate_normal(t_ray *r, t_ray_hit *h)
{
	if (v3f_dot(h->object->data, r->dir) < 0)
		return (h->object->data);
	else
		return (v3f_negative(h->object->data));
}

t_vector3f	sphere_calculate_normal(t_ray *r, t_ray_hit *h)
{
	(void)r;
	return (v3f_div_float(v3f_sub(h->point, h->object->position), h->object->radius));
}

/*int		sphere_intersect(t_ray *ray, t_object *object, float *delta)*/
/*{*/
	/*float		a;*/
	/*float		b;*/
	/*float		c;*/
	/*float		d;*/
	/*t_vector3f	dist;*/

	/*dist = v3f_sub(ray->start, object->position);*/
	/*a = v3f_dot(ray->dir, ray->dir);*/
	/*b = 2.0f * v3f_dot(ray->dir, dist);*/
	/*c = v3f_dot(dist, dist);*/
	/*d = (b * b) - (4.0f * (a * c));*/

	/*if (d == 0.0f)*/
	/*{*/
		/**delta = (-b);*/
		/*return (0);*/
	/*}*/
	/*if (d > 0.0f)*/
	/*{*/
		/**delta = sqrtf(d);*/
		/*float t1 = (-b + d) / (2.0f * a);*/
		/*float t2 = (-b - d) / (2.0f * a);*/
		/*if (t1 < t2)*/
		/*{*/
			/**delta = t1;*/
			/*return (1);*/
		/*}*/
		/*else*/
		/*{*/
			/**delta = t2;*/
			/*return (1);*/
		/*}*/
	/*}*/
	/*return (0);*/
/*}*/

/*int		plane_intersect(t_ray *ray, t_object *obj, float *delta)*/
/*{*/
	/*t_vector3f	dist;*/
	/*float		a;*/

	/*a = v3f_dot(ray->dir, obj->data);*/
	/*dist = v3f_add(ray->start, v3f_negative(v3f_mul_float(obj->data, obj->radius)));*/

	/*if (a == 0)*/
		/*return (0);*/
	/*else*/
	/*{*/
		/*(void)delta;*/
		/*return (0);*/
		/**delta = -1 * v3f_dot(obj->data, dist) / a;*/
		/*return (1);*/
	/*}*/
	/*return (0);*/
/*}*/
