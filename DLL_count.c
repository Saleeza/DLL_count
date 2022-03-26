#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct dlist
{
    int data;
    struct dlist *link;
    struct dlist *prev;
} node ;
void create(node **end,node **head)
{
    int item,ch=1,choice;
    if (*head!=NULL)
    {
        printf("\n-----list already exists----");
    }
     node *temp=(node*)malloc(sizeof(node));

    while(ch==1)
    {

    printf("\n\tEnter the element to be inserted : ");
    scanf("%d",&item);
    node *new=(node*)malloc(sizeof(node));
    new->data=item;
    new->link=NULL;
    new->prev=NULL;

    if (*head==NULL)
    {
        temp=*head=*end=new;
    }
    else
    {
     temp->link=new;
     new->prev=temp;
    temp=new;
    }
    *end=new;
    printf("\n\tdo you want to continue  1)yes    2)no  ");
    scanf("%d",&choice);
    ch=choice;
}
}
 
void display(node *head,node *end)
{
    node *temp;
    printf("\n\t prev address   address   data    new address");
    for (temp=head;temp!=NULL;temp=temp->link)
    {
        printf("\n\t%10u   %10u   %d    %10u",temp->prev,temp,temp->data,temp->link);
    }

     printf("\n\t==================================================");
     printf("\n\t prev address   address   data    new address");
    for (temp=end;temp!=NULL;temp=temp->prev)
    {
        printf("\n\t%10u   %10u   %d    %10u",temp->prev,temp,temp->data,temp->link);
    }
    return ;
}
void count(node *end)
{   
    int count=0;
     node *temp;
    for (temp=end;temp!=NULL;temp=temp->prev)
    {
        count++;
    }
    printf("\n\tthe total number of elements in the DLL are %d\n",count);
    return ;
}

int main()
{
    
    int choice;
    node* head= ( node*)malloc(sizeof( node));
     node* end= ( node*)malloc(sizeof( node));
    end=head=NULL;
     while (1)
     {
      printf("\n\t\t-----------main menu-------\n");
     printf("\t 1) create a doubly linkedlist\n");
     printf("\t 2) display \n");
     printf("\t 3) total number of nodes in Doubly Linked List \n ");
     printf("\t 4) exit\n");

     printf("\tenter the choice  ");

     scanf("%d",&choice);

        switch(choice)
      {
        case 1:
           create(&end,&head);
           break;
        case 2:
           display(head,end);
           break;
        case 3:
           count(end);
           break;
        case 4:
          exit(0);
      }
     }
    }