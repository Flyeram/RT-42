/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_material	*material_new(t_scene *scene, t_vector3f maps[3], float reflect, int texture)
{
	t_material *mat;

	mat = malloc(sizeof(t_material));
	mat->ambiant = maps[0];
	mat->diffuse = maps[1];
	mat->specular = maps[2];
	mat->reflection = reflect;
	mat->texture = NULL;
	if (texture >= 0)
		mat->texture = list_get_data_at(scene->textures, texture);
	return (mat);
}
