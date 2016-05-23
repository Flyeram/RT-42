#include "raytracer.h"

t_material	*material_new(t_vector3f amb, t_vector3f diff, t_vector3f spec)
{
	t_material *mat;

	mat = malloc(sizeof(t_material));
	mat->ambiant = amb;
	mat->diffuse = diff;
	mat->specular = spec;
	return (mat);
}
