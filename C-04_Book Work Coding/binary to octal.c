#include<stdio.h>
#include<conio.h>
int main()
{
    int  a[10], n, i;
    int  clrscr ();
    printf("Enter Your Number = ");
    scanf("%d",&n);
    for(i=0;n>0;i++)
    {
        a[i]=n%2;
        n=n/2;

    }
    printf("Converted Number : ");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",a);
    }

    getch();

}
