/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_m4f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/23 13:04:14 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_M4F_H
# define RMATH_M4F_H

# include <math.h>
# include <stdlib.h>
# include "rmath_utils.h"
# include "rmath_typedefs.h"
# include "rmath_structs.h"

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

#endif
