#include "depth-first_search.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct graph g;
	
	g.number_of_verticies = 6;
	g.graph = (int *)malloc((g.number_of_verticies*g.number_of_verticies)*sizeof(int));

	for (int i = 0; i < g.number_of_verticies; ++i)
		for (int j = 0; j < g.number_of_verticies; ++j)
			g.graph[i*g.number_of_verticies+j] = -1;


	//test1
	// g.graph[0*g.number_of_verticies+0] = 1;
	// g.graph[0*g.number_of_verticies+1] = 2;
	// g.graph[1*g.number_of_verticies+0] = 3;
	// g.graph[1*g.number_of_verticies+1] = 4;
	// g.graph[2*g.number_of_verticies+0] = 3;
	// g.graph[3*g.number_of_verticies+0] = 4;
	// g.graph[3*g.number_of_verticies+1] = 5;

	g.graph[0*g.number_of_verticies+0] = 1;
	g.graph[0*g.number_of_verticies+1] = 2;
	g.graph[0*g.number_of_verticies+2] = 3;
	g.graph[1*g.number_of_verticies+0] = 4;
	g.graph[2*g.number_of_verticies+0] = 4;
	g.graph[3*g.number_of_verticies+0] = 5;


	depth_first_search(g, 0);

	return 0;
}