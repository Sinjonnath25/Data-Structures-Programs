#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void insertion_sort(int *,int);
int main(){
	int a[100],n,i;
	printf("\nEnter number of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	insertion_sort(a,n);
	printf("\nAfter sorting elements are\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}
void insertion_sort(int *arr,int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(temp<arr[j] && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
