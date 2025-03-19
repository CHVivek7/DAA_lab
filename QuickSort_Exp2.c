#include <stdio.h>
#include <stdlib.h>

void quick(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }
    quick(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void quick(int a[], int low, int high) {
    int pivot;
    if (low < high) {
        pivot = partition(a, low, high);
        quick(a, low, pivot - 1);
        quick(a, pivot + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    while (i <= j) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

