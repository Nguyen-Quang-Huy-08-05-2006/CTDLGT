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
    printf("\n]");
}

// in cach 2
void printGraph2(Graph *graph)
{
    printf("\n");
    for (int i = 0; i < graph->V; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < graph->V; j++)
        {
            if (graph->adjMatrix[i][j] == 1)
            {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

// duyet graph DFS
void DFSutil(Graph *graph, int src, int *visited)
{
    // b1: Danh dau src da duoc duyet
    visited[src] = 1;
    // b2: in dinh src
    printf("%d ", src);
    // b3: su dung vong lap kiem tra tat ca cac duong tu dinh
    for (int i = 0; i < graph->V; i++)
    {
        // b4: kiem tra co duong den dinh tiep theo
        if (graph->adjMatrix[src][i] == 1 && visited[i] == 0)
        {
            // b5: goi lai ham voi dinh tiep theo dc duyet
            DFSutil(graph, i, visited);
        }
    }
}

void DFS(Graph *graph, int src)
{
    // b1 khoi tao visited
    int *visited = (int *)calloc(graph->V, sizeof(int));
    // b2 in ra thong bao
    printf("DFS tu dinh %d:", src);
    // b3 goi ham
    DFSutil(graph, src, visited);
    free(visited);
}

// Duyet graph BFS
void

    int
    main(void)
{
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 0, 2);

    printGraph(graph);
    printGraph2(graph);

    DFS(graph, 0);

    return 0;
}