#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n; // Number of vertices
int graph[100][100]; // Adjacency matrix representation
int path[100]; // Current path being explored
bool visited[100]; // Tracks visited vertices
int count = 0; // Counts Hamiltonian cycles
int startVertex; // Starting vertex for the cycle

// Function to print a Hamiltonian cycle
void printCycle() {
    printf("Hamiltonian Cycle %d: ", ++count);
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i] + 1); // Print vertices starting from 1
    }
    printf("%d\n", startVertex + 1); // Complete the cycle, adjusting for 1-based indexing
}

// Function to check if a vertex can be added to the path
bool isSafe(int v, int pos) {
    if (visited[v]) {
        return false;
    }
    if (pos == 0) {
        return true; // First vertex is always safe
    }
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }
    return true;
}

// Recursive function to find Hamiltonian cycles
void hamiltonianCycleUtil(int pos) {
    if (pos == n) {
        if (graph[path[n - 1]][startVertex]) {
            printCycle();
        }
        return;
    }

    for (int v = 0; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            visited[v] = true;
            hamiltonianCycleUtil(pos + 1);
            visited[v] = false; // Backtrack
        }
    }
}

// Function to find all Hamiltonian cycles
void hamiltonianCycle() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    path[0] = startVertex; // Start with the specified start vertex
    visited[startVertex] = true;
    hamiltonianCycleUtil(1); // Start from the second position
}

int main() {
    printf("Enter the number of vertices: ");

    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex (1 to %d): ", n);
    scanf("%d", &startVertex);
    startVertex--; // Adjust to 0-based indexing
    hamiltonianCycle();
    if (count == 0) {
        printf("No Hamiltonian Cycle Found\n");
    }
    return 0;
}
