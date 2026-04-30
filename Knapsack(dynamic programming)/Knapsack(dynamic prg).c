#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, m;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);

    int w[n+1], p[n+1];

    printf("Enter weights:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter profits:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    int V[n+1][m+1];

    // Step 1: Build DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else if (w[i] > j)
                V[i][j] = V[i-1][j];
            else
                V[i][j] = max(V[i-1][j], V[i-1][j-w[i]] + p[i]);
        }
    }

    // Step 2: Print optimal value
    printf("\nOptimal Profit = %d\n", V[n][m]);

    // Step 3: Find selected objects
    int X[n+1];
    for (int i = 1; i <= n; i++)
        X[i] = 0;

    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (V[i][j] != V[i-1][j]) {
            X[i] = 1;
            j = j - w[i];
        }
        i--;
    }

    // Step 4: Print selected objects
    printf("Selected objects:\n");
    for (int i = 1; i <= n; i++) {
        if (X[i] == 1)
            printf("Object %d ", i);
    }

    return 0;
}
