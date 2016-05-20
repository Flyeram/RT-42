#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <libft.h>
#include <rlists.h>
#include <rmath.h>
#include <mlx.h>
#include "typedefs.h"
#include "structs.h"

#define MAX_RAY_LENGTH 20000.0f
#define MAX_RAY_REFLECTIONS 50

int			rasterize(t_core *core);
int			ray_hit(t_ray *ray, t_ray_hit *hit, t_scene *scene);
int			is_shadowed(t_ray *light, t_scene *scene, float delta);
int			calculate_pixel(t_scene *scene, int x, int y);
void		calculate_lighting(t_ray_hit *hit, t_ray *ray, t_scene *scene,
								float coef, float color[3]);
t_texture	*tex_new(t_core *env, int width, int height);
void		tex_clear(t_texture *tex);
void		tex_draw_pixel_index(t_texture *tex, int index, int pixel);
void		tex_draw_pixel(t_texture *tex, int x, int y, int pixel);
int			tex_get_pixel(t_texture *tex, int x, int y);
int			sphere_intersect(t_ray *ray, t_object *obj, float *delta);

#endif
