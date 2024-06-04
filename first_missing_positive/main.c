#include <stdio.h>
#include <stdlib.h>

void insertion(int *A, int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {
    int n, a;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertion(arr, n);

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] + 1 != arr[i + 1]) {
            printf("Missing element is: %d\n", arr[i] + 1);
            break;
        }
    }

    return 0;
}
