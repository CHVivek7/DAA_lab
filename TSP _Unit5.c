//
// Created by USER on 01-04-2025.
//
#include <stdio.h>
int n;
int arr[10][10];
int node[10][10];
int temp1[10][10];
int shortest[10][10];
int src;
int node_cost;
int path[10];
int visited[10];
int count = 0;
int reduction() {
    int row_reduction = 0, column_reduction = 0;
    for (int i = 0; i < n; i++) {
        int min = 999;
        for (int j = 0; j < n; j++) {
            if (temp1[i][j] < min) {
                min = temp1[i][j];
            }
        }
        if (min != 999 && min != 0) {
            for (int j = 0; j < n; j++) {
                if (temp1[i][j] != 999) {
                    temp1[i][j] -= min;
                }
            }
            row_reduction += min;
        }
    }
    for (int i = 0; i < n; i++) {
        int min = 999;
        for (int j = 0; j < n; j++) {
            if (temp1[j][i] < min) {
                min = temp1[j][i];
            }
        }
        if (min != 999 && min != 0) {
            for (int j = 0; j < n; j++) {
                if (temp1[j][i] != 999) {
                    temp1[j][i] -= min;
                }
            }
            column_reduction += min;
        }
    }
    return row_reduction + column_reduction;  // Return total reduction cost
}
int replace(int src, int node) {
    for (int i=0;i<n;i++) {
        temp1[src][i] = 999;
        temp1[i][node] = 999;
    }
    temp1[node][src]=999;

    int t_cost = reduction();
    return t_cost;
}
void tsp(int src) {
    int to;
    int cost_node = 999;
    if (src!=1) {
        for (int i =0;i<n;i++) {
            for (int j =0;j<n;j++) {
                temp1[i][j] = node[i][j];
            }
        }
    }

    if (count == n) {
        return ;
    }
    for (int i=0;i<n;i++) {
        if (i != src && visited[i] == 0) {
            int t = replace(src,i);
            t+=node[src][i]+node_cost;
            if (t<cost_node) {
                cost_node = t;
                to = i;
                for (int k=0;k<n;k++) {
                    for (int l=0;l<n;l++) {
                        shortest[k][l] = temp1[k][l];
                    }
                }
            }
            for (int i1 =0;i1<n;i1++) {
                for (int j1 =0;j1<n;j1++) {
                    temp1[i1][j1] = node[i1][j1];
                }
            }
        }
    }
    for (int k=0;k<n;k++) {
        for (int l=0;l<n;l++) {
            node[k][l] = shortest[k][l];
        }
    }
    path[count++] = to;
    visited[to] = 1;
    node_cost=cost_node;
    tsp(to);
}
int main(){
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix of the graph: (use 999 for infinity)");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            node[i][j]=arr[i][j];
        }
        visited[i]=0;
    }
    printf("Enter the source: (1 to n)");
    scanf("%d", &src);
    src = src - 1;
    visited[src]=1;
    path[count++]=src;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp1[i][j] = node[i][j];
        }
    }
    node_cost = reduction();
    tsp(src);
    if (arr[path[n-1]][path[0]]==999) {
        printf("No such path exists");
        return;
    }
    printf("The shortest path from source %d is :", src);
    for (int k=0;k<n;k++) {
        printf("%d ", path[k]+1);
    }
    int final=0;
    for (int i=1;i<n;i++) {
        final+=arr[path[i-1]][path[i]];
    }

    final += arr[path[n-1]][path[0]];
    printf("The final cost is: %d", final);
}




