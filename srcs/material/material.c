#include <stdlib.h>
#include "material.h"

t_material	*new_material(t_color_rgba color)
{
	t_material	*material;

	material = (t_material*)malloc(sizeof(t_material));
	material->color = color;
	return (material);
}

void	destroy_material(t_material *material)
{
	free(material);
}