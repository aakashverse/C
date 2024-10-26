#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *st)
{
    if(st->top==-1)
    return 1;

    else
    return 0;
}

int isfull(struct stack *st)
{
    if(st->top==st->size-1)
    return 1;

    else
    return 0;
}

void push(struct stack *st,char value)
{
    if(isfull(st))
    printf("Stack Overflow\n");

    else
    {
        st->top++;
        st->arr[st->top]=value;
        //printf("pushed %d into the stack\n",st->arr[st->top]);
    }
}

char pop(struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack Underflow\n");
        return '\0';
    }

    else
    {
        //printf("popped %d from the stack\n",st->arr[st->top]);
        return st->arr[(st->top)--];
        
    }
}

int precedence(char ch)
{
    if(ch=='*' || ch=='/')
    return 3;
    else if(ch=='+' || ch=='-')
    return 2;
    else
    return 0;
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    return 1;
    else
    return 0; 
}

char* InToPost(char* infix)
{
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->size=10;
    st->top=-1;
    st->arr=(char*)malloc(st->size*sizeof(char));
    char* postfix=(char*)malloc(strlen(infix)+1*sizeof(char*));
    int i=0; // Track infix Traversal 
    int j=0; //Track postfix Addition

    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++,j++;
        }
        else
        {
            if(precedence(infix[i])>precedence(st->arr[st->top]))
            {
                push(st,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(st);
                j++;

            }
        }  
    }
    while(!isEmpty(st))
    {
        postfix[j]=pop(st);
        j++;
    }
    
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="x-y/z-k*d";
    printf("postfix is: %s",InToPost(infix));


}