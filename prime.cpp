#include<stdio.h>
int main(){
	int i,n,flag=1;
	printf("\nEnter the number to be checked : ");
	scanf("%d",&n);
	for(i=2;i<=n/2;i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	if(flag)
	printf("\n%d is a prime number",n);
	else
	printf("\n%d is not a prime number",n);
}
