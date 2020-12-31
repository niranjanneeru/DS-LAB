# include "sort.h"
# include <stdio.h>

int main() {
    int total, num;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &total);
    node *root = NULL;
    printf("Enter the elements to be sorted: ");
    for (int i = 0; i < total; i++) {
        scanf("%d", &num);
        root = insertInto(root, num);
    }
    printf("Array in Sorted Order: ");
    inorder(root);
    empty(root);
    return 0;
}