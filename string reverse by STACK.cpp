//String reversal
#include<stdio.h>
#include<string.h>
#define MAX 100
struct stack
{
    char info[MAX];
    int top;
};
typedef struct stack STK;
void push(STK *,char);
char pop(STK *);
int main(void)
{
    STK stk;
    int i=0;
    char string[MAX],rev_str[MAX];
    stk.top=-1;
    printf("\nEnter a string to reverse : ");
    gets(string);
    while(string[i]!='\0')
    {
        push(&stk,string[i]);
        i++;
    }
    i=0;
    while(stk.top!=-1)
     {
         rev_str[i++]=pop(&stk);
     }
     rev_str[i]='\0';
     printf("\nThe reversed string is : ");
     puts(rev_str);
    return 0;
}
void push(STK *p,char item)
{
    if(p->top==MAX-1)
    {
        printf("\nStack Overflow");
        return;
    }
    p->info[++p->top]=item;
}
char pop(STK *p)
{
    if(p->top==-1)
    {
        printf("Stack Underflow");
        return '\0';
    }
    return p->info[p->top--];
}

