#include <stdio.h>
#include <stdlib.h>

int a[100];
int min, max;

void MinMax(int i, int j) {
    int min1, max1;
    if (i == j) {
        min = max = a[i];
        return;
    }
    else if (i == j - 1) {
        if (a[i] > a[j]) {
            min = a[j];
            max = a[i];
        } else {
            min = a[i];
            max = a[j];
        }
        return;
    }
    int mid = (i + j) / 2;
    MinMax(i, mid);
    min1 = min;
    max1 = max;
    MinMax(mid + 1, j);

    if (max1 > max) max = max1;
    if (min1 < min) min = min1;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("The elements in the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    MinMax(0, n - 1);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
