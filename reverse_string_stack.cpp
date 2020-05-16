#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
struct stack{
	char info[max];
	int top;
};
typedef struct stack STK;
void push(STK *,char);
char pop(STK*);

int main(){
	STK stk;
	stk.top=-1;
	char string[max],rev_string[max];
	int i;
	printf("\nREVERSE STRING USING STACK\n");
	printf("\nEnter the string to reverse: ");
	gets(string);
	while(string[i]!='\0'){
		push(&stk,string[i]);
		i++;
	}
	i=0;
	while(stk.top!=-1){
		rev_string[i]=pop(&stk);
		i++;
	}
	rev_string[i]='\0';
	printf("\nThe Reversed String is: ");
	puts(rev_string);
}

void push(STK *p,char item){
	if(p->top==max-1){
		printf("\nStack Overflow");
		return;
	}	
	p->info[++p->top]=item;
}

char pop(STK *p){
	if(p->top==-1){
		printf("\nStack Underflow");
		return '\0';
	}
	return p->info[p->top--];
}
