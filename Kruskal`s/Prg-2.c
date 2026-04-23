#include <stdio.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], parent[MAX];
int n;

// Find function
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void union_set(int i, int j) {
    parent[j] = i;
}

// Kruskal function
void kruskal() {
    int i, j, a, b, u, v;
    int min, mincost = 0, edge_count = 0;

    // Initialize parent
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    while (edge_count < n - 1) {
        min = INF;

        // Find minimum edge
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find roots
        u = find(u);
        v = find(v);

        // If no cycle
        if (u != v) {
            printf("%d -- %d == %d\n", a, b, min);
            mincost += min;
            union_set(u, v);
            edge_count++;
        }

        // Remove edge
        cost[a][b] = cost[b][a] = INF;
    }

    printf("Total cost = %d\n", mincost);
}

// Main function
int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (except diagonal)
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    kruskal();

    return 0;
}
