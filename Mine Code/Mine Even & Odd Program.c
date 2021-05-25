#include<stdio.h>
int main()
{
    int n;
    while(n!=1)
    {
    int val;
    printf("\n");
    printf("\t\tEnter any Number : ");
    scanf("%d",&val);

    if((val/2)* 2== val)
    {
     printf("\t\tResult: Even\n");
    }

    else{
        printf("\t\tResult : ODD");
    }

    return 0;
    }
}
