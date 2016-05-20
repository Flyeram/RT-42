/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/23 13:04:14 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_H
# define RMATH_H

# include <math.h>
# include <stdlib.h>
# include "rmath_typedefs.h"
# include "rmath_structs.h"

# define PI 3.14159265358979323846

/*
**	MATRIX4F METHODS
*/
void			m4f_identity(t_matrix4f *matrix);
void			m4f_translate(t_matrix4f *matrix, t_vector3f t);
void			m4f_rotate(t_matrix4f *matrix, t_vector3f r);
void			m4f_scale(t_matrix4f *matrix, t_vector3f s);
void			m4f_screen_space(t_matrix4f *m, float width, float height);
void			m4f_perspective(t_matrix4f *m, float degfov,
								t_vector2f screen, t_vector2f frustum);
float			m4f_get_determinant(t_matrix4f *m);
void			m4f_adjugate(t_matrix4f *m);
void			m4f_invert(t_matrix4f *m);
t_matrix4f		*m4f_cpy(t_matrix4f *dst, t_matrix4f *src);
t_matrix4f		*m4f_mul(t_matrix4f *m1, t_matrix4f *m2);
t_matrix4f		*m4f_mul_new(t_matrix4f *m1, t_matrix4f *m2);
t_matrix4f		*m4f_new();
t_vector4f		m4f_mul_vector(t_matrix4f *m, t_vector4f v);
/*
**	VECTOR4F METHODS
*/
float			v4f_length(t_vector4f vector);
float			v4f_dot(t_vector4f v1, t_vector4f v2);
float			v4f_get_at(t_vector4f v, int index);
void			v4f_normalize(t_vector4f *vector);
t_vector4f		v4f_normalized(t_vector4f vector);
t_vector4f		v4f_rotate(t_vector4f vector, float angle);
t_vector4f		v4f_add(t_vector4f v1, t_vector4f v2);
t_vector4f		v4f_sub(t_vector4f v1, t_vector4f v2);
t_vector4f		v4f_mul(t_vector4f v1, t_vector4f v2);
t_vector4f		v4f_div(t_vector4f v1, t_vector4f v2);
t_vector4f		v4f_add_float(t_vector4f v1, float val);
t_vector4f		v4f_sub_float(t_vector4f v1, float val);
t_vector4f		v4f_mul_float(t_vector4f v1, float val);
t_vector4f		v4f_div_float(t_vector4f v1, float val);
t_vector4f		v4f_cross(t_vector4f v1, t_vector4f v2);
t_vector4f		v4f_lerp(t_vector4f v1, t_vector4f v2, float lerp_factor);
t_vector4f		*v4f_new(float x, float y, float z, float w);
t_vector4f		*v4f_new_cpy(t_vector4f *src);
t_vector4f		*v4f_add_new(t_vector4f v1, t_vector4f v2);
t_vector4f		*v4f_sub_new(t_vector4f v1, t_vector4f v2);
t_vector4f		*v4f_mul_new(t_vector4f v1, t_vector4f v2);
t_vector4f		*v4f_div_new(t_vector4f v1, t_vector4f v2);
/*
**	VECTOR3F METHODS
*/
float			v3f_length(t_vector3f vector);
float			v3f_dot(t_vector3f v1, t_vector3f v2);
void			v3f_normalize(t_vector3f *vector);
t_vector3f		v3f_normalized(t_vector3f vector);
t_vector3f		v3f_rotate(t_vector3f vector, float angle);
t_vector3f		v3f_add(t_vector3f v1, t_vector3f v2);
t_vector3f		v3f_sub(t_vector3f v1, t_vector3f v2);
t_vector3f		v3f_mul(t_vector3f v1, t_vector3f v2);
t_vector3f		v3f_div(t_vector3f v1, t_vector3f v2);
t_vector3f		v3f_add_float(t_vector3f v1, float val);
t_vector3f		v3f_sub_float(t_vector3f v1, float val);
t_vector3f		v3f_mul_float(t_vector3f v1, float val);
t_vector3f		v3f_div_float(t_vector3f v1, float val);
t_vector3f		v3f_lerp(t_vector3f v1, t_vector3f v2, float lerp_factor);
t_vector3f		*v3f_new(float x, float y, float z);
t_vector3f		*v3f_new_cpy(t_vector3f *src);
t_vector3f		*v3f_add_new(t_vector3f v1, t_vector3f v2);
t_vector3f		*v3f_sub_new(t_vector3f v1, t_vector3f v2);
t_vector3f		*v3f_mul_new(t_vector3f v1, t_vector3f v2);
t_vector3f		*v3f_div_new(t_vector3f v1, t_vector3f v2);
t_vector3f		v3f_cross(t_vector3f v1, t_vector3f v2);
/*
**	VECTOR2F METHODS
*/
float			v2f_length(t_vector2f vector);
float			v2f_dot(t_vector2f v1, t_vector2f v2);
void			v2f_normalize(t_vector2f *vector);
t_vector2f		v2f_normalized(t_vector2f vector);
t_vector2f		v2f_rotate(t_vector2f vector, float angle);
t_vector2f		v2f_add(t_vector2f v1, t_vector2f v2);
t_vector2f		v2f_sub(t_vector2f v1, t_vector2f v2);
t_vector2f		v2f_mul(t_vector2f v1, t_vector2f v2);
t_vector2f		v2f_div(t_vector2f v1, t_vector2f v2);
t_vector2f		v2f_add_float(t_vector2f v1, float val);
t_vector2f		v2f_sub_float(t_vector2f v1, float val);
t_vector2f		v2f_mul_float(t_vector2f v1, float val);
t_vector2f		v2f_div_float(t_vector2f v1, float val);
t_vector2f		v2f_lerp(t_vector2f v1, t_vector2f v2, float lerp_factor);
t_vector2f		*v2f_new(float x, float y);
t_vector2f		*v2f_new_cpy(t_vector2f *src);
t_vector2f		*v2f_add_new(t_vector2f v1, t_vector2f v2);
t_vector2f		*v2f_sub_new(t_vector2f v1, t_vector2f v2);
t_vector2f		*v2f_mul_new(t_vector2f v1, t_vector2f v2);
t_vector2f		*v2f_div_new(t_vector2f v1, t_vector2f v2);

#endif
