#include<stdio.h>
int main(){
	int i,num,mul,sum=0;
	printf("\nEnter num:");
	scanf("%d",&num);
	for(i=1;i<=10;i++){
		mul=num*i;
		sum+=mul;
		printf("%d ",mul);
	}
	printf("\nSum=%d",sum);
}
