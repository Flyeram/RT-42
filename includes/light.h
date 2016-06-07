#ifndef LIGHT_H
# define LIGHT_H

t_light		*light_new(t_vector3f pos, t_vector3f color);
t_vector3f	light_get_ambiant(t_light *l, t_ray_hit *h, float c);
t_vector3f	light_get_diffuse(t_light *l, t_ray *p, t_ray_hit *h);
t_vector3f	light_get_specular(t_light *l, t_ray *r, t_ray *p, t_ray_hit *h);
int			light_is_eligible(t_light *l, t_ray_hit *h, float *t);

#endif