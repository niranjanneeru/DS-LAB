// Aim :- Implement Circular Deque Data Structure using Array

// Input:- enqueue,dequeue operations through front and rear
// Output:- deque after operations
// Data Structure used :- Deque (Array in FIFO) pointed by FRONT and REAR

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
// enqueueFront(ITEM) and enqueueRear(ITEM)
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)


// dequeueFront() and dequeueRear()
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)


#include <stdio.h>
#include <stdlib.h>

#define loop(i,n) for (int i = 0; i < n; i++)

struct deque{
  int front;
  int rear;
  int max_size;
  int * queue;
};

int isFull(struct deque *d){
  if(d->front == (d->rear+1)%d->max_size){
    return 1;
  }
  return 0;
}

int isEmpty(struct deque *d){
  if(d->front == -1){
    return 1;
  }
  return 0;
}

void create_deque(struct deque *d){
  printf("Enter the max size of the queue: ");
  scanf("%d",&d->max_size);
  d->front = d->rear = -1;
  d->queue = (int *)malloc(d->max_size * sizeof(int));
}

void enqueuerear(struct deque *d,int item){
  if(isFull(d)){
    printf("%s\n","Deque Overflow");
    return;
  }
  if(d->front==-1 && d->rear==-1){
    d->front = d->rear = 0;
    d->queue[d->rear] = item;
  }else{
    d->rear = (d->rear+1)%d->max_size;
    d->queue[d->rear] = item;
  }
}

void enqueuefront(struct deque *d,int item){
  if(isFull(d)){
    printf("%s\n","Deque Overflow");
    return;
  }
  if(d->front==-1 && d->rear==-1){
    d->front = d->rear = 0;
    d->queue[d->front] = item;
  }else if (d->front==0){
    d->front = d->max_size - 1;
    d->queue[d->front] = item;
  }else{
    d->front--;
    d->queue[d->front] = item;
  }
}

void printqueue(struct deque *d){
  printf("\n");
  printf("Front :- %d Rear :- %d\n",d->front,d->rear);
  if(isEmpty(d)){
    printf("%s\n","Empty Queue");
    return;
  }
  int i = d->front;
  while(i!=d->rear){
    printf("%d ",*(d->queue + i));
    i = (i+1)%d->max_size;
  }
  printf("%d\n",*(d->queue+d->rear));
}

int dequefront(struct deque *d){
  if(isEmpty(d)){
    printf("%s\n","Deque Underflow");
    return NULL;
  }
  int item = d->queue[d->front];
  if(d->front==d->rear){
    d->front = d->rear = -1;
  }else{
    d->front =  (d->front+1)%d->max_size;
  }
  return item;
}

int dequerear(struct deque *d){
  if(isEmpty(d)){
    printf("%s\n","Deque Underflow");
    return NULL;
  }
  int item = d->queue[d->rear];
  if(d->front==d->rear){
    d->front = d->rear = -1;
  }else if (d->rear==0){
    d->rear = d->max_size - 1;
  }else{
    d->rear--;
  }
  return item;
}


int main(){
  struct deque deque_array;
  create_deque(&deque_array);
  enqueuerear(&deque_array,20);
  printqueue(&deque_array);
  enqueuerear(&deque_array,20);
  printqueue(&deque_array);
  dequerear(&deque_array);
  printqueue(&deque_array);
  dequefront(&deque_array);
  enqueuerear(&deque_array,20);
  enqueuerear(&deque_array,20);
  enqueuerear(&deque_array,20);
  printqueue(&deque_array);
  return 0;
}
