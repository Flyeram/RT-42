#include "raytracer.h"

int		handle_expose(t_core *core)
{
	mlx_put_image_to_window(core->mlx, core->win, core->screen->img, 0, 0);
	return (1);
}

int		handle_events(int key_code, t_core *core)
{
	if (key_code == KEY_EXIT)
		exit(3);
	if (key_code == KEY_ALIASING)
	{
		//to do
	}
	camera_move(core->scene->camera, key_code);
	camera_rotate(core->scene->camera, key_code);
	rasterize(core);
	handle_expose(core);
	return (0);
}

void	core_init(t_core *core, t_scene *scene)
{
	if ((core->win = mlx_new_window(core->mlx,
									core->screen_size.x, core->screen_size.y,
									"Raytracer")) == NULL)
		exit(0);
	if ((core->screen = tex_new(core->mlx, core->screen_size.x, core->screen_size.y)) == NULL)
		exit(0);
	core->scene = scene;
	rasterize(core);
	mlx_expose_hook(core->win, handle_expose, core);
	mlx_hook(core->win, 2, (1L << 0), handle_events, core);
	mlx_loop(core->mlx);
}

int		main(int ac, char **av)
{
	t_core		core;
	t_scene		scene;

	if (ac != 2 || (core.mlx = mlx_init()) == NULL)
		return (0);
	scene_parse(&core, &scene, av[1]);
	core_init(&core, &scene);
	return (0);
}
