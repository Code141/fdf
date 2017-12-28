#include "plane.h"

static t_vector3	**plane_vertices(int x, int y)
{
	t_vector3 **vertices;
	
	vertices = (t_vector3**)malloc(sizeof(t_vector3*) * 5);
	vertices[0] = new_vector3(-x / 2, -y / 2, 0);
	vertices[1] = new_vector3(-x / 2, y / 2, 0);
	vertices[2] = new_vector3(x / 2, -y / 2, 0);
	vertices[3] = new_vector3(x / 2, y / 2, 0);
	vertices[4] = NULL;
	return (vertices);
}

static t_edge		**plane_edges(t_vector3 **vertices)
{
	t_edge **edges;
 
	edges = (t_edge**)malloc(sizeof(t_edge*) * 6);
	edges[0] = new_edge(vertices[0], vertices[1]);
	edges[1] = new_edge(vertices[0], vertices[2]);
	edges[2] = new_edge(vertices[1], vertices[3]);
	edges[3] = new_edge(vertices[2], vertices[3]);
	edges[4] = new_edge(vertices[1], vertices[2]);
	edges[5] = NULL;
	return (edges);
}

static t_face		**plane_faces(t_edge **edges)
{
	t_face **faces; 

	faces = (t_face**)malloc(sizeof(t_face*) * 3);
	faces[0] = new_face(edges[0], edges[1], edges[4]);
	faces[1] = new_face(edges[2], edges[3], edges[4]);
	faces[2] = NULL;
	return (faces);
}

t_geometry	*new_plane(int x, int y)
{
	t_geometry	*geo;

	geo = (t_geometry*)malloc(sizeof(t_geometry));
	geo->vertices = plane_vertices(x, y);
	geo->edges = plane_edges(geo->vertices);
	geo->faces = plane_faces(geo->edges);
	return (geo);
}