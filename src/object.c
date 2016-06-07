#include "raytracer.h"

t_object	*object_new(t_vector3f p, t_vector3f d, float r, t_material *m)
{
	t_object *obj;

	obj = malloc(sizeof(t_object));
	obj->position = p;
	obj->rotation = d;
	obj->radius = r;
	obj->mat = m;
	return (obj);
}

void		object_set_type(t_object *obj, char *type)
{
	if (ft_strcmp(type, "sphere") == 0)
		sphere_init(obj);
	else if (ft_strcmp(type, "plane") == 0)
		plane_init(obj);
	else if (ft_strcmp(type, "cylinder") == 0)
		cylinder_init(obj);
	else if (ft_strcmp(type, "cone") == 0)
		cone_init(obj);
	else if (ft_strcmp(type, "disk") == 0)
		disk_init(obj);
	else
		exit (0);
}

t_object	*object_parse(char **split, t_scene *scene)
{
	t_object *obj;

	obj = object_new(parse_v3f(split + 1),
					parse_v3f(split + 4),
					ft_atof(split[7]),
					list_get_data_at(scene->materials, ft_atoi(split[8])));
	object_set_type(obj, split[0]);
	return (obj);
}
