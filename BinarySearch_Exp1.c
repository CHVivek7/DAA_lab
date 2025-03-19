#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);
int BinarySearch(int arr[], int l, int h, int x);

int main() {
    int n = 1;
    int x;
    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter the element of the array: ");
    scanf("%d", &arr[0]);

    int ch = 1;
    while (ch) {
        char k;
        printf("Do you want to enter more elements? (y/n): ");
        scanf(" %c", &k);  // changed to accept a character properly
        if (k == 'y' || k == 'Y') {
            n++;
            arr = (int*)realloc(arr, n * sizeof(int));
            printf("Enter the element of the array: ");
            scanf("%d", &arr[n-1]);
            insertionSort(arr, n);
            printf("\n");
        } else {
            printf("Enter element to Search: ");
            scanf("%d", &x);
            int res = BinarySearch(arr, 0, n-1, x);  // Pass n-1 instead of n
            if (res == -1) {
                printf("Element not found\n");
            } else {
                printf("Element found at index: %d\n", res);
            }
            ch = 0;
        }
    }
    return 0;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int BinarySearch(int arr[], int l, int h, int x) {
    if (l > h) {
        return -1;  // Return -1 if not found
    }

    int mid = (l + h) / 2;
    if (arr[mid] == x) {
        return mid;  // Return the index where found
    } else if (arr[mid] > x) {
        return BinarySearch(arr, l, mid - 1, x);
    } else {
        return BinarySearch(arr, mid + 1, h, x);
    }
}
