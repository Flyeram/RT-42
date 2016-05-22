#include "raytracer.h"
#include <stdio.h>

int		rasterize(t_core *core)
{
	static int rasterized = 0;
	int pixel;
	int x;
	int y;

	if (rasterized == 0)
		rasterized = 1;
	else
		return (1);

	y = 0;
	while (y < core->screen_size.y)
	{
		x = 0;
		while (x < core->screen_size.x)
		{
			pixel = calculate_pixel(core, x, y);
			tex_draw_pixel(core->screen, x, y, pixel);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(core->mlx, core->win, core->screen->img, 0, 0);
	return (1);
}

int		raycast(t_ray *ray, t_ray_hit *hit, t_object *ignore, t_scene *scene)
{
	float		delta;
	t_object	*iterator;

	delta = ray->length;
	hit->object = NULL;
	hit->delta = delta;
	ray->dir = v3f_normalized(ray->dir);
	list_set_start(scene->objects);
	while ((iterator = list_next(scene->objects)))
	{
		if (ignore != NULL && ignore == iterator)
			continue ;
		if (iterator->intersect(ray, iterator, &delta))
		{
			if (delta < hit->delta)
			{
				hit->object = iterator;
				hit->delta = delta;
			}
		}
	}
	if (hit->object == NULL)
		return (0);
	hit->point = v3f_add(ray->start, v3f_mul_float(ray->dir, hit->delta));
	hit->normal = hit->object->calculate_normal(ray, hit);
	return (1);
}

t_vector3f	light_get_illumination(t_light *light, t_ray_hit *hit)
{
	float		angle;
	t_vector3f	light_vec;

	light_vec = v3f_normalized(v3f_sub(hit->point, light->position));
	angle = v3f_dot(hit->normal, v3f_negative(light_vec));
	if (angle <= 0)
		return ((t_vector3f) { 0.0f, 0.0f, 0.0f });
	else
		return (v3f_mul(hit->object->mat->diffuse,
						v3f_mul_float(light->intensity, angle)));
}

t_vector3f	calculate_lighting(t_scene *scene, t_ray_hit *hit)
{
	t_vector3f	color;
	t_ray		photon;
	t_ray_hit	photon_hit;
	t_light		*light;

	color = hit->object->mat->ambiant;
	list_set_start(scene->lights);
	while ((light = list_next(scene->lights)))
	{
		photon.start = hit->point;
		photon.dir = v3f_sub(light->position, hit->point);
		photon.length = v3f_length(photon.dir);
		if (!raycast(&photon, &photon_hit, hit->object, scene))
			color = v3f_add(color, light_get_illumination(light, hit));
	}
	return (color);
}

int		calculate_pixel(t_core *core, int x, int y)
{
	t_ray_hit	hit;
	t_ray		ray;

	ray.start = core->scene->camera->position;
	ray.dir = camera_ray_dir(core->scene->camera, x, y, core->screen_size);
	ray.length = MAX_RAY_LENGTH;
	if (!raycast(&ray, &hit, NULL, core->scene))
		return (0);
	return (v3f_to_color(calculate_lighting(core->scene, &hit)));
}
