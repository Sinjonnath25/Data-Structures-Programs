#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *next;
	struct node *prev;
	int data;
};
struct node *head=NULL;
typedef struct node nd;
void insert();
void display();
void del_begin();
void del_end();
void del_loc();
 
 int main(){
 	int ch;
 	printf("\nDoubly Linked List operations");
 	printf("\n1.Insert \n2.Display \n3.Delete at begin \n4.Delete at end\n5.Delete at location\n0.Exit");
 	while(1){
 	printf("\nEnter your choice:");
 	scanf("%d",ch);
 	switch(ch){
 		case 1:insert(); break;
 		case 2:display(); break;
 		case 3:del_begin(); break;
 		case 4:del_end(); break;
 		case 5:del_loc(); break;
 		case 0:exit(0);break;
 		default:printf("\nEntered Invalid Choice");
	 }
 }
 }
 void insert(){
 	struct node *ptr,*temp;  
   int item;  
   ptr = (nd*) malloc(sizeof(nd));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\nnode inserted\n");  
 }
 void display(){
 	nd *ptr;
 	ptr=head;
 	printf("\nPrinting Values:\n");
 	while(ptr!=NULL){
 		printf("%d\t",ptr->data);
 		ptr=ptr->next;
	 }
 }
 void del_begin(){
 	nd *ptr;
 	if(head==NULL){
 		printf("\nUnderflow");
 		return;
	 }
	 else if(head->next==NULL){
	 	head=NULL;
	 	free(head);
	 }
	 else{
 	ptr=head;
 	head=head->next;
 	head->next->prev=NULL;
 	free(ptr);
 }
 	printf("\nNode is Deleted");
 }
 void del_end(){
 	nd *ptr;
 	if(head==NULL){
 		printf("\nUnderflow");
 		return;
	 }
	 else if(head->next==NULL){
	 	head=NULL;
	 	free(head);
	 }
	 else{
	 	ptr=head;
	 	while(ptr->next!=NULL)
	 	ptr=ptr->next;
	 	
	 	ptr->prev->next=NULL;
	 	free(ptr);
	 }
	 printf("\nNode deleted");
 }

void del_loc(){
	nd *ptr,*temp;
	int p;
	printf("\nEnter the value after which we have to delete:");
	scanf("%d",p);
	if(head==NULL){
		printf("\nUnderflow");
		return;
	}
	else {
		while(ptr->data!=p)
		ptr=ptr->next;
		
		temp=ptr->next;
		ptr->next=temp->next;
		temp->next->prev=ptr;
		free(temp);
		
	}
	printf("\nNode deleted");
	display();
}













