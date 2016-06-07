#ifndef TEXTURE_H
# define TEXTURE_H

t_texture	*tex_new(void *env, int width, int height);
t_texture	*tex_new_xpm(void *env, char *file);
void		tex_clear(t_texture *tex);
void		tex_draw_pixel(t_texture *tex, int x, int y, int pixel);
int			tex_get_pixel(t_texture *tex, int x, int y);

#endif
