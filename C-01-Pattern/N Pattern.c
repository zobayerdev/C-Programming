#include<stdio.h>
int main()
{
	int n,j,i ;
	printf("Enter Any Key:");
	scanf("%d",&n);
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
	  return 0 ;
}
