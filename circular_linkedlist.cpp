#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node ND;

void insert_begining(ND **ptr,int item)
{
    ND *temp;
    temp=(ND *)malloc(sizeof(ND));
    if(!temp)
    {
        printf("Insufficient Memory........");
        return;
    }
    temp->info=item;
    if(*ptr==NULL)
    {
        temp->next=temp;
        *ptr=temp;
        return;
    }
    temp->next=(*ptr)->next;
    (*ptr)->next=temp;
    printf("%d",temp->info);
}
void insert_end(ND **ptr,int item)
{
    ND *temp;
    temp=(ND *)malloc(sizeof(ND));
    if(!temp)
    {
        printf("Insufficient Memory........");
        return;
    }
    temp->info=item;
    if(*ptr==NULL)
    {
        temp->next=temp;
        *ptr=temp;
        return;
    }
    temp->next=(*ptr)->next;
    (*ptr)->next=temp;
    *ptr=temp;
}
void insert_before(ND *ptr,int item)
{  int flg;
   if(ptr==NULL)
   {
       printf("Empty Linked List......");
       return;
   }
   ND *current=ptr;

   do{if(current->next->info==item)
    {
        flg=1;
        break;
    }
       current=current->next;
   }while(current!=ptr);
   if(flg==0)
   {
       printf("You entered a wrong value.....");
       return;
   }
   ND *temp;
   temp=(ND *)malloc(sizeof(ND));
   printf("\nEnter a value you want to Enter : ");
   scanf("%d",&temp->info);
   temp->next=current->next;
   current->next=temp;
}
void insert_after(ND **ptr,int item)
{  int flg;
   if(*ptr==NULL)
   {
       printf("Empty Linked List......");
       return;
   }
   ND *current=*ptr;

   do{if(current->info==item)
    {
        flg=1;
        break;
    }
       current=current->next;
   }while(current!=*ptr);
   if(flg==0)
   {
       printf("You entered a wrong value.....");
       return;
   }
   ND *temp;
   temp=(ND *)malloc(sizeof(ND));
   printf("\nEnter a value you want to Enter : ");
   scanf("%d",&temp->info);
   temp->next=current->next;
   current->next=temp;
   if(current==*ptr)
    *ptr=temp;
}
void del_ete_begin(ND **ptr)
{
    ND *f=(*ptr)->next;
    if(f==*ptr)
    {
        *ptr=NULL;
        free(f);
        return;
    }
    (*ptr)->next=f->next;
    printf("\nDeleted Element is %d",f->info);
    free(f);
}
void del_ete_end(ND **ptr)
{
    ND *f=(*ptr)->next,*preptr,*p=*ptr;
    if(f==*ptr)
    {
        *ptr=NULL;
        free(f);
        return;
    }
    do{
        preptr=p;
        p=p->next;
    }while(p!=*ptr);
    preptr->next=p->next;
    *ptr=preptr;
    printf("\nDeleted Element is %d",p->info);
    free(p);
}
void display(ND *p)
{
    ND *current;
    if(!p)
        return;
    current=p->next;
    do{
        printf("%d ",current->info);
        current=current->next;
    }while(current!=p->next);
}
void del_ete_before(ND *ptr,int x)
{
    ND *preptr_1,*preptr_2,*p;
    preptr_1=preptr_2=p=ptr->next;

   do{
       if(p->info==x)
        break;
       preptr_2=preptr_1;
       preptr_1=p;
       p=p->next;
   }while(p!=ptr->next);
   if(p==ptr->next)
   {
       printf("\nInvalid input........");
       return;
   }
   preptr_2->next=p;
   printf("\nDeleted Element is %d",preptr_1->info);

   if(preptr_1==ptr->next)
    ptr->next=p;
  free(preptr_1);
}
void del_ete_after(ND **ptr,int x)
{
     ND *preptr,*p;
    preptr=p=(*ptr)->next;
  printf("Hello");
   do{
       if(preptr->info==x)
        break;
       preptr=p;
       p=p->next;
   }while(p!=(*ptr)->next);
     if(p==(*ptr)->next)
   {
       printf("\nInvalid input........");
       return;
   }
   preptr->next=p->next;
   printf("\nDeleted Element is %d",p->info);
   if(p==*ptr)
    *ptr=preptr;
   free(p);

}

int main()
{   ND *tail;
     tail=NULL;
    int ch,val;
    do{printf("\nEnter 1 to insert at begining \nEnter 2 to insert at end\ninsert 3 to insert after\nEnter 4 to insert before\ninsert 5 to delete at begin\nEnter 6 to delete at end\nEnter 7 to display\nEnter your choice :");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter an element to insert :");;
               scanf("%d",&val);
               insert_begining(&tail,val);
               break;
        case 2:printf("\nEnter an element to insert :");;
               scanf("%d",&val);
               insert_end(&tail,val);
               break;
        case 3:printf("\nEnter a value after which you want to insert");
                scanf("%d",&val);
                insert_after(&tail,val);
                break;
        case 4:printf("\nEnter a value before which you want to insert");
                scanf("%d",&val);
                insert_before(tail,val);
                break;
        case 5:del_ete_begin(&tail);
               break;
        case 6:del_ete_end(&tail);
            break;
        case 8:printf("\nEnter the value before which you want to delete :");
             scanf("%d",&val);
            del_ete_before(tail,val);
            break;
        case 9:printf("\nEnter the value after which you want to delete :");
             scanf("%d",&val);
            del_ete_after(&tail,val);
            break;
        case 7:display(tail);
    }
    }while(ch);
}
