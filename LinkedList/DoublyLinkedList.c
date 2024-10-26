#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

// Case-1
void DoublyLLTraversal(struct Node* head)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;

        
    }

    // while(temp!=NULL)
    // {
    //     printf("%d ",temp->data);
    //     temp=temp->prev;
        
    // }
}

// Case-2
struct Node* DoublyLLInsertionAtFirst(struct Node* head,int value)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=head;
    temp->prev=NULL;
    head=temp;

    return head;
}

//Case-3
struct Node* DoublyLLInsertionAtEnd(struct Node* head,int value)
{
    struct Node* p=head;

    while(p->next!=NULL)
    {
        p=p->next;
    }
    
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    p->next=temp;
    temp->prev=p;
    temp->next=NULL;
    return head;
}

//Case-4
struct Node* DoublyLLInsertionAtMiddle(struct Node* head,int pos,int value)
{
    struct Node* p=head;
    while(pos)
    {
        p=p->next;
        pos--;
    }

    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;

    temp->next=p->next;
    p->next->prev=temp;
    p->next=temp;
    temp->prev=p;
   
    return head;
}

int main()
{
    struct Node* head;
    struct Node* p1;
    struct Node* p2;
    struct Node* p3;
    struct Node* p4;

    head=(struct Node*)malloc(sizeof(struct Node));
    p1=(struct Node*)malloc(sizeof(struct Node));
    p2=(struct Node*)malloc(sizeof(struct Node));
    p3=(struct Node*)malloc(sizeof(struct Node));
    p4=(struct Node*)malloc(sizeof(struct Node));

    //Linking elements of doubly linked list

    head->data=3;
    head->prev=NULL;
    head->next=p1;

    p1->data=14;
    p1->prev=head;
    p1->next=p2;
    
    p2->data=23;
    p2->prev=p1;
    p2->next=p3;
    
    p3->data=31;
    p3->prev=p2;
    p3->next=p4;

    p4->data=42;
    p4->prev=p3;
    p4->next=NULL;
    
    
    DoublyLLTraversal(head);

   // head=DoublyLLInsertionAtFirst(head,16);
    

    //head=DoublyLLInsertionAtEnd(head,54);
    

    head=DoublyLLInsertionAtMiddle(head,3,91);
    printf("\n");

    DoublyLLTraversal(head);
    
}