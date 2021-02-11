# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct {
    int length;
    int *arr;
    int heap_size;
} heap;

void print(heap *a) {
    for (int i = 1; i <= a->length;
         ++i) {
        printf("%d ", *(a->arr + i));
    }
    printf("\n");
}

void max_heapify(heap *a, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int argmax = i;
    if (left <= a->heap_size && a->arr[left] > a->arr[argmax]) {
        argmax = left;
    }
    if (right <= a->heap_size && a->arr[right] > a->arr[argmax]) {
        argmax = right;
    }
    if (argmax != i) {
        int temp = a->arr[i];
        a->arr[i] = a->arr[argmax];
        a->arr[argmax] = temp;
//        print(a);
        max_heapify(a, argmax);
    }
}

void build_heap(heap *a) {
    a->heap_size = a->length;
    for (int i = floor(a->length / 2); i >= 1; --i) {
        max_heapify(a, i);
    }
}

void heapsort(heap *a) {
    build_heap(a);
    for (int i = a->length; i > 1; --i) {
        int temp = a->arr[1];
        a->arr[1] = a->arr[a->heap_size];
        a->arr[a->heap_size] = temp;
        a->heap_size--;
        max_heapify(a, 1);
    }
    print(a);
}

int binary_search(heap *a, int item) {
    int start = 1;
    int end = a->length;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a->arr[mid] == item) {
            return mid;
        } else if (a->arr[mid] > item) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}

int main() {
    heap a;
    printf("Enter the number of elements: ");
    scanf("%d", &a.length);
    a.arr = (int *) malloc(sizeof(int) * a.length);
    printf("Enter the Elements: ");
    for (int i = 1; i <= a.length; ++i) {
        scanf("%d", a.arr + i);
    }
    heapsort(&a);
    int item;
    printf("Enter a element to search: ");
    scanf("%d", &item);
    int pos = binary_search(&a, item);
    if (pos) {
        printf("Element Found in %d position", pos);
    } else {
        printf("Element Not Found");
    }
    free(a.arr);
}