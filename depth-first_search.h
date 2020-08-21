//проверка вершины 
int check_vertex(int vertex);

//поиск в ширину
int depth_first_search(int graph[][6], int vertex);

//проверка что вершина не была проверена
int check_vertex_transition(int visited_vertices[], int current_vertex);
