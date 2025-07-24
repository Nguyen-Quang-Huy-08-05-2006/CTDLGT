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
    graph->adjMatrix[dest][src] = 1;
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
    printf("\n]\n");
}

void countK(Graph *graph, int k)
{
    int count = 0;
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            if (graph->adjMatrix[i][j] == 1 && i == k)
                count++;
        }
    }
    printf("so dinh ke voi %d la: %d", k, count);
}

int main(void)
{
    int firstNode, secondNode, size;
    printf("Nhap vao dinh do thi: ");
    scanf("%d", &size);
    Graph *graph = createGraph(size);

    while (1)
    {
        printf("First Node & secondNode: ");
        if (scanf("%d %d", &firstNode, &secondNode) != 2)
            break;
        addEdge(graph, firstNode, secondNode);
        printGraph(graph);
    }

    printf("nhap dinh k muon kiem tra: ");
    int k;
    scanf("%d", &k);
    countK(graph, k);

    return 0;
}