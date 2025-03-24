#include <stdio.h>

int count = 0;
void Subset_Sum(int set[], int n, int m, int partial[], int size, int sum, int index) {
    if (sum == m) {
        count++;
        printf("solution : %d\n",count);
        for (int i = 0; i < size; i++) {
            printf("%d ", partial[i]);
        }
        printf("\n");
        return;
    }
    if (sum > m || index >= n) {
        return;
    }
    partial[size] = set[index];
    Subset_Sum(set, n, m, partial, size + 1, sum + set[index], index + 1);

    Subset_Sum(set, n, m, partial, size, sum, index + 1);
}

int main() {
    int n, m;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }
    int set[n];
    int partial[n];

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the sum to be found: ");
    scanf("%d", &m);

    Subset_Sum(set, n, m, partial, 0, 0, 0);

    if (count == 0) {
        printf("No subset found\n");
    }else{
        printf("Total Number of solutions : %d\n",count);
    }

    return 0;
}