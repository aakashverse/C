#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if(q->r==q->f)
    return 1;
    else
    return 0;
}

int isFull(struct queue *q)
{
    if(q->r==q->size-1)
    return 1;
    else
    return 0;
}

void enqueue(struct queue *q,int a)
{
    if(isFull(q))
    printf("Queue Overflow");
    else
    q->arr[++q->r]=a;
}

int dequeue(struct queue *q)
{
    int a=-1;

    if(isEmpty(q)){
    printf("Queue Underflow");
    }

    else{
    a=q->arr[++q->f];
    }
    
    return a;
}


// void qtraversal(struct queue *q)
// {
//     while(q!=q->size-1)
//     printf("%d ",q->arr[q->r]);
// }
int main()
{
    struct queue q;
    q.size=10;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    
    
    enqueue(&q,12);
    enqueue(&q,32);
    enqueue(&q,42);

    printf("dequeueing element %d\n",dequeue(&q));
    printf("dequeueing element %d\n",dequeue(&q));
    printf("dequeueing element %d\n",dequeue(&q));

    if(isEmpty(&q)){
    printf("q is empty");
    }

    if(isFull(&q)){
    printf("q is full");
    }
    
    //qtraversal(&q);


    

}