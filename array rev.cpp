#include<stdio.h>
#include<stdlib.h>
#define max 100
int main(){
	int n,i,a[max],b[max],ori,rev;
	printf("\nEnter number of array elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	ori=0;
	rev=n-1;
	while(rev>=0){
		b[ori]=a[rev];
		ori++;
		rev--;
	}
	printf("\nOriginal Array:\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\nReversed Array:\n");
	for(i=0;i<n;i++)
	printf("%d\t",b[i]);
}
