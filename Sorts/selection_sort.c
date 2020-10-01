// Aim :- Sort Using Selection Sort

// Input:- Array of Elements to be Sorted
// Output:- Sorted Array
// Data Structure used :- Array

// Start
// 1. Take input size of the array in a variable n
// 2. Accept the n elements in to array arr
// 3. Compare the first 2 elements if first is greater than second they are swapped and increase the counter variable
// 4. Continue this till the last element
// 5. each loop will make last element the largest
// 6. Stop the sort when every element is sorted
// Stop
//

// Time Complexity
// Best Case:- O(n2)
// Avergae Case :- O(n2)
// Worst Case :- O(n2)

// Space Complexity
// Worst Case :- O(1)

#include <stdio.h>

void selection_sort(int *, int);

void print_array(int *, int n);

int main() {
    int n;
    int arr[100];
    printf("Enter a number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in the array: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    selection_sort(arr, n);
    printf("After Selection Sort: ");
    print_array(arr, n);
    return 0;
}

void print_array(int *p, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void selection_sort(int *p, int n) {
    int comp = 0;
    int swap = 0;
    int small = 0;
    for (int i = 0; i < n; ++i) {
        small = i;
        for (int j = i + 1; j < n; ++j) {
            comp++;
            if (p[j] < p[small]) {
                small = j;
            }
        }
        if (small != i) {
            int temp = p[i];
            p[i] = p[small];
            p[small] = temp;
            swap++;
        }
    }
    printf("Iteration: %d\nSwaps: %d\n", comp, swap);
}

// Output
//
// Enter a number of elements: 5
// Enter the elements in the array: 5 4 3 2 1
// Iteration: 10
// Swaps: 2
// After Selection Sort: 1 2 3 4 5
//
// Enter a number of elements: 5
// Enter the elements in the array: 1 2 3 4 5
// Iteration: 10
// Swaps: 0
// After Selection Sort: 1 2 3 4 5
//
// Enter a number of elements: 5
// Enter the elements in the array: 1 2 5 4 3
// Iteration: 10
// Swaps: 1
// After Selection Sort: 1 2 3 4 5
