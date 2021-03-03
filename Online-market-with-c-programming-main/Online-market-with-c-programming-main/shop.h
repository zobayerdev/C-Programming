
void shop()
{
    system("cls");
    int s;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t    ================\n");
    printf("\t\t\t\t\t    | Our Services |");
    printf("\n\t\t\t\t\t    ================\n"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\t1. Clothing");
    printf("\n\n\t\t\t\t2. Electronics");
    printf("\n\n\t\t\t\t3. Health & Care");
    printf("\n\n\t\t\t\t4. Furnitures");
    printf("\n\n\t\t\t\t5. Consumer Foods");
    printf("\n\n\t\t\t\t6. Stationaries");
    printf("\n\n\t\t\t\t7. Digital Services");
    printf("\n\n\t\t\t\t8. <= Back");
    printf("\n\n\t\t\t\t________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");

    scanf("%d",&s);
    switch(s)
    {
    case 1:
        clothing();
        break;

    case 2:
        electronics();
        break;

    case 3:
        healthcare();
        break;

    case 4:
        furnitures();
        break;

    case 5:
        consumer_foods();
        break;

    case 6:
        stationaries();
        break;

    case 7:
        digital_service();
        break;

    case 8:
        main();

    default:
        printf("Error!");
    }

}
