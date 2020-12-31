# include <stdio.h>
# include <stdlib.h>

typedef struct binary_tree_node {
    int data;
    struct binary_tree_node *LTree;
    struct binary_tree_node *RTree;
} node;

node *buildTree() {
    int data;
    printf("Enter data (0 to Exit): ");
    scanf_s("%d", &data);
    if (data != 0) {
        node *new_node = (node *) malloc(sizeof(node));
        new_node->data = data;
        printf("Node to the Left of %d\n", data);
        new_node->LTree = buildTree();
        printf("Node to the Right of %d\n", data);
        new_node->RTree = buildTree();
        return new_node;
    } else {
        return NULL;
    }
}

node *search(node *root, int key) {
    if (!root) {
        return NULL;
    }
    if (root->data != key) {
        node *temp = search(root->LTree, key);
        if (temp != NULL) {
            return temp;
        }
        return search(root->RTree, key);

    } else {
        return root;
    }
}

void insert(node *root, int value, int key) {
    node *pos = search(root, key);
    if (!pos) {
        printf("Element not Found");
        return;
    }
    if (!pos->RTree || !pos->LTree) {
        node *temp = (node *) malloc(sizeof(node));
        temp->data = value;
        temp->LTree = temp->RTree = NULL;
        if (!pos->LTree) {
            pos->LTree = temp;
            printf("Insertion Complete to the left of %d",pos->data);
        } else if (!pos->RTree) {
            pos->RTree = temp;
            printf("Insertion Complete to the right of %d",pos->data);
        }
    } else {
        printf("The Element Already have a subtree");
    }
}

node *search_parent(node *root, node *parent, int value) {
    if(!root){
        return NULL;
    }
    if (root->data != value) {
        parent = root;
        node *temp = search_parent(root->LTree, parent, value);
        if (temp) {
            return temp;
        }
        return search_parent(root->RTree, parent, value);
    } else {
        return parent;
    }
}

void delete(node *root,int value) {
    if (!root) {
        printf("Empty Tree");
        return;
    }
    node *pos = search_parent(root, NULL, value);
    if (!pos) {
        printf("Element Not in Tree");
        return;
    }
    if (pos->LTree->data == value) {
        if (!pos->LTree->LTree && !pos->LTree->RTree) {
            free(pos->LTree);
            pos->LTree = NULL;
            printf("Deletion Complete from the left of %d",pos->data);
        } else {
            printf("Non Leaf Node");
            return;
        }
    } else if(pos->RTree->data == value){
        if (!pos->RTree->LTree && !pos->RTree->RTree) {
            free(pos->RTree);
            pos->RTree = NULL;
    printf("Deletion Complete from the right of %d",pos->data);
        } else {
            printf("Non Leaf Node");
        }
    }
}

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