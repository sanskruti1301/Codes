#include <stdio.h>

int V, E;

void display_edges(int arr[][2], int n)
{
    printf("Edges:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d---%d\n", arr[i][0], arr[i][1]);
    }
}

void createAdjMatrix(int Adj[][V + 1], int arr[][2], int n)
{
    for (int i = 0; i < V + 1; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            Adj[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int x = arr[i][0];
        int y = arr[i][1];
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

void printAdjMatrix(int Adj[][V + 1])
{
    printf("Adjacency Matrix:\n");
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            printf("%d\t", Adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter number of vertices: \n");
    scanf("%d", &V);

    int arr[V * (V - 1) / 2][2];
    int n = 0; // Number of edges

    printf("\nEnter the connection between vertices (e.g., '1 2' for an edge between vertices 1 and 2):\n");
    while (1)
    {
        if (n >= V * (V - 1) / 2)
        {
            printf("Maximum number of edges reached.\n");
            break;
        }

        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &arr[n][j]);
        }

        n++;

        printf("\nIf you want to add more edges, press 1. Otherwise, press 0: ");
        int c;
        scanf("%d", &c);

        if (c != 1)
        {
            break;
        }
    }

    E = n; // Set the number of edges based on the actual number entered

    int Adj[V + 1][V + 1];
    createAdjMatrix(Adj, arr, n);
    printAdjMatrix(Adj);
    display_edges(arr, n);

    return 0;
}
