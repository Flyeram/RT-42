/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_v3f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/05/24 11:05:32 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_V3F_H
# define RMATH_V3F_H

# include <math.h>
# include <stdlib.h>
# include "rmath_utils.h"
# include "rmath_typedefs.h"
# include "rmath_structs.h"

# define V3F_INIT(x, y, z)	(t_vector3f) { x, y, z }
# define V3F_ZERO			(t_vector3f) { +0, +0, +0 }
# define V3F_ONE			(t_vector3f) { +1, +1, +1 }
# define V3F_FORWARD		(t_vector3f) { +0, +0, +1 }
# define V3F_BACK			(t_vector3f) { +0, +0, -1 }
# define V3F_UP				(t_vector3f) { +0, +1, +0 }
# define V3F_DOWN			(t_vector3f) { +0, -1, +0 }
# define V3F_RIGHT			(t_vector3f) { +1, +0, +0 }
# define V3F_LEFT			(t_vector3f) { -1, +0, +0 }

float			v3f_length(t_vector3f vector);
float			v3f_dot(t_vector3f v1, t_vector3f v2);
float			v3f_distance(t_vector3f v1, t_vector3f v2);
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
t_vector3f		v3f_negative(t_vector3f v);
t_vector3f		v3f_cross(t_vector3f v1, t_vector3f v2);
t_vector3f		*v3f_new(float x, float y, float z);
t_vector3f		*v3f_new_cpy(t_vector3f *src);
t_vector3f		*v3f_add_new(t_vector3f v1, t_vector3f v2);
t_vector3f		*v3f_sub_new(t_vector3f v1, t_vector3f v2);
t_vector3f		*v3f_mul_new(t_vector3f v1, t_vector3f v2);
t_vector3f		*v3f_div_new(t_vector3f v1, t_vector3f v2);
int				v3f_to_color(t_vector3f v);

#endif
