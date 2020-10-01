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
  struct queue deque_array;
  create_queue(&deque_array);
  enqueue(&deque_array,20);
  printqueue(&deque_array);
  enqueue(&deque_array,20);
  printqueue(&deque_array);
  enqueue(&deque_array,20);
  printqueue(&deque_array);
  enqueue(&deque_array,20);
  printqueue(&deque_array);
  enqueue(&deque_array,20);
  printqueue(&deque_array);
  dequeue(&deque_array);
  printqueue(&deque_array);
  dequeue(&deque_array);
  printqueue(&deque_array);
  dequeue(&deque_array);
  printqueue(&deque_array);
  dequeue(&deque_array);
  printqueue(&deque_array);
  dequeue(&deque_array);
  printqueue(&deque_array);
  return 0;
}
