#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

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
    head=(struct Node*)malloc(sizeof(struct Node));
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
   return 0;

}