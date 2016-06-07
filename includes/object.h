#ifndef OBJECT_H
# define OBJECT_H

t_object	*object_parse(char **split, t_scene *scene);
t_object	*object_new(t_vector3f p, t_vector3f d, float r, t_material *m);
void		object_set_type(t_object *obj, char *type);

#endif
