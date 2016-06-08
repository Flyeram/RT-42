/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTERIZER_H
# define RASTERIZER_H

void		rasterize(t_core *core);
int			calculate_pixel(t_scene *scene, t_camera *cam, int x, int y);
t_vector3f	calculate_sub_pixel(t_scene *scene, t_camera *cam, t_vector2f pos, float coef);
t_vector3f	calculate_lighting(t_scene *scene, t_ray *ray, t_ray_hit *hit, float coef);
t_vector3f	calculate_texture_color(t_ray_hit *hit);

#endif
