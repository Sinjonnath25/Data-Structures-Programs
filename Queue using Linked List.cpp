#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

void insert(int);
void del();
void display();
int peek();

int main()
{
   int choice, value,p;
   //clrscr();
   printf("\n:: Queue Implementation using Linked List ::\n");
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Peek \n5. Exit\n");
      while(1){
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 insert(value);
		 break;
	 case 2: del(); break;
	 case 3: display(); break;
	 case 4: p=peek();
	 		printf("\nThe value at Front is %d",p);
			break;
	 case 5: printf("\nExit Successfully");
	 exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
void insert(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear->next = newNode;
      rear = newNode;
   }
   printf("\nInsertion is Success!!!\n");
}
void del()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}
void display()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   /*else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d\n",temp->data);
   }*/
   else {
   	struct Node *temp=front;
   	while(temp!=NULL){
   		printf("%d\t",temp->data);
   		temp=temp->next;
	   }
   }
}
int peek(){
	if(front == NULL){
      printf("\nQueue is Empty!!!\n");
      return -1;
  }
   else{
   	return front->data;
   }
	
}
