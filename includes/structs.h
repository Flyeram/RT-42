#ifndef STRUCTS_H
#define STRUCTS_H

struct			s_scene
{
	t_vector2f	viewport;
	t_list		*objects;
	t_list		*lights;
	t_list		*materials;
};

struct			s_object
{
	t_vector3f	position;
	t_vector3f	scale;
	t_material	*mat;
	t_intersect	intersect;
	
};

struct			s_material
{
	t_vector3f	diffuse;
	t_vector3f	specular;
	float		diff_value;
	float		spec_value;
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
	int			reflected;
};

struct			s_ray_hit
{
	t_object	*object;
	t_vector3f	normal;
	t_vector3f	point;
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
};

#endif
