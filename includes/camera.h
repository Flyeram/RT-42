#ifndef CAMERA_H
# define CAMERA_H

# define ZOOM	0.52056705055

t_camera	*camera_new(t_vector3f p, t_vector3f r, t_vector2f view);
t_vector3f	camera_direction(t_camera *c, t_vector2f pos);
void		camera_rotate(t_camera *cam, int key_code);
void		camera_move(t_camera *cam, int key_code);

#endif
