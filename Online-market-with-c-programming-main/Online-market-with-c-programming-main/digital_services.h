void digital_service()
{
    system("cls");
    int d;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t    ===================\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t    | Digital Service |");
    printf(ANSI_COLOR_YELLOW"\n\t\t\t\t\t    ===================\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t1. Gift Cards\n");
    printf("\n\t\t\t\t2. Account Subscription\n");
    printf("\n\t\t\t\t3. Game Top-Up\n");
    printf("\n\t\t\t\t4. Bkash to Paypal\n");
    printf("\n\t\t\t\t5. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&d);
    switch(d)
    {
    case 1:
        gift();
        break;

    case 2:
        account_sub();
        break;

    case 3:
        game();
        break;

    case 4:
        bkash_paypal();
        break;

    case 5:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void gift()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Gift site ");
    printf("\n\t\t\t\t1.  music-Box --500 Taka\n");
    printf("\n\t\t\t\t2.  Light box --500 Taka\n");
    printf("\n\t\t\t\t3.  Doll --500 Taka\n");
}
void account_sub()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Account site ");
    printf("\n\t\t\t\t1. Netflix Subscription --150 Taka\n");
    printf("\n\t\t\t\t5. G-Suite --60 Taka\n");
    printf("\n\t\t\t\t3. Netflix Gift Voucher--200 Taka\n");
}
void game()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Games site ");
    printf("\n\t\t\t\t1. Free-Fire -Weekly--250 Taka\n");
    printf("\n\t\t\t\t2. Free-Fire-Monthly--660 Taka\n");
    printf("\n\t\t\t\t3. Free-Fire-100 Diamond--1360 Taka\n");
    printf("\n\t\t\t\t4. Free-Fire-210 Diamond--220 Taka\n");
    printf("\n\t\t\t\t5. Free-Fire-320 Diamond --260 Taka\n");
    printf("\n\t\t\t\t7. Free-Fire-510 Diamond--430 Taka\n");
    printf("\n\t\t\t\t7. PUBG-UC--430 Taka\n");
}
void bkash_paypal()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Games site ");
    printf("\n\t\t\t\t1. Dollar To Taka--2tk per dollar changes\n");
    printf("\n\t\t\t\t2. Taka To Dollar--2 tk per dollar changes\n");
}
