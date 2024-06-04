#include <stdio.h>
#include <stdlib.h>

void printarray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d \t", A[i]);
    }
    printf("\n");
}

void merge(int *a, int mid, int low, int high) {
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= high) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void merge_sort(int *a, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

int main() {
    int n, i, j;
    printf("Enter size \n");
    scanf("%d", &n);
    int a1[n];
    int low = 0;
    int high = n - 1;
    printf("Enter elements of array  \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }
    printf("\n Array  before sorting \n");
    printarray(a1, n);
    merge_sort(a1, low, high);
    printf("\n Array  after sorting \n");
    printarray(a1, n);

    return 0;
}
