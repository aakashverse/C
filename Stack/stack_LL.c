#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top=NULL;   //Globally declared for--> pop operation

int isEmpty(struct Node *top)
{
    if(top==NULL)
    return 1;

    else
    return 0;
}

int isFull(struct Node *top)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

    if(temp==NULL)
    return 1;

    else
    return 0;
}

struct Node* push(struct Node* top,int val)
{
    if(isFull(top))
    printf("Stack Overflow\n");

    else
    {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=val;
        printf("pushed %d into the stack\n",val);
        temp->next=top;
        top=temp;
        return top;
    }
}

int pop(struct Node* tp)
{
    if(isEmpty(tp))
    printf("Stack Underflow\n");
    
    else
    {
        struct Node* temp=tp;
        top=tp->next;
        int x=temp->data;
        free(temp);
        return x;
    }

}

void LLTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int peek(struct Node* top,int index)
{
    if(index<0)
    return -1; 

    while(index--)
    {
        top=top->next;
    }
    return top->data;

}

int main()
{
    top=push(top,4);
    top=push(top,23);
    top=push(top,44);
    top=push(top,64);
    top=push(top,15);
    printf("popped element is: %d\n",pop(top));

    LLTraversal(top);
    int pelement=peek(top,2);
    printf("\nThe peek element is: %d",pelement);
    //printf("%d",isEmpty(top));
}