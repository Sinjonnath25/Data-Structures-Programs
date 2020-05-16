#include <stdio.h>
#include <stdlib.h>
void dir_graph();
void undir_graph();
void create_graph(int **,int);
void DFS(int **,int *,int,int);
int visited[10]={0};   //Global Variable
int main()
{
   int ch;
   do{printf("\nEnter 1 for directed graph\nEnter 2 for undirected graph\nEnter 0 to Exit\nEnter your choice : ");
   scanf("%d",&ch);
   switch(ch)
   {
       case 1:dir_graph();
              break;
       case 2:undir_graph();
              break;
       case 0:printf("You have exited from the program.........");
              break;
       default:printf("Invalid Input %d ",ch);
   }
   }while(ch);
}
void dir_graph()
{   int **a,n,id,od,i,j,*v;
    printf("\nEnter the no of nodes in that graph : ");
    scanf("%d",&n);
    a=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
        a[i]=(int *)malloc(n*sizeof(int));
        v=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        v[i]=0;
    create_graph(a,n);
    printf("\nNode no     \tIn degree\tOut degree\tTotal degree\n");
    for(i=0;i<n;i++)
    {
      id=od=0;
      for(j=0;j<n;j++)
        if(a[j][i]==1)
        id++;
       for(j=0;j<n;j++)
        if(a[i][j]==1)
        od++;
        printf("  %d\t         %d\t       %d\t        %d\n",i+1,id,od,id+od);
    }
    DFS(a,v,0,n);
}
void undir_graph()
{   int **a,n,i,j,d,*v;
    printf("\nEnter the no of nodes in that graph : ");
    scanf("%d",&n);
    a=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
        a[i]=(int *)malloc(n*sizeof(int));
    v=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        v[i]=0;
    create_graph(a,n);
    printf("\nNode no\t        Degree\n");
    for(i=0;i<n;i++)
    {


        for(j=0;j<n;j++)
    {
      d=0;
        if(a[i][j]==1)
        d++;}
        printf("%d\t           %d\n",i+1,d);
    }
    DFS(a,v,0,n);
}
void create_graph(int **a,int n)
{   int i,j;
    char r;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(i==j)
           {
               a[i][j]=0;
               continue;}
        else
        {    fflush(stdin);
            printf("\nAre node %d and node %d adjacent ? (Y/N) : ",i+1,j+1);
            r=getchar();
            if(r=='Y' || r=='y')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    printf("The Generated Adjacency matrix : \n");
    for(i=0;i<n;i++)
        {for(j=0;j<n;j++)
        printf("%d  ",a[i][j]);
        printf("\n");}
}
void DFS(int **a,int *visited,int start,int n)
{
  int *stack;
  stack=(int *)malloc(n*sizeof(int));
  int top=-1,i;
  printf("%c",start+65);
  visited[start]=1;
  stack[++top]=start;
  while(top!=-1)
  {
      start=stack[top];
      for(i=0;i<n;i++)
      {
          if(a[start][i]==1 && visited[i]==0)
          {
              stack[++top]=i;
              printf("%c  ",i+65);
              visited[i]=1;
              break;
          }

      }
      if(i==n)
        top--;
  }
}
