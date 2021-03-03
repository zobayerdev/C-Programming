#include<conio.h>
#include<stdio.h>
int main()
{

    int n = 5;
    int i, j, size;
    int k = 1, l = 1, m = n - 1;
    for (i = 0; i< n; i++)
        printf("* ", k++);

    printf("\n");


    for (i= 1; i < n- 1; i++)
        {


        for (j= 0; j < 2 * (n - i - 1);
            j ++)
            printf(" ");


        printf("* ", m--);

        printf("\n");
    }

for (i = 0; i< n; i++)
        printf("* ", l++);

// print N Pattern

    printf("\n\n");
	for( i=1;i<=n;i++)
	  {
	  	for( j=1;j<=n;j++)
		{
			if(j==1 || i==j || j==n)

				   printf("*");

              else
                   printf(" ");

		}
		printf("\n");
	  }
getch ();
}


