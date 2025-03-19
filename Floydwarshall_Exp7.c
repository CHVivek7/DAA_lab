#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MAX

void main() {
    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);
    
    int arr[n][n];

    // Initialize adjacency matrix with INT_MAX for no direct edge
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                arr[i][j] = 0; // Distance to self is zero
            } else {
                arr[i][j] = INT_MAX;
            }
        }
    }

    printf("Enter the number of edges: ");
    int edges;
    scanf("%d", &edges);

    int src, dist, edge;
    for (int i = 0; i < edges; i++) {
        printf("Enter the vertices and weight of edge %d: ", i + 1);
        scanf("%d", &src);
        scanf("%d", &dist);
        scanf("%d", &edge);
        
        arr[src][dist] = edge; // Assign weight to edge
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][k] != INT_MAX && arr[k][j] != INT_MAX && arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    // Print shortest path matrix
    printf("\nShortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

