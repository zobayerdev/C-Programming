#include<stdio.h>
int main()
{
    int i,flag = 0,sum=0;
    do
    {
        scanf("%d",&i);
        if(i<0)
        {
            i=-1;
            printf("i==%d\n",i);
            ++flag;
            printf("f=%d\n",flag);
        }
        printf("i=%d\n",i);
        sum=sum+i;
        printf("s=%d\n",sum);
    }
    while(i!=0);
    printf("sum = %d and flag = %d",sum,flag);
    return 0;
}
