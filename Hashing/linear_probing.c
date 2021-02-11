# include <stdio.h>

# define SIZE 10

int hash_function(int item) {
    return item % SIZE;
}

void insert(int *arr, int item) {
    int pos = hash_function(item);
    int i = pos;
    while (arr[i] != -1) {
        i = (i + 1) % SIZE;
        if (pos == i) {
            printf("Hash Table is Full\n");
            return;
        }
    }
    arr[i] = item;
}

void print(int *arr) {
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", *(arr + i));
    }
}

int search(int *arr, int item) {
    int pos = hash_function(item);
    int i = pos;
    while (arr[i] != item) {
        i = (i + 1) % SIZE;
        if (i == pos) {
            return -1;
        }
    }
    return i;
}

int delete(int *arr, int item) {
    int pos = search(arr, item);
    if (pos == -1) {
        return 0;
    }
    arr[pos] = -1;
    return 1;
}

int main() {
    int arr[SIZE];
    int i;
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = -1;
    }
    start:
    printf("Choose an Operation: \n1.Insert\n2.Delete\n3.Search\n4.Print: ");
    scanf("%d", &i);
    switch (i) {
        case 1:
            printf("Enter an element to insert: ");
            scanf("%d", &i);
            if (i == -1) {
                printf("Can't Insert That Element\n");
                goto start;
            }
            insert(arr, i);
            goto start;
        case 2:
            printf("Enter an element to delete: ");
            scanf("%d", &i);
            if (i == -1) {
                printf("Can't Delete That Element\n");
                goto start;
            }
            if (delete(arr, i)) {
                printf("Deletion Successful\n");
            } else {
                printf("Deletion Unsuccessful\n");
            }
            goto start;
        case 3:
            printf("Enter an element to search: ");
            scanf("%d", &i);
            if (i == -1) {
                printf("Can't Search That Element");
                goto start;
            }
            int loc = search(arr, i);
            if (loc != -1) {
                printf("Element found in %d position\n", loc);
            } else {
                printf("Element Not Found\n");
            }
            goto start;
        case 4:
            print(arr);
            goto start;
        default:
            printf("Exiting...");
    }
    return 0;
}