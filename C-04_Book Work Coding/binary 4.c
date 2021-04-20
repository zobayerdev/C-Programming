#include<stdio.h>
int main()
{
int a[10],n,i;
printf("enter decimal no.: ");
scanf("%d",&n);
for (i=0;n>0;i++)
{
a[i]=n%2;
n=n/2;
}
printf("Binary value: ");
for (i=i-1;i>=0;i--)
{
cout<<a[i];
}
getch();

}
