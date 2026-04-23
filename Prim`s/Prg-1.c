#include <stdio.h>

#define MAX 50

int cost[MAX][MAX], vis[MAX], n;

void prims() {
    int i, j, k;
    int u = 0, v = 0;
    int min, sum = 0;

    vis[0] = 1; // start from vertex 0

    printf("\nEdges in MST:\n");

    for (i = 0; i < n - 1; i++) {
        min = 999;

        for (j = 0; j < n; j++) {
            if (vis[j] == 1) {
                for (k = 0; k < n; k++) {
                    if (vis[k] == 0 && cost[j][k] < min) {
                        min = cost[j][k];
                        u = j;
                        v = k;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n", u, v, min);

        vis[v] = 1;
        sum += min;
    }

    printf("Total cost = %d\n", sum);
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 (no edge) with large value
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    // Initialize visited array
    for (i = 0; i < n; i++) {
        vis[i] = 0;
    }

    prims();

    return 0;
}
