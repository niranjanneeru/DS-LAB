// Aim :- Sort Using Insertion Sort

// Input:- Array of Elements to be Sorted
// Output:- Sorted Array
// Data Structure used :- Array

// Start
// 1. Store size of the array in variable n
// 2. Accept the n elements in to array arr
// 3. Iterate till last element
// 4. Store the current element in temp
// 5. Compare temp with the element before it
// 6. If larger check the element before it
// 7. When you find a smaller number or if it's terminal end shift the numbers which are larger ahead of one step and make place for temp in the position after the smaller one
// 8. If there is no smaller element go back to the loop
// Stop
//

// Time Complexity
// Best Case:- O(n)
// Avergae Case :- O(n2)
// Worst Case :- O(n2)

// Space Complexity
// Worst Case :- O(1)

#include <stdio.h>

void insertion_sort(int *, int);

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
    insertion_sort(arr, n);
    printf("After Insertion Sort: ");
    print_array(arr, n);
    return 0;
}

void print_array(int *p, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void insertion_sort(int *p, int n) {
    int iter = 0;
    int swap = 0;
    for (int i = 1; i < n; i++) {             // n
        int j = i - 1;
        int temp = p[i];
        iter++;
        while (j >= 0 && temp < p[j]) {    // n*n
            p[j + 1] = p[j];
            j--;
            iter++;
            swap++;
        }
        p[j + 1] = temp;
        print_array(p,n);
    }
    printf("Iteration: %d\nSwaps: %d\n", iter, swap);
}

// Output
// Enter a number of elements: 5
// Enter the elements in the array: 1 2 3 4 5
// Iteration: 4
// Swaps: 0
// After Insertion Sort: 1 2 3 4 5
//
// Enter a number of elements: 5
// Enter the elements in the array: 1 2 5 4 3
// Iteration: 7
// Swaps: 3
// After Insertion Sort: 1 2 3 4 5
//
// Enter a number of elements: 5
// Enter the elements in the array: 5 4 3 2 1
// Iteration: 14
// Swaps: 10
// After Insertion Sort: 1 2 3 4 5
