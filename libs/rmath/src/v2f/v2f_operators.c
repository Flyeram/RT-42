/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:46:16 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath.h"

t_vector2f	v2f_add(t_vector2f v1, t_vector2f v2)
{
	return ((t_vector2f) { v1.x + v2.x, v1.y + v2.y });
}

t_vector2f	v2f_sub(t_vector2f v1, t_vector2f v2)
{
	return ((t_vector2f) { v1.x - v2.x, v1.y - v2.y });
}

t_vector2f	v2f_mul(t_vector2f v1, t_vector2f v2)
{
	return ((t_vector2f) { v1.x * v2.x, v1.y * v2.y });
}

t_vector2f	v2f_div(t_vector2f v1, t_vector2f v2)
{
	return ((t_vector2f) { v1.x / v2.x, v1.y / v2.y });
}
