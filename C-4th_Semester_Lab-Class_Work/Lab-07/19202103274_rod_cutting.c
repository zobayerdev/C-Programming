#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

bottom_up_cut_rod(int p[], int n)
{

    int i, j, q;
    int r[100];
    r[0] = 0;


    for(j = 1; j<=n; j++)
    {
        q = -1000;
    }

    for(i=1; i<=j; i++)
    {
        q = MAX(q, p[i] + r[j-i]);
    }

    r[j] = q;
}


int main()
{
    int p[] = {1, 15, 25, 35, 45, 50};
    int rod_length = 5;
    printf("Maximum Profit: %d\n", bottom_up_cut_rod(p, rod_length));
    return 0;
}
