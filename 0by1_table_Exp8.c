#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
void knapsack(int n, int m, int profits[], int weights[]);
int main() {
  int n, m;
  printf("Enter the number of items and the knapsack capacity: ");
  scanf("%d %d", &n, &m);
  int profits[n], weights[n];
  printf("Enter profits and weights of the items:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &profits[i], &weights[i]);
  }
  knapsack(n, m, profits, weights);
  return 0;
}

void knapsack(int n, int m, int profits[], int weights[]) {
  int T[n+1][m+1];
  int sum=0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        T[i][j] = 0;
      } else if (j - weights[i - 1] >= 0) {
        T[i][j] = max(T[i - 1][j], profits[i - 1] + T[i - 1][j - weights[i - 1]]);
      } else {
        T[i][j] = T[i - 1][j];
      }
    }
  }
  int max_value = T[n][m];
  int tm = m, total_profit = max_value;
  for (int i = n; i > 0 && max_value > 0; i--) {
    if (max_value != T[i - 1][tm]) { // Item was included
      printf("Item %d with profit %d and weight %d\n", i, profits[i - 1], weights[i - 1]);
      max_value -= profits[i - 1];
      tm -= weights[i - 1];
    }
  }
  printf("The maximum value of the knapsack is: %d\n", total_profit);
}