#include "raytracer.h"

void		rasterize(t_core *core)
{
	int pixel;
	int x;
	int y;

	core->scene->camera->sampling = 1;
	y = 0;
	while (y < core->screen_size.y)
	{
		x = 0;
		while (x < core->screen_size.x)
		{
			pixel = calculate_pixel(core->scene, core->scene->camera, x, y);
			tex_draw_pixel(core->screen, x, y, pixel);
			x++;
		}
		y++;
	}
}

int			calculate_pixel(t_scene *scene, t_camera *cam, int x, int y)
{
	t_vector3f	color;
	t_vector2f	sub;
	float		sampling;
	float		increment;

	sub.x = x;
	color = V3F_ZERO;
	sampling = (1.0f / cam->sampling);
	increment = (1.0f / (cam->sampling / 2));
	while (sub.x < x + 1)
	{
		sub.y = y;
		while (sub.y < y + 1)
		{
			color = v3f_add(color, calculate_sub_pixel(scene, cam, sub, sampling));
			sub.y += increment;
		}
		sub.x += increment;
	}
	return (v3f_to_color(color));
}

t_vector3f	calculate_sub_pixel(t_scene *scene, t_camera *cam, t_vector2f pos, float coef)
{
	t_ray_hit	hit;
	t_ray		ray;
	t_vector3f	color;
	float		reflection;

	color = V3F_ZERO;
	ray = RAY_INIT(cam->position, camera_direction(cam, pos), RAY_LENGTH);
	while (coef > 0.0f && ray.level < MAX_RAY_REFLECTIONS)
	{
		if (!ray_cast(&ray, &hit, scene))
			break ;
		color = v3f_add(color, calculate_lighting(scene, &ray, &hit, coef));
		/*color = v3f_mul(color, calculate_texture_color(&hit));*/
		coef *= hit.object->mat->reflection;
		reflection = 2.0f * v3f_dot(ray.dir, hit.normal);
		ray.start = hit.point;
		ray.dir = v3f_sub(ray.dir, v3f_mul_float(hit.normal, reflection));
		ray.level++;
	}
	return (color);
}

t_vector3f	calculate_lighting(t_scene *scene, t_ray *ray, t_ray_hit *hit, float coef)
{
	t_vector3f	color;
	t_ray		photon;
	t_light		*light;
	float		t;

	color = V3F_ZERO;
	list_set_start(scene->lights);
	while ((light = list_next(scene->lights)))
	{
		color = v3f_add(color, light_get_ambiant(light, hit, coef));
		if (!light_is_eligible(light, hit, &t))
			continue ;
		photon.start = hit->point;
		photon.dir = v3f_mul_float(v3f_sub(light->position, hit->point), 1 / t);
		photon.length = v3f_distance(photon.start, light->position);
		if (!ray_cast(&photon, NULL, scene))
			color =
			v3f_add(color,
					v3f_mul_float(v3f_add(light_get_specular(light, ray, &photon, hit),
										light_get_diffuse(light, &photon, hit)), coef));
	}
	return (color);
}

t_vector3f	calculate_texture_color(t_ray_hit *hit)
{
	t_vector2f	uv;
	t_vector3f	color;
	int			pixel;

	color = V3F_ONE;
	if (hit->object->mat->texture != NULL)
	{
		uv = ray_get_uv(hit);
		pixel = tex_get_pixel(hit->object->mat->texture, uv.x, uv.y);
		color = V3F_INIT(((pixel >> 16) & 0xFF) / 255,
						((pixel >> 8) & 0xFF) / 255,
						((pixel >> 0) & 0xFF) / 255);
	}
	return (color);
}
