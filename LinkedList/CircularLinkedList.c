#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// case-1
struct Node* insertAtfirst(struct Node* head,int value)
{
    //struct Node* ptr=head;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;

    // Point to itself if the list is empty
    if (head == NULL) 
    {
        temp->next = temp; 
        return temp;
    }

    struct Node* p=head->next;

    while(p->next!=head)
    {
        p=p->next;
    }
    // At this point p points to the last node of the circular LL

    p->next=temp;
    temp->next=head;
    head=temp;
    return head;
}

// case-2, case-3, case-4 same as LL
void LLTraversal(struct Node* head)
{
    struct Node* temp=head;

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}


int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    
    //Allocating memory
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    
    struct Node* first=head;
    
    //Linking all nodes of circular LL
    first->data=8;
    first->next=second;

    second->data=23;
    second->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=9;
    fourth->next=head;

    //Traversal of circular linked list

    LLTraversal(head);
    printf("\n");

    head=insertAtfirst(head,13);

    LLTraversal(head);
}