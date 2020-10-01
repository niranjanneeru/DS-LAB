// Aim :- Implement Queue Data Structure using Array

// Input:- enqueue,dequeue operations
// Output:- queue after operations
// Data Structure used :- Queue (Array in FIFO) pointed by FRONT and REAR

// Start
// 1. Take a array of size N QUEUE[N]
// 2. Initialize FRONT = -1 and REAR = -1
// 3. enqueue(ITEM)
// 4.     if(N-1==REAR)
// 5.          print "QUEUE OVERFLOW"
// 6.
// 7.     else if(FRONT == -1 && REAR == -1)
// 8.          FRONT=REAR=0
// 9.          QUEUE[REAR] = ITEM
// 10.    else
// 11.         REAR = REAR + 1
// 12.         QUEUE[REAR] = ITEM
// 13. dequeue()
// 14.     if(FRONT == -1)
// 15.          print "QUEUE UNDERFLOW"
// 16.     ITEM = QUEUE[FRONT]
// 17.     else if(FRONT == REAR)
// 18.          FRONT=REAR=-1
// 19.     else
// 20.          FRONT = FRONT + 1
// 21.     return ITEM
// Stop
//

// Time Complexity
// enqueue(ITEM)
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)


// dequeue()
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)


#include <stdio.h>
#include <stdlib.h>

#define loop(j,n) for (int i = j; i < n; i++)

struct queue{
  int front;
  int rear;
  int max_size;
  int * queue;
};

int isFull(struct queue *d){
  if(d->max_size-1 == d->rear){
    return 1;
  }
  return 0;
}

int isEmpty(struct queue *d){
  if(-1 == d->front){
    return 1;
  }
  return 0;
}
void create_queue(struct queue *d){
  printf("Enter the max size of the queue: ");
  scanf("%d",&d->max_size);
  d->front = d->rear = -1;
  d->queue = (int *)malloc(d->max_size * sizeof(int));
}

void enqueue(struct queue *d,int item){
  if(isFull(d)){
    printf("Queue Overflow\n");
    return;
  }
  if(d->front == -1 && d->rear == -1){
    d->front = d->rear = 0;
  }else{
    d->rear++;
  }
  d->queue[d->rear]=item;
}

int dequeue(struct queue *d){
  if(isEmpty(d)){
    printf("Queue UnderFlow\n");
    return NULL;
  }
  int item = d->queue[d->front];
  if(d->front==d->rear){
    d->front=d->rear=-1;
  }else{
    d->front++;
  }
  return item;
}

void printqueue(struct queue *d){
  printf("\n");
  printf("Front :- %d Rear :- %d\n",d->front,d->rear);
  loop(d->front,d->rear)
    printf("%d ",*(d->queue + i));
  printf("\n");
}


int main(){
  struct queue que_array;
  create_queue(&que_array);
  enqueue(&que_array,20);
  printqueue(&que_array);
  dequeue(&que_array);
  printqueue(&que_array);
  return 0;
}
