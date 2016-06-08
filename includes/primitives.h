/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVES_H
# define PRIMITIVES_H


int		sphere_intersect(t_ray *ray, t_object *obj, float *delta);
int		plane_intersect(t_ray *ray, t_object *obj, float *delta);
int		cylinder_intersect(t_ray *ray, t_object *obj, float *delta);
int		cone_intersect(t_ray *ray, t_object *obj, float *delta);
int		disk_intersect(t_ray *ray, t_object *obj, float *delta);

int		sphere_calculate_normal(t_ray *r, t_ray_hit *h);
int		plane_calculate_normal(t_ray *r, t_ray_hit *h);
int		cylinder_calculate_normal(t_ray *r, t_ray_hit *h);
int		cone_calculate_normal(t_ray *r, t_ray_hit *h);

void	sphere_init(t_object *obj);
void	plane_init(t_object *obj);
void	cylinder_init(t_object *obj);
void	cone_init(t_object *obj);
void	disk_init(t_object *obj);

int		resolve_quadratic(float det, float a, float b, float *t);

#endif
