#include<stdio.h>
#include<conio.h>

int main(){
int m[50],n,i;
printf("Enter Your Decimal Number = ");
scanf("%d",&n);

    for (i=0;n>0;i++)
  {
    m[i]=n%2;
   n=n/2;
 }
    printf("Binary value= ");
    for (i=i-1;i>=0;i--)
 {
     printf("%d" ,m[i]);
 }
       getch();

 }
