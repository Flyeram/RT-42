#include "raytracer.h"
#include "get_next_line.h"
#include <fcntl.h>

t_vector3f	parse_v3f(char **split)
{
	return ((t_vector3f){	ft_atof(split[0]),
							ft_atof(split[1]),
							ft_atof(split[2]) });
}

static void parse_line(t_core *core, t_scene *scene, char **split)
{
	if (split[0] == NULL || split[0][0] == '#')
		return ;
	if (ft_strcmp(split[0], "camera") == 0)
		scene->camera = camera_new(parse_v3f(split + 1),
									parse_v3f(split + 4),
									parse_v3f(split + 7));
	else if (ft_strcmp(split[0], "object") == 0)
		list_push_back(scene->objects, object_parse(split + 1, scene));
	else if (ft_strcmp(split[0], "material") == 0)
		list_push_back(scene->materials, material_new(parse_v3f(split + 1),
													parse_v3f(split + 4),
													parse_v3f(split + 7)));
	else if (ft_strcmp(split[0], "light") == 0)
		list_push_back(scene->lights, light_new(parse_v3f(split + 1),
												(t_vector3f) { 1, 1, 1 }));
	else if (ft_strcmp(split[0], "render") == 0)
		core->screen_size = (t_vector2f){ft_atoi(split[1]), ft_atoi(split[2])};
}

void		scene_parse(t_core *core, t_scene *scene, char *path)
{
	int		fd;
	int		size;
	char	*line;
	char	**split;

	scene->objects = list_new(sizeof(t_object *));
	scene->lights = list_new(sizeof(t_light *));
	scene->materials = list_new(sizeof(t_material *));
	if ((fd = open(path, O_RDWR)) < 0)
		exit(0);
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, ' ', &size);
		parse_line(core, scene, split);
		ft_delete_tab((void **)split, size);
		free(line);
	}
}
