# include <stdio.h>
# include <stdlib.h>

typedef struct bst_node {
    int data;
    struct bst_node *LTree;
    struct bst_node *RTree;
} node;


void empty(node *root) {
    if (!root) {
        return;
    }
    empty(root->LTree);
    free(root->LTree);
    empty(root->RTree);
    free(root->RTree);
}

void inorder(node *root) {
    if (root) {
        inorder(root->LTree);
        printf("%d ", root->data);
        inorder(root->RTree);
    }
}

node *create(int data) {
    node *root = (node *) malloc(sizeof(node));
    root->data = data;
    root->LTree = NULL;
    root->RTree = NULL;
    return root;
}

node *insertInto(node *root, int data) {
    if (!root) {
        return create(data);
    }
    node *ptr = root, *ptr1;
    while (ptr) {
        if (data <= ptr->data) {
            ptr1 = ptr;
            ptr = ptr->LTree;
        } else if (data > ptr->data) {
            ptr1 = ptr;
            ptr = ptr->RTree;
        }
    }
    if (!ptr) {
        node *new_node = (node *) malloc(sizeof(node));
        new_node->data = data;
        new_node->LTree = new_node->RTree = NULL;

        if (ptr1->data > data) {
            ptr1->LTree = new_node;
        } else {
            ptr1->RTree = new_node;
        }
    }
    return root;// TO LET THE PROGRAM KNOW IT WAS SUCCESSFUL;
}