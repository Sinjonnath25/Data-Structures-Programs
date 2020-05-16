#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
void merge_sort(int a[],int ,int);
void merge(int a[],int,int,int);
int main(){
	int arr[max],i,n;
	printf("\nEnter how many elements in array:");
	scanf("%d",&n);
	printf("\Enter the Array elements to Sort:\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	merge_sort(arr,0,n-1);
	printf("\nAfter Merge sort the array is:\n");
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
	getch();
}
void merge_sort(int arr[],int beg,int end){
	int mid;
	if(beg<end){
	mid=(beg+end)/2;
	merge_sort(arr,beg,mid);
	merge_sort(arr,mid+1,end);
	merge(arr,beg,mid,end);
}
}
void merge(int arr[],int beg,int mid,int end){
	int temp[max],index=beg,i=beg,j=mid+1,k;
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]){
		temp[index]=arr[i];
		i++;}
		else if(arr[i]>arr[j]){
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	if(i>mid) {
	while(j<=end){
		temp[index]=arr[j];
		j++;
		index++;
	}
}
else while(i<=mid){
	temp[index]=arr[i];
	i++;
	index++;
}
for(k=beg;k<index;k++)
arr[k]=temp[k];
}
