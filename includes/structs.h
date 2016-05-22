#ifndef STRUCTS_H
#define STRUCTS_H

struct			s_scene
{
	t_list		*objects;
	t_list		*lights;
	t_list		*materials;
	t_camera	*camera;
};

struct			s_camera
{
	t_vector3f	up;
	t_vector3f	right;
	t_vector3f	up_left;
	t_vector3f	position;
	t_vector3f	direction;
	t_vector2f	viewport;
	float		viewdist;
};

struct			s_object
{
	t_vector3f	position;
	t_vector3f	data;
	float		radius;
	t_material	*mat;
	t_intersect	intersect;
	t_normal	calculate_normal;
};

struct			s_material
{
	t_vector3f	ambiant;
	t_vector3f	diffuse;
	t_vector3f	specular;
	float		shininess;
	float		shine_strength;
};

struct			s_light
{
	t_vector3f	position;
	t_vector3f	intensity;
};

struct			s_ray
{
	t_vector3f	start;
	t_vector3f	dir;
	float		length;
};

struct			s_ray_hit
{
	t_object	*object;
	t_vector3f	point;
	t_vector3f	normal;
	float		delta;
};

struct			s_texture
{
	void		*img;
	char		*pixels;
	int			bytes_per_pixel;
	int			l_size;
	int			size;
	int			width;
	int			height;
	int			endian;
};

struct			s_core
{
	void		*mlx;
	void		*win;
	t_texture	*screen;
	t_scene		*scene;
	t_vector2f	screen_size;
};

#endif
