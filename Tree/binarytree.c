#include <stdio.h>
# include <stdlib.h>
# include "binarytree.h"
# include <ctype.h>

int main() {
    int choose, value, key;
    node *root = NULL;
    start:
    printf("\nChoose an Operation\n1. Build Tree\n2. Insert into a Tree\n3. Delete into a Tree\n4. PreOrder\n5. InOrder\n6. PostOrder\n7. Exit\n: ");
    scanf_s("%d", &choose);
    switch (choose) {
        case 1:
            if (root != NULL) {
                printf("This process will override existing tree");
                printf("Are you sure to proceed: ");
                fflush(stdin);
                if (tolower(getchar()) != 'y') {
                    goto start;
                } else {
                    empty(root);
                }
            }
            printf("Creating a Tree...\n");
            root = buildTree();
            if (root == NULL) {
                printf("Tree wasn't made");
            }
            goto start;
        case 2:
            if(!root){
                printf("Empty Tree\n");
                printf("Perform Build Tree First\n");
                goto start;
            }
            printf("Enter the value you want to Insert: ");
            scanf_s("%d", &value);
            printf("Enter where the value is to be Inserted: ");
            scanf_s("%d", &key);
            insert(root, value, key);
            goto start;
        case 3:
            printf("Enter the value to be deleted: ");
            scanf_s("%d", &value);
            remove_node(&root, value);
            goto start;
        case 4:
            preorder(root);
            goto start;
        case 5:
            inorder(root);
            goto start;
        case 6:
            postorder(root);
            goto start;
        default:
            printf("Exiting....");
            empty(root);
    }
}