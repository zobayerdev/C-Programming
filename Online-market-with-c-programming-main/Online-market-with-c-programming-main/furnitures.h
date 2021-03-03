void furnitures()
{
    system("cls");
    int f;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t    ==============\n");
    printf("\t\t\t\t\t    | Furnitures |");
    printf("\n\t\t\t\t\t    ==============\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t1. Living Room\n");
    printf("\n\t\t\t\t2. Drawing Room\n");
    printf("\n\t\t\t\t3. Kitchen\n");
    printf("\n\t\t\t\t4. Bathroom\n");
    printf("\n\t\t\t\t5. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&f);
    switch(f)
    {
    case 1:
        living();
        break;

    case 2:
        drawing();
        break;

    case 3:
        kitchen();
        break;

    case 4:
        bathroom();
        break;

    case 5:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void living()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Living-room Accessorise site ");
    printf("\n\t\t\t\t1. Bed--10000 Taka\n");
    printf("\n\t\t\t\t2. Table--5000 Taka\n");
    printf("\n\t\t\t\t3. Sofa--1,50000 Taka\n");
    printf("\n\t\t\t\t4. Devan--2,00000 Taka\n");
    printf("\n\t\t\t\t5. Rollin-Chair--5000 Taka\n");
}
void drawing()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Drawing  site ");
    printf("\n\t\t\t\t1. Show-pics--2500 Taka\n");
    printf("\n\t\t\t\t2. Flower--100 Taka\n");
    printf("\n\t\t\t\t3. Tv-Mart-- 300 Taka\n");
    printf("\n\t\t\t\t4. T-table-- 35,00Taka\n");
    printf("\n\t\t\t\t5. Pic-Art -- 95,0 Taka\n");
    printf("\n\t\t\t\t6. wheel-chair -- 95,000 Taka\n");
}
void kitchen()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Kitchen site ");
    printf("\n\t\t\t\t1. Pan--1500 Taka\n");
    printf("\n\t\t\t\t2. Non-stikiPan--1500 Taka\n");
}
void bathroom()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Bathroom site ");
    printf("\n\t\t\t\t1. Herpik--250 Taka\n");
    printf("\n\t\t\t\t2. Floor-Brash--100 Taka\n");
    printf("\n\t\t\t\t3. Ditargent-- 150 Taka\n");
    printf("\n\t\t\t\t4. Soda-- 30 Taka\n");
}
