#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct queue
{
    int item;
    int front;
    int rear;
    int size;
    int *a;
};

void create_queue(struct queue *q)
{
    q->front=q->rear=-1;
    printf("enter the size of queue\n");
    scanf("%d",&q->size);
    q->a=(int *)malloc(q->size*sizeof(int));
}

void insert_queue(struct queue *q,int b)
{
    if(q->rear>=q->size-1)
        printf("queue is full\n");
    else if(q->front==-1&&q->rear==-1)
    {
        q->front=q->rear=0;
        q->a[q->rear]=b;
    }
    else
    {
        q->rear=q->rear+1;
        q->a[q->rear]=b;
    }

}

void delete_queue(struct queue *q)
{
    if(q->front==-1 && q->rear==-1)
        printf("queue is empty\n");
    else if(q->front==q->rear)
    {
        q->item=q->a[q->front];
        q->front=q->rear=-1;
    }
    else
    {
        q->item=q->a[q->front];
        q->front=q->front+1;
    }

}
void display_queue(struct queue *q)
{
    int j=0;
    for(int i=q->front;i<q->rear;i++)
    {
        printf("queue=%d with front=%d\n",q->a[i],q->front+j);
        j++;
    }
}

void main()
{
    struct queue q1;
    int p,r,s;
    create_queue(&q1);
    A1:
    printf("choose an option\n");
    printf("1=insertion\n 2=deletion\n 3=print_queue\n");
    scanf("%d",&p);
    switch(p)
    {
        case 1:
            printf("enter the element to be inserted\n");
            scanf("%d",&r);
            insert_queue(&q1,r);
            goto A1;

        case 2:
            delete_queue(&q1);
            goto A1;

        case 3:
            display_queue(&q1);
            break;

        default:
            printf("invalid input\n");
    }

}