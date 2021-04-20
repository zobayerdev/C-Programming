#include<stdio.h>
int main()
{
    int n,r,sum=0,t;
    scanf("%d",&n);
    t=n;
    while(n>0)
    {
        r=n%10;
        sum=(sum*10)+r;
        n=n/10;
    }
    if(t==sum)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}
