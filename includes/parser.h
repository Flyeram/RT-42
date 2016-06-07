#ifndef PARSER_H
# define PARSER_H

void		scene_parse(t_core *core, t_scene *scene, char *path);
t_vector3f	parse_v3f(char **split);
t_material	*material_new(t_scene *scene, t_vector3f maps[3], float r, int texture);

#endif
