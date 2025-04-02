#include <stdio.h>
#include <stdbool.h>

#define MAX 100 // Maximum number of vertices

int G[MAX][MAX] = {0}; // Adjacency matrix for the graph
int x[MAX] = {0};      // Array to store the colors of vertices
int n, m;              // n: number of vertices, m: number of colors
bool solutionFound = false;

void printSolution() {
    solutionFound = true;
    printf("Solution: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void nextValue(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (m + 1); // Assign the next color
        if (x[k] == 0) return;       // No more colors available
        int j;
        for (j = 1; j <= n; j++) {
            if (G[k][j] && x[k] == x[j]) break; // Check adjacency conflict
        }
        if (j == n + 1) return; // Valid color found
    }
}

void mcoloring(int k) {
    while (true) {
        nextValue(k);
        if (x[k] == 0) return; // No valid color for this vertex
        if (k == n) {
            printSolution(); // Print solution when all vertices are colored
        } else {
            mcoloring(k + 1); // Recur for the next vertex
        }
    }
}

int findChromaticNumber() {
    for (m = 1; m <= n; m++) { // Start with 1 color and increment
        for (int i = 1; i <= n; i++) 
		x[i] = 0; // Reset color array
        solutionFound = false;
        mcoloring(1);
        if (solutionFound) return m; // If at least one solution is found, return m
    }
    return n; // In the worst case, the chromatic number is n
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    // Find and print the chromatic number
    int chromaticNumber = findChromaticNumber();
    printf("Chromatic Number: %d\n", chromaticNumber);

    return 0;
}
