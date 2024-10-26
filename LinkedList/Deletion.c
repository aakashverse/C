#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Case-1
struct Node* DelAtFirst(struct Node* head)
{
    struct Node* p=head;
    head=head->next;
    free(p);
    return head;
}

//  Case-2
struct Node* DelAtIndex(struct Node* head,int index)
{
    struct Node* p=head;

    while(index--)
    p=p->next;

    struct Node* q=p->next;
    p->next=q->next;
    free(q);
    return head;
}

// Case-3
struct Node* DelAtEnd(struct Node* head)
{
    struct Node* temp1=head;
    struct Node* temp2=NULL;

    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }

    free(temp1);
    temp2->next=NULL;
    return head;
}

// Case-4
struct Node* DelAfterNode(struct Node* head,struct Node* prevNode)
{
    struct Node* temp=prevNode->next;
    prevNode->next=temp->next;
    free(temp);
    return head;
}

void LLTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
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
    struct Node* p4;
    
    //Allocate memory to each Node Dynamically
    head =(struct Node*)malloc(sizeof(struct Node));
    p1=(struct Node*)malloc(sizeof(struct Node));
    p2=(struct Node*)malloc(sizeof(struct Node));
    p3=(struct Node*)malloc(sizeof(struct Node));
    p4=(struct Node*)malloc(sizeof(struct Node));

   head->data=4;
   head->next=p1;

   p1->data=5;
   p1->next=p2;

   p2->data=19;
   p2->next=p3;

   p3->data=25;
   p3->next=p4;

   p4->data=10;
   p4->next=NULL;
   
   LLTraversal(head);
   printf("\n");

   //head=DelAtFirst(head); 

   //head=DelAtIndex(head,1);

   //head=DelAtEnd(head);

   head=DelAfterNode(head,p1);
    
   LLTraversal(head);
   return 0;

}