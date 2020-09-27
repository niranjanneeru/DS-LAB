// Aim :- Sort Using Bubble Sort

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
// Best Case:- O(n)
// Avergae Case :- O(n2)
// Worst Case :- O(n2)

// Space Complexity
// Worst Case :- O(1)

#include <stdio.h>

void bubble_sort(int *, int);

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
    bubble_sort(arr, n);
    printf("After Bubble Sort: ");
    print_array(arr, n);
    return 0;
}

void print_array(int *p, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void bubble_sort(int *p, int n) {
    int iter = 0;
    int swap = 0;
    int flag = 0;
    for (int i = 0; i < n - 1; ++i) {
        flag = 0;
        for (int j = 0; j < n - i - 1; ++j) {
            iter++;
            if (p[j] > p[j + 1]) {
                flag = 1;
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                swap++;
            }
        }
        if (flag == 0) {
            break;
        }
//        print_array(p,n);
    }
    printf("Iteration: %d\nSwaps: %d\n", iter, swap);
}

// Output

// Enter a number of elements: 5
// Enter the elements in the array: 1 2 3 4 5
// Iteration: 4
// Swaps: 0
// After Bubble Sort: 1 2 3 4 5
//
// Enter a number of elements: 5
// Enter the elements in the array: 1 2 5 4 3
// Iteration: 9
// Swaps: 3
// After Bubble Sort: 1 2 3 4 5
//
// Enter a number of elements: 5
// Enter the elements in the array: 5 4 3 2 1
// Iteration: 10
// Swaps: 10
// After Bubble Sort: 1 2 3 4 5
