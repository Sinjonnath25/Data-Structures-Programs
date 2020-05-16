#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
int main(){
	int a[max][max],b[max][max],c[max][max],i,j,m,n,p,q,k;
	printf("\nEnter the number of rows and column of 1st Matrix:");
	scanf("%d%d",&m,&n);
	printf("\nEnter the number of rows and column of 2nd Matrix:");
	scanf("%d%d",&p,&q);
	if(n!=p){
		printf("\nMatrix multiplication is not possible");
		exit(1);
	}
	printf("\nEnter Elements of 1st matrix:\n");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	printf("\nEnter Elements of 2nd matrix:\n");
	for(i=0;i<p;i++)
	for(j=0;j<q;j++)
	scanf("%d",&b[i][j]);
	
	for(i=0;i<m;i++)
	for(j=0;j<q;j++){
		c[i][j]=0;
		for(k=0;k<n;k++)
		c[i][j]=c[i][j]+a[i][k]*b[k][j];
	}
	printf("\nResultant Matrix:\n");
	for(i=0;i<m;i++){
	printf("\n");
	for(j=0;j<q;j++)
	printf("%d\t",c[i][j]);
}
	
}
