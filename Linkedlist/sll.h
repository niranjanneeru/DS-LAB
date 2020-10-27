# include <stdio.h>
# include <stdlib.h>

struct node_int
{
    int val;
    struct node_int *link;
};

struct node_int * create_sll_int(){
    return NULL;
}

void print_sll_int(struct node_int * head){
    printf("Linked List:- ");
    while(head){
        printf("%d ",head->val);
        head = head->link;
    }
    printf("\n");
}

void insert_sll_int(struct node_int ** head,int val,int where){
    struct node_int * ptr = *head;
    if(*head==NULL){
        struct node_int * node = (struct node_int *)malloc(sizeof(struct node_int));
        if(node==NULL){
            printf("Memory Underflow\n");
            return;
        }
        node->val = val;
        node->link = *head;
        *head = node;
        return;
    }
    while(ptr->val != where && ptr->link!=NULL){
        ptr = ptr->link;
    }
    if(ptr->val!=where){
        printf("Key not Found\n");
        return;
    }
    struct node_int * node = (struct node_int *)malloc(sizeof(struct node_int));
    if(node==NULL){
        printf("Memory Underflow\n");
        return;
    }
    node->val = val;
    node->link = ptr->link;
    ptr->link = node;
}

int delete_sll_int(struct node_int ** head,int val){
    struct node_int * prev,*ptr = *head;
    if(*head==NULL){
        printf("List Underflow");
        return NULL;
    }
    if((*head)->val==val){
        int value = (*head)->val;
        *head = ptr->link;
        free(ptr);
        return value;
    }
    while(ptr->val != val && ptr->link != NULL){
        prev = ptr;
        ptr= ptr->link;
    }
    if(ptr->val!=val){
        printf("Key not Found");
        return NULL;
    }
    prev->link = ptr->link;
    int value = ptr->val;
    free(ptr);
    return value;
}