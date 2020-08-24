struct graph
{
	int number_of_verticies;
	int *graph;
};

//проверка вершины 
int check_vertex(int vertex);

//поиск в ширину
void depth_first_search(struct graph g, int vertex);

//проверка что вершина не была проверена
int check_vertex_transition(int visited_vertices[], int current_vertex, int number_of_verticies);
