void payment(int c)
{
    system("cls");
    int p, n;
    char a[] = "Bkash";
    char b[] = "Rocket";
    char l[] = "Nagad";
    char d[] = "Credit/Debit";
    char e[] = "Cash On Delivery";
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ===========\n");
    printf("\t\t\t\t\t | Payment |");
    printf("\n\t\t\t\t\t ===========\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t Choose a payment method:\n");
    printf("\n\t\t\t\t 1. %s\n", a);
    printf("\n\t\t\t\t 2. %s\n", b);
    printf("\n\t\t\t\t 3. %s\n", l);
    printf("\n\t\t\t\t 4. %s\n", d);
    printf("\n\t\t\t\t 5. %s\n", e);
    printf("\n\t\t\t\t 6. <= Back to the shop\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    switch(n)
    {
    case 1:
        bkash();
        break;

    case 2:
        rocket();
        break;

    case 3:
        nagad();
        break;

    case 4:
        card();
        break;

    case 5:
        cod(c);
        break;

    case 6:
        shop();
        break;

    default:
        printf("Error!");

    }
}

bkash()
{
    system("cls");
    int m, o, p;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t =========\n");
    printf("\t\t\t\t\t | Bkash |");
    printf("\n\t\t\t\t\t =========\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your bkash number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter the OTP\n");
    printf("\t\t\t\t--------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &o);
    printf("\n\t\t\t\tEnter your pin\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &p);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t =========\n");
        fprintf(pay, "\t\t\t\t\t | Bkash |");
        fprintf(pay, "\n\t\t\t\t\t =========\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your bkash number\n");
        fprintf(pay, "\t\t\t\t------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter the OTP\n");
        fprintf(pay, "\t\t\t\t--------------\n");
        fprintf(pay, "\t\t\t\t=> %d", o);
        fprintf(pay, "\n\t\t\t\tEnter your pin\n");
        fprintf(pay, "\t\t\t\t---------------\n");
        fprintf(pay, "\t\t\t\t=> %d", p);
        fclose(pay);
    }

    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\t\tYou have paid your amount with Bkash.\n" ANSI_COLOR_RESET);
    //Sleep(100);

    thanks();
}

rocket()
{
    system("cls");
    int m, o, p;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ==========\n");
    printf("\t\t\t\t\t | Rocket |");
    printf("\n\t\t\t\t\t ==========\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your rocket number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter the OTP\n");
    printf("\t\t\t\t--------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &o);
    printf("\n\t\t\t\tEnter your pin\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &p);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t ==========\n");
        fprintf(pay, "\t\t\t\t\t | Rocket |");
        fprintf(pay, "\n\t\t\t\t\t ==========\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your rocket number\n");
        fprintf(pay, "\t\t\t\t------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter the OTP\n");
        fprintf(pay, "\t\t\t\t--------------\n");
        fprintf(pay, "\t\t\t\t=> %d", o);
        fprintf(pay, "\n\t\t\t\tEnter your pin\n");
        fprintf(pay, "\t\t\t\t---------------\n");
        fprintf(pay, "\t\t\t\t=> %d", p);
        fclose(pay);
    }


    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\t\tYou have paid your amount with Rocket.\n" ANSI_COLOR_RESET);

    thanks();
}
nagad()
{
    system("cls");
    int m, o, p;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t =========\n");
    printf("\t\t\t\t\t | Nagad |");
    printf("\n\t\t\t\t\t =========\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your nagad number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter the OTP\n");
    printf("\t\t\t\t--------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &o);
    printf("\n\t\t\t\tEnter your pin\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &p);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t =========\n");
        fprintf(pay, "\t\t\t\t\t | Nagad |");
        fprintf(pay, "\n\t\t\t\t\t =========\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your nagad number\n");
        fprintf(pay, "\t\t\t\t------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter the OTP\n");
        fprintf(pay, "\t\t\t\t--------------\n");
        fprintf(pay, "\t\t\t\t=> %d", o);
        fprintf(pay, "\n\t\t\t\tEnter your pin\n");
        fprintf(pay, "\t\t\t\t---------------\n");
        fprintf(pay, "\t\t\t\t=> %d", p);
        fclose(pay);
    }


    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\t\tYou have paid your amount with Nagad.\n" ANSI_COLOR_RESET);

    thanks();
}
card()
{
    system("cls");
    int m, o, p;
    char n[200];
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ================\n");
    printf("\t\t\t\t\t | Credit/Debit |");
    printf("\n\t\t\t\t\t ================\n\n"ANSI_COLOR_RESET);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your full name:\n");
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", n);
    printf("\n\t\t\t\tEnter your card number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter your CVC\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &o);
    printf("\n\t\t\t\tEnter your pin\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &p);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t ================\n");
        fprintf(pay, "\t\t\t\t\t | Credit/Debit |");
        fprintf(pay, "\n\t\t\t\t\t ================\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your full name:\n");
        fprintf(pay, "\t\t\t\t---------------------\n");
        fprintf(pay, "\t\t\t\t=> %s", n);
        fprintf(pay, "\n\t\t\t\tEnter your card number\n");
        fprintf(pay, "\t\t\t\t------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter your pin\n");
        fprintf(pay, "\t\t\t\t---------------\n");
        fprintf(pay, "\t\t\t\t=> %d", p);
        fclose(pay);
    }


    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\t\tYou have paid your amount with Card.\n" ANSI_COLOR_RESET);

    thanks();
}
cod()
{
    system("cls");
    int m;
    char o[200];
    char n[200];
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ====================\n");
    printf("\t\t\t\t\t | Cash On Delivery |");
    printf("\n\t\t\t\t\t ====================\n\n"ANSI_COLOR_RESET);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your full name:\n");
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", n);
    printf("\n\t\t\t\tEnter your phone number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your address:\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", o);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t ====================\n");
        fprintf(pay, "\t\t\t\t\t | Cash On Delivery |");
        fprintf(pay, "\n\t\t\t\t\t ====================\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your full name:\n");
        fprintf(pay, "\t\t\t\t---------------------\n");
        fprintf(pay, "\t\t\t\t=> %s", n);
        fprintf(pay, "\n\t\t\t\tEnter your phone number\n");
        fprintf(pay, "\t\t\t\t-------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter your address:\n");
        fprintf(pay, "\t\t\t\t--------------------\n");
        fprintf(pay, "\t\t\t\t=> %s", o);
        fclose(pay);
    }

    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\tYou choose cash on delivery. Your product will be delivered soon.\n" ANSI_COLOR_RESET);

    thanks();
}
