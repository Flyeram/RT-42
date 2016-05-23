/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/23 13:04:14 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_UTILS_H
# define RMATH_UTILS_H

# include <stdlib.h>
# include "rmath_typedefs.h"
# include "rmath_structs.h"
# define PI 3.14159265358979323846

inline float	minf(float a, float b);
inline int		mini(int a, int b);
inline float	maxf(float a, float b);
inline int		maxi(int a, int b);
inline float	clampf(float val, float min, float max);
inline int		clampi(int val, int min, int max);
inline float	clampf01(float val);

#endif
