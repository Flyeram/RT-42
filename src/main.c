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

void	scene_init(t_scene *scene)
{
	scene->objects = list_new(sizeof(void *));
	scene->lights = list_new(sizeof(void *));
	scene->materials = list_new(sizeof(void *));
	scene->camera = camera_new(	(t_vector3f) { 0.0f, 10.0f, -50.0f },
								(t_vector3f) { 0.0f, -5.0f,  10.0f },
								(t_vector3f) { 0.0f, 1.0f,   0.0f });
	t_material	*mat;
	
	mat = malloc(sizeof(t_material));
	*mat = (t_material)
	{
		{ 0.1f, 0.1f, 0.1f },
		{ 1.0f, 1.0f, 1.0f },
		{ 0.0f, 0.0f, 0.0f },
		0.5f,
		60.0f
	};
	list_push_back(scene->materials, mat);

	mat = malloc(sizeof(t_material));
	*mat = (t_material)
	{
		{ 0.1f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },
		0.5f,
		60.0f
	};
	list_push_back(scene->materials, mat);

	mat = malloc(sizeof(t_material));
	*mat = (t_material)
	{
		{ 0.0f, 0.0f, 0.1f },
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 0.0f },
		0.5f,
		60.0f
	};
	list_push_back(scene->materials, mat);

	/*mat = malloc(sizeof(t_material));*/
	/**mat = (t_material) { {0.0f, 1.0f, 1.0f }, {1.0, 1.0, 1.0}, 0.5f, 60.0f };*/
	/*list_push_back(scene->materials, mat);*/

	/*mat = malloc(sizeof(t_material));*/
	/**mat = (t_material) { {1.0f, 0.0f, 1.0f }, {1.0, 1.0, 1.0}, 0.5f, 60.0f };*/
	/*list_push_back(scene->materials, mat);*/

	/*mat = malloc(sizeof(t_material));*/
	/**mat = (t_material) { {0.5f, 0.5f, 0.5f }, {1.0, 1.0, 1.0}, 0.5f, 60.0f };*/
	/*list_push_back(scene->materials, mat);*/

	t_object	*obj;

	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object)*/
	/*{*/
		/*{ 5.0f, 0.0f, -5.0f },*/
		/*{ 100, 100, 100 },*/
		/*2,*/
		/*list_get_data_at(scene->materials, 0),*/
		/*&sphere_intersect,*/
		/*&sphere_calculate_normal*/
	/*};*/
	/*list_push_back(scene->objects, obj);*/

	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object)*/
	/*{*/
		/*{ -5.0f, 0.2f, -2.0f },*/
		/*{ 100, 100, 100 },*/
		/*2,*/
		/*list_get_data_at(scene->materials, 1),*/
		/*&sphere_intersect,*/
		/*&sphere_calculate_normal*/
	/*};*/
	/*list_push_back(scene->objects, obj);*/

	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object)*/
	/*{*/
		/*{ 5.0f, 0.2f, -2.0f },*/
		/*{ 100, 100, 100 },*/
		/*2,*/
		/*list_get_data_at(scene->materials, 2),*/
		/*&sphere_intersect,*/
		/*&sphere_calculate_normal*/
	/*};*/
	/*list_push_back(scene->objects, obj);*/

	obj = malloc(sizeof(t_object));
	*obj = (t_object)
	{
		{ 0, -2, 0 },
		{ 0, 1, 0 },
		2,
		list_get_data_at(scene->materials, 1),
		&plane_intersect,
		&plane_calculate_normal
	};
	list_push_back(scene->objects, obj);

	obj = malloc(sizeof(t_object));
	*obj = (t_object)
	{
		{ 0, 0, 2 },
		{ 0, 0, 1 },
		2,
		list_get_data_at(scene->materials, 2),
		&plane_intersect,
		&plane_calculate_normal
	};
	list_push_back(scene->objects, obj);

	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object)*/
	/*{*/
		/*{ 0.0f, 0.0f, -8.0f },*/
		/*{ 100, 100, 100 },*/
		/*1,*/
		/*list_get_data_at(scene->materials, 2),*/
		/*&cylinder_intersect,*/
		/*&cylinder_calculate_normal*/
	/*};*/
	/*list_push_back(scene->objects, obj);*/

	obj = malloc(sizeof(t_object));
	*obj = (t_object)
	{
		{ 0.0f, 0.0f, 2.0f },
		{ 100, 100, 100 },
		1,
		list_get_data_at(scene->materials, 2),
		&cone_intersect,
		&cone_calculate_normal
	};
	list_push_back(scene->objects, obj);

	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object)*/
	/*{*/
		/*{ 0, 20, 0 },*/
		/*{ 0, -1, 0 },*/
		/*2,*/
		/*list_get_data_at(scene->materials, 0),*/
		/*&plane_intersect,*/
		/*&plane_calculate_normal*/
	/*};*/
	/*list_push_back(scene->objects, obj);*/

	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object) { {320 + 100, 240 - 100, 0}, {100, 100, 100}, 100, list_get_data_at(scene->materials, 1), &sphere_intersect};*/
	/*list_push_back(scene->objects, obj);*/
	
	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object) { {320 - 100, 240 + 100, 0}, {100, 100, 100}, 100, list_get_data_at(scene->materials, 2), &sphere_intersect};*/
	/*list_push_back(scene->objects, obj);*/

	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object) { {320 + 100, 240 + 100, 0}, {100, 100, 100}, 100, list_get_data_at(scene->materials, 3), &sphere_intersect};*/
	/*list_push_back(scene->objects, obj);*/

	/*obj = malloc(sizeof(t_object));*/
	/**obj = (t_object) { { 0, 0, 100 }, {0, 1, 0 }, -200, list_get_data_at(scene->materials, 2), &plane_intersect};*/
	/*list_push_back(scene->objects, obj);*/


	t_light		*light;

	/*light = malloc(sizeof(t_light));*/
	/**light = (t_light) { {0, 240, -100}, {2, 2, 2} };*/
	/*list_push_back(scene->lights, light);*/

	/*light = malloc(sizeof(t_light));*/
	/**light = (t_light) { { 0.0f, 50, -5.0f }, { 1.0f, 1.0f, 1.0f } };*/
	/*list_push_back(scene->lights, light);*/

	light = malloc(sizeof(t_light));
	*light = (t_light) { { 15.0f, 10.0f, -2.0f }, { 1.0f, 1.0f, 1.0f } };
	list_push_back(scene->lights, light);


	light = malloc(sizeof(t_light));
	*light = (t_light) { { -15.0f, 10.0f, -2.0f }, { 1.0f, 1.0f, 1.0f } };
	list_push_back(scene->lights, light);

	/*light = malloc(sizeof(t_light));*/
	/**light = (t_light) { { -10.0f, 30, -5.0f }, { 1.0f, 1.0f, 1.0f } };*/
	/*list_push_back(scene->lights, light);*/

	/*light = malloc(sizeof(t_light));*/
	/**light = (t_light) { { -3, 3, -5 }, { 0.0f, 0.0f, 1.0f } };*/
	/*list_push_back(scene->lights, light);*/

	/*light = malloc(sizeof(t_light));*/
	/**light = (t_light) { {0, 0, 0}, {0.6f, 0.7f, 1.0f} };*/
	/*list_push_back(scene->lights, light);*/
}

int		main(void)
{
	t_core		core;
	t_scene		scene;

	core.screen_size = (t_vector2f) { 840, 600 };
	scene_init(&scene);
	core_init(&core, &scene);

	return (0);
}
