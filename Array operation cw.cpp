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
void fax22();
int main()
{int ch;
 do{ printf("\n Menu:\n");
printf("\n 1.create");
printf("\n 2.display");
printf("\n 3.insertion");
printf("\n 4.Deletion");
printf("\n 5.duplicate deletion");
printf("\n 6.search:");
printf("\n 7.Max & Min Element");
printf("\n 8.2nd max ,2nd min");
printf("\n 9.exit");
printf("\n Enter your choice:");
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
	case 8:fax22();
                break;
	case 9:exit(0);
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
printf("\n Enter the elements:");
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


void fax22(){
	int i,j,temp,b[100];
	for(i=0;i<n;i++)
	b[i]=a[i];
	for(i=0;i<n;i++)
	for(j=0;j<n-i-1;j++){
		if(b[j]>b[j+1]){
			temp=b[j];
			b[j]=b[j+1];
			b[j+1]=temp;
		}
	}
printf("\n 2nd Max element is %d",b[n-2]);
printf("\n 2nd Min element is %d",b[1]);
	
}
