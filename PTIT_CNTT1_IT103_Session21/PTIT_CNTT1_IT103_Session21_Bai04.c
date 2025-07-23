#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int V;
    int **adjMatrix;
} Graph;

Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        graph->adjMatrix[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
}

void printGraph(Graph *graph)
{
    printf("[\n");
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            printf("\t%d", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n]");
}

int main(void)
{
    Graph *graph = createGraph(3);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    printGraph(graph);

    return 0;
}