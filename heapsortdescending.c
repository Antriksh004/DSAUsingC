// HEAP SORT USING THE C LANGUAGE

// HEAP SORT  is a comparison-based sorting technique based on Binary Heap data structure. It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. Repeat the same process for the remaining elements.

// HEAP SORT ALGORITHM
// To solve the problem follow the below idea:

// First convert the array into heap data structure using heapify, then one by one delete the root node of the Max-heap and replace it with the last node in the heap and then heapify the root of the heap. Repeat this process until size of heap is greater than 1.

// Build a heap from the given input array.
// Repeat the following steps until the heap contains only one element:
// Swap the root element of the heap (which is the largest element) with the last element of the heap.
// Remove the last element of the heap (which is now in the correct position).
// Heapify the remaining elements of the heap.
// The sorted array is obtained by reversing the order of the elements in the input array.

// CODE STARTS HERE

#include <stdio.h>

// DISPLAYING(PRINTING) ARRAY
int display_arr(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("%d ", a[i]);
    }
    printf("\n");
}

// function to swap the position of two elements

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to heapify the code

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap

void heapify(int arr[], int n, int i)
{
    // find the largest among root

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if left child is larger than the root

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    // if right child is larger than the largest

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    display_arr(arr, n);

    // swap and continue heapifying
    // if the root is not largest
    // if the largest is not root

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        display_arr(arr, n);
        // recursively heapify the affected sub tree
        heapify(arr, n, largest);
        display_arr(arr, n);
    }
}

// funtion for the heap sort
// building max heap
void heapsort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {

        heapify(arr, n, i);
        display_arr(arr, n);
    }
    display_arr(arr, n);
    printf("the heap has been created\n");

    // heap sort

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        //    display_arr(arr,n);
        // heapify the root element to to get the highest element at root again

        heapify(arr, i, 0);
        //this heapify is only heapifying the small slices of array
    }
}

// driver code
int main()
{
    int arr[] = {55,63,72,89,92};
    int n = sizeof(arr) / sizeof(arr[0]);
    // function call

    heapsort(arr, n);
    printf("the sorted array is : \n");
    display_arr(arr, n);

    return 0;
}


// COMPLEXITY ANALYSIS

// Time Complexity: O(N log N)
// Auxiliary Space: O(1)

// IMPORTANT POINTS:

// Heap sort is an in-place algorithm. 
// Its typical implementation is not stable but can be made stable (See this)
// Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of reference.

// ADVANTAGES OF HEAP SORT:

// Efficiency –  The time required to perform Heap sort increases logarithmically while other algorithms may grow exponentially slower as the number of items to sort increases. This sorting algorithm is very efficient.
// Memory Usage – Memory usage is minimal because apart from what is necessary to hold the initial list of items to be sorted, it needs no additional memory space to work
// Simplicity –  It is simpler to understand than other equally efficient sorting algorithms because it does not use advanced computer science concepts such as recursion.

// DISADVANTAGES OF THE HEAP SORT:
// Costly: Heap sort is costly.
// Unstable: Heap sort is unstable. It might rearrange the relative order.
// Efficient: Heap Sort is not very efficient when working with highly complex data. 