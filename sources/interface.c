/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 18:33:52 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 22:50:55 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdio.h>


void		interface_generate_layout(t_interface *ui, t_vector2f resolution)
{
	t_vector3f		scale_vector;
	t_matrix4f		*scale;
	t_ui_hook		hooks[4];
	t_ui_element	*elem;
	t_vector4f		remap;
	int				ytmp;
	float			offsetX;
	float			offsetY;
	float			pitY;
	float			pitX;

	scale_vector.x = resolution.x / NATIVE_WIDTH;
	scale_vector.y = resolution.y / NATIVE_HEIGHT;
	scale_vector.z = 0;
	scale = m4f_new();
	m4f_scale(scale, scale_vector);
	ui->matrix = scale;
	hooks[0] = button_click_down;
	hooks[2] = button_mouse_enter;
	hooks[3] = button_mouse_leave;


	offsetX = resolution.x / 20;
	offsetY = resolution.y / 20;
	pitY = resolution.y / 200;
	pitX = resolution.x / 200;


	ui->hide_ui = 1;
	// screenshot button
	remap = m4f_mul_vector(scale, V4F_INIT(200, 40, 0, 0));
	hooks[1] = button_hide_interface;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(offsetX, offsetY), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	ui->hide_label = label_new_attach(ui, elem, "Hide Interface");

	// screenshot button
	remap = m4f_mul_vector(scale, V4F_INIT(198, 40, 0, 0));
	hooks[1] = button_screenshot;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - remap.x - offsetX, offsetY), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	label_new_attach(ui, elem, "Screenshot");

	// reload button
	hooks[1] = button_reload_scene;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - remap.x - offsetX, offsetY + pitY + remap.y), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	label_new_attach(ui, elem, "Reload");


	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - remap.x - offsetX, offsetY + (pitY * 3) + (remap.y * 3)), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "Post Effects");

	hooks[1] = button_blurr;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - remap.x - offsetX, offsetY + (pitY * 4) + (remap.y * 4)), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	ui->blurr = label_new_attach(ui, elem, "Blurr : Off");

	hooks[1] = button_grayscale;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - remap.x - offsetX, offsetY + (pitY * 5) + (remap.y * 5)), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	ui->grayscale = label_new_attach(ui, elem, "Grayscale : Off");

	hooks[1] = button_sepia;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - remap.x - offsetX, offsetY + (pitY * 6) + (remap.y * 6)), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	ui->sepia = label_new_attach(ui, elem, "Sepia : Off");

	hooks[1] = button_inverse;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - remap.x - offsetX, offsetY + (pitY * 7) + (remap.y * 7)), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	ui->inverse = label_new_attach(ui, elem, "Inverse : Off");

	// aliasing label
	remap = m4f_mul_vector(scale, V4F_INIT(150 + (pitX * 2), 40, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - remap.x, offsetY + (pitY * 9) + (remap.y * 9)), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "Aliasing");

	// minus aliasing button
	ytmp = remap.y;
	hooks[1] = button_aliasing_down;
	remap = m4f_mul_vector(scale, V4F_INIT(50, 40, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - (remap.x * 3) - (pitX * 2), offsetY + (pitY * 10) + (remap.y * 10)), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	label_new_attach(ui, elem, "-");

	// aliasing value
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - (remap.x * 2) - pitX, offsetY + (pitY * 10) + (remap.y * 10)), V2F_INIT(remap.x, remap.y));
	ui->aliasing = label_new_attach(ui, elem, "1");
	label_update_text(ui->aliasing, "1", V3F_INIT(0, 1, 0));

	// plus aliasing button
	hooks[1] = button_aliasing_up;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - remap.x, offsetY + (pitY * 10) + (remap.y * 10)), V2F_INIT(remap.x, remap.y));
	element_bind_hooks(elem, hooks);
	label_new_attach(ui, elem, "+");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(offsetX + remap.x + pitX, resolution.y - offsetY - (remap.y * 2) - pitY), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "W");



	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - remap.x - pitX, resolution.y - offsetY - remap.y), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "Top");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - remap.x - pitX, resolution.y - offsetY - (remap.y * 2) - pitY), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "Bot");


	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - (remap.x * 2) - (pitX * 2), resolution.y - offsetY - remap.y), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, ">");


	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - (remap.x * 4) - (pitX * 4), resolution.y - offsetY - remap.y), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "<");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - (remap.x * 3) - (pitX * 3), resolution.y - offsetY - remap.y), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "v");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - offsetX - (remap.x * 3) - (pitX * 3), resolution.y - offsetY - (remap.y * 2) - pitY), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "^");

	ytmp = remap.y;
	remap = m4f_mul_vector(scale, V4F_INIT(200 + pitX * 3, 40, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(offsetX, resolution.y - offsetY - (ytmp * 3) - (pitY * 2)), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "Movements");

	elem = element_new(ui, 0xFFFFFF, V2F_INIT(resolution.x - remap.x - offsetX - pitX, resolution.y - offsetY - (ytmp * 3) - (pitY * 2)), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "Rotation");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(offsetX, resolution.y - offsetY - remap.y), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "Q");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(offsetX + remap.x + pitX, resolution.y - offsetY - remap.y), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "S");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(offsetX + (remap.x * 2) + (pitX * 2), resolution.y - offsetY - remap.y), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "D");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(offsetX + (remap.x * 3) + (pitX * 3), resolution.y - offsetY - (remap.y * 2) - pitY), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "T");

	remap = m4f_mul_vector(scale, V4F_INIT(50, 50, 0, 0));
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(offsetX + (remap.x * 3) + (pitX * 3), resolution.y - offsetY - remap.y), V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "G");

	progress_bar_init(ui, resolution);
}

void		interface_init(t_interface *ui, t_vector2f resolution)
{
	if (TTF_Init() == -1)
		exit(0);
	if ((ui->font = TTF_OpenFont("resources/font.ttf", resolution.y / 25)) == NULL)
		exit(0);
	ui->elements = list_new(sizeof(void *));
	ui->labels = list_new(sizeof(void *));
	interface_generate_layout(ui, resolution);
}

void		interface_poll_events(t_core *core)
{
	t_ui_element	*iterator;
	t_vector2f		mousepos;

	mousepos = get_mouse_pos();
	list_set_start(core->interface.elements);
	while ((iterator = list_next(core->interface.elements)))
		element_update(iterator, core, mousepos);
}

void		interface_draw(t_interface *ui, SDL_Surface *s)
{
	t_ui_element	*i;
	t_label			*j;

	list_set_start(ui->elements);
	while ((i = list_next(ui->elements)))
		if (i->active)
			SDL_BlitSurface(i->texture->img, NULL, s, (SDL_Rect *)&i->rect);
	list_set_start(ui->labels);
	while ((j = list_next(ui->labels)))
		if (j->active)
			SDL_BlitSurface(j->texture->img, NULL, s, (SDL_Rect *)&j->rect);
}
