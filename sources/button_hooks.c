/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 21:23:12 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/29 15:55:56 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	button_mouse_enter(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xCCCCCC);
	swap_buffer(core);
}

void	button_mouse_leave(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	swap_buffer(core);
}

void	button_click_down(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0x777777);
	swap_buffer(core);
}

void	button_aliasing_up(t_ui_element *elem, t_core *core)
{
	t_camera	*cam;
	t_vector3f	color;
	char		*aliasing_str;
	int			old_sampling;

	element_set_color(elem, 0xFFFFFF);
	cam = core->scene->camera;
	old_sampling = cam->sampling;
	cam->sampling = clampi(cam->sampling * 2, ALIASING_MIN, ALIASING_MAX);
	color = V3F_INIT(0, 0, 0);
	if (cam->sampling != old_sampling)
	{
		aliasing_str = ft_itoa(cam->sampling);
		if (cam->sampling == ALIASING_MAX)
			color = V3F_INIT(1.0f, 0.0f, 0.0f);
		label_update_text(core->interface.aliasing, aliasing_str, color);
		free(aliasing_str);
		rasterize_mt(core);													/////CHANGE
	}
}

void	button_aliasing_down(t_ui_element *elem, t_core *core)
{
	t_camera	*cam;
	t_vector3f	color;
	char		*aliasing_str;
	int			old_sampling;

	element_set_color(elem, 0xFFFFFF);
	cam = core->scene->camera;
	old_sampling = cam->sampling;
	color = V3F_INIT(0, 0, 0);
	cam->sampling = clampi(cam->sampling / 2, ALIASING_MIN, ALIASING_MAX);
	if (cam->sampling != old_sampling)
	{
		if (cam->sampling == ALIASING_MIN)
			color = V3F_INIT(0.0f, 1.0f, 0.0f);
		aliasing_str = ft_itoa(cam->sampling);
		label_update_text(core->interface.aliasing, aliasing_str, color);
		free(aliasing_str);
		rasterize_mt(core);													/////CHANGE
	}
}

void	button_screenshot(t_ui_element *elem, t_core *core)
{
	(void)elem;
	screenshot(core, SCREENSHOT_FILENAME);
}

void	button_reload_scene(t_ui_element *elem, t_core *core)
{
	(void)elem;
	core_free(core);
	parsing(core, core->scene, core->file);
	core_init(core, core->scene);
	interface_init(&core->interface, core->screen_size);
	rasterize_mt(core);
}

void	button_hide_interface(t_ui_element *elem, t_core *core)
{
	t_ui_element	*it_elem;
	t_label			*it_label;

	core->interface.hide_ui = !core->interface.hide_ui;
	list_set_start(core->interface.elements);
	while ((it_elem = list_next(core->interface.elements)))
		if (it_elem != elem)
			it_elem->active = core->interface.hide_ui;
	list_set_start(core->interface.labels);
	while ((it_label = list_next(core->interface.labels)))
		if (it_label != core->interface.hide_label)
			it_label->active = core->interface.hide_ui;
	if (core->interface.hide_ui)
		label_update_text(core->interface.hide_label, "Hide Interface", V3F_INIT(0, 0, 0));
	else
		label_update_text(core->interface.hide_label, "Show Interface", V3F_INIT(0, 0, 0));
	progress_bar_show(&core->interface, 0);
	swap_buffer(core);
}

void	button_blurr(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	core->filters[0].activated = !core->filters[0].activated;
	if (core->filters[0].activated)
	{
		label_update_text(core->interface.blurr, "Blurr : On", V3F_INIT(0, 0, 0));
		post_effects_blurr(core->screen);
		swap_buffer(core);
	}
	else
	{
		label_update_text(core->interface.blurr, "Blurr : Off", V3F_INIT(0, 0, 0));
		rasterize_mt(core);
	}
}

void	button_grayscale(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	core->filters[1].activated = !core->filters[1].activated;
	if (core->filters[1].activated)
	{
		label_update_text(core->interface.grayscale, "Grayscale : On", V3F_INIT(0, 0, 0));
		post_effects_grayscale(core->screen);
		swap_buffer(core);
	}
	else
	{
		label_update_text(core->interface.grayscale, "Grayscale : Off", V3F_INIT(0, 0, 0));
		rasterize_mt(core);
	}
}

void	button_sepia(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	core->filters[2].activated = !core->filters[2].activated;
	if (core->filters[2].activated)
	{
		label_update_text(core->interface.sepia, "Sepia : On", V3F_INIT(0, 0, 0));
		post_effects_sepia(core->screen);
		swap_buffer(core);
	}
	else
	{
		label_update_text(core->interface.sepia, "Sepia : Off", V3F_INIT(0, 0, 0));
		rasterize_mt(core);
	}
}

void	button_inverse(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	core->filters[3].activated = !core->filters[3].activated;
	if (core->filters[3].activated)
	{
		label_update_text(core->interface.inverse, "Inverse : On", V3F_INIT(0, 0, 0));
		post_effects_inverse(core->screen);
		swap_buffer(core);
	}
	else
	{
		label_update_text(core->interface.inverse, "Inverse : Off", V3F_INIT(0, 0, 0));
		rasterize_mt(core);
	}
}
