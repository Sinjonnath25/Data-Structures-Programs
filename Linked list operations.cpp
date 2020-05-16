#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
int info;
struct node *next;
};
typedef struct node nd;
nd *start=NULL;
void creat();
void display();
void atbegin();
void atend();
void after();
void length();
void deletefirst();
void deletelast();
void deleteat();
void reverse();

int main(){
int ch;
//while(1){
printf("\n Linked LIst Operations:");
printf("\n 1.To creat");
printf("\n 2.display");
printf("\n 3.Insert at begin");
printf("\n 4.Insert at End\n 5.Insert after");
printf("\n 6.length of the linked list");
printf("\n 7.Delete at start");
printf("\n 8.Delete at last");
printf("\n 9.Delete at a position");
printf("\n11. Reverse");
printf("\n 10.To EXit");
while(1){
printf("\n\n Enter your choice:");
scanf("%d",&ch);

switch(ch){
case 1: creat();
       break;
case 2: display();
       break;
case 3: atbegin();
       break;
case 4: atend();
       break;
case 5: after();
       break;
case 6: length();
       break;
case 7: deletefirst();
		break;
case 8: deletelast();
		break;
case 9: deleteat();
		break;
case 11: reverse();
		break;
case 10: exit(0);
       break;
default: printf("\n Entered invalid choice");
        break;
}
}
}
void creat(){
nd *ptr,*temp;
temp=(nd*)malloc(sizeof(nd));
printf("\n Enter the node data:");
scanf("%d",&temp->info);
temp->next=NULL;
if(start==NULL){
 start=temp;
}
else{
ptr=start;
while(ptr->next!=NULL){
ptr=ptr->next;
}
ptr->next=temp;
}
}
void display(){
nd *ptr;
ptr=start;
printf("\nThe linked list is:\n");
while(ptr!=NULL)
{
printf("%d\t",ptr->info);
ptr=ptr->next;
}
}
void atbegin(){
nd *temp;
temp=(nd*)malloc(sizeof(nd));
printf("\n Enter the node data:");
scanf("%d",&temp->info);
temp->next=NULL;
if(start==NULL){
 start=temp;
}
else{
temp->next=start;
start=temp;
}
}
void atend(){
nd *ptr,*temp;
temp=(nd*)malloc(sizeof(nd));
printf("\n Enter the node data:");
scanf("%d",&temp->info);
temp->next=NULL;
if(start==NULL){
 start=temp;
}
else{
ptr=start;
while(ptr->next!=NULL){
ptr=ptr->next;
}
ptr->next=temp;
}
}

void after(){
int pos,i;
nd *temp,*ptr;
ptr=start;
printf("\nEnter the position to add the node:");
scanf("%d",&pos);
temp=(nd*)malloc(sizeof(nd));
printf("\nEnter the value of the node data:");
scanf("%d",&temp->info);
temp->next==NULL;
if(pos==0){
temp->next=start;
start=temp;
}
else{
for(i=0,ptr=start;i<pos-1;i++){
ptr=ptr->next;
if(ptr==NULL)
{ printf("\nposition not found");
  return;
}
}
temp->next=ptr->next;
ptr->next=temp;
}
}
void length(){
int count=0;
nd *ptr;
ptr=start;
while(ptr!=NULL)
{
ptr=ptr->next;
count++;
}
printf("\nThe length of the linked list is %d",count);
}

void deletefirst(){
	nd *temp;
	temp=start;

		start=temp->next;
		temp->next=NULL;
		free(temp);
		printf("\nFirst node is deleted");
	}
void deletelast(){
	nd *todel,*secdel;
	todel=secdel=start;
	while(todel->next!=NULL)
	{
		secdel=todel;
		todel=todel->next;
	}
	secdel->next=NULL;
	free(todel);
	printf("\nlast node is deleted");
	
}
void deleteat(){
	int i,pos;
    nd *toDelete, *prevNode;
    printf("\nEnter the position to delete:");
    scanf("%d",&pos);

    if(start == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = start;
        prevNode = start;

        for(i=1; i<pos; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == start)
                start = start->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

            /* Delete nth node */
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}
/*void reverse(){
	nd *p,*q,*r;
	if(start==NULL||start->next==NULL){
		printf("\nThere is only one element in LinkedList");
	p=NULL;
	q=start;
	r=q->next;
	while(r!=NULL){
		q->next=p;
		p=q;
		q=r;
		r=r->next;
	}
	q->next=p;
	start=q;
	}
}*/
void reverse()
{
   nd *prevNode, *curNode;

    if(start!= NULL)
    {
        prevNode = start;
        curNode = start->next;
        start=start->next;

        prevNode->next = NULL; // Make first node as last node

        while(start!= NULL)
        {
            start= start->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = start;
        }

        start = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
    }
}







