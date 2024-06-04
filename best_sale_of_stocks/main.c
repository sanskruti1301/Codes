#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, maxProfit = 0;

    printf("Enter number of days:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter stock prices for each day:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int profit = arr[j] - arr[i];
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}
