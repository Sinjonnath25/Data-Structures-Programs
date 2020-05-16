#include<stdio.h>
struct Sparse{
int row;
int column;
int value;
};
typedef struct Sparse spr;
int main()
{
        int a[100][100],i,j,k=0,n,c,r,count,limit,b[100][100];
	spr arr[100];
        printf("\nHow many rows & columns?: ");
        scanf("%d %d",&r,&c);
	limit=r*c/2;
        printf("\nEnter the Matrix:\n");
        for(i=0;i<r;i++)
                for(j=0;j<c;j++)
                        scanf("%d",&a[i][j]);
        printf("\nThe Entered matrix is :\n");
        for(i=0;i<r;i++)
        {printf("\n");
        for(j=0;j<c;j++)
        printf("%d\t",a[i][j]);		
		}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
		if(a[i][j]==0)
			count++;
		}
	if(count>limit)
	{
		printf("\nIt is a Sparse Matrix");
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				{
				if(a[i][j]!=0)
					{arr[k].row=i;
					arr[k].column=j;
					arr[k].value=a[i][j];
					k++;
					}
				}
	n=k;
	printf("\nRow Column Value");
	for(i=0;i<n;i++)
		printf("\n%d    %d    %d",arr[i].row,arr[i].column,arr[i].value); 
	}
	else
		printf("\nNot Sparse matrix");
		
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		b[j][i]=a[i][j];
	printf("\nTraspose of Spasr Matrix:\n");
	for(i=0;i<c;i++){
	printf("\n");
		for(j=0;j<r;j++)
		printf("%d\t",b[i][j]);
	}
		
	return 0;
}

