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
int			calculate_pixel(t_core *scene, int x, int y);
t_vector3f	calculate_lighting(t_scene *scene, t_ray_hit *hit);
t_texture	*tex_new(t_core *env, int width, int height);
void		tex_clear(t_texture *tex);
void		tex_draw_pixel_index(t_texture *tex, int index, int pixel);
void		tex_draw_pixel(t_texture *tex, int x, int y, int pixel);
int			tex_get_pixel(t_texture *tex, int x, int y);
t_camera	*camera_new(t_vector3f pos, t_vector3f look, t_vector3f up);
t_vector3f	camera_ray_dir(t_camera *cam, float x, float y, t_vector2f screen);

void		scene_parse(t_core *core, t_scene *scene, char *path);
t_vector3f	parse_v3f(char **split);

t_object	*object_parse(char **split, t_scene *scene);
t_object	*object_new(t_vector3f p, t_vector3f d, float r, t_material *m);
void		object_set_type(t_object *obj, char *type);
t_light		*light_new(t_vector3f pos, t_vector3f color);
t_material	*material_new(t_vector3f a, t_vector3f d, t_vector3f s);

t_vector3f	light_get_diffuse(t_light *l, t_ray_hit *h);
t_vector3f	light_get_specular(t_light *l, t_ray_hit *h);

int			sphere_intersect(t_ray *ray, t_object *obj, float *delta);
int			plane_intersect(t_ray *ray, t_object *obj, float *delta);
int			cylinder_intersect(t_ray *ray, t_object *obj, float *delta);
int			cone_intersect(t_ray *ray, t_object *obj, float *delta);

t_vector3f	sphere_calculate_normal(t_ray *r, t_ray_hit *h);
t_vector3f	plane_calculate_normal(t_ray *r, t_ray_hit *h);
t_vector3f	cylinder_calculate_normal(t_ray *r, t_ray_hit *h);
t_vector3f	cone_calculate_normal(t_ray *r, t_ray_hit *h);

void		sphere_init(t_object *obj);
void		plane_init(t_object *obj);
void		cylinder_init(t_object *obj);
void		cone_init(t_object *obj);


#endif
