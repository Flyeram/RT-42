#include "raytracer.h"

t_camera	*camera_new(t_vector3f pos, t_vector3f look, t_vector3f up)
{
	t_camera	*ret;
	t_vector3f	ratio;

	ret = malloc(sizeof(t_camera));
	ret->viewdist = 1.0f;
	ret->viewport = (t_vector2f) { 0.5f, 0.35f };
	ret->position = pos;
	ret->up = up;
	ret->direction = v3f_normalized(v3f_sub(look, pos));
	ret->right = v3f_cross(ret->up, ret->direction);
	ret->up = v3f_cross(ret->direction, ret->right);
	ratio = v3f_sub(v3f_mul_float(ret->up, ret->viewport.y / 2.0f),
					v3f_mul_float(ret->right, ret->viewport.x / 2.0f));
	ratio = v3f_add(ratio, v3f_mul_float(ret->direction, ret->viewdist));
	ret->up_left = v3f_add(ret->position, ratio);
	return (ret);
}

t_vector3f	camera_ray_dir(t_camera *cam, float x, float y, t_vector2f screen)
{
	t_vector3f sub;

	x = (cam->viewport.x / screen.x) * x;
	y = (cam->viewport.y / screen.y) * y;
	sub = v3f_sub(v3f_mul_float(cam->right, x), v3f_mul_float(cam->up, y));

	return (v3f_sub(v3f_add(cam->up_left, sub), cam->position));
}
