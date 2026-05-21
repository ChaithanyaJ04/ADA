#include <stdio.h>
#include <time.h>

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i;      // Assume root is largest
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n)
{
    int i;

    // Build Max Heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (i = n - 1; i > 0; i--)
    {
        // Swap root with last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;

    start = clock();

    heapSort(arr, n);

    end = clock();

    printf("\nSorted array using Max Heap Sort:\n");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}
