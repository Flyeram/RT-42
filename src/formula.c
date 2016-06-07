#include "raytracer.h"

int			resolve_quadratic(float det, float a, float b, float *t)
{
	float		sqr;
	float		t_array[2];
	int			ret_value;

	ret_value = 0;
	sqr = sqrt(det);
	t_array[0] = (-b - sqr) / (2 * a);
	t_array[1] = (-b + sqr) / (2 * a);
	if (t_array[0] > 0.01f && (t_array[0] < *t))
	{
		*t = t_array[0];
		ret_value = 1;
	}
	if (t_array[1] > 0.01f && (t_array[1] < *t))
	{
		*t = t_array[1];
		ret_value = 1;
	}
	return (ret_value);
}
