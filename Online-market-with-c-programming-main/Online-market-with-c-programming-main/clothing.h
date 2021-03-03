
void clothing()
{
    system("cls");
    int c;

    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t    ====================\n");
    printf("\t\t\t\t\t    | Clothing Section |");
    printf("\n\t\t\t\t\t    ====================\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t1. Women\n");
    printf("\n\t\t\t\t2. Men\n");
    printf("\n\t\t\t\t3. Children\n");
    printf("\n\t\t\t\t4. Footwear\n");
    printf("\n\t\t\t\t5. Jewelries\n");
    printf("\n\t\t\t\t6. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");

    scanf("%d",&c);
    switch(c)
    {
    case 1:
        women();
        break;

    case 2:
        men();
        break;

    case 3:
        children();
        break;

    case 4:
        footwear();
        break;

    case 5:
        jwelries();
        break;

    case 6:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void women()
{
    system("cls");
    int n;
    char a[] = "Sharee";
    char b[] = "Shirt";
    char c[] = "Denim";
    char d[] = "Three Piece";
    int p = 1200, q = 500, r = 600, s = 1800;
    int x;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t =================\n");
    printf("\t\t\t\t\t | Women Section |");
    printf("\n\t\t\t\t\t =================\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t 1. %s ----- %d Taka\n", a, p);
    printf("\n\t\t\t\t 2. %s ----- %d Taka\n", b, q);
    printf("\n\t\t\t\t 3. %s ----- %d Taka\n", c, r);
    printf("\n\t\t\t\t 4. %s ----- %d Taka\n", d, s);
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    printf("\t\t\t\tEnter quantity: ");
    scanf("%d", &x);
    switch(n)
    {
    case 1:
        invoice(a, p*x, x);
        break;

    case 2:
        invoice(b, q*x, x);
        break;

    case 3:
        invoice(c, r*x, x);
        break;

    case 4:
        invoice(d, s*x, x);
        break;

    case 5:
        clothing();
        break;

    default:
        printf("Error!");

    }
}

void men()
{
    system("cls");
    int n;
    char a[] = "Shirt";
    char b[] = "Denim";
    char c[] = "T-shirt";
    char d[] = "Blazer";
    int p = 900, q = 500, r = 300, s = 2000;
    int x;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ===============\n");
    printf("\t\t\t\t\t | Men Section |");
    printf("\n\t\t\t\t\t ===============\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t 1. %s ----- %d Taka\n", a, p);
    printf("\n\t\t\t\t 2. %s ----- %d Taka\n", b, q);
    printf("\n\t\t\t\t 3. %s ----- %d Taka\n", c, r);
    printf("\n\t\t\t\t 4. %s ----- %d Taka\n", d, s);
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    printf("\t\t\t\tEnter quantity: ");
    scanf("%d", &x);
    switch(n)
    {
    case 1:
        invoice(a, p*x, x);
        break;

    case 2:
        invoice(b, q*x, x);
        break;

    case 3:
        invoice(c, r*x, x);
        break;

    case 4:
        invoice(d, s*x, x);
        break;

    case 5:
        clothing();
        break;

    default:
        printf("Error!");

    }
}


void children()
{
    system("cls");
    int n;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ====================\n");
    printf("\t\t\t\t\t | Children Section |");
    printf("\n\t\t\t\t\t ====================\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t 1. Shirt--500 Taka\n");
    printf("\n\t\t\t\t 2. Pant--500 Taka\n");
    printf("\n\t\t\t\t 3. Toy--1200 Taka\n");
    printf("\n\t\t\t\t 4. Watch--300 Taka\n");
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Shirt || Price: 500 Taka");
        break;

    case 2:
        printf("Your order is : Pant || Price: 500 Taka");
        break;

    case 3:
        printf("Your order is : Toy || Price: 1200 Taka");
        break;

    case 4:
        printf("Your order is : Watch || Price: 300 Taka");
        break;

    case 5:
        clothing();
        break;


    default:
        printf("Error!");
    }

}

void footwear()
{
    system("cls");
    int n;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ====================\n");
    printf("\t\t\t\t\t | Footwear Section |");
    printf("\n\t\t\t\t\t ====================\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t 1. Shoes--1500 Taka\n");
    printf("\n\t\t\t\t 2. Socks--200 Taka\n");
    printf("\n\t\t\t\t 3. Belt--300 Taka\n");
    printf("\n\t\t\t\t 4. Wallet--1200 Taka\n");
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Shoes || Price: 1500 Taka");
        break;

    case 2:
        printf("Your order is : Socks || Price: 200 Taka");
        break;

    case 3:
        printf("Your order is : Belt || Price: 300 Taka");
        break;

    case 4:
        printf("Your order is : Wallet || Price: 1200 Taka");
        break;
    case 5:
        clothing();
        break;

    default:
        printf("Error!");
    }

}

void jwelries()
{
    system("cls");
    int n;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ===================\n");
    printf("\t\t\t\t\t | Jewelry Section |");
    printf("\n\t\t\t\t\t ===================\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t 1. Neekless--2,50,000 Taka\n");
    printf("\n\t\t\t\t 2. Braselet--15000 Taka\n");
    printf("\n\t\t\t\t 3. Chain-- 5000 Taka\n");
    printf("\n\t\t\t\t 4. Diamond-Ring 20,000 Taka\n");
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Neekless || Price: 2,50,000 Taka");
        break;

    case 2:
        printf("Your order is : Braselet || Price: 15000 Taka");
        break;

    case 3:
        printf("Your order is : Chain || Price: 5000 Taka");
        break;

    case 4:
        printf("Your order is : Diamond-Ring || Price: 20,000 Taka");
        break;
    case 5:
        clothing();
        break;

    default:
        printf("Error!");
    }
}
