#include <stdio.h>
#include <stdlib.h>
void main() {
    int n, m;
    printf("\nEnter the number of elements: ");
    scanf("%d", &m);
    int a[m];
    printf("\nEnter elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                a[j] = a[j] + a[j+1] - (a[j+1] = a[j]);

            }
        }
    }
    printf("Enter the number of tapes: ");
    scanf("%d", &n);
    int x = (m / n) + 1;
    int arr[n][x];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < x; j++) {
            arr[i][j] = -1;
        }
    }
    int j = 0, k = 0;
    for (int i = 0; i < m; i++) {
        arr[j][k] = a[i];
        j++;
        if (j == n) {
            j = 0;
            k++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("\nStorage on tape %d: ", i + 1);
        for (int j = 0; j < x; j++) {
            if (arr[i][j] != -1) {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}
