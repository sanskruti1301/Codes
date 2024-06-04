#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solve(int mask, int currCity, int ans, int allVisited, int dist[][100], int n, int dp[][1 << 15]) {
    if (mask == allVisited) {
        return dist[currCity][0];
    }
    if (dp[currCity][mask] != -1) {
        return dp[currCity][mask];
    }
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            mask = mask | (1 << city);
            int distAns = dist[currCity][city] + solve(mask, city, ans, allVisited, dist, n, dp);
            ans = min(ans, distAns);
        }
    }
    return dp[currCity][mask] = ans;
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    int dist[n][100];
    printf("Enter the matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    int dp[n][1 << 15];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << 15); j++) {
            dp[i][j] = -1;
        }
    }
    int ans = INT_MAX;
    int allVisited = (1 << n) - 1;
    int shortestDistance = solve(1, 0, ans, allVisited, dist, n, dp);
    printf("Shortest Distance: %d\n", shortestDistance);
    return 0;
}
