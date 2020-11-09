// Aim:- Single Linked List Implementation

// Input through functions like addAsFirst(),addAsLast(),addWithKey(),addWithIndex(),deleteFirst(),deleteLast(),deleteWithKey(),deleteWithIndex(),display()
// Output :- LinkedList after successful operations

// Data Structure Used:- Singly Linked List with a header pointed to the First Node {int data,node link}

// Algorithm
// 1. Create Header pointer (HEAD) and assign it to be NULL
// 2. addAsFirst(val)
// 3.  next = GetNode(node)
// 4.  if next is NULL
// 5.   print MEMORY UNDERFLOW
// 6.   return NULL
// 7.  next->data = val
// 8.  next->link = HEAD
// 9.  HEAD = next

// 10. deleteFirst()
// 11.  if HEAD = NULL
// 12.      print LinkedList Underflow
// 13.  else
// 14.      val = HEAD->data
// 15.      ptr = HEAD
// 16.      HEAD = HEAD->link
// 17.      ReturnNode(ptr)
// 18.      return val

// 19. addAsLast(int val)
// 20.  next = GetNode(node)
// 21.  if next is NULL
// 22.   print MEMORY UNDERFLOW
// 23.   return NULL
// 24.  if HEAD is NULL
// 25.   next->data = val
// 26.   next->link = HEAD
// 27.   HEAD = next
// 28.  else
// 29.   ptr = HEAD
// 30.   while ptr->link != NULL
// 31.      ptr = ptr->link
// 32.    next->data = val
// 33.    next->link = ptr->link
// 34.    ptr->link = next

// 35. deleteLast()
// 36.   prev = NULL
// 37.   ptr = head;
// 38.   if HEAD == NULL
// 39.      print "List Underflow"
// 40.   if HEAD->link == NULL
// 41.       val = HEAD->data
// 42.       HEAD = ptr->link;
// 43.       ReturnNode(ptr)
// 44.       return value
// 45.   while (ptr->link != NULL)
// 46.        prev = ptr;
// 47.        ptr = ptr->link;
// 48.   prev->link = ptr->link;
// 49.   val = ptr->val;
// 50.   ReturnNode(ptr)
// 51.   return value

// 52. print()
// 53. ptr = HEAD
// 54. while(ptr)
// 55.   print ptr->val
// 56.   ptr=ptr->link

// 57. addWithKey(int val,int key)
// 58.  next = GetNode(node)
// 59.  if next is NULL
// 60.   print MEMORY UNDERFLOW
// 61.   return NULL
// 62.  if HEAD is NULL
// 63.   next->data = val
// 64.   next->link = HEAD
// 65.   HEAD = next
// 66.  else
// 67.   ptr = HEAD
// 68.   while ptr->link != NULL and ptr->data != key
// 69.      ptr = ptr->link
// 70.      if ptr->data == key
// 71.          next->data = val
// 72.          next->link = ptr->link
// 73.          ptr->link = next
// 74.      else
// 75.          print KEY NOT FOUND

// 76. addWithIndex(int val,int where)
// 77.     count = 2
// 78.     if where < 1 : PRINT Invalid Index;
// 79.        exit
// 80.  next = GetNode(node)
// 81.  if next is NULL
// 82.   print MEMORY UNDERFLOW
// 83.   return NULL
// 84.  if HEAD is NULL
// 85.   next->data = val
// 86.   next->link = HEAD
// 87.   HEAD = next
// 88.  else
// 89.   ptr = HEAD
// 90.   while ptr->link != NULL and count != where
// 91.      ptr = ptr->link
// 92.       count++
// 93.      if where == count
// 94.          next->data = val
// 95.          next->link = ptr->link
// 96.          ptr->link = next
// 97.      else
// 98.          print Index NOT FOUND

// 99. deleteWithKey(int key)
// 100.   prev = HEAD
// 101.   ptr = HEAD;
// 102.   if HEAD == NULL
// 103.      print "List Underflow"
// 104.   if HEAD->val == val
// 105.       val = HEAD->data
// 106.       HEAD = ptr->link;
// 107.       ReturnNode(ptr)
// 108.       return value
// 109.   while (ptr->link != NULL and ptr->data != key)
// 110.        prev = ptr;
// 111.        ptr = ptr->link;
// 112.   if ptr->data != key
// 113.        print KEY NOT FOUND
// 114.        return
// 115.   prev->link = ptr->link;
// 116.   val = ptr->val;
// 117.   ReturnNode(ptr)
// 118.   return value

// 119. deleteWithIndex(int where)
// 120.   count = 1
// 121.      if where < 1
// 122.        print INVALID INDEX
// 123.        exit
// 124.   prev = HEAD
// 125.   ptr = HEAD;
// 126.   if HEAD == NULL
// 127.      print "List Underflow"
// 128.   if where == 1
// 129.       val = HEAD->data
// 130.       HEAD = ptr->link;
// 131.       ReturnNode(ptr)
// 132.       return value
// 133.   while (ptr->link != NULL and count != where)
// 134.        prev = ptr;
// 135.        ptr = ptr->link;
// 136.        count++
// 137.   if count !=where
// 138.        print INDEX NOT FOUND
// 139.        return
// 140.   prev->link = ptr->link;
// 141.   val = ptr->val;
// 142.   ReturnNode(ptr)
// 143.   return value

//Result
//  addAsFirst(val)
//  Time Complexity :- O(1)
//  Space Complexity :- O(1)
//  deleteFirst()
//  Time Complexity :- O(1)
//  Space Complexity :- O(1)
//  addAsLast(int val)
//  Time Complexity :- O(n)
//  Space Complexity :- O(1)
//  deleteLast()
//  Time Complexity :- O(n)
//  Space Complexity :- O(1)
//  print()
//  Time Complexity :- O(n)
//  Space Complexity :- O(1)
//  addWithKey(int val,int key)
//  Time Complexity :- O(n) (Worst Case)(Depend on Key and if it's not found)
//  Space Complexity :- O(1)
//  addWithIndex(int val,int where)
//  Time Complexity :- O(n) (Worst Case)(Depend on where and if it's not found)
//  Space Complexity :- O(1)
//  deleteWithKey(int key)
//  Time Complexity :- O(n) (Worst Case)(Depend on Key and if it's not found)
//  Space Complexity :- O(1)
//  deleteWithIndex(int where)
//  Time Complexity :- O(n) (Worst Case)(Depend on where and if it's not found)
//  Space Complexity :- O(1)

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
    struct node *prev = *head, *ptr = *head;
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
    if (where <= 0) {
        printf("Index not Found\n");
        return;
    }
    if (*head == NULL) {
        if (where != 1) {
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
    int count = 1;
    struct node *prev = *head, *ptr = *head;
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
        count++;
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


void clearList(struct node *head) {
    struct node *ptr;
    while (head) {
        ptr = head;
        head = head->link;
        free(ptr);
    }
}