/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# define RAY_LENGTH 20000.0f
# define MAX_RAY_REFLECTIONS 2
# define RAY_INIT(pos, dir, length) (t_ray) { pos, dir, length, 0};

int				ray_cast(t_ray *ray, t_ray_hit *hit, t_scene *scene);
t_vector2f		ray_get_uv(t_ray_hit *hit);

#endif
