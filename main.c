#include "depth-first_search.h"
#include <stdio.h>

int main()
{
	printf("			                     +---------+              \n");
	printf("	                                     |         |	      \n");
	printf("			                     |    4    |              \n");
	printf("			                +--->+         |              \n");
	printf("			                |    +----+----+              \n");
	printf("			 +---------+    |         ^                   \n");
	printf("			 |         |    |         |                   \n");
	printf("			 |    1    +----+         |                   \n");
	printf("               +-------->+         |    |         |                   \n");
	printf("	       |         |         |    |    +----+----+              \n");
	printf("       	       |         +---------+    |    |         |              \n");
	printf("	       |                        |    |    3    +------+       \n");
	printf("        +------+-+                      +--->+         |      |       \n");
	printf("	|        |                           +----+----+      |       \n");
	printf("	|   0    |                                ^           v       \n");
	printf("	|        |                                |      +----+----+  \n");
	printf("	+------+-+                                |      |         |  \n");
	printf("	       |                                  |      |    5    |  \n");
	printf("	       |                                  |      |         |  \n");
	printf("	       |                                  |      +---------+  \n");
	printf("	       |                                  |                   \n");
	printf("	       |         +---------+              |                   \n");
	printf("	       |         |         |              |                   \n");
	printf("	       +-------->+    2    +--------------+		      \n");
	printf("	        	 |         |                                  \n");
	printf("			 +---------+                                  \n");

	printf("\n\n");

	int graph[6][6];

	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
		{
			graph[i][j] = -1;
		}

	graph[0][0] = 1;
	graph[0][1] = 2;
	graph[1][0] = 3;
	graph[1][1] = 4;
	graph[2][0] = 3;
	graph[3][0] = 4;
	graph[3][1] = 5;

	printf("Путь: ");
	depth_first_search(graph, 0);

	printf("\n");

	return 0;
}
