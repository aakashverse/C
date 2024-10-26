#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Case-1
struct Node* InsertAtFirst(struct Node* head,int value)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=head;
    //head=temp;
    return temp;
}

// Case-2
struct Node* insertAtIndex(struct Node* head,int value,int index)
{
    struct Node* p=head;
    while(index--)
    p=p->next;

    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

    temp->data=value;
    temp->next=p->next;
    p->next=temp;
    return head;
}

//Case-3
struct Node* insertAtEnd(struct Node* head,int value)
{
   struct Node* q=head;
   while(q->next!=NULL)
   q=q->next;

   struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
   temp->data=value;
   temp->next=NULL;
   q->next=temp;
   return head;
}

// Case-4
struct Node* insertAfterNode(struct Node* head,struct Node* prevNode,int value)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

    temp->data=value;
    temp->next=prevNode->next;
    prevNode->next=temp;
    return head;
}

void LLTraversal(struct Node* ptr)
{
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    //create LL
    struct Node* head;
    struct Node* p1;
    struct Node* p2;
    struct Node* p3;
    
    //Allocate memory to each Node Dynamically
    head =(struct Node*)malloc(sizeof(struct Node));
    p1=(struct Node*)malloc(sizeof(struct Node));
    p2=(struct Node*)malloc(sizeof(struct Node));
    p3=(struct Node*)malloc(sizeof(struct Node));

   head->data=4;
   head->next=p1;

   p1->data=5;
   p1->next=p2;

   p2->data=19;
   p2->next=p3;

   p3->data=25;
   p3->next=NULL;
   
   LLTraversal(head);
   //head=insertAtFirst(head,10);
   printf("\n");
   //head=insertAtIndex(head,17,2);

   //head=insertAtEnd(head,42);
   
   head=insertAfterNode(head,p1,64);

   LLTraversal(head);
   return 0;

}