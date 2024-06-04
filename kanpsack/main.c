#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) {
        return 0;
    }

    // If weight of nth item is more than W, then this item cannot be included in optimal solution
    if (wt[n - 1] > W) {
        return knapsack(W, wt, val, n - 1);
    }

    // Return max of two cases: nth item included, nth item excluded
    else {
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
    }
}

int main() {
    int profit[3];
    int weight[3];
    printf("Enter profits\n");
    for (int i=0;i<3;i++)
    {
        scanf("%d",&profit[i]);
    }
    printf("Enter weights\n");
    for (int i=0;i<3;i++)
    {
        scanf("%d",&weight[i]);
    }

    int W;
    printf("Enter W\n");
    scanf("%d",&W);
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("%d", knapsack(W, weight, profit, n));
    return 0;
}
