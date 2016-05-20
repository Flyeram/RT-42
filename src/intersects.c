#include "raytracer.h"
#include <stdio.h>

int		sphere_intersect(t_ray *ray, t_object *object, float *delta)
{
	/*static int	test = 0;*/
	t_vector3f	dist;
	float		b;
	float		d;
	float		solutions[2];
	int			correct_solution;

	/*test ++;*/
	dist = v3f_sub(object->position, ray->start);

	/*printf("%d\n", test);*/
	/*printf("%f : %f : %f\n", object->position.x, object->position.y, object->position.z);*/
	/*printf("%f : %f : %f\n", dist.x, dist.y, dist.z);*/

	b = v3f_dot(ray->dir, dist);
	d = b * b - v3f_dot(dist, dist) + object->scale.x * object->scale.x;
	if (d < 0.0f)
		return (0);

	/*printf("%f\n", b);*/

	solutions[0] = b - sqrtf(d);
	solutions[1] = b + sqrtf(d);

	/*printf("%f : %f\n", solutions[0], solutions[1]);*/
	correct_solution = 0;
	if (solutions[0] > 0.1f && solutions[0] < *delta)
	{
		*delta = solutions[0];
		correct_solution = 1;
	}
	if (solutions[1] > 0.1f && solutions[1] < *delta)
	{
		*delta = solutions[1];
		correct_solution = 1;
	}
	return (correct_solution);
}
