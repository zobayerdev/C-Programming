#include<stdio.h>
#include<conio.h>
int main()
{

   int num;
    printf("Enter Your Value = ");
    scanf("%d",&num);

    for( int a=1;num!=0;a++)
    {
        a<<num%2;
        num=num/2;
    }
printf("Result : %ld ",num);


    getch();




}
