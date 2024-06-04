#include <stdio.h>
#include <stdlib.h>

void dijkstras(int n, int cost[10][10], int s, int dist[10]) {
    int i, v, count = 0, min, visited[10];

    for (i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    visited[s] = 1;
    dist[s] = 0;

    while (count < n - 1) { // Loop n-1 times
        min = 999;

        for (i = 0; i < n; i++) {
            if (dist[i] < min && visited[i] == 0) {
                min = dist[i];
                v = i;
            }
        }

        visited[v] = 1;
        count++;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] > dist[v] + cost[v][i]) {
                dist[i] = dist[v] + cost[v][i];
            }
        }
    }
}

int main() {
    int i, j, n, s, cost[10][10], dist[10];

    printf("Enter no. of nodes:\n");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999; // to represent infinity
        }
    }

    printf("Enter source vertex:\n");
    scanf("%d", &s);

    dijkstras(n, cost, s, dist);

    printf("\nShortest path from vertex %d:\n", s);
    for (i = 0; i < n; i++) {
        if (s != i)
            printf("%d to %d = %d\n", s, i, dist[i]);
    }

    return 0;
}
