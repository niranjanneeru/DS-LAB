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

void preorder(node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->LTree);
        preorder(root->RTree);
    }
}

void postorder(node *root) {
    if (root) {
        postorder(root->LTree);
        postorder(root->RTree);
        printf("%d ", root->data);
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
        if (data < ptr->data) {
            ptr1 = ptr;
            ptr = ptr->LTree;
        } else if (data > ptr->data) {
            ptr1 = ptr;
            ptr = ptr->RTree;
        } else {
            printf("ITEM ALREADY EXIST");
            return root;
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
        return root;// TO LET THE PROGRAM KNOW IT WAS SUCCESSFUL;
    }
}

node *succ(node *ptr) {
    node *ptr1 = ptr->RTree;
    if (ptr1) {
        while (ptr->LTree) {
            ptr1 = ptr1->LTree;
        }
    }
    return ptr1;
}

node *clear(node *root, int data) {
    node *ptr = root;
    node *parent = NULL;
    int flag = 1;
    if (!ptr) {
        printf("EMPTY TREE");
        return;
    }
    while (ptr && flag) {
        if (data < ptr->data) {
            parent = ptr;
            ptr = ptr->LTree;
        } else if (data > ptr->data) {
            parent = ptr;
            ptr = ptr->RTree;
        } else {
            flag = 0;
        }
    }
    if (flag) {
        printf("No Item");
        return root;
    }
    if (parent == NULL) {
        empty(root);
        root = NULL;
        return root;
    }
    if (!ptr->LTree && !ptr->RTree) {
        if (parent->LTree == ptr) {

            parent->LTree = NULL;
        } else {
            parent->RTree = NULL;
        }
    } else {
        if (ptr->LTree && ptr->RTree) {
            node *ptr1 = succ(ptr);
            int res = ptr1->data;
            clear(root, res);
            ptr->data = res;
        } else {
            if (parent->LTree == ptr) {
                if (ptr->LTree) {
                    parent->LTree = ptr->LTree;
                } else {
                    parent->LTree = ptr->RTree;
                }
            } else if (parent->RTree == ptr) {
                if (ptr->RTree) {
                    parent->RTree = ptr->RTree;
                } else {
                    parent->RTree = ptr->LTree;
                }
            }
        }
    }
    return root;
}


int num_leaf_nodes(node *root) {
    if(!root){
        return 0;
    }
    if (!root->LTree && !root->RTree) {
        return 1;
    } else {
        return num_leaf_nodes(root->LTree) + num_leaf_nodes(root->RTree);
    }
}