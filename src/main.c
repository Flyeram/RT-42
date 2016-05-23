#include "raytracer.h"

void	core_init(t_core *core, t_scene *scene)
{
	if ((core->mlx = mlx_init()) == NULL)
		exit(0);
	if ((core->win = mlx_new_window(core->mlx,
									core->screen_size.x, core->screen_size.y,
									"Raytracer")) == NULL)
		exit(0);
	if ((core->screen = tex_new(core, core->screen_size.x, core->screen_size.y)) == NULL)
		exit(0);
	core->scene = scene;
	mlx_loop_hook(core->mlx, (int (*)(void *))&rasterize, core);
	mlx_loop(core->mlx);
}

int		main(int ac, char **av)
{
	t_core		core;
	t_scene		scene;

	if (ac != 2)
		return (0);
	scene_parse(&core, &scene, av[1]);
	core_init(&core, &scene);
	return (0);
}
