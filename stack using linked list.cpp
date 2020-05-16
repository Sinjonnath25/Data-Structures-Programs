#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
typedef struct node ND;
struct stack{
	ND *top;
};
typedef struct stack STK;
void push(STK*,int);
void pop(STK*);
 
int main(){
 	STK stk;
 	int i,x;
 	stk.top=NULL;
 	do{
 		printf("\nEnter 1 to push");
 		printf("\nEnter 2 to pop");
 		printf("\nEnter 0 to exit");
 		printf("\n\nEnter your choice :");
 		scanf("%d",&i);
 		
 		switch(i){
 			case 1:printf("Enter the element to push :");
 					scanf("%d",&x);
 					push(&stk,x);
 					break;
 			case 2: pop(&stk);
 					break;
 			case 0: printf("\nThe End");
 					break;
 			default:printf("\nInvalid Choice");
 			
		 }
	 }while(i!=0);
 }
 
 void push(STK *p,int item){
 	ND *temp;
 	temp=(ND*)malloc(sizeof(ND));
 	if(!temp){
 		printf("\nStack Overflow");
 		return;
	 }
	 temp->info=item;
	 temp->next=p->top;
	 p->top=temp;
 }
 void pop(STK *p){
 	ND *temp;
 	if(p->top==NULL){
 		printf("\nStack Underflow");
 		return;
	 }
	 temp=p->top;
	 p->top=temp->next;
	 printf("\nPopped element is %d",temp->info);
	 free(temp);
	 
}
