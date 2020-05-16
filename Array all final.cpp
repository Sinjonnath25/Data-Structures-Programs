#include<stdio.h>
#include<stdlib.h>
int a[100];
int m,n,i,j,k,pos,val;
void creat();
void display();
void insert();
void del();
void dupli();
void search();
void max();
void max2();
void min2();
int main()
{int ch;
printf("\n Menu:\n");
printf("\n 1.create");
printf("\n 2.display");
printf("\n 3.insertion");
printf("\n 4.Deletion");
printf("\n 5.duplicate deletion");
printf("\n 6.search:");
printf("\n 7.Max & Min Element");
printf("\n 8.2nd max");
printf("\n 9.2nd minimum");
printf("\n 10.exit");
while(1){
printf("\n\n Enter your choice:");
scanf("%d",&ch);
switch(ch){
	case 1:creat();
		break;
	case 2:display();
                break;
	case 3:insert();
                break;
	case 4:del();
                break;
	case 5:dupli();
                break;
	case 6:search();
                break;
	case 7:max();
                break;
	case 8:max2();
                break;
    case 9:min2();
    			break;
	case 10:exit(0);
                break;
	default:printf("\nEntered Invalid Choice");
                break;
	}
}while(ch!=9);
return 0;
}


void creat(){
printf("\n Enter how many elements in the array:");
scanf("%d",&n);
printf("\n Enter the elements:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
}

void display(){
printf("\n The elements are:");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}

void insert()
{printf("Enter the position and element to insert:");
scanf("%d%d",&pos,&val);
for(i=n-1;i>=pos;i--)
 a[i+1]=a[i];
a[pos]=val;
n=n+1;
}

void del(){
printf("\nEnter the position to delete:");
scanf("%d",&pos);
val=a[pos];
for(i=pos;i<n-1;i++)
a[i]=a[i+1];
n--;
printf("\nThe Deleted element is %d:",val);
display();
}

void dupli(){
for(i=0;i<n;i++){
 for(j=i+1;j<n;){
  if(a[j]==a[i]){
 for(k=j;k<n;k++)
  {a[k]=a[k+1];
 }
n--;}
else 
j++;
}}
printf("\nAfter deletion:");
display();

}
void search(){
printf("\n Enter the element to search");
scanf("%d",&val);
for(i=0;i<n;i++)
{if(a[i]==val){
printf("\n The element is present in %d position",i);
break;}}
if(i==n)
printf("\n Element not found");

}

void max()
{int max=a[0];
int min=a[0];
for(i=1;i<n;i++)
 {if(a[i]>max)
 max=a[i];
 if(a[i]<min)
 min=a[i];
}
printf("\n Max element is %d",max);
printf("\n Min element is %d",min);
}

void max2()
{ 
int large,large2;
large=a[0];
for(i=0;i<n;i++)
{
	if(a[i]>large)
	large=a[i];
}
large2=a[1];
for(i=0;i<n;i++)
{
	if(a[i]!=large)
	{
		if(a[i]>large2)
	large2=a[i];
	}
}
printf("\n the 2nd largest element is: %d",large2);
}

void min2()
{
	int small,small2;
	small=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<small)
		small=a[i];
	}
	small2=a[1];
	for(i=2;i<n;i++)
	{
		if(a[i]!=small)
		{
			if(a[i]<small2)
		small2=a[i];
		}
	}
	printf("\n the 2nd smallest element is: %d",small2);
}
