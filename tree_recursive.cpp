#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int info;
	struct node *left;
	struct node *right;
};
typedef struct node nd;
void insert(nd**,int);
void inorder(nd*);
void preorder(nd*);
void postorder(nd*);

int main(){
nd *tree;
tree=NULL;
int i,ch,x;
printf("\nRecursive Traversal of Tree");
printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit");
while(1){
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch){
	case 1:printf("\nEnter node data:");
	       scanf("%d",&x);
			insert(&tree,x);
			break;
	case 2: preorder(tree);
	        break;
	case 3: inorder(tree);
	        break;
	case 4: postorder(tree);
	        break;
	case 5: exit(0);
	        break;
	default:printf("\nEntered invalid choice");
	
}
}
}
void insert(nd **ptr,int item){
	nd *temp,*current;
	temp=(nd*)malloc(sizeof(nd));
	temp->info=item;
	temp->left=temp->right=NULL;
	if(!*ptr)
{
*ptr=temp;
return;
}
	current=*ptr;
	/*if(*ptr==0){
		*ptr=temp;
		return;
	}*/
	while(current->info!=item){
		if(current->info>item){
			if(current->left!=NULL)
			current=current->left;
		else{
		current->left=temp;
		return;}
	}
	else if(current->info<item)
	{
		if(current->right!=NULL)
		current=current->right;
		else{
		current->right=temp;
		return;}
	}
}
printf("\nDuplicate not allowed");
free(temp);
}
void inorder(nd *p){
	if(!p)
	return;
	inorder(p->left);
	printf(" %d",p->info);
	inorder(p->right);
}
void preorder(nd *p)
{
 if(!p)
 return;
printf(" %d",p->info);
preorder(p->left);
preorder(p->right);
}
void postorder(nd *p)
{
 if(!p)
 return;

postorder(p->left);
postorder(p->right);
printf(" %d",p->info);

}
