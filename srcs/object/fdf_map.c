# include "fdf_map.h"

void		fdf_map_elevation(t_fdf_map *map, t_mesh *mesh)
{
	int i;
	int j;
	int x;
	int y;

	x = map->width;
	y = map->height;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("VERTICE [%d][%d] = %d\n", j, i, map->map[i][j]);
			mesh->geometry->vertices[(i * x) + j]->z = map->map[i][j] * 5;
			j++;
		}
		i++;
	}

}

t_object	*new_fdf_map(t_fdf_map *map, int color)
{
	t_geometry	*geometry;
	t_material	*material;
	t_object	*obj;
	int x;
	int y;
	int size;
	x = map->width - 1;
	y = map->height - 1;
	size = 6;

	geometry = new_surface(x * size, y * size, x, y);
	material = new_material(color);
	obj = new_object(new_mesh(geometry, material));

	fdf_map_elevation(map, obj->mesh);


	return (obj);
}