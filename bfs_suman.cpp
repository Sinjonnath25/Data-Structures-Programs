#include<stdio.h>
#define max 100
int queue[max],visit[max],front,rear;
int adj[max][max];
void insert(int item)
{
        if(front==rear&&rear==-1)
                {
                queue[++rear]=item;
                front++;
                }
        else
           queue[++rear]=item;
}
int del_ete()
{
int x=0;
        if(front==rear)
                {
                x=queue[front];
                front=rear=-1;
                return x;
                }
        else
          return  queue[front++];
}
void bfs(int s,int n)
{
int p,i;
insert(s);
p=del_ete();
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
		{insert(i);
		visit[i]=1;}
	}
	p=del_ete();
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
front=rear=-1;
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
bfs(s,n);
}
