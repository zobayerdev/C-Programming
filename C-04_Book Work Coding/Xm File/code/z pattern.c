void alphabet_Z_Pattern(int n)
{
    int i, j, size;

    // Declaring the values of Right,
    // Left and Diagonal values
    int k = 1, l = 1, m = n - 1;

    // Loop for printing the first row
    for (i = 0; i< n; i++)
        printf("* ", k++);

    printf("\n");

    // Main Loop for the rows from (2 to n-1)
    for (i= 1; i < n- 1; i++)
        {

        // Spaces for the diagonals
        for (j= 0; j < 2 * (n - i - 1);
            j ++)
            printf(" ");

        // Printing the diagonal values
        printf("*", m--);

        printf("\n");
    }

    // Loop for printing the last row
    for (i = 0; i< n; i++)
        printf("* ", l++);
}

// Driver Cod
int main()
{
    // Size of the Pattern
    int N = 5;

    alphabet_Z_Pattern(N);

    return 0;
}
