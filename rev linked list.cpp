#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
struct node{
	int info;
	struct node*next;
};
typedef struct node ND;
int main(){
	ND *start,*temp;
	start=NULL;
	do{
		temp=(ND*)malloc(sizeof(ND));
		printf("\nEnter an integer Value:");
		scanf("%d",&temp->info);
		temp->next=start;
		start=temp;
		fflush(stdin);
		printf("\nWant to continue?(y/n)");
	}while(toupper(getchar())!='N');
	
	printf("\n Elements of Linked list:");
	while(start!=NULL){
		printf(" %d",start->info);
		start=start->next;
	}
}
