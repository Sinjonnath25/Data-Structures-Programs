#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int info;
	struct node *next;
};
struct node *start;
typedef struct node nd;
void create();
void display();
void insert_pos();
void delete_pos();
int main(){
		int choice;
        while(1){
                printf("\n***SINGLE LINKED LIST OPERATIONS:****\n");
                printf("\n                MENU                             \n");
                printf("---------------------------------------\n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Insert at the beginning    \n");
                printf("\n 4.Insert at the end  \n");
                printf("\n 5.Insert at specified position       \n");
                printf("\n 6.Delete from beginning      \n");
                printf("\n 7.Delete from the end        \n");
                printf("\n 8.Delete from specified position     \n");
                printf("\n 9.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        /*case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        */case 5:
                                        insert_pos();
                                        break;/*
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        */case 8:
                                        delete_pos();
                                        break;
                        /*case 9:
                                        exit(0);
                                        break;
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;*/
                }//end of switch()
        }
        return 0;
}//end of main()

void create(){
	nd *temp,*ptr;
	temp=(nd*)malloc(sizeof(nd));
	printf("\nEnter node data:");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(start==NULL){
		start=temp;
		return;
	}
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
	
}
void display(){
	nd *ptr;
	ptr=start;
	if(start==NULL){
		printf("\nits empty!");
	}
	printf("\nElements are:\n");
	while(ptr!=NULL){
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
	
}

void insert_pos(){
	int pos,i,x;
	nd *temp,*ptr;
	temp=(nd*)malloc(sizeof(nd));
	ptr=start;
	printf("\nEnter the pos to add:");
	scanf("%d",&pos);
	printf("\nEnter the node value to add:");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(pos==0){
		temp->next=start;
		start=temp;
	}
	else{
		for(i=0;i<pos-1;i++){
			ptr=ptr->next;
			if(ptr==NULL)
			printf("\nItem not found");
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
display();	
}

void delete_pos(){
	int pos,i;
	printf("\nEnter pos to delete:");
	scanf("%d",&pos);
	nd *temp,*next;
	temp=start;
	if(start==NULL){
		printf("\nlist is empty");
		return;
	}
	if(pos==0){
		start=start->next;
		free(temp);
		return;
	}
	for(i=0;temp!=NULL && i<pos-1;i++)
		temp=temp->next;
		next=temp->next->next;
		free(temp->next);
		temp->next=next;
	display();
}
