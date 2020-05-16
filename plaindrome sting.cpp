#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ispalin(char[]);
int main(){
	char arr[100];
	printf("\nEnter the string:");
	gets(arr);
	if(ispalin(arr))
	 printf("\nSting is Palindrome");
	else
	 printf("\nString is not Palindrome");	 
}
int ispalin(char a[]){
	int i=0,j=0;
	while(a[j]!='\0')
		j++;
	j--;
	while(i<j){
		if(a[i]!=a[j])
		 return 0;
		i++;
		j--;
	}
	return(1);
}
