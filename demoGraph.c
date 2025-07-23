typedef struct Graph
{
    int V;
    int **adjMaxtrix;
} Graph;

Graph *createGrpah(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMaxtrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        graph->adjMaxtrix[i] = (int *)malloc(V * sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph, int src, int sest)
{
    graph->adjMaxtrix[src][dest] = 1;
    grpah->adjMatric
}

int main(void)
{

    return 0;
}