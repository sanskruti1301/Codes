#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c = 1, count = 0;

    printf("Enter dividend: \n");
    scanf("%d", &a);
    printf("Enter divisor: \n");
    scanf("%d", &b);

    if (a < 0 || b < 0) {
        if (a < 0 && b < 0) {
            c = 1;
        } else {
            c = -1;
        }
        a = abs(a);
        b = abs(b);
    }

    if (b == 0) {
        printf("Cannot divide by zero.\n");
    } else {
        while (a >= b) {
            a = a - b;
            count++;
        }
        printf("Quotient: %d\n", count * c);
    }

    return 0;
}
