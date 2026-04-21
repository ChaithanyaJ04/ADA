#include <stdio.h>

// Merge function
void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int c[high - low + 1];   // temporary array

    // Merge two halves
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    // Copy remaining elements
    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    // Copy back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = c[k];
}

// Merge Sort function
void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int n;

    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
