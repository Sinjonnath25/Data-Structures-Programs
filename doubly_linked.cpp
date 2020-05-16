#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *left,*right;
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
  temp->left=NULL;
  temp->right=*ptr;
  if(*ptr!=NULL)
    (*ptr)->left=temp;
    *ptr=temp;
}
void insert_end(ND **ptr,int item)
{
    ND *temp,*p;
    temp=(ND *)malloc(sizeof(ND));
    if(!temp)
    {
        printf("Insufficient Memory........");
        return;
    }
    temp->info=item;
    temp->right=NULL;
    if(*ptr==NULL)
    {
        temp->left=NULL;
        *ptr=temp;
        return;
    }
    p=*ptr;
    while(p->right!=NULL)
        p=p->right;
    p->right=temp;
    temp->left=p;
}
void insert_before(ND **ptr,int item)
{  ND *p=*ptr,*temp;;
    while(p->right!=NULL)
    {
        if(p->info==item)
            break;
        p=p->right;
    }
    temp=(ND *)malloc(sizeof(ND));
    printf("\nEnter a value you want to insert : ");
    scanf("%d",&temp->info);
    temp->right=p;

    p->left->right=temp;
    temp->left=p->left;
    p->left=temp;
}
void insert_after(ND **ptr,int item)
{  ND *p=*ptr,*temp;;
    while(p->right!=NULL)
    {
        if(p->info==item)
            break;
        p=p->right;
    }
    temp=(ND *)malloc(sizeof(ND));
    printf("\nEnter a value you want to insert : ");
    scanf("%d",&temp->info);
    temp->left=p;
    temp->right=p->right;
    if(p->right==NULL)
    {
        p->right=temp;
        return;
    }
    p->right->left=temp;
    p->right=temp;
}
void del_ete_begin(ND **ptr)
{
  ND *p=*ptr;
  *ptr=(*ptr)->right;
  printf("\nDeleted Element is %d",p->info);
  free(p);
}
void del_ete_end(ND **ptr)
{
    ND *p=*ptr;
    while(p->right!=NULL)
        p=p->right;
    p->left->right=NULL;
   printf("\nDeleted Element is %d",p->info);
  free(p);
}
void display(ND *p)
{
   while(p!=NULL)
   {
       printf("%d  ",p->info);
       p=p->right;
   }
}
void del_ete_before(ND **ptr,int x)
{  ND *p=*ptr;
  while(p->right!=NULL)
    {
        if(p->info==x)
            break;
        p=p->right;
    }
    if(p->left==*ptr)
       {
         *ptr=(*ptr)->right;
         printf("\nDeleted Element is %d",p->left->info);
         free(p->left);
         return;}
    p->left->left->right=p->right;
    p->right->left=p->left->right;
    printf("\nDeleted Element is %d",p->left->info);
         free(p->left);
}
/*void del_ete_after(ND **ptr,int x)
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
*/

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
                insert_before(&tail,val);
                break;
        case 5:del_ete_begin(&tail);
               break;
        case 6:del_ete_end(&tail);
            break;
        case 8:printf("\nEnter the value before which you want to delete :");
             scanf("%d",&val);
            del_ete_before(&tail,val);
            break;
       /* case 9:printf("\nEnter the value after which you want to delete :");
             scanf("%d",&val);
            del_ete_after(&tail,val);
            break;*/
        case 7:display(tail);
    }
    }while(ch);
}

