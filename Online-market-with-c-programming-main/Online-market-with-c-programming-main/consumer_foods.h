void consumer_foods()
{
    system("cls");
    int c;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t    ==================\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t    | Consumer Foods |");
    printf(ANSI_COLOR_YELLOW"\n\t\t\t\t\t    ==================\n"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\t1. Grocery Items\n");
    printf("\n\t\t\t\t2. Beverages\n");
    printf("\n\t\t\t\t3. Dairy\n");
    printf("\n\t\t\t\t4. Meat & Fish\n");
    printf("\n\t\t\t\t5. Snacks\n");
    printf("\n\t\t\t\t6. Cooking Needs\n");
    printf("\n\t\t\t\t7. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        grocery();
        break;

    case 2:
        beverages();
        break;

    case 3:
        dairy();
        break;

    case 4:
        meat();
        break;

    case 5:
        snacks();
        break;

    case 6:
        cooking();
        break;

    case 7:
        shop();

    default:
        printf("Error!");
    }
}
void grocery()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Grocerry Item site ");
    printf("\n\t\t\t\t1. Rice--2500 Taka\n");
    printf("\n\t\t\t\t2. Lantil--100 Taka\n");
    printf("\n\t\t\t\t3. Potato-- 50 Taka\n");
    printf("\n\t\t\t\t4. Cucumber-- 30 Taka\n");
    printf("\n\t\t\t\t5. Onion -- 95,0 Taka\n");
}
void beverages()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Beverage Item site ");
    printf("\n\t\t\t\t1. Pepsi--2500 Taka\n");
    printf("\n\t\t\t\t2. CocaCola--100 Taka\n");
    printf("\n\t\t\t\t3. 7Up-- 50 Taka\n");
    printf("\n\t\t\t\t4. Sprite-- 30 Taka\n");
    printf("\n\t\t\t\t5. Mountain-Due -- 95,0 Taka\n");
}
void dairy()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Dairy Item site ");
    printf("\n\t\t\t\t1. Milk--250 Taka\n");
    printf("\n\t\t\t\t2. Honey--100 Taka\n");
    printf("\n\t\t\t\t3. Dano-Milk-- 50 Taka\n");
    printf("\n\t\t\t\t4. Gorur Gura Milk-- 30 Taka\n");
    printf("\n\t\t\t\t5. Minarel Water-- 50 Taka\n");
}
void meat()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Meat & Fish Item site ");
    printf("\n\t\t\t\t1. Chicken--120 Taka--per kg\n");
    printf("\n\t\t\t\t2. Beef--500  Taka-- per kg\n");
    printf("\n\t\t\t\t3. Baffalow meat-- 500 Taka--per kg\n");
    printf("\n\t\t\t\t4. Duck Meat-- 300 Taka--per kg\n");
    printf("\n\t\t\t\t5. Chiken-- 250 Taka--per pic\n");
}
void snacks()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Snacks Item site ");
    printf("\n\t\t\t\t1. Chips--10 Taka\n");
    printf("\n\t\t\t\t2. Biscuits--50  Taka\n");
    printf("\n\t\t\t\t3. Chanachur-- 50 Taka\n");
    printf("\n\t\t\t\t4. Pithas-- 30 Taka\n");
    printf("\n\t\t\t\t5. Samucha-- 50 Taka\n");
}
void cooking()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Cooking Needs site ");
    printf("\n\t\t\t\t1. Kneif--150 Taka\n");
    printf("\n\t\t\t\t2. Spoon--50  Taka\n");
    printf("\n\t\t\t\t3. Plate-- 600 Taka\n");
    printf("\n\t\t\t\t4. Pan-- 300 Taka\n");
    printf("\n\t\t\t\t5. Glass-- 350 Taka\n");
}
