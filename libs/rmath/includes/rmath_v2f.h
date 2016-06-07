/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_v2f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/23 13:04:14 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_V2F_H
# define RMATH_V2F_H

# include <math.h>
# include <stdlib.h>
# include "rmath_utils.h"
# include "rmath_typedefs.h"
# include "rmath_structs.h"

# define V2F_INIT(x, y)		(t_vector2f) { x, y }
# define V2F_ZERO			(t_vector2f) { +0, +0 }
# define V2F_ONE			(t_vector2f) { +1, +1 }
# define V2F_UP				(t_vector2f) { +0, +1 }
# define V2F_DOWN			(t_vector2f) { +0, -1 }
# define V2F_RIGHT			(t_vector2f) { +1, +0 }
# define V2F_LEFT			(t_vector2f) { -1, +0 }

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
t_vector2f		v2f_negative(t_vector2f v);
t_vector2f		*v2f_new(float x, float y);
t_vector2f		*v2f_new_cpy(t_vector2f *src);
t_vector2f		*v2f_add_new(t_vector2f v1, t_vector2f v2);
t_vector2f		*v2f_sub_new(t_vector2f v1, t_vector2f v2);
t_vector2f		*v2f_mul_new(t_vector2f v1, t_vector2f v2);
t_vector2f		*v2f_div_new(t_vector2f v1, t_vector2f v2);

#endif
