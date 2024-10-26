#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isfull(struct Stack *st)
{
    if(st->top==st->size-1)
    return 1;

    else
    return 0;
}

int isEmpty(struct Stack *st)
{
    if(st->top==-1)
    return 1;

    else
    return 0;
}

void push(struct Stack *st,int value)
{
    if(isfull(st))
    printf("Stack Overflow\n");

    else
    {
        st->top++;
        st->arr[st->top]=value;
        printf("pushed %d into the stack\n",st->arr[st->top]);
    }
}

int peek(struct Stack *st,int pos)
{
    if(st->top-pos+1<0)
    printf("Entered position is invalid!");

    else
    {
        return st->arr[st->top-pos+1];
    }
}

void pop(struct Stack *st)
{
    if(isEmpty(st))
    printf("Stack Underflow\n");

    else
    {
        printf("popped %d from the stack\n",st->arr[st->top]);
        st->top--;
    }
}

int StackTop(struct Stack *st)
{
    return st->arr[st->top];
}

int StackBottom(struct Stack *st)
{
    return st->arr[0];
}

int main()
{
    struct Stack *st=(struct Stack*)malloc(sizeof(struct Stack));
    st->size=10;
    st->top=-1;
    st->arr=(int*)malloc(st->size*sizeof(int));

    isfull(st);
    isEmpty(st);

    push(st,4);
    push(st,13);
    push(st,24);
    push(st,42);
    push(st,62);
    push(st,23);
    push(st,62);
    // push(st,51);
    // push(st,54);
    // push(st,67);
    // push(st,82);
    // push(st,79); //  Stack Overflow
    // pop(st);
    // pop(st);

    peek(st,2);

   // printf("%d ",peek(st,1));
   
   //Printing values inside the stack using peek operation
   for(int i=1;i<=st->top+1;i++)
   {
    printf("The value at position %d is %d\n",i,peek(st,i));
   }

   // Stack top
   printf("%d ",StackTop(st));

   //stack bottom
   printf("%d",StackBottom(st));



}