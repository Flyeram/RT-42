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
	while (y < core->scene->viewport.y)
	{
		x = 0;
		while (x < core->scene->viewport.x)
		{
			pixel = calculate_pixel(core->scene, x, y);
			tex_draw_pixel(core->screen, x, y, pixel);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(core->mlx, core->win, core->screen->img, 0, 0);
	return (1);
}

int		ray_hit(t_ray *ray, t_ray_hit *hit, t_scene *scene)
{
	/*static int test = 0;*/
	float		dot;
	t_object	*iterator;
	t_object	*selected;

	selected = NULL;
	hit->delta = MAX_RAY_LENGTH;
	list_set_start(scene->objects);
	while ((iterator = list_next(scene->objects)) != NULL)
	{
		if (iterator->intersect(ray, iterator, &hit->delta))
			selected = iterator;
	}
	hit->object = selected;
	if (hit->object == NULL)
		return (0);
	hit->point = v3f_add(ray->start, v3f_mul_float(ray->dir, hit->delta));
	hit->normal = v3f_sub(hit->point, hit->object->position);
	/*printf("%f : %f : %f\n", ray->start.x, ray->start.y, ray->start.z);*/
	/*printf ("delta : %f\n", hit->delta);*/
	/*printf("hit.point       : %f : %f : %f\n", hit->point.x, hit->point.y, hit->point.z);*/
	/*printf("object.position : %f : %f : %f\n", selected->position.x, selected->position.y, selected->position.z);*/
	/*printf("hit.normal      : %f : %f : %f\n", hit->normal.x, hit->normal.y, hit->normal.z);*/
	dot = v3f_dot(hit->normal, hit->normal);
	if (dot == 0.0f)
		return (0);
	dot = 1.0f / sqrtf(dot);
	hit->normal = v3f_mul_float(hit->normal, dot);
	return (1);
}

int			is_shadowed(t_ray *light, t_scene *scene, float delta)
{
	t_object *object;

	list_set_start(scene->objects);
	while ((object = list_next(scene->objects)) != NULL)
	{
		if (object->intersect(light, object, &delta))
			return (1);
	}
	return (0);
}

float		max(float a, float b)
{
	return (a < b) ? b : a;
}

void		calculate_lighting(t_ray_hit *hit, t_ray *ray, t_scene *scene,
								float coef, float color[3])
{
	t_ray		light_ray;
	t_light		*light;
	float		factor;
	/*float		delta;*/
	/*t_vector3f	dist;*/

	light_ray.start = hit->point;
	list_set_start(scene->lights);
	while ((light = list_next(scene->lights)) != NULL)
	{
		/*if (v3f_dot(hit->normal, dist) <= 0.0f)*/
			/*continue ;*/
		/*delta = sqrtf(v3f_dot(dist, dist));*/
		light_ray.dir = v3f_sub(light->position, hit->point);
		float light_projection = v3f_dot(light_ray.dir, hit->normal);
		if (light_projection <= 0.0f)
			continue ;
		float light_dist = v3f_dot(light_ray.dir, light_ray.dir);
		float tmp = light_dist;
		if (light_dist == 0.0f)
			continue ;
		tmp = 1.0f / sqrtf(tmp);
		light_ray.dir = v3f_mul_float(light_ray.dir, tmp);
		light_projection *= tmp;
		if (!is_shadowed(&light_ray, scene, light_dist))
		{
			factor = v3f_dot(light_ray.dir, hit->normal) * coef;
			color[0] += factor * light->intensity.x * hit->object->mat->diffuse.x;
			color[1] += factor * light->intensity.y * hit->object->mat->diffuse.y;
			color[2] += factor * light->intensity.z * hit->object->mat->diffuse.z;

			t_vector3f blinnDir = v3f_sub(light_ray.dir, ray->dir);
			float f2 = v3f_dot(ray->dir, hit->normal);
			float temp = v3f_dot(blinnDir, blinnDir);
			if (temp != 0.0f)
			{
				float blinn = (1.0f / sqrt(temp)) * max(light_projection - f2, 0.0f);
				blinn = coef * powf(blinn, hit->object->mat->spec_value);
				color[0] += blinn * hit->object->mat->specular.x * light->intensity.x;
				color[1] += blinn * hit->object->mat->specular.y * light->intensity.y;
				color[2] += blinn * hit->object->mat->specular.z * light->intensity.z;
			}
		}
	}
}

int		calculate_pixel(t_scene *scene, int x, int y)
{
	float		reflect_coeff;
	float		reflect;
	float		color[3];
	t_ray_hit	hit;
	t_ray		ray;

	color[0] = 0.0f;
	color[1] = 0.0f;
	color[2] = 0.0f;
	reflect_coeff = 1.0f;
	ray = (t_ray) { { x, y, -10000.0f }, { 0.0f, 0.0f, 1.0f }, 0 };
	while (ray.reflected < MAX_RAY_REFLECTIONS && reflect_coeff > 0.0f)
	{
		if (!ray_hit(&ray, &hit, scene))
			break ;
		calculate_lighting(&hit, &ray, scene, reflect_coeff, color);
		reflect_coeff *= hit.object->mat->diff_value;
		reflect = 2.0f * v3f_dot(ray.dir, hit.normal);
		ray.start = hit.point;
		ray.dir = v3f_sub(ray.dir, v3f_mul_float(hit.normal, reflect));
		/*printf("%f : %f : %f\n", ray.dir.x, ray.dir.y, ray.dir.z);*/
		ray.reflected++;
	}
	/*printf("%f : %f : %f\n", ft_clampf01(color[0]) * 255.0f, ft_clampf01(color[1]) * 255.0f, ft_clampf01(color[2]) * 255.0f);*/
	return ((255 << 24) |
			((unsigned char)(ft_clampf01(color[2]) * 255.0f) << 16) |
			((unsigned char)(ft_clampf01(color[1]) * 255.0f) << 8) |
			((unsigned char)(ft_clampf01(color[0]) * 255.0f)));
}
