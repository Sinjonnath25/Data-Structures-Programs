#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node
{
int info;
struct node *left,*right;
};
typedef struct node ND;
struct stack
{
 ND *info[MAX];
int top;
};
typedef struct stack STK;

void insert(ND **,int);
void preorder(ND *);
void postorder(ND *);
void inorder(ND *);
void push(STK *,ND *);
ND * pop(STK *);
void nonrecursive_preorder(ND *);
void nonrecursive_inorder(ND *);
void nonrecursive_postorder(ND *);
int main()
{
ND *tree;
int i,x;
tree=NULL;
do{
  printf("\n1 :Insert\n2 :PreOrder travarsal\n3 :PostOrder Traveral\n4 :InOrder Travarsal\n5 :Nonrecursive preorder travasal\n6 :Nonrecursive inorder travasal\n7 :Nonrecursive postorder travarsal\n0 :To Exit");
 printf("\n Enter your choice :");
 scanf("%d",&i);
 switch(i)
{
 case 1:printf("\nEnter node value :");
       scanf("%d",&x);
      insert(&tree,x);
       break;
 case 2:printf("PreOrder Travarsal : ");
       preorder(tree);
      break;
 case 3:printf("PostOrder Travarsal : ");
       postorder(tree);
      break;
 case 4:printf("InOrder Travarsal : ");
       inorder(tree);
      break;
 case 5:printf("PreOrder Travarsal : ");
       nonrecursive_preorder(tree);
      break;
case 6:printf("InOrder Travarsal : ");
       nonrecursive_inorder(tree);
      break;
case 7:printf("PostOrder Travarsal : ");
       nonrecursive_postorder(tree);
      break;
 case 0:printf("You have exited from the program..........");
       break;
default:printf("Invalid input...........");
}
}while(i!=0);
}
void insert(ND **ptr,int item)
{
ND *temp,*current;
temp=(ND *)malloc(sizeof(ND));
if(!temp)
{
printf("\nInsufficient memory......");
return;
}
temp->info=item;
temp->left=temp->right=NULL;
if(*ptr==NULL)
{
*ptr=temp;
return;
}
current=*ptr;
while(current->info!=item)
{
if(current->info>item)
    if(current->left!=NULL)
     current=current->left;
   else
    {
    current->left=temp;
    return;
}
else
 if(current->right!=NULL)
 current=current->right;
 else
 {
 current->right=temp;
  return;
}
}
printf("\nDuplication NOt allowed......");
free(temp);
}
void preorder(ND *p)
{
 if(!p)
 return;
printf(" %d",p->info);
preorder(p->left);
preorder(p->right);
}
void inorder(ND *p)
{
 if(!p)
 return;
inorder(p->left);
printf(" %d",p->info);
inorder(p->right);
}
void postorder(ND *p)
{
 if(!p)
 return;

postorder(p->left);
postorder(p->right);
printf(" %d",p->info);

}
void nonrecursive_preorder(ND *p)
{
STK stk;
stk.top=-1;
while(p!=NULL)
{
printf(" %d",p->info);
if(p->right!=NULL)
push(&stk,p->right);
if(p->left!=NULL)
 p=p->left;
else
 p=pop(&stk);
}}
void nonrecursive_inorder(ND *p)
{
STK stk;
stk.top=-1;
while(p!=NULL)
{
push(&stk,p);
if(p->left!=NULL)
{
 p=p->left;
 continue;
}
while((p=pop(&stk))!=NULL)
{
printf(" %d",p->info);
if(p->right!=NULL)
{
p=p->right;
break;
}
}
}
}
void push(STK *p,ND *item)
{
if(p->top == MAX-1)
{
 printf("\nStack Overflow.......");
  return;
}
p->info[++p->top]=item;
}
ND * pop(STK *p)
{
if(p->top==-1)
 return(NULL);
return(p->info[p->top--]);
}
void nonrecursive_postorder(ND *p)
{
ND *t;
STK stk1,stk2;
stk1.top=stk2.top=-1;
push(&stk1,p);
while(stk1.top!=-1)
{
t=pop(&stk1);
push(&stk2,t);
if(t->left!=NULL)
 push(&stk1,t->left);
if(t->right!=NULL)
 push(&stk1,t->right);
}
while((p=pop(&stk2))!=NULL)
printf(" %d",p->info);
}
