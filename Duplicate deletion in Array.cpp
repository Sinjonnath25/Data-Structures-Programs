#include<stdio.h>
int main(){
	int i, j, d, k, n, a[50], b[50], c=0;

	printf("\nEnter the size of the array\t");
	scanf("%d", &n);

	printf("\nEnter the values one by one:\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(i=0; i<n; i++){
		for(j=0; j<c; j++){
			if(a[i]==b[j])
			break;
		}
		if(j==c){
			b[c]=a[i];
			c++;
		}
	}
	printf("\nAfter duplicate deletion the array becomes as:\n");
	for(i=0; i<c; i++)
		printf("%d\t", b[i]);

}
