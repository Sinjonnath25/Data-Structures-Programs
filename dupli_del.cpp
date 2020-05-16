#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[100],i,j,k,n;
	printf("\nHow many elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	for(j=i+1;j<n;){
		if(a[j]==a[i]){
			for(k=j;k<n;k++)
			a[k]=a[k+1];
			n--;
		}
		j++;
		
	}
	printf("\nAfter duplicate deletion:\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}
