#include <stdio.h>
# include <stdlib.h>
# include "binarytree.h"

int main() {
    printf("Creating a Tree...\n");
    node *root = buildTree();
    if (root == NULL) {
        printf("Tree wasn't made");
        return 0;
    }
    int choose, value, key;
    start:
    printf("\nChoose an Operation\n1. Insert into a Tree\n2. Delete into a Tree\n3. PreOrder\n4. InOrder\n5. PostOrder\n6. Exit\n: ");
    scanf_s("%d", &choose);
    switch (choose) {
        case 1:
            printf("Enter the value you want to Insert: ");
            scanf_s("%d", &value);
            printf("Enter where the value is to be Inserted: ");
            scanf_s("%d", &key);
            insert(root, value, key);
            goto start;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf_s("%d", &value);
            remove(root, value);
            goto start;
        case 3:
            preorder(root);
            goto start;
        case 4:
            inorder(root);
            goto start;
        case 5:
            postorder(root);
            goto start;
        default:
            printf("Exiting....");
            empty(root);
    }
}