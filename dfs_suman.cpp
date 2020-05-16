#include<stdio.h>
#define max 100
int stack[max],visit[max],adj[max][max],top=-1;
void push(int);
int pop();
int peep();
void push(int item)
{
                stack[++top]=item;
}
int pop()
{
                return stack[top--];
}
void dfs(int s,int n)
{
int p,i;
push(s);
p=pop();
if(p!=0)
  {
   printf("%d\t",p);
   visit[p]=1;
  }
while(p!=0)
   {
        for(i=1;i<=n;i++)
        {
        if((visit[i]==0)&&(adj[p][i]!=0))
                {push(i);visit[i]=1;}
        }
        p=pop();
        if(p==0)
            continue;
        printf("%d\t",p);
        visit[p]=1;
   }
for(i=1;i<=n;i++)
        visit[i]=1;
}
int main()
{
int i,j,s,n;
top=-1;
printf("\nEnter the size n of adjacency matrix:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:");
for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
                {
                scanf("%d",&adj[i][j]);
                }
printf("\nEnter starting vertex:");
scanf("%d",&s);
for(i=1;i<=n;i++)
        visit[i]=0;
dfs(s,n);
}
