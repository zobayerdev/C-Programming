void healthcare()
{
    system("cls");
    int h;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t    ===============\n");
    printf("\t\t\t\t\t    | Health Care |");
    printf("\n\t\t\t\t\t    ===============\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t1. Medical Accessories\n");
    printf("\n\t\t\t\t2. Hygienic Products\n");
    printf("\n\t\t\t\t3. Personal Care\n");
    printf("\n\t\t\t\t4. Dental Care\n");
    printf("\n\t\t\t\t5. Medicines\n");
    printf("\n\t\t\t\t6. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");

    scanf("%d",&h);
    switch(h)
    {
    case 1:
        medical_acc();
        break;

    case 2:
        hygenic();
        break;

    case 3:
        personal();
        break;

    case 4:
        dental();
        break;

    case 5:
        medicines();
        break;

    case 6:
        shop();

    default:
        printf("Error!");
    }
}
void medical_acc()
{
    int n;
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Medicine site ");
    printf("\n\t\t\t\t1. Bed--250 Taka\n");
    printf("\n\t\t\t\t2. Chair--100 Taka\n");
    printf("\n\t\t\t\t3. Injection-- 300 Taka\n");
    printf("\n\t\t\t\t4. Fanel-- 35,00Taka\n");
    printf("\n\t\t\t\t5. Acid -- 95,000 Taka\n");
    printf("\n\t\t\t\t6. Wheel-chair -- 95,000 Taka\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Bed || Price: 250 Taka");
        break;

    case 2:
        printf("Your order is : Chair || Price: 100 Taka");
        break;

    case 3:
        printf("Your order is : Injection || Price: 300 Taka");
        break;

    case 4:
        printf("Your order is : Fanel || Price: 35,00 Taka");
        break;

    case 5:
        printf("Your order is : Acid || Price: 95,000 Taka");
        break;

    case 6:
        printf("Your order is : Wheel-chair || Price: 95,000 Taka");
        break;

    default:
        printf("Error!");
    }

}
void hygenic()
{
    int n;
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Hygenic Goods site ");
    printf("\n\t\t\t\t1. Osmotics Cosmeceuticals--2500 Taka\n");
    printf("\n\t\t\t\t2. BPI Sports--100 Taka\n");
    printf("\n\t\t\t\t3. Bulk Apothecary-- 300 Taka\n");
    printf("\n\t\t\t\t4. The Dairy Fairy -- 5,00Taka\n");
    printf("\n\t\t\t\t5. Oyin Handmade -- 5,000 Taka\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Osmotics Cosmeceuticals || Price: 2500 Taka");
        break;

    case 2:
        printf("Your order is : BPI Sports || Price: 100 Taka");
        break;

    case 3:
        printf("Your order is : Bulk Apothecary || Price: 300 Taka");
        break;

    case 4:
        printf("Your order is : The Dairy Fairy || Price: 5,00 Taka");
        break;

    case 5:
        printf("Your order is : Oyin Handmade || Price: 5,000 Taka");
        break;

    default:
        printf("Error!");
    }
}
void personal()
{
    int n;
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Personal Goods site ");
    printf("\n\t\t\t\t1. Fast Aid--250 Taka\n");
    printf("\n\t\t\t\t2. Bandage-- 100 Taka\n");
    printf("\n\t\t\t\t3. Kneif-- 300 Taka\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Fast Aid || Price: 250 Taka");
        break;

    case 2:
        printf("Your order is : Bandage || Price: 100 Taka");
        break;

    case 3:
        printf("Your order is : Kneif || Price: 300 Taka");
        break;

    default:
        printf("Error!");
    }
}
void dental()
{
    int n;
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Dental site ");
    printf("\n\t\t\t\t1. Teeth cleaner--250 Taka\n");
    printf("\n\t\t\t\t2. Mouth Wash--250 Taka\n");
    printf("\n\t\t\t\t3. Fake Teeth--500  Taka\n");
    printf("\n\t\t\t\t4. Brush--20 Taka\n");
    printf("\n\t\t\t\t5. Tooth-pest-- 250 Taka\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Teeth cleaner || Price: 250 Taka");
        break;

    case 2:
        printf("Your order is : Mouth Wash || Price: 250 Taka");
        break;

    case 3:
        printf("Your order is : Fake Teeth || Price: 500 Taka");
        break;

    case 4:
        printf("Your order is : Brush || Price: 20 Taka");
        break;

    case 5:
        printf("Your order is : Tooth-pest || Price: 250 Taka");
        break;

    default:
        printf("Error!");
    }
}
void medicines()
{
    int n;
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the madicine site ");
    printf("\n\t\t\t\t1. Ace--10 Taka\n");
    printf("\n\t\t\t\t2. Deflux--50 Taka\n");
    printf("\n\t\t\t\t3. Sinaron Plus--20 Taka\n");
    printf("\n\t\t\t\t4. Isoral Mums--100 Taka\n");
    printf("\n\t\t\t\t5. Viscosid --150  Taka\n");
    printf("\n\t\t\t\t6. Napa -- 10 Taka\n");
    printf("\n\t\t\t\t7. Sallyn --5  Taka\n");
    printf("\n\t\t\t\t8.  Tofen --23 Taka\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Ace || Price: 10 Taka");
        break;

    case 2:
        printf("Your order is : Deflux || Price: 50 Taka");
        break;

    case 3:
        printf("Your order is : Sinaron Plus || Price: 20 Taka");
        break;

    case 4:
        printf("Your order is : Isoral Mums || Price: 100 Taka");
        break;

    case 5:
        printf("Your order is : Viscosid || Price: 150 Taka");
        break;

    case 6:
        printf("Your order is : Napa || Price: 10 Taka");
        break;

    case 7:
        printf("Your order is : Sallyn || Price: 5 Taka");
        break;

    case 8:
        printf("Your order is : Tofen || Price: 23 Taka");
        break;

    default:
        printf("Error!");
    }
}
