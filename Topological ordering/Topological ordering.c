#include <stdio.h>

#define MAX 10

int main()
{
    int adj[MAX][MAX], indegree[MAX];
    int n, i, j, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    // Calculate indegree of each vertex
    for(i = 0; i < n; i++)
    {
        indegree[i] = 0;
        for(j = 0; j < n; j++)
        {
            indegree[i] += adj[j][i];
        }
    }

    printf("Topological Ordering:\n");

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            // Select source vertex
            if(indegree[i] == 0)
            {
                printf("%d ", i);

                indegree[i] = -1; // Mark as removed

                // Remove outgoing edges
                for(j = 0; j < n; j++)
                {
                    if(adj[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }

                found = 1;
                count++;
            }
        }

        // Cycle detection
        if(found == 0)
        {
            printf("\nGraph contains a cycle. Topological ordering not possible.\n");
            break;
        }
    }

    return 0;
}
