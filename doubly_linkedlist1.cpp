#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
typedef struct node nd;
nd* insert_end(nd *,int);
void display(nd*);
nd *del_end(nd*);
nd *del_beg(nd*);
nd *del_after(nd*,int);
nd* insert_before(nd*,int);
nd* del_before(nd*,int);
nd *insert_beg(nd *);
nd* insert_after(nd *,int);
nd* insert_after(nd* start,int item)
{
nd *new_node,*ptr,*aftptr;
new_node=(nd*)malloc(sizeof(nd));
printf("\nEnter the value to insert:");
scanf("%d",&new_node->data);
ptr=start;
while(ptr->data!=item)
	ptr=ptr->next;
aftptr=ptr->next;
ptr->next=new_node;
new_node->next=aftptr;
aftptr->prev=new_node;
new_node->prev=ptr;
return start;
}
nd* del_after(nd* start,int item)
{
nd *ptr,*aftptr,*p;
ptr=start;
while(ptr->data!=item)
	ptr=ptr->next;
aftptr=ptr->next;
if(aftptr->next==NULL)
{
	ptr->next=NULL;
	aftptr->prev=NULL;
}
else
{
p=aftptr->next;
ptr->next=p;
p->prev=ptr;
aftptr->next=aftptr->prev=NULL;
}
free(aftptr);
return start;
}
nd *del_beg(nd*start)
{
nd *ptr;
if(start->next==NULL)
	{
	free(start);
	start=NULL;
	}
else{
	ptr=start;
	start=start->next;
	start->prev=NULL;
	ptr->next=NULL;
	free(ptr);
}
return start;
}
nd* del_before(nd* start,int item)
{
nd *ptr,*preptr,*p;
ptr=start;
while(ptr->data!=item)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
p=start;
while(p->next!=preptr)
	p=p->next;
p->next=ptr;
ptr->prev=p;
preptr->prev=preptr->next=NULL;
free(preptr);
return start;
}
nd* insert_beg(nd *start)
{
	nd* new_node;
	new_node=(nd*)malloc(sizeof(nd));
	printf("\nEnter Value:");
	scanf("%d",&new_node->data);
	new_node->next=start;
	new_node->prev=NULL;
	start->prev=new_node;
	start=new_node;
	return start;
}
nd* insert_before(nd* start,int item)
{
int x;
nd* ptr,*preptr;
ptr=start;
while(ptr->data!=item)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
nd* new_node;
new_node=(nd*)malloc(sizeof(nd));
printf("\nEnter the node value to insert:");
scanf("%d",&x);
if(start==ptr)
{
start=new_node;
new_node->data=x;
new_node->next=ptr;
new_node->prev=NULL;
ptr->prev=new_node;
start=new_node;
}
else{
new_node->data=x;
new_node->next=ptr;
ptr->prev=new_node;
preptr->next=new_node;
new_node->prev=preptr;
return start;
	}
}
nd *del_end(nd *start)
{
nd *ptr,*preptr,*check;
if(start->next==NULL)
	{
	free(start);
	start=NULL;
	}
else{
ptr=start;
while(ptr->next!=NULL)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
preptr->next=NULL;
ptr->prev=NULL;
free(ptr);
}
return start;
}
nd* insert_end(nd *start,int item)
{
nd *ptr;
ptr=start;
nd* new_node;
new_node=(nd*)malloc(sizeof(nd));
if(start==NULL)
	{
	new_node->prev=NULL;
	new_node->data=item;
	new_node->next=NULL;
	start=new_node;
	}
else{
	while(ptr->next!=NULL)
		ptr=ptr->next;
	new_node->data=item;
	new_node->next=NULL;
	ptr->next=new_node;
	new_node->prev=ptr;
	}
return start;
}
void display(nd *start)
{
nd *ptr;
ptr=start;
printf("\n");
printf("\nLinked List:");
while(ptr !=NULL)
   {    printf("\t%d",ptr->data);
       ptr=ptr->next;
   }
}
nd *start=NULL;
int main()
{
        int i,ch,item;
        nd *ptr;
        nd *preptr,*aftptr;
        do{
	printf("\nDoubly Linked List\n");
        printf("\n1.To Display Linked list");
        printf("\n2.Insert at End.");
        printf("\n3.Insert at beginning");
	printf("\n4.Insert after a node");
	printf("\n5.Insert before a node");
	printf("\n6.Delete from end");
	printf("\n7.Delete from beginning");
	printf("\n8.Delete after a node");
	//printf("\n9.Delete before a node");
        printf("\n0.To Exit.");
        printf("\n\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
                {
                case 2: printf("\nEnter Value :");
			scanf("%d",&item);
			start=insert_end(start,item);
                        break;
                case 1: display(start);
                        break;
                case 6: if(start==NULL)
                                printf("\nLinked List already empty.");
                        else
                        	start=del_end(start);
                        break;
		case 5: printf("\nEnter the node value before which to insert:");
			scanf("%d",&item);
			start=insert_before(start,item);
			break;
		case 9: printf("\nEnter the node value before which to delete:");
                        scanf("%d",&item);
                        start=del_before(start,item);
                        break;
		case 3: start=insert_beg(start);
			break;
		case 7: start=del_beg(start);
			break;
		case 8: printf("\nEnter the node value after which to delete:");
			scanf("%d",&item);
			start=del_after(start,item);
			break;
		case 4: printf("\nEnter the node value after which to insert:");
			scanf("%d",&item);
			start=insert_after(start,item);
			break;
                case 0: printf("\nTHE END\n");
                        break;
                default:printf("\nInvalid choice.");
                }
        }while(ch!=0);
        return 0;
}
