void electronics()
{
    system("cls");
    int e;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t    ==============\n");
    printf("\t\t\t\t\t    | Electroics |");
    printf("\n\t\t\t\t\t    ==============\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t 1. Home Appliances\n");
    printf("\n\t\t\t\t 2. Computer Accessories\n");
    printf("\n\t\t\t\t 3. Digital Goods");
    printf("\n\t\t\t\t 4. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&e);
    switch(e)
    {
    case 1:
        home_app();
        break;

    case 2:
        computer();
        break;

    case 3:
        digital_goods();
        break;

    case 4:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void home_app()
{
    int n;
    printf("\n\t\t\t\t1. Fan -- 3500 Taka\n");
    printf("\n\t\t\t\t2. Light -- 250 Taka\n");
    printf("\n\t\t\t\t3. Calling Bell --250 Taka\n");
    printf("\n\t\t\t\t4. Switch --250 Taka\n");
    printf("\n\t\t\t\t5. Electric Door --5000 Taka\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Fan || Price: 3500 Taka");
        break;

    case 2:
        printf("Your order is : Light || Price: 250 Taka");
        break;

    case 3:
        printf("Your order is : Calling Bell || Price: 250 Taka");
        break;

    case 4:
        printf("Your order is : Switch || Price: 250 Taka");
        break;

    case 5:
        printf("Your order is : Electric Door || Price: 5000 Taka");
        break;

    default:
        printf("Error!");
    }
}
void computer()
{

    int n;
    printf("\n\t\t\t\t1. Ram-- 3500 Taka\n");
    printf("\n\t\t\t\t2. Ram -- 250 Taka\n");
    printf("\n\t\t\t\t3. Ram -- 200 Taka\n");
    printf("\n\t\t\t\t4. SSD -- 250 Taka\n");
    printf("\n\t\t\t\t5. SSD -- 5000 Taka\n");
    printf("\n\t\t\t\t1. Processor-I -- 3500 Taka\n");
    printf("\n\t\t\t\t2. Processor-II -- 250 Taka\n");
    printf("\n\t\t\t\t3. Processor-Ill --200 Taka\n");
    printf("\n\t\t\t\t4. Processor-IV --250 Taka\n");
    printf("\n\t\t\t\t5. Processor-V --5000 Taka\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Ram || Price: 3500 Taka");
        break;

    case 2:
        printf("Your order is : Ram || Price: 250 Taka");
        break;

    case 3:
        printf("Your order is : Ram || Price: 250 Taka");
        break;

    case 4:
        printf("Your order is : SSD || Price: 250 Taka");
        break;

    case 5:
        printf("Your order is : SSD || Price: 5000 Taka");
        break;

    case 6:
        printf("Your order is : Processor-I || Price: 3500 Taka");
        break;

    case 7:
        printf("Your order is : Processor-II || Price: 250 Taka");
        break;

    case 8:
        printf("Your order is : Processor-III || Price: 250 Taka");
        break;

    case 9:
        printf("Your order is : Processor-IV || Price: 250 Taka");
        break;

    case 10:
        printf("Your order is : Processor-V || Price: 5000 Taka");
        break;

    default:
        printf("Error!");
    }
}
void digital_goods()
{
    int n;
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Digital Goods site ");
    printf("\n\t\t\t\t1. Electric Door--2000 Taka\n");
    printf("\n\t\t\t\t2. Washing Machine--45,000 Taka\n");
    printf("\n\t\t\t\t3. Refrigrator--35,000 Taka\n");
    printf("\n\t\t\t\t4. Blander Machine -- 35,00Taka\n");
    printf("\n\t\t\t\t5. Fridge -- 95,000 Taka\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Electric Door || Price: 2000 Taka");
        break;

    case 2:
        printf("Your order is : Washing Machine || Price: 45,000 Taka");
        break;

    case 3:
        printf("Your order is : Refrigrator || Price: 35,00 Taka");
        break;

    case 4:
        printf("Your order is : Blander Machine || Price: 35,000 Taka");
        break;

    case 5:
        printf("Your order is : Fridge || Price: 95,000 Taka");
        break;

    default:
        printf("Error!");
    }
}
