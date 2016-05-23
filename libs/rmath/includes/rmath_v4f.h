/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_v4f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/23 13:04:14 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_V4F_H
# define RMATH_V4F_H

# include <math.h>
# include <stdlib.h>
# include "rmath_utils.h"
# include "rmath_typedefs.h"
# include "rmath_structs.h"

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
t_vector4f		v4f_negative(t_vector4f v);
t_vector4f		*v4f_new(float x, float y, float z, float w);
t_vector4f		*v4f_new_cpy(t_vector4f *src);
t_vector4f		*v4f_add_new(t_vector4f v1, t_vector4f v2);
t_vector4f		*v4f_sub_new(t_vector4f v1, t_vector4f v2);
t_vector4f		*v4f_mul_new(t_vector4f v1, t_vector4f v2);
t_vector4f		*v4f_div_new(t_vector4f v1, t_vector4f v2);
inline int		v4f_to_color(t_vector4f color);

#endif
