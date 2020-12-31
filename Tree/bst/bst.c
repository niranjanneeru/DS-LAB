#include <stdio.h>
# include <stdlib.h>
# include "bst.h"

int main() {
    int choose, value;
    node *root = NULL;
    start:
    printf("\nChoose an Operation\n1. Insert into a Tree\n2. Delete into a Tree\n3. PreOrder\n4. InOrder\n5. PostOrder\n6. Number of Leaf Nodes\n7. Exit\n: ");
    scanf_s("%d", &choose);
    switch (choose) {
        case 1:
            printf("Enter the value you want to Insert: ");
            scanf_s("%d", &value);
            root = insertInto(root, value);
            goto start;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf_s("%d", &value);
            root = clear(root, value);
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
        case 6:
            printf("Number of Leaf Nodes :- %d",num_leaf_nodes(root));
            goto start;
        default:
            printf("Exiting....");
            empty(root);
    }
}