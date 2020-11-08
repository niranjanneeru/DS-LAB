# include <stdio.h>
# include <stdlib.h>

struct node {
    int val;
    struct node *link;
};

struct node *create() {
    return NULL;
}


void addAsFirst(struct node **head, int val) {
    struct node *next = (struct node *) malloc(sizeof(struct node));
    if (next == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    next->link = *head;
    *head = next;
    next->val = val;
}

int deleteFirst(struct node **head) {
    if (*head == NULL) {
        printf("LinkedList UnderFlow");
        return NULL;
    }
    int val = (*head)->val;
    struct node *ptr = *head;
    *head = (*head)->link;
    free(ptr);
    return val;
}

void addAsLast(struct node **head, int val) {
    struct node *ptr = *head;
    if (*head == NULL) {
        struct node *node = (struct node *) malloc(sizeof(struct node));
        if (node == NULL) {
            printf("Memory Underflow\n");
            return;
        }
        node->val = val;
        node->link = *head;
        *head = node;
        return;
    }
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    struct node *node = (struct node *) malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    node->val = val;
    node->link = ptr->link;
    ptr->link = node;
}


int deleteLast(struct node **head) {
    struct node *prev, *ptr = *head;
    if (*head == NULL) {
        printf("List Underflow");
        return NULL;
    }
    if ((*head)->link == NULL) {
        int value = (*head)->val;
        *head = ptr->link;
        free(ptr);
        return value;
    }
    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = ptr->link;
    int value = ptr->val;
    free(ptr);
    return value;
}

void print(struct node *head) {
    printf("Linked List:- ");
    while (head) {
        printf("%d ", head->val);
        head = head->link;
    }
    printf("\n");
}

void addWithKey(struct node **head, int val, int where) {
    struct node *ptr = *head;
    if (*head == NULL) {
        struct node *node = (struct node *) malloc(sizeof(struct node));
        if (node == NULL) {
            printf("Memory Underflow\n");
            return;
        }
        node->val = val;
        node->link = *head;
        *head = node;
        return;
    }
    while (ptr->val != where && ptr->link != NULL) {
        ptr = ptr->link;
    }
    if (ptr->val != where) {
        printf("Key not Found\n");
        return;
    }
    struct node *node = (struct node *) malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    node->val = val;
    node->link = ptr->link;
    ptr->link = node;
}


int deleteWithKey(struct node **head, int val) {
    struct node *prev=*head, *ptr = *head;
    if (*head == NULL) {
        printf("List Underflow");
        return NULL;
    }
    if ((*head)->val == val) {
        int value = (*head)->val;
        *head = ptr->link;
        free(ptr);
        return value;
    }
    while (ptr->val != val && ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    if (ptr->val != val) {
        printf("Key not Found");
        return NULL;
    }
    prev->link = ptr->link;
    int value = ptr->val;
    free(ptr);
    return value;
}

void addWithIndex(struct node **head, int val, int where) {
    int count = 2;
    struct node *ptr = *head;
    if(where <= 0){
        printf("Index not Found\n");
        return;
    }
    if(*head == NULL){
        if(where != 1){
            printf("Index not Found\n");
            return;
        }
    }
    if (where == 1) {
        struct node *node = (struct node *) malloc(sizeof(struct node));
        if (node == NULL) {
            printf("Memory Underflow\n");
            return;
        }
        node->val = val;
        node->link = *head;
        *head = node;
        return;
    }
    while (count != where && ptr->link != NULL) {
        ptr = ptr->link;
        count++;
    }
    if (count != where) {
        printf("Index not Found\n");
        return;
    }
    struct node *node = (struct node *) malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    node->val = val;
    node->link = ptr->link;
    ptr->link = node;
}


int deleteWithIndex(struct node **head, int where) {
    int count = 2;
    struct node *prev=*head, *ptr = *head;
    if (*head == NULL) {
        printf("List Underflow");
        return NULL;
    }
    if (where == 1) {
        int value = (*head)->val;
        *head = ptr->link;
        free(ptr);
        return value;
    }
    while (where != count && ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    if (where != count) {
        printf("Index not Found");
        return NULL;
    }
    prev->link = ptr->link;
    int value = ptr->val;
    free(ptr);
    return value;
}