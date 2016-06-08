/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct			s_scene
{
	t_list		*objects;
	t_list		*lights;
	t_list		*materials;
	t_list		*textures;
	t_camera	*camera;
};

struct			s_camera
{
	t_vector3f	position;
	t_vector3f	rotation;
	t_vector2f	viewport;
	int			sampling;
};

struct			s_object
{
	t_vector3f	position;
	t_vector3f	rotation;
	float		radius;
	t_material	*mat;
	t_intersect	intersect;
	t_normal	normal;
};

struct			s_material
{
	t_texture	*texture;
	t_vector3f	ambiant;
	t_vector3f	diffuse;
	t_vector3f	specular;
	float		reflection;
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
	int			level;
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
