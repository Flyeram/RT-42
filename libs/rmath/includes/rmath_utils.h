/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/05/24 13:38:51 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_UTILS_H
# define RMATH_UTILS_H

# include <stdlib.h>
# include "rmath_typedefs.h"
# include "rmath_structs.h"
# define PI 3.14159265358979323846
# define POW2(x) x * x

float	minf(float a, float b);
int		mini(int a, int b);
float	maxf(float a, float b);
int		maxi(int a, int b);
float	clampf(float val, float min, float max);
int		clampi(int val, int min, int max);
float	clampf01(float val);

#endif
