#include <stdio.h>

///swapping function using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int A[], int n, int i)
{
    /// Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && A[left] > A[largest])
        largest = left;
    if (right < n && A[right] > A[largest])
        largest = right;

    /// Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(& A[i], & A[largest]);
        heapify(A, n, largest);
    }
}


///main function to do heap sort
void heapSort(int A[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    /// Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&A[0], &A[i]);
        show(A, n);

        /// Heapify root element to get highest element at root again
        heapify(A, i, 0);

    }
}

///print function

void show(int A[], int n)
{

    for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
    printf("\n");

}


///main function
int main()
{
    int A[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Unsorted array is: ");
    for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
    printf("\n\n");

    heapSort(A, n);

    printf("\nSorted array is: \n");
    show(A, n);
}

