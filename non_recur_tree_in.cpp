#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node
{
int info;
struct node *left,*right;
};
typedef struct node nd;
struct stack
{
 nd *info[MAX];
int top;
};
typedef struct stack STK;

void insert(nd **,int);
void push(STK*,nd* );
nd *pop(STK*);
void inorder(nd*);
int main()
{
nd*tree;
int i,x;
tree=NULL;
do{
  printf("\n1 :Insert\n2 Nonrecursive inorder travasal\n0 :To Exit");
 printf("\n Enter your choice :");
 scanf("%d",&i);
 switch(i)
{
 case 1:printf("\nEnter node value :");
       scanf("%d",&x);
      insert(&tree,x);
       break;
 case 2:printf("InOrder Travarsal : ");
       inorder(tree);
      break;
 case 0:printf("You have exited from the program..........");
       break;
default:printf("Invalid input...........");
}
}while(i!=0);
}
void insert(nd **ptr,int item){
	nd *temp,*current;
	temp=(nd*)malloc(sizeof(nd));
	temp->info=item;
	temp->left=temp->right=NULL;
	if(*ptr==NULL){
		*ptr=temp;
		return;
	}
	current=*ptr;
	while(current->info!=item){
		if(current->info>item){
			if(current->left!=NULL)
			current=current->left;
			else{
			current->left=temp;
			return;
		}
		}
		else if(current->right!=NULL)
		 current=current->right;
		 else{
		 	current->right=temp;
		 	return;
		 }
		
	}
	printf("\nDuplication is not allowed");
	free(temp);
}

void push(STK *p,nd *item){
	if(p->top==MAX-1){
		printf("\nOverflow");
		return;}
	
	p->info[++p->top]=item;
}
nd *pop(STK *p){
	if(p->top==-1){
		printf("\nUnderflow");
		return(NULL);
	}
	return(p->info[p->top--]);
}

void inorder(nd *p){
	STK stk;
	stk.top=-1;
	while(p!=NULL){
		push(&stk,p);
		if(p->left!=NULL){
			p=p->left;
			continue;
		}
		while((p=pop(&stk))!=NULL){
			printf("%d ",p->info);
			if(p->right!=NULL){
				p=p->right;
				break;
			}
		}
	}
}
