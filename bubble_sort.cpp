#include <stdio.h>
void bubble_sort(int *a,int n);

int main() {
    int a[50],i,n;
    printf("\nHow many elements in Array:");
    scanf("%d",&n);
    printf("\nEnter elements:\n");
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     bubble_sort(a,n);
     printf("\nAfter Bubble Sort:\n");
     for(i=0;i<n;i++)
     printf("%d ",a[i]);
	return 0;
}
void bubble_sort(int *a,int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
