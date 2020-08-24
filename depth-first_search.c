#include <stdio.h>
#include "depth-first_search.h"

//проверка вершины 
int check_vertex(int vertex)
{
	//нужная вершина под номером 2
	if (vertex == 5)
		return 1;
	return 0;
}

//проверка что вершина еще не юзана
int check_vertex_transition(int visited_vertices[], int current_vertex, int number_of_verticies)
{
	int vertex_not_visited = 1;
	for (int i = 0; i < number_of_verticies; ++i)
		if (visited_vertices[i] == current_vertex)
			vertex_not_visited = 0;

	return vertex_not_visited;
}

//поиск в ширину
void depth_first_search(struct graph g, int vertex)
{
	int stop = 0, index_v = 0, index_s = 0;
	int visited_vertices[g.number_of_verticies];
	int stack_vertices[20];

	for (int i = 0; i < g.number_of_verticies; ++i)
		visited_vertices[i] = -1;

	for (int i = 0; i < 20; ++i)
		stack_vertices[i] = -1;

	//добавляем 0 в stack_vertices и visited_vertices
	stack_vertices[index_s] = vertex;
	index_s += 1;

	visited_vertices[index_v] = stack_vertices[index_s-1];
	index_v += 1;

	for (int i = 0; i < g.number_of_verticies; ++i)
	{
		if (stop)
			break;

		if (g.graph[vertex*g.number_of_verticies+i] != -1)
		{
			int current_vertex = g.graph[vertex*g.number_of_verticies+i];

			//добавляем 1 в stack_vertices и visited_vertices
			stack_vertices[index_s] = current_vertex;
			index_s += 1;

			visited_vertices[index_v] = stack_vertices[index_s-1];
			index_v += 1;

			for (int j = 0; j < 1000; ++j)
			{
				if (check_vertex(current_vertex))
				{
					printf("%d \n", current_vertex);
					printf("%d - заданная вершина \n", current_vertex);
					stop = 1;
					break;
				}

				int check = 0;

				printf("%d ", current_vertex);
				//выбираем соседа
				for (int l = 0; l < g.number_of_verticies; ++l)
					if (g.graph[current_vertex*g.number_of_verticies+l] != -1)
					{
						if (check_vertex_transition(visited_vertices, 
							g.graph[current_vertex*g.number_of_verticies+l], g.number_of_verticies))
						{
							current_vertex = g.graph[current_vertex*g.number_of_verticies+l];
							check += 1;
							break;
						}
					}

				//если соседей нет откатываем стек
				if (check == 0)
				{
				 	current_vertex = stack_vertices[index_s-2];
				 	stack_vertices[index_s-1] = -1;
				 	index_s -= 1;
				}
				else
				{
					stack_vertices[index_s] = current_vertex;
					index_s += 1;

					visited_vertices[index_v] = stack_vertices[index_s-1];
					index_v += 1;
				}
			}
		}
	}
}