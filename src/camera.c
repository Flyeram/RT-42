#include "raytracer.h"

t_camera	*camera_new(t_vector3f pos, t_vector3f rotation, t_vector2f size)
{
	t_camera	*ret;

	ret = malloc(sizeof(t_camera));
	ret->viewport = size;
	ret->position = pos;
	ret->rotation = rotation;
	return (ret);
}

t_vector3f	camera_direction(t_camera *cam, t_vector2f pos)
{
	t_vector3f	dir;
	float		ratio;

	ratio = cam->viewport.x / cam->viewport.y;
	pos.x = (2 * (pos.x / cam->viewport.x) - 1) * ratio * ZOOM;
	pos.y = (1 - 2 * (pos.y / cam->viewport.y)) * ZOOM;
	dir.x = pos.x * cos(cam->rotation.y) * cos(cam->rotation.x) +
			pos.y * (cos(cam->rotation.y) * sin(cam->rotation.x) *
			sin(cam->rotation.z) - sin(cam->rotation.y) *
			cos(cam->rotation.z)) + cos(cam->rotation.y) *
			sin(cam->rotation.x) * cos(cam->rotation.z) +
			sin(cam->rotation.y) * sin(cam->rotation.z);
	dir.y = pos.x * sin(cam->rotation.y) * cos(cam->rotation.x) +
			pos.y * (sin(cam->rotation.y) * sin(cam->rotation.x) *
			sin(cam->rotation.z) + cos(cam->rotation.y) *
			cos(cam->rotation.z)) + sin(cam->rotation.y) *
			sin(cam->rotation.x) * cos(cam->rotation.z) -
			cos(cam->rotation.y) * sin(cam->rotation.z);
	dir.z = pos.x * -sin(cam->rotation.x) + pos.y * cos(cam->rotation.x) *
				sin(cam->rotation.z) + cos(cam->rotation.x) * cos(cam->rotation.z);
	return (v3f_normalized(dir));
}

void	camera_move(t_camera *cam, int key_code)
{
	if (key_code == MOVE_RIGHT)
		cam->position.x -= 50;
	else if (key_code == MOVE_LEFT)
		cam->position.x += 50;
	else if (key_code == MOVE_UP)
		cam->position.y -= 50;
	else if (key_code == MOVE_DOWN)
		cam->position.y += 50;
	else if (key_code == MOVE_FORWARD)
		cam->position.z += 50;
	else if (key_code == MOVE_BACK)
		cam->position.z -= 50;
}

void	camera_rotate(t_camera *cam, int key_code)
{
	if (key_code == ROTATE_RIGHT)
		cam->rotation.x -= 50;
	else if (key_code == ROTATE_LEFT)
		cam->rotation.x += 50;
	else if (key_code == ROTATE_UP)
		cam->rotation.y -= 50;
	else if (key_code == ROTATE_DOWN)
		cam->rotation.y += 50;
	else if (key_code == ROTATE_FORWARD)
		cam->rotation.z += 50;
	else if (key_code == ROTATE_BACK)
		cam->rotation.z -= 50;
}
