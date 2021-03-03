void stationaries()
{
    system("cls");
    int s;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t    ================\n");
    printf("\t\t\t\t\t    | Stationaries |");
    printf("\n\t\t\t\t\t    ================\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t1. Books\n");
    printf("\n\t\t\t\t2. Study Equipment\n");
    printf("\n\t\t\t\t3. Lab Accessories\n");
    printf("\n\t\t\t\t4. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&s);
    switch(s)
    {
    case 1:
        books();
        break;

    case 2:
        study();
        break;

    case 3:
        lab();
        break;

    case 4:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void books()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Books site ");
    printf("\n\t\t\t\t1. Class 8th books all--1400 Taka\n");
    printf("\n\t\t\t\t2. Class 9th books all--1500 Taka\n");
    printf("\n\t\t\t\t3. Class 10th books all--1600 Taka\n");
    printf("\n\t\t\t\t4. Class 11th books all--2000 Taka\n");
    printf("\n\t\t\t\t5. Class 12th books all--2200 Taka\n");
    printf("\n\t\t\t\t5. Versity books all--2300 Taka\n");
}
void study()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Books site ");
    printf("\n\t\t\t\t1. Geomeitry--200 Taka\n");
    printf("\n\t\t\t\t2. Pen--15 Taka\n");
    printf("\n\t\t\t\t3. Paper--160 Taka\n");
    printf("\n\t\t\t\t4. Pencil--20 Taka\n");
    printf("\n\t\t\t\t5. penbox--220 Taka\n");
}
void lab()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Lab Accessorise site ");
    printf("\n\t\t\t\t1. Acid--500 Taka\n");
    printf("\n\t\t\t\t2. Lamp--150 Taka\n");
    printf("\n\t\t\t\t3. Tube Fanel--160 Taka\n");
    printf("\n\t\t\t\t4. Lab Paper--20 Taka\n");
    printf("\n\t\t\t\t5. Aprone--220 Taka\n");
    printf("\n\t\t\t\t6. Gloves --60 Taka\n");
    printf("\n\t\t\t\t7. Glass--220 Taka\n");
}
