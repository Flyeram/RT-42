/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_texture		*tex_new(void *mlx, int width, int height)
{
	t_texture	*ret;

	ret = (t_texture *)malloc(sizeof(t_texture));
	if ((ret->img = mlx_new_image(mlx, width, height)) == NULL)
		exit(0);
	if ((ret->pixels = mlx_get_data_addr(ret->img,
										&ret->bytes_per_pixel,
										&ret->l_size,
										&ret->endian)) == NULL)
		exit(0);
	ret->bytes_per_pixel /= 8;
	ret->width = width;
	ret->height = height;
	ret->size = ret->height * ret->l_size;
	return (ret);
}

t_texture		*tex_new_xpm(void *mlx, char *file)
{
	t_texture	*ret;

	ret = (t_texture *)malloc(sizeof(t_texture));
	if ((ret->img = mlx_xpm_file_to_image(mlx, file,
												&ret->width,
												&ret->height)) == NULL)
		exit(0);
	if ((ret->pixels = mlx_get_data_addr(ret->img,
										&ret->bytes_per_pixel,
										&ret->l_size,
										&ret->endian)) == NULL)
	ret->bytes_per_pixel /= 8;
	ret->size = ret->height * ret->l_size;
	return (ret);
}

void			tex_clear(t_texture *tex)
{
	ft_memset(tex->pixels, 0, tex->size);
}

void			tex_draw_pixel(t_texture *tex, int x, int y, int pixel)
{
	*((unsigned int *)(tex->pixels +
	((y * tex->l_size) +
	(x * tex->bytes_per_pixel)))) = pixel;
}

int				tex_get_pixel(t_texture *tex, int x, int y)
{
	return (*((unsigned int *)(tex->pixels +
			((y * tex->l_size) +
			(x * tex->bytes_per_pixel)))));
}
