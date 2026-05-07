#include <stdio.h>

int main()
{
    int n, p[10], d[10], i, j, m, pos, t;

    printf("Enter n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;
        d[i] = -1;   // left direction
    }

    while(1)
    {
        // Print permutation
        for(i = 0; i < n; i++)
            printf("%d ", p[i]);
        printf("\n");

        m = 0;
        pos = -1;

        // Find largest mobile element
        for(i = 0; i < n; i++)
        {
            j = i + d[i];

            if(j >= 0 && j < n && p[i] > p[j] && p[i] > m)
            {
                m = p[i];
                pos = i;
            }
        }

        if(pos == -1)
            break;

        j = pos + d[pos];

        // Swap elements
        t = p[pos];
        p[pos] = p[j];
        p[j] = t;

        // Swap directions
        t = d[pos];
        d[pos] = d[j];
        d[j] = t;

        pos = j;

        // Reverse direction
        for(i = 0; i < n; i++)
            if(p[i] > m)
                d[i] = -d[i];
    }

    return 0;
}
