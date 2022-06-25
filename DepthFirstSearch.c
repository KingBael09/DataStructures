#include <stdio.h>

int sourceV, vertex, edge, time, visited[10], graph[10][10];

void DFS(int i)
{
    int j;
    visited[i] = 1;

    printf(" %d->", i++);
    for (j = 0; j < vertex; j++)
    {
        if (graph[i][j] == 1 && visited == 0)
        {
            DFS(j);
        }
    }
}

int input()
{
    printf("\nEnter No. of Edges: ");
    scanf("%d", &edge);
    printf("\nEnter Number of Vertices: ");
    scanf("%d", &vertex);
}

void display()
{
    printf("Graph\n");
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            printf(" %d ", graph[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int i, j, vertex1, vertex2;
    input();
    for (i = 0; i < vertex; i++)
    {
        for (j = 0; j < vertex; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (i = 0; i < edge; i++)
    {
        printf("Enter the edges in v1 v2: ");
        scanf("%d%d", &vertex1, &vertex2);
        graph[vertex1 - 1][vertex2 - 1] = 1;
    }
    display();
    printf("Enter Source of Vertex: ");
    scanf("%d", &sourceV);
    DFS(sourceV - 1);
}