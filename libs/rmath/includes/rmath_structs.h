/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:30:57 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:20:38 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_STRUCTS_H
# define RMATH_STRUCTS_H

struct					s_vector3f
{
	float				x;
	float				y;
	float				z;
};

struct					s_vector4f
{
	float				x;
	float				y;
	float				z;
	float				w;
};

struct					s_vector2f
{
	float				x;
	float				y;
};

struct					s_matrix4f
{
	float				m[4][4];
};

#endif
