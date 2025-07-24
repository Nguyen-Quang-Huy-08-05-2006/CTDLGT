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

void printAdjMatrix(Graph *graph)
{
    printf("Ma tran ke:\n");
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printAdjList(Node *adjList[], int V)
{
    printf("\nDanh sach ke:\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d: ", i);
        Node *temp = adjList[i];
        while (temp != NULL)
        {
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void convertMatrixToList(int **matrix, Node *adjList[], int V)
{
    for (int i = 0; i < V; i++)
    {
        adjList[i] = NULL;
        for (int j = V - 1; j >= 0; j--)
        {
            if (matrix[i][j] == 1)
            {
                Node *newNode = createNode(j);
                newNode->next = adjList[i];
                adjList[i] = newNode;
            }
        }
    }
}

int main(void)
{
    int size;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &size);

    Graph *graph = createGraph(size);

    int firstNode, secondNode;
    printf("Nhap canh 1 va canh 2:\n");
    while (1)
    {
        printf("First Node & secondNode: ");
        if (scanf("%d %d", &firstNode, &secondNode) != 2)
            break;
        addEdge(graph, firstNode, secondNode);
        printfGraph(graph, size);
    }

    printAdjMatrix(graph);

    Node *adjList[100];
    convertMatrixToList(graph->adjMatrix, adjList, size);
    printAdjList(adjList, size);

    return 0;
}
