#include <stdio.h>
#include <stdlib.h>

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

void addEdge(Node *adjList[], int u, int v)
{
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void printfGraph(Node *adjList[], int v)
{
    printf("\n");
    for (int i = 0; i < v; i++)
    {
        printf("%d: ", i);
        Node *temp = adjList[i];
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(void)
{
    int firstNode, secondNode, size;
    printf("Nhap vao dinh do thi: ");
    scanf("%d", &size);
    Node *adjList[size];
    for (int i = 0; i < size; i++)
    {
        adjList[i] = NULL;
    }
    while (1)
    {
        printf("First Node & secondNode: ");
        if (scanf("%d %d", &firstNode, &secondNode) != 2)
            break;
        addEdge(adjList, firstNode, secondNode);
        printfGraph(adjList, size);
    }
}