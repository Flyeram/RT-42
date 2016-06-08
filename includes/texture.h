/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:58:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

t_texture	*tex_new(void *env, int width, int height);
t_texture	*tex_new_xpm(void *env, char *file);
void		tex_clear(t_texture *tex);
void		tex_draw_pixel(t_texture *tex, int x, int y, int pixel);
int			tex_get_pixel(t_texture *tex, int x, int y);

#endif
