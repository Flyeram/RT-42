#ifndef RAY_H
# define RAY_H

# define RAY_LENGTH 20000.0f
# define MAX_RAY_REFLECTIONS 2
# define RAY_INIT(pos, dir, length) (t_ray) { pos, dir, length, 0};

int				ray_cast(t_ray *ray, t_ray_hit *hit, t_scene *scene);
t_vector2f		ray_get_uv(t_ray_hit *hit);

#endif
