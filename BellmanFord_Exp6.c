#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void BellmanFord(int graph[][100], int V, int src);
int main() {
  int v, e;
  printf("Enter the number of vertices and edges: ");
  scanf("%d %d", &v, &e);
  int graph[100][100];
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      graph[i][j] = (i == j) ? 0 : INT_MAX; // Self-loops are 0, others are INT_MAX
    }
  }
  for (int i = 0; i < e; i++) {
    int a, b, w;
    printf("Enter the vertices and weight of edge %d: ", i + 1);
    scanf("%d %d %d", &a, &b, &w);
    graph[a][b] = w;  // Directed graph
  }
  int src;
  printf("Enter the source vertex: ");
  scanf("%d", &src);
  BellmanFord(graph, v, src);
  return 0;
}

void BellmanFord(int graph[][100], int V, int src) {
  int dist[100];
  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
  }
  dist[src] = 0;
  for (int i = 0; i < V - 1; i++) {
    for (int j = 0; j < V; j++) {
      for (int k = 0; k < V; k++) {
        if (graph[j][k] != INT_MAX && dist[j] != INT_MAX && dist[j] + graph[j][k] < dist[k]) {
          dist[k] = dist[j] + graph[j][k];
        }
      }
    }
  }
  for (int j = 0; j < V; j++) {
    for (int k = 0; k < V; k++) {
      if (graph[j][k] != INT_MAX && dist[j] != INT_MAX && dist[k] > dist[j] + graph[j][k]) {
        printf("Negative cycle detected\n");
        return;
      }
    }
  }
  for (int i = 0; i < V; i++) {
    if (dist[i] == INT_MAX)
      printf("Distance from %d to %d is INF\n", src, i);
    else
      printf("Distance from %d to %d is %d\n", src, i, dist[i]);
  }
}