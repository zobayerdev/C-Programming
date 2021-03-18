#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE   "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void gotoxy(short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

////////////////////////////////////////////////// Structure ///////////////////////////////////////////////////////////

struct shop
{
    int code;
    int price;
    char name[1000];
};

struct item
{
    char productname[40], c;
    int productid;
    int price;
    int discount;
    int after_discount;
} st;

////////////////////////////////////////////////// Loading Bar /////////////////////////////////////////////////////////

loadingBar()
{
    system("cls");
    char a = 177, b = 219;
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t");
    printf("Loading...\n\n");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 26; i++)
        printf("%c", a);
    printf("\r");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 26; i++)
    {
        printf(ANSI_COLOR_RED);
        printf(ANSI_COLOR_YELLOW"%c", b);
        Sleep(20);
    }
}

////////////////////////////////////////////////// Registration /////////////////////////////////////////////////////////

registration()
{
    system("cls");
    char name[200], email[100], usrname[100], address[200], pass[100], pass2[100];
    int mobile;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t====================\n");
    printf("\t\t\t\t\t||  Registration  ||\n");
    printf("\t\t\t\t\t====================\n\n"ANSI_COLOR_RESET);
    fflush(stdin);
    printf("\t\t\t\tEnter your full name\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", name);
    printf("\n\t\t\t\tEnter your mobile number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &mobile);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your address\n");
    printf("\t\t\t\t------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", address);
    printf("\n\t\t\t\tEnter your e-mail\n");
    printf("\t\t\t\t-----------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &email);
    printf("\n\t\t\t\tChoose your username\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &usrname);
    fflush(stdin);
    printf("\n\t\t\t\tChoose your password\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", &pass);
    fflush(stdin);
    printf("\n\t\t\t\tConfirm your password\n");
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", &pass2);
    int result;
    result = strcmp(pass, pass2);
    if(result == 0)
    {
        FILE *fptr;
        fptr = fopen("registration.txt","w");
        fprintf(fptr,"\t\t\t\tFull Name: %s\n\t\t\t\tMobile Number: +880%d\n\t\t\t\tAddress: %s\n\t\t\t\tE-mail: %s\n", name, mobile, address, email);
        fclose(fptr);

        FILE *username;
        username = fopen("username.dat", "w");
        fprintf(username, "%s", usrname);
        fclose(username);

        FILE *passx;
        passx = fopen("password.dat", "w");
        fprintf(passx, "%s", pass);
        fclose(passx);
        MessageBox(NULL,"  Registration Successful\n  Thank You", "Registration", MB_ICONINFORMATION | MB_OK);
        signin();
    }

    else
    {

        try_reg(name, mobile, address, email, usrname);
    }
}

try_reg(char name[200], int mobile, char address[200], char email[100], char usrname[100])
{
    char pass[100];
    char pass2[100];
    int res;
    res = strcmp(pass, pass2);
    do
    {
        fflush(stdin);
        MessageBox(NULL,"  Your Password didn't match\n  Retry", "Registration", MB_ICONWARNING | MB_OK);
        printf("\n\t\t\t\tChoose your password again\n");
        printf("\t\t\t\t--------------------------\n");
        printf("\t\t\t\t=> ");
        scanf("%s", &pass);
        printf("\n\t\t\t\tConfirm your password\n");
        printf("\t\t\t\t---------------------\n");
        printf("\t\t\t\t=> ");
        scanf("%s", &pass2);
    }
    while (res == 0);
    FILE *fptr;
    fptr = fopen("registration.txt","w");
    fprintf(fptr,"\t\t\t\tFull Name: %s\n\t\t\t\tMobile Number: +880%d\n\t\t\t\tAddress: %s\n\t\t\t\tE-mail: %s\n", name, mobile, address, email);
    fclose(fptr);

    FILE *username;
    username = fopen("username.dat", "w");
    fprintf(username, "%s", usrname);
    fclose(username);
    FILE *passx;
    passx = fopen("password.dat", "w");
    fprintf(passx, "%s", pass);
    fclose(passx);
    MessageBox(NULL,"  Registration Successful\n  Thank You", "Registration", MB_ICONINFORMATION | MB_OK);
    signin();
}

///////////////////////////////////////////////// Sign In /////////////////////////////////////////////////////////////

signin()
{
    system("cls");
    char user[100], password[100], usr[100], passc[100];
    int n, i;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t===============\n");
    printf("\t\t\t\t\t||  Sign In  ||\n");
    printf("\t\t\t\t\t===============\n" ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your username\n");
    printf("\t\t\t\t-------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &user);
    printf("\n\t\t\t\tEnter your password\n");
    printf("\t\t\t\t-------------------\n");
    printf("\t\t\t\t=> ");
    FILE *username;
    username = fopen("username.dat", "r");
    fscanf(username, "%s", &usr);
    FILE *passx;
    passx = fopen("password.dat", "r");
    fscanf(passx, "%s", &passc);
    int length;
    length = strlen(passc);
    for(i=0; i<length; i++)
    {
        password[i] = getch();
        printf("*");
    }
    password[i]='\0';

    int users = strcmp(usr, user);
    int passes = strcmp(passc, password);
    if((users == 0)&&(passes == 0))
    {
        MessageBox(0, "  Log In Successful", "Log In", MB_ICONINFORMATION | MB_OK);
        sign_option();
    }

    else
    {
        int msgboxID = MessageBox(NULL,"  Wrong Credentials\n  Do you want to try again?", "Log In", MB_ICONWARNING | MB_RETRYCANCEL);
        switch (msgboxID)
        {
        case IDRETRY:
            signin();
            break;

        case IDCANCEL:
            user_panel();
            break;
        }
    }
}

//////////////////////////////////////////////////// Graphics ////////////////////////////////////////////////

graphics()
{
    system("cls");
    int x;
    printf(ANSI_COLOR_BLUE"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t");
    char name1[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  WELCOME ";

    for(x=0; name1[x]!=NULL; x++)
    {
        printf(ANSI_COLOR_RESET"%c",name1[x]);
        Sleep(40);
    }
    char name2[] = "TO OUR  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    for(x=0; name2[x]!=NULL; x++)
    {
        printf("%c",name2[x]);
        Sleep(40);
    }
    printf("\n\n\t\t\t\t");
    char name3[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb  MULTI SHOPPING SYSTEM  \xdb\xdb\xdb\xdb\xdb\xdb";
    for(x=0; name3[x]!=NULL; x++)
    {
        printf(ANSI_COLOR_YELLOW"%c",name3[x]);
        Sleep(40);
    }
    printf(ANSI_COLOR_RED"\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n"ANSI_COLOR_RESET);

    Sleep(1000);
}

///////////////////////////////////////////////////// Credit ///////////////////////////////////////////////////

credit()
{
    system("cls");
    printf(ANSI_COLOR_YELLOW"\n\n\n\n\n\n\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\n\t\t\tTeam Member - 01  |  Tunazzinur Rahman Kabbo  |  ID: 19202103268\n");
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    printf("\t\t\tTeam Member - 02  |  MD. Zobayer Hasan Nayem  |  ID: 19202103274\n");
    printf(ANSI_COLOR_GREEN"\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    printf("\t\t\tTeam Member - 03  |  MD. Mehedi Hasan         |  ID: 19202103264\n");
    printf(ANSI_COLOR_RED"\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\n\t\t\tPress any key to go back to main menu...");
    getch();
    menu();


}


/////////////////////////////////////////////////// Menu /////////////////////////////////////////////////////////////

menu()
{
    system("cls");
    int num,i;
    printf(ANSI_COLOR_RED"\n\n\t\t\t\t  ___________________________\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t  ===========================\n");
    printf(ANSI_COLOR_MAGENTA"\t\t\t\t /|||||||||||||||||||||||||||\\\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t  |_________________________|\n");
    printf(ANSI_COLOR_RED"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t  |    ONLINE MULTI-SHOP    |\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_MAGENTA"\t\t\t\t  |_________________________|\n");
    printf(ANSI_COLOR_RED"\t\t\t\t /___________________________\\\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t|_____________________________|"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\t1. User Panel\n");
    printf("\t\t\t\t2. Admin Panel\n");
    printf("\t\t\t\t3. Feedback\n");
    printf("\t\t\t\t4. Credits\n");
    printf("\t\t\t\t5. Exit\n");
    printf("\n\n\t\t\t\tEnter your choice : ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        loadingBar();
        user_panel();
        break;

    case 2:
        loadingBar();
        admin();
        break;

    case 3:
        feedback();
        break;

    case 4:
        credit();
        break;

    case 5:
        MessageBox(NULL,"  Thank You For Using Our Service\n  Stay With Us", "Exit", MB_ICONEXCLAMATION | MB_OK);
        exit(1);
        break;

    default:
        MessageBox(NULL,"  Wrong Input\n  Compile Again", "Error", MB_ICONWARNING | MB_OK);
        exit(1);
        break;
    }
}

feedback()
{
    system("cls");
    printf(ANSI_COLOR_MAGENTA"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb FEEDBACK \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    char name[500];
    char email[500];
    char str[500];
    float s;
    FILE *fp;
    fp = fopen("feedback.txt", "a");
    fflush(stdin);
    printf("\n\t\t\t\tEnter your full name: ");
    scanf("%[^\n]s", name);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your e-mail: ");
    scanf("%[^\n]s", email);
    fflush(stdin);
    printf("\n\t\t\t\tWrite your feedback: ");
    scanf("%[^\n]s", str);
    printf("\n\t\t\t\tGive us stars (1 to 5): ");
    scanf("%f", &s);
    fprintf(fp, "\n\n\t\t\t\t==>\n\t\t\t\tName: %s\n\t\t\t\tE-mail: %s\n\t\t\t\tFeedback: %s\n\t\t\t\tStars: %d", name, email, str, s);
    fclose(fp);
    MessageBox(0, "  We have got your feedback\n  Thank You", "Feedback", MB_ICONINFORMATION | MB_OK);
    menu();
}


sign_option()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_MAGENTA"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb User Option \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Enter Shop");
    printf("\n\t\t\t\t\t[2] Edit Profile");
    printf("\n\t\t\t\t\t[3] Product Request");
    printf("\n\t\t\t\t\t[4] Log Out");
    printf("\n\t\t\t\t\t[5] Exit!");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        loadingBar();
        shop();
        break;

    case 2:
        loadingBar();
        edit_profile();
        break;

    case 3:
        loadingBar();
        request();
        break;

    case 4:
        user_panel();
        break;

    case 5:
        exit(0);
        break;

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        sign_option();
    }
}


edit_profile()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_MAGENTA"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Edit Profile \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Edit User Details");
    printf("\n\t\t\t\t\t[2] Edit User Name");
    printf("\n\t\t\t\t\t[3] Edit Password");
    printf("\n\t\t\t\t\t[4] Back");
    printf("\n\t\t\t\t\t[5] Exit!");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        user_details();
        break;

    case 2:
        edit_username();
        break;

    case 3:
        edit_password();
        break;

    case 4:
        sign_option();
        break;

    case 5:
        exit(0);
        break;

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        sign_option();
    }
}


user_details()
{
    system("cls");
    FILE * fPtr;
    char ch;
    fPtr = fopen("registration.txt", "r");
    printf(ANSI_COLOR_MAGENTA"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Edit User Details \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN" ");
    printf("\n\t\t\t\tYour User Data:");
    printf("\n\t\t\t\t===============\n");
    do
    {
        ch = fgetc(fPtr);
        putchar(ch);
    }
    while(ch != EOF);
    fclose(fPtr);
    printf(" "ANSI_COLOR_RESET);
    int z;
    printf("\n\n\t\t\t\t[1] Edit details");
    printf("\n\t\t\t\t[2] Back");
    printf("\n\t\t\t\t__________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        edit_details();
        break;

    case 2:
        edit_profile();
        break;

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        sign_option();
    }
}


edit_details()
{
    system("cls");
    char name[200], email[100], address[200];
    int mobile;
    FILE *fptr;
    fptr = fopen("registration.txt","w");
    printf(ANSI_COLOR_MAGENTA"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Edit User Details \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n"ANSI_COLOR_RESET);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your full name\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", name);
    printf("\n\t\t\t\tEnter your mobile number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &mobile);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your address\n");
    printf("\t\t\t\t------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", address);
    printf("\n\t\t\t\tEnter your e-mail\n");
    printf("\t\t\t\t-----------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &email);
    fprintf(fptr,"\t\t\t\tFull Name: %s\n\t\t\t\tMobile Number: +880%d\n\t\t\t\tDistrict Name: %s\n\t\t\t\tE-mail: %s\n", name, mobile, address, email);
    fclose(fptr);
    MessageBox(0, "  User Details Updated Successfully", "User Details Update", MB_ICONINFORMATION | MB_OK);
    edit_profile();
}


edit_username()
{
    system("cls");
    printf(ANSI_COLOR_MAGENTA"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Edit User Name \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    char usrname[100];
    char newl[100];

    FILE *username;
    username = fopen("username.dat", "r");
    fscanf(username, "%s", &usrname);
    printf("\n\t\t\t\t\tYour old user name: ");
    printf(ANSI_COLOR_RED"%s"ANSI_COLOR_RESET, usrname);
    fclose(username);

    FILE *newn;
    newn = fopen("username.dat", "w");
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\tEnter your new user name: "ANSI_COLOR_RESET);
    scanf("%s", &newl);
    fprintf(newn, "%s", newl);
    fclose(newn);
    MessageBox(0, "  User Name Updated Successfully", "User Name Update", MB_ICONINFORMATION | MB_OK);
    edit_profile();
}


edit_password()
{
    system("cls");
    printf(ANSI_COLOR_MAGENTA"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Edit Password \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    char passs[100];
    char newl[100];

    FILE *pass;
    pass = fopen("password.dat", "r");
    fscanf(pass, "%s", &passs);
    printf("\n\t\t\t\t\tYour old password: ");
    printf(ANSI_COLOR_RED"%s"ANSI_COLOR_RESET, passs);
    fclose(pass);

    FILE *newn;
    newn = fopen("password.dat", "w");
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\tEnter your new password: "ANSI_COLOR_RESET);
    scanf("%s", &newl);
    fprintf(newn, "%s", newl);
    fclose(newn);

    MessageBox(0, "  Password Updated Successfully", "Password Update", MB_ICONINFORMATION | MB_OK);
    edit_profile();
}


request()
{
    system("cls");
    printf(ANSI_COLOR_BLUE"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Request Product \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    char name[500];
    char email[500];
    char str[500];
    FILE *fp;
    fp = fopen("request.dat", "a");
    fflush(stdin);
    printf("\n\t\t\t\tEnter your full name: ");
    scanf("%[^\n]s", name);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your e-mail: ");
    scanf("%[^\n]s", email);
    fflush(stdin);
    printf("\n\t\t\t\tWrite your product request: ");
    scanf("%[^\n]s", str);
    fprintf(fp, "\n\n\t\t\t\t==>\n\t\t\t\tName: %s\n\t\t\t\tE-mail: %s\n\t\t\t\tProduct Request: %s", name, email, str);
    fclose(fp);
    MessageBox(0, "  We have got your request\n  Thank You", "Product Request", MB_ICONINFORMATION | MB_OK);
    sign_option();
}


user_panel()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_GREEN"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb User Panel \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Registration");
    printf("\n\t\t\t\t\t[2] Sign In");
    printf("\n\t\t\t\t\t[3] Enter shop as a guest");
    printf("\n\t\t\t\t\t[4] <== Back");
    printf("\n\t\t\t\t\t[5] Exit!");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        loadingBar();
        registration();
        break;

    case 2:
        loadingBar();
        signin();
        break;

    case 3:
        loadingBar();
        shop();
        break;

    case 4:
        menu();

    case 5:
        exit(0);

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        user_panel();
    }

}

/////////////////////////////////////////////////// Admin ////////////////////////////////////////////////////////////

admin()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\n\n\n\n\n\n\t\t\t      \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\n\t\t\t\t You have to log in first to access the admin panel.");
    printf(ANSI_COLOR_BLUE"\n\n\t\t\t\t\t     Press any key to login.");
    printf(ANSI_COLOR_RED"\n\n\t\t\t      \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    getch();
    admin_login();
}


admin_login()
{
    system("cls");
    int i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "admin";
    char pass[10] = "admin";
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADMIN LOGIN \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\tUser Name : ");
    scanf("%s", &uname);
    printf("\n\t\t\tPassword : ");
    while(i < 10)
    {
        pword[i] = getch();
        c = pword[i];
        if(c == 13) break;
        else printf("*");
        i++;
    }
    pword[i] = '\0';
    i = 0;

    if(strcmp(uname,"admin") == 0 && strcmp(pword,"admin") == 0)
    {
        MessageBox(0, "  Log In Successful", "Admin", MB_ICONINFORMATION | MB_OK);
        admin_panel();
    }
    else
    {
        int msgboxID = MessageBox(NULL,"  Wrong Credentials\n  Do you want to try again?", "Admin", MB_ICONWARNING | MB_RETRYCANCEL);
        switch (msgboxID)
        {
        case IDRETRY:
            admin_login();
            break;

        case IDCANCEL:
            menu();
            break;
        }
    }
}


admin_panel()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Admin Panel \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Add Items");
    printf("\n\t\t\t\t\t[2] Delete Items");
    printf("\n\t\t\t\t\t[3] View Items");
    printf("\n\t\t\t\t\t[4] Edit Items");
    printf("\n\t\t\t\t\t[5] Feedbacks");
    printf("\n\t\t\t\t\t[6] Product Requests");
    printf("\n\t\t\t\t\t[7] <= Back");
    printf("\n\t\t\t\t\t[8] Exit!");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        add();

    case 2:
        deleteproduct();

    case 3:
        read();

    case 4:
        edits();

    case 5:
        feedbacks();

    case 6:
        requests();

    case 7:
        menu();

    case 8:
        exit(0);

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }


}



///////////////////////////////////////////////////////////////////// --------- Read Feedbacks --------- /////////////////////////////////////////////////////////////////////////////////
void requests()
{
    system("cls");
    FILE * fPtr;
    char ch;
    fPtr = fopen("request.dat", "r");
    if(fPtr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Product Requests \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN" ");
    do
    {
        ch = fgetc(fPtr);
        putchar(ch);
    }
    while(ch != EOF);

    fclose(fPtr);

    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\tPress any key to go back\n"ANSI_COLOR_RESET);
    getch();
    admin_panel();
}


void feedbacks()
{
    system("cls");
    FILE * fPtr;
    char ch;
    fPtr = fopen("feedback.txt", "r");
    if(fPtr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Feedbacks \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN" ");
    do
    {
        ch = fgetc(fPtr);
        putchar(ch);
    }
    while(ch != EOF);

    fclose(fPtr);

    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\tPress any key to go back\n"ANSI_COLOR_RESET);
    getch();
    admin_panel();
}

/////////////////////////////////////////////////////////////////////////// ---------- Edit ----------- ///////////////////////////////////////////////////////////////////////////////////

edits()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb EDIT PRODUCTS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Edit Male Products");
    printf("\n\t\t\t\t\t[2] Edit Female Products");
    printf("\n\t\t\t\t\t[3] Edit Children Products");
    printf("\n\t\t\t\t\t[4] Edit Electronics Products");
    printf("\n\t\t\t\t\t[5] Edit Discounted Products");
    printf("\n\t\t\t\t\t[6] <= Back");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        edit_male();

    case 2:
        edit_female();

    case 3:
        edit_children();

    case 4:
        edit_electronics();

    case 5:
        edit_discount();

    case 6:
        admin_panel();

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
}
edit_male_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb EDIT MALE PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
edit_male()
{
    int index, valid;
    char target[40];
    FILE *fp, *rp;
    int a=0;
    int id;
    char edit;
    long int size = sizeof(st);
    if((fp=fopen("male.dat","r+"))==NULL)
    {
        edit_male_graphics();
        printf("NO RECORD FOUND.");
        getch();
        admin_panel();
    }
    else
    {
        system("cls");
        edit_male_graphics();
        rp = fopen("TempFile.dat","a");
        printf("\n\t\t\t\tEnter Item's Code to edit: ");
        scanf("%d",&id);
        fflush(stdin);
        while(fscanf(fp,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                a = 1;
                printf(ANSI_COLOR_GREEN"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb RECORD FOUND \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
                printf("\n\t\t\t\tItem's Name: %s", st.productname);
                printf("\n\t\t\t\tPrice: %d", st.price);
                printf("\n\t\t\t\tItem's Code: %d"ANSI_COLOR_RESET, st.productid);

                printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb NEW RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
                do
                {
                    fflush(stdin);
                    printf("\n\t\t\t\tNew Item's Name\t\t: ");
                    gets(st.productname);
                    st.productname[0] = toupper(st.productname[0]);
                    for (index = 0; index < strlen(st.productname); ++index)
                    {
                        if(isalpha(st.productname[index]))
                            valid = 1;
                        else
                        {
                            valid = 0;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        printf("\n Name contain invalid character. Please 'Enter' again");
                        getch();
                    }
                }
                while(!valid);

                printf("\n\t\t\t\tEnter New Price: ");
                scanf("%d", &st.price);
                printf("\n\t\t\t\tEnter New Item's Code: "ANSI_COLOR_RESET);
                scanf("%d", &st.productid);

                printf("\n\n\t\t\t\tPress 'Y' to edit the existing record or any key to cancel");
                edit=getche();
                if(edit == 'y' || edit == 'Y')
                {
                    fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                    fflush(stdin);
                    printf("\n\n\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
                }
            }
            else
            {
                fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                fflush(stdin);
            }

        }
        if(!a)
        {
            printf("\n\n\t\t\t\tTHIS ITEM DOESN'T EXIST!!!!");
        }
        fclose(rp);
        fclose(fp);
        remove("male.dat");
        rename("TempFile.dat","male.dat");
        getch();
    }
    edits();
}
edit_female_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb EDIT FEMALE PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
edit_female()
{
    int index, valid;
    char target[40];
    FILE *fp, *rp;
    int a=0;
    int id;
    char edit;
    long int size = sizeof(st);
    if((fp=fopen("female.dat","r+"))==NULL)
    {
        edit_female_graphics();
        printf("NO RECORD FOUND.");
        getch();
        admin_panel();
    }
    else
    {
        system("cls");
        edit_female_graphics();
        rp = fopen("TempFile.dat","a");
        printf("\n\t\t\t\tEnter Item's Code to edit: ");
        scanf("%d",&id);
        fflush(stdin);
        while(fscanf(fp,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                a = 1;
                printf(ANSI_COLOR_GREEN"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb RECORD FOUND \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
                printf("\n\t\t\t\tItem's Name: %s", st.productname);
                printf("\n\t\t\t\tPrice: %d", st.price);
                printf("\n\t\t\t\tItem's Code: %d"ANSI_COLOR_RESET, st.productid);

                printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb NEW RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
                do
                {
                    fflush(stdin);
                    printf("\n\t\t\t\tNew Item's Name\t\t: ");
                    gets(st.productname);
                    st.productname[0] = toupper(st.productname[0]);
                    for (index = 0; index < strlen(st.productname); ++index)
                    {
                        if(isalpha(st.productname[index]))
                            valid = 1;
                        else
                        {
                            valid = 0;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        printf("\n Name contain invalid character. Please 'Enter' again");
                        getch();
                    }
                }
                while(!valid);

                printf("\n\t\t\t\tEnter New Price: ");
                scanf("%d", &st.price);
                printf("\n\t\t\t\tEnter New Item's Code: "ANSI_COLOR_RESET);
                scanf("%d", &st.productid);

                printf("\n\n\t\t\t\tPress 'Y' to edit the existing record or any key to cancel");
                edit=getche();
                if(edit == 'y' || edit == 'Y')
                {
                    fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                    fflush(stdin);
                    printf("\n\n\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
                }
            }
            else
            {
                fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                fflush(stdin);
            }

        }
        if(!a)
        {
            printf("\n\n\t\t\t\tTHIS ITEM DOESN'T EXIST!!!!");
        }
        fclose(rp);
        fclose(fp);
        remove("female.dat");
        rename("TempFile.dat","female.dat");
        getch();
    }
    edits();
}
edit_child_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb EDIT CHILDREN PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
edit_children()
{
    int index, valid;
    char target[40];
    FILE *fp, *rp;
    int a=0;
    int id;
    char edit;
    long int size = sizeof(st);
    if((fp=fopen("child.dat","r+"))==NULL)
    {
        edit_child_graphics();
        printf("NO RECORD FOUND.");
        getch();
        admin_panel();
    }
    else
    {
        system("cls");
        edit_child_graphics();
        rp = fopen("TempFile.dat","a");
        printf("\n\t\t\t\tEnter Item's Code to edit: ");
        scanf("%d",&id);
        fflush(stdin);
        while(fscanf(fp,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                a = 1;
                printf(ANSI_COLOR_GREEN"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb RECORD FOUND \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
                printf("\n\t\t\t\tItem's Name: %s", st.productname);
                printf("\n\t\t\t\tPrice: %d", st.price);
                printf("\n\t\t\t\tItem's Code: %d"ANSI_COLOR_RESET, st.productid);

                printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb NEW RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
                do
                {
                    fflush(stdin);
                    printf("\n\t\t\t\tNew Item's Name\t\t: ");
                    gets(st.productname);
                    st.productname[0] = toupper(st.productname[0]);
                    for (index = 0; index < strlen(st.productname); ++index)
                    {
                        if(isalpha(st.productname[index]))
                            valid = 1;
                        else
                        {
                            valid = 0;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        printf("\n Name contain invalid character. Please 'Enter' again");
                        getch();
                    }
                }
                while(!valid);

                printf("\n\t\t\t\tEnter New Price: ");
                scanf("%d", &st.price);
                printf("\n\t\t\t\tEnter New Item's Code: "ANSI_COLOR_RESET);
                scanf("%d", &st.productid);

                printf("\n\n\t\t\t\tPress 'Y' to edit the existing record or any key to cancel");
                edit=getche();
                if(edit == 'y' || edit == 'Y')
                {
                    fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                    fflush(stdin);
                    printf("\n\n\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
                }
            }
            else
            {
                fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                fflush(stdin);
            }

        }
        if(!a)
        {
            printf("\n\n\t\t\t\tTHIS ITEM DOESN'T EXIST!!!!");
        }
        fclose(rp);
        fclose(fp);
        remove("child.dat");
        rename("TempFile.dat","child.dat");
        getch();
    }
    edits();
}
edit_elec_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb EDIT ELECTRONIC PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
edit_electronics()
{
    int index, valid;
    char target[40];
    FILE *fp, *rp;
    int a=0;
    int id;
    char edit;
    long int size = sizeof(st);
    if((fp=fopen("elec.dat","r+"))==NULL)
    {
        edit_elec_graphics();
        printf("NO RECORD FOUND.");
        getch();
        admin_panel();
    }
    else
    {
        system("cls");
        edit_elec_graphics();
        rp = fopen("TempFile.dat","a");
        printf("\n\t\t\t\tEnter Item's Code to edit: ");
        scanf("%d",&id);
        fflush(stdin);
        while(fscanf(fp,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                a = 1;
                printf(ANSI_COLOR_GREEN"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb RECORD FOUND \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
                printf("\n\t\t\t\tItem's Name: %s", st.productname);
                printf("\n\t\t\t\tPrice: %d", st.price);
                printf("\n\t\t\t\tItem's Code: %d"ANSI_COLOR_RESET, st.productid);

                printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb NEW RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
                do
                {
                    fflush(stdin);
                    printf("\n\t\t\t\tNew Item's Name\t\t: ");
                    gets(st.productname);
                    st.productname[0] = toupper(st.productname[0]);
                    for (index = 0; index < strlen(st.productname); ++index)
                    {
                        if(isalpha(st.productname[index]))
                            valid = 1;
                        else
                        {
                            valid = 0;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        printf("\n Name contain invalid character. Please 'Enter' again");
                        getch();
                    }
                }
                while(!valid);

                printf("\n\t\t\t\tEnter New Price: ");
                scanf("%d", &st.price);
                printf("\n\t\t\t\tEnter New Item's Code: "ANSI_COLOR_RESET);
                scanf("%d", &st.productid);

                printf("\n\n\t\t\t\tPress 'Y' to edit the existing record or any key to cancel");
                edit=getche();
                if(edit == 'y' || edit == 'Y')
                {
                    fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                    fflush(stdin);
                    printf("\n\n\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
                }
            }
            else
            {
                fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                fflush(stdin);
            }

        }
        if(!a)
        {
            printf("\n\n\t\t\t\tTHIS ITEM DOESN'T EXIST!!!!");
        }
        fclose(rp);
        fclose(fp);
        remove("elec.dat");
        rename("TempFile.dat","elec.dat");
        getch();
    }
    edits();
}
edit_discount_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb EDIT DISCOUNT PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
edit_discount()
{
    int index, valid;
    char target[40];
    FILE *fp, *rp;
    int a=0;
    int id;
    char edit;
    long int size = sizeof(st);
    if((fp=fopen("discount.dat","r+"))==NULL)
    {
        edit_discount_graphics();
        printf(ANSI_COLOR_RED"\n\t\t\t\tNO RECORD FOUND."ANSI_COLOR_RESET);
        getch();
        edits();
    }
    else
    {
        system("cls");
        edit_discount_graphics();
        rp = fopen("Temp_discount.dat","a");
        printf("\n\t\t\t\tEnter Item's Code to edit: ");
        scanf("%d",&id);
        fflush(stdin);
        while(fscanf(fp,"%d %s %d %d %d", &st.productid, &st.productname, &st.price, &st.discount, &st.after_discount)!=EOF)
        {
            if(id == st.productid)
            {
                a = 1;
                printf(ANSI_COLOR_GREEN"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb RECORD FOUND \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
                printf("\n\t\t\t\tItem's Code: %d", st.productid);
                printf("\n\t\t\t\tItem's Name: %s", st.productname);
                printf("\n\t\t\t\tOriginal Price: %d", st.price);
                printf(ANSI_COLOR_RED"\n\t\t\t\tDiscount Percentage: %d"ANSI_COLOR_RESET, st.discount);
                printf(ANSI_COLOR_GREEN"\n\t\t\t\tDiscounted Price: %d"ANSI_COLOR_RESET, st.after_discount);

                printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb NEW RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
                do
                {

                    printf("\n\t\t\t\tEnter New Item's Code: "ANSI_COLOR_RESET);
                    scanf("%d", &st.productid);
                    fflush(stdin);
                    printf("\n\t\t\t\tEnter New Item's Name\t\t: ");
                    gets(st.productname);
                    st.productname[0] = toupper(st.productname[0]);
                    for (index = 0; index < strlen(st.productname); ++index)
                    {
                        if(isalpha(st.productname[index]))
                            valid = 1;
                        else
                        {
                            valid = 0;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        printf("\n\t\t\t\tName contain invalid character. Please 'Enter' again");
                        getch();
                    }
                }
                while(!valid);

                printf("\n\t\t\t\tEnter New Price: ");
                scanf("%d", &st.price);
                printf("\n\t\t\t\tEnter New Discount Percentage: ");
                scanf("%d", &st.discount);

                int sum;
                sum = (st.discount*st.price)/100;
                st.after_discount = (st.price-sum);


                printf("\n\n\t\t\t\tPress 'Y' to edit the existing record or any key to cancel");
                edit=getche();
                if(edit == 'y' || edit == 'Y')
                {
                    fprintf(rp,"%d %s %d %d %d", st.productid, st.productname, st.price, st.discount, st.after_discount);
                    fflush(stdin);
                    printf(ANSI_COLOR_BLUE"\n\n\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!"ANSI_COLOR_RESET);
                }
            }
            else
            {
                fprintf(rp,"%d %s %d %d %d", st.productid, st.productname, st.price, st.discount, st.after_discount);
                fflush(stdin);
            }

        }
        if(!a)
        {
            printf("\n\n\t\t\t\tTHIS ITEM DOESN'T EXIST!!!!");
        }
        fclose(rp);
        fclose(fp);
        remove("discount.dat");
        rename("Temp_discount.dat","discount.dat");
        getch();
    }
    edits();
}

//////////////////////////////////////////////////////////////////////// ---------- Read ------------ /////////////////////////////////////////////////////////////////////////////////

read()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb VIEW PRODUCTS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] View Male Products");
    printf("\n\t\t\t\t\t[2] View Female Products");
    printf("\n\t\t\t\t\t[3] View Children Products");
    printf("\n\t\t\t\t\t[4] View Electronics Products");
    printf("\n\t\t\t\t\t[5] View Discounted Products");
    printf("\n\t\t\t\t\t[6] <= Back");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        read_male();

    case 2:
        read_female();

    case 3:
        read_children();

    case 4:
        read_electronics();

    case 5:
        read_discount();

    case 6:
        admin_panel();

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
}
male_item_view()
{
    system("cls");
    FILE *f;
    int i, q;
    if((f=fopen("male.dat","r"))==NULL)
    {
        gotoxy(10,3);
        printf("NO RECORDS");
        printf("\n\t\tPress any key to go back");
        getch();
        read();
    }
    else
    {
        gotoxy(0,5);
        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }
        gotoxy(5,6);
        printf("\t\t\t\tName");
        gotoxy(25,6);
        printf("\t\t\t\tPrice");
        gotoxy(40,6);
        printf("\t\t\t\tCode\n");

        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }

        q = 8;
        while(fscanf(f,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            gotoxy(5,q);
            printf("\t\t\t\t%s", st.productname);
            gotoxy(25,q);
            printf("\t\t\t\t%d", st.price);
            gotoxy(40,q);
            printf("\t\t\t\t%d", st.productid);
            q++;
        }

        printf("\n\t\t\t      ");
        for(i = 0; i < 50; i++)
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
    }
    fclose(f);
}
read_male()
{
    male_item_view();
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\tPress any key to go to back"ANSI_COLOR_RESET);
    getch();
    read();
}
female_item_view()
{
    system("cls");
    FILE *f;
    int i, q;
    if((f=fopen("female.dat","r"))==NULL)
    {
        gotoxy(10,3);
        printf("NO RECORDS");
        printf("\n\t\tPress any key to go back");
        getch();
        read();
    }
    else
    {
        gotoxy(0,5);
        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }
        gotoxy(5,6);
        printf("\t\t\t\tName");
        gotoxy(25,6);
        printf("\t\t\t\tPrice");
        gotoxy(40,6);
        printf("\t\t\t\tCode\n");

        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }

        q = 8;
        while(fscanf(f,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            gotoxy(5,q);
            printf("\t\t\t\t%s", st.productname);
            gotoxy(25,q);
            printf("\t\t\t\t%d", st.price);
            gotoxy(40,q);
            printf("\t\t\t\t%d", st.productid);
            q++;
        }

        printf("\n\t\t\t      ");
        for(i = 0; i < 50; i++)
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
    }
    fclose(f);
}
read_female()
{
    female_item_view();
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\tPress any key to go to back"ANSI_COLOR_RESET);
    getch();
    read();
}
child_item_view()
{
    system("cls");
    FILE *f;
    int i, q;
    if((f=fopen("child.dat","r"))==NULL)
    {
        gotoxy(10,3);
        printf("NO RECORDS");
        printf("\n\t\tPress any key to go back");
        getch();
        read();
    }
    else
    {
        gotoxy(0,5);
        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }
        gotoxy(5,6);
        printf("\t\t\t\tName");
        gotoxy(25,6);
        printf("\t\t\t\tPrice");
        gotoxy(40,6);
        printf("\t\t\t\tCode\n");

        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }

        q = 8;
        while(fscanf(f,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            gotoxy(5,q);
            printf("\t\t\t\t%s", st.productname);
            gotoxy(25,q);
            printf("\t\t\t\t%d", st.price);
            gotoxy(40,q);
            printf("\t\t\t\t%d", st.productid);
            q++;
        }

        printf("\n\t\t\t      ");
        for(i = 0; i < 50; i++)
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
    }
    fclose(f);
}
read_children()
{
    child_item_view();
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\tPress any key to go to back"ANSI_COLOR_RESET);
    getch();
    read();
}
elec_item_view()
{
    system("cls");
    FILE *f;
    int i, q;
    if((f=fopen("elec.dat","r"))==NULL)
    {
        gotoxy(10,3);
        printf("NO RECORDS");
        printf("\n\t\tPress any key to go back");
        getch();
        read();
    }
    else
    {
        gotoxy(0,5);
        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }
        gotoxy(5,6);
        printf("\t\t\t\tName");
        gotoxy(25,6);
        printf("\t\t\t\tPrice");
        gotoxy(40,6);
        printf("\t\t\t\tCode\n");

        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }

        q = 8;
        while(fscanf(f,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            gotoxy(5,q);
            printf("\t\t\t\t%s", st.productname);
            gotoxy(25,q);
            printf("\t\t\t\t%d", st.price);
            gotoxy(40,q);
            printf("\t\t\t\t%d", st.productid);
            q++;
        }

        printf("\n\t\t\t      ");
        for(i = 0; i < 50; i++)
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
    }
    fclose(f);
}
read_electronics()
{
    elec_item_view();
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\tPress any key to go back"ANSI_COLOR_RESET);
    getch();
    read();
}
item_view_discount()
{
    system("cls");
    FILE *f;
    int i, q;
    if((f=fopen("discount.dat","r"))==NULL)
    {
        gotoxy(10,3);
        printf(ANSI_COLOR_RED"\n\t\t\t\tNO RECORDS"ANSI_COLOR_RESET);
        printf("\n\t\t\t\tPress any key to go back.");
        getch();
        read();
    }
    else
    {
        gotoxy(0,5);
        printf("\t\t");
        for(i = 0; i < 88; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }
        gotoxy(5,6);
        printf("\t\tCode");
        gotoxy(15,6);
        printf("\t\tName");
        gotoxy(30,6);
        printf("\t\tOriginal Price\n");
        gotoxy(50,6);
        printf("\t\tDiscount Percentage\n");
        gotoxy(72,6);
        printf("\t\tDiscounted Price\n");

        printf("\t\t");
        for(i = 0; i < 88; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }

        q = 8;
        while(fscanf(f,"%d %s %d %d %d", &st.productid, &st.productname, &st.price, &st.discount, &st.after_discount)!=EOF)
        {
            gotoxy(5,q);
            printf("\t\t%d", st.productid);
            gotoxy(15,q);
            printf("\t\t%s", st.productname);
            gotoxy(30,q);
            printf("\t\t    %d", st.price);
            gotoxy(50,q);
            printf("\t\t       %d%%", st.discount);
            gotoxy(72,q);
            printf("\t\t     %d", st.after_discount);
            q++;
        }

        printf("\n\t\t");
        for(i = 0; i < 88; i++)
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
    }
    fclose(f);
}
read_discount()
{
    item_view_discount();
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\tPress any key to go back!"ANSI_COLOR_RESET);
    getch();
    read();
}

/////////////////////////////////////////////////////////////////////////////////// ---------- Delete ------------- //////////////////////////////////////////////////////////////////////////////////

deleteproduct()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE PRODUCTS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Delete Male Products");
    printf("\n\t\t\t\t\t[2] Delete Female Products");
    printf("\n\t\t\t\t\t[3] Delete Children Products");
    printf("\n\t\t\t\t\t[4] Delete Electronics Products");
    printf("\n\t\t\t\t\t[5] Delete Discounted Products");
    printf("\n\t\t\t\t\t[6] <= Back");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        del_male();

    case 2:
        del_female();

    case 3:
        del_children();

    case 4:
        del_electronics();

    case 5:
        del_discount();

    case 6:
        admin_panel();

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
}
del_male_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE MALE PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
del_male()
{
    char target[40];
    int found=0;
    FILE *sfile, *tfile;
    sfile=fopen("male.dat","r");
    tfile=fopen("TempFile.dat","w+");
    del_male_graphics();
    printf("\n\t\t\t\tEnter Name To Delete: ");
    fflush(stdin);
    scanf("%s",target);
    target[0]=toupper(target[0]);
    while (fscanf(sfile,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
    {
        if(strcmp(target, st.productname)==0)
        {
            found=1;
        }
        else
        {
            fprintf(tfile,"%s %d %d\n", st.productname, st.price, st.productid);
        }
    }
    if(!found)
    {
        del_male_graphics();
        printf(ANSI_COLOR_RED"\n\n\a\t\t\t\t\t\tRecord not found!!"ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\tRecord deleted");
    }
    fclose(sfile);
    fclose(tfile);
    remove("male.dat");
    rename("TempFile.dat","male.dat");

    printf("\n\n\n\t\t\t\tPress any key to go to admin panel!");
    while((st.c = getch()) =='\r');
    deleteproduct();
}
del_female_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE FEMALE PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
del_female()
{
    char target[40];
    int found=0;
    FILE *sfile, *tfile;
    sfile=fopen("female.dat","r");
    tfile=fopen("TempFile.dat","w+");
    del_female_graphics();
    printf("\n\t\t\t\tEnter Name To Delete: ");
    fflush(stdin);
    scanf("%s",target);
    target[0]=toupper(target[0]);
    while (fscanf(sfile,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
    {
        if(strcmp(target, st.productname)==0)
        {
            found=1;
        }
        else
        {
            fprintf(tfile,"%s %d %d\n", st.productname, st.price, st.productid);
        }
    }
    if(!found)
    {
        del_female_graphics();
        printf(ANSI_COLOR_RED"\n\n\a\t\t\t\t\t\tRecord not found!!"ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\tRecord deleted");
    }
    fclose(sfile);
    fclose(tfile);
    remove("female.dat");
    rename("TempFile.dat","female.dat");

    printf("\n\n\n\t\t\t\tPress any key to go to admin panel!");
    while((st.c = getch()) =='\r');
    deleteproduct();
}
del_child_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE CHILDREN PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
del_children()
{
    char target[40];
    int found=0;
    FILE *sfile, *tfile;
    sfile=fopen("child.dat","r");
    tfile=fopen("TempFile.dat","w+");
    del_child_graphics();
    printf("\n\t\t\t\tEnter Name To Delete: ");
    fflush(stdin);
    scanf("%s",target);
    target[0]=toupper(target[0]);
    while (fscanf(sfile,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
    {
        if(strcmp(target, st.productname)==0)
        {
            found=1;
        }
        else
        {
            fprintf(tfile,"%s %d %d\n", st.productname, st.price, st.productid);
        }
    }
    if(!found)
    {
        del_child_graphics();
        printf(ANSI_COLOR_RED"\n\n\a\t\t\t\t\t\tRecord not found!!"ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\tRecord deleted");
    }
    fclose(sfile);
    fclose(tfile);
    remove("child.dat");
    rename("TempFile.dat","child.dat");

    printf("\n\n\n\t\t\t\tPress any key to go to admin panel!");
    while((st.c = getch()) =='\r');
    deleteproduct();
}
del_elec_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE ELECTRONIC PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
del_electronics()
{
    char target[40];
    int found=0;
    FILE *sfile, *tfile;
    sfile=fopen("elec.dat","r");
    tfile=fopen("TempFile.dat","w+");
    del_elec_graphics();
    printf("\n\t\t\t\tEnter Name To Delete: ");
    fflush(stdin);
    scanf("%s",target);
    target[0]=toupper(target[0]);
    while (fscanf(sfile,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
    {
        if(strcmp(target, st.productname)==0)
        {
            found=1;
        }
        else
        {
            fprintf(tfile,"%s %d %d\n", st.productname, st.price, st.productid);
        }
    }
    if(!found)
    {
        del_elec_graphics();
        printf(ANSI_COLOR_RED"\n\n\a\t\t\t\t\t\tRecord not found!!"ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\tRecord deleted");
    }
    fclose(sfile);
    fclose(tfile);
    remove("elec.dat");
    rename("TempFile.dat","elec.dat");

    printf("\n\n\n\t\t\t\tPress any key to go to admin panel!");
    while((st.c = getch()) =='\r');
    deleteproduct();
}
del_discount_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE DISCOUNT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
del_discount()
{
    char target[40];
    int found=0;
    FILE *sfile, *tfile;
    sfile=fopen("discount.dat","r");
    tfile=fopen("Temp_discount.dat","w+");
    del_discount_graphics();
    printf("\n\t\t\t\tEnter Name To Delete: ");
    fflush(stdin);
    scanf("%s",target);
    target[0]=toupper(target[0]);
    while (fscanf(sfile,"%d %s %d %d %d", &st.productid, &st.productname, &st.price, &st.discount, &st.after_discount)!=EOF)
    {
        if(strcmp(target, st.productname)==0)
        {
            found=1;
        }
        else
        {
            fprintf(tfile,"%d %s %d %d %d", st.productid, st.productname, st.price, st.discount, st.after_discount);
        }
    }
    if(!found)
    {
        del_discount_graphics();
        printf(ANSI_COLOR_RED"\n\n\a\t\t\t\t\t\tRecord not found!!"ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\tRecord deleted");
    }
    fclose(sfile);
    fclose(tfile);
    remove("discount.dat");
    rename("Temp_discount.dat","discount.dat");
    printf("\n\n\n\t\t\t\tPress any key to go back!");
    while((st.c = getch()) =='\r');
    deleteproduct();
}


///////////////////////////////////////////////////////////////////////////////////////////// -----------ADD----------- ////////////////////////////////////////////////////////////////////////////////////////////////////////////

add()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD PRODUCTS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Add Male Products");
    printf("\n\t\t\t\t\t[2] Add Female Products");
    printf("\n\t\t\t\t\t[3] Add Children Products");
    printf("\n\t\t\t\t\t[4] Add Electronics Products");
    printf("\n\t\t\t\t\t[5] Add Discounted Products");
    printf("\n\t\t\t\t\t[6] <= Back");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        add_male();

    case 2:
        add_female();

    case 3:
        add_children();

    case 4:
        add_electronics();

    case 5:
        add_discount();

    case 6:
        admin_panel();

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
}
add_male_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD MALE PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
add_male()
{
    int index, valid;
    char c;
    int ID;
    int a=0;
    FILE *fp;
    do
    {
        add_male_graphics();
        fp = fopen("male.dat","a+");

        if((fp = fopen("male.dat","a+"))!=NULL)
        {
I:
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Code: "ANSI_COLOR_RESET);
            scanf("%d",&ID);
            while(fscanf(fp,"%s %d %d", &st.productname, &st.price, &st.productid)!=EOF)
            {
                if(ID == st.productid)
                {
                    do
                    {
                        add_male_graphics();
                        printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t   [*] THE PRODUCT CODE ALREADY EXIST.\n");
                        printf(ANSI_COLOR_GREEN"\n\t\t\t\t   Press any key to continue...\n"ANSI_COLOR_RESET);
                        getch();
                        add_male_graphics();
                        goto I;
                    }
                    while(ID =! st.productid);
                }
            }
            st.productid = ID;
        }

        else
        {
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Product Code: "ANSI_COLOR_RESET);
            scanf("%d", &st.productid);
        }

        do
        {
            fflush(stdin);
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Name: "ANSI_COLOR_RESET);
            fflush(stdin);
            scanf("%[^\n]s", &st.productname);
            st.productname[0]=toupper(st.productname[0]);
            for (index=0; index < strlen(st.productname); ++index)
            {
                if(isalpha(st.productname[index]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf(ANSI_COLOR_RED"\nName contain invalid character. Please 'Enter' again"ANSI_COLOR_RESET);
                getch();
            }
        }
        while(!valid);


        printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Price: "ANSI_COLOR_RESET);
        scanf("%d",&st.price);

        fp=fopen("male.dat","a");
        fprintf(fp,"\n%s %d %d", st.productname, st.price, st.productid);
        fclose(fp);
        printf(ANSI_COLOR_GREEN"\n\n\t\t\t\tPress 'Enter' to add more item or any other key to go back"ANSI_COLOR_RESET);
    }
    while((c = getch()) =='\r');
    add();
}
add_female_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD FEMALE PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
add_female()
{
    int index, valid;
    char c;
    int ID;
    int a=0;
    FILE *fp;
    do
    {
        add_female_graphics();
        fp = fopen("female.dat","a+");

        if((fp = fopen("female.dat","a+"))!=NULL)
        {
I:
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Code: "ANSI_COLOR_RESET);
            scanf("%d",&ID);
            while(fscanf(fp,"%s %d %d", &st.productname, &st.price, &st.productid)!=EOF)
            {
                if(ID == st.productid)
                {
                    do
                    {
                        add_female_graphics();
                        printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t   [*] THE PRODUCT CODE ALREADY EXIST.\n");
                        printf(ANSI_COLOR_GREEN"\n\t\t\t\t   Press any key to continue...\n"ANSI_COLOR_RESET);
                        getch();
                        add_female_graphics();
                        goto I;
                    }
                    while(ID =! st.productid);
                }
            }
            st.productid = ID;
        }

        else
        {
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Product Code: "ANSI_COLOR_RESET);
            scanf("%d", &st.productid);
        }

        do
        {
            fflush(stdin);
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Name: "ANSI_COLOR_RESET);
            fflush(stdin);
            scanf("%[^\n]s", &st.productname);
            st.productname[0]=toupper(st.productname[0]);
            for (index=0; index < strlen(st.productname); ++index)
            {
                if(isalpha(st.productname[index]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf(ANSI_COLOR_RED"\nName contain invalid character. Please 'Enter' again"ANSI_COLOR_RESET);
                getch();
            }
        }
        while(!valid);


        printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Price: "ANSI_COLOR_RESET);
        scanf("%d",&st.price);

        fp=fopen("female.dat","a");
        fprintf(fp,"\n%s %d %d", st.productname, st.price, st.productid);
        fclose(fp);
        printf(ANSI_COLOR_GREEN"\n\n\t\t\t\tPress 'Enter' to add more item or any other key to go back"ANSI_COLOR_RESET);
    }
    while((c = getch()) =='\r');
    add();
}
add_child_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD CHILDREN PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
add_children()
{
    int index, valid;
    char c;
    int ID;
    int a=0;
    FILE *fp;
    do
    {
        add_child_graphics();
        fp = fopen("child.dat","a+");

        if((fp = fopen("child.dat","a+"))!=NULL)
        {
I:
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Code: "ANSI_COLOR_RESET);
            scanf("%d",&ID);
            while(fscanf(fp,"%s %d %d", &st.productname, &st.price, &st.productid)!=EOF)
            {
                if(ID == st.productid)
                {
                    do
                    {
                        add_child_graphics();
                        printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t   [*] THE PRODUCT CODE ALREADY EXIST.\n");
                        printf(ANSI_COLOR_GREEN"\n\t\t\t\t   Press any key to continue...\n"ANSI_COLOR_RESET);
                        getch();
                        add_child_graphics();
                        goto I;
                    }
                    while(ID =! st.productid);
                }
            }
            st.productid = ID;
        }

        else
        {
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Product Code: "ANSI_COLOR_RESET);
            scanf("%d", &st.productid);
        }

        do
        {
            fflush(stdin);
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Name: "ANSI_COLOR_RESET);
            fflush(stdin);
            scanf("%[^\n]s", &st.productname);
            st.productname[0]=toupper(st.productname[0]);
            for (index=0; index < strlen(st.productname); ++index)
            {
                if(isalpha(st.productname[index]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf(ANSI_COLOR_RED"\nName contain invalid character. Please 'Enter' again"ANSI_COLOR_RESET);
                getch();
            }
        }
        while(!valid);


        printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Price: "ANSI_COLOR_RESET);
        scanf("%d",&st.price);

        fp=fopen("child.dat","a");
        fprintf(fp,"\n%s %d %d", st.productname, st.price, st.productid);
        fclose(fp);
        printf(ANSI_COLOR_GREEN"\n\n\t\t\t\tPress 'Enter' to add more item or any other key to go back"ANSI_COLOR_RESET);
    }
    while((c = getch()) =='\r');
    add();
}
add_elec_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD ELECTRONIC PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
add_electronics()
{
    int index, valid;
    char c;
    int ID;
    int a=0;
    FILE *fp;
    do
    {
        add_elec_graphics();
        fp = fopen("elec.dat","a+");

        if((fp = fopen("elec.dat","a+"))!=NULL)
        {
I:
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Code: "ANSI_COLOR_RESET);
            scanf("%d",&ID);
            while(fscanf(fp,"%s %d %d", &st.productname, &st.price, &st.productid)!=EOF)
            {
                if(ID == st.productid)
                {
                    do
                    {
                        add_elec_graphics();
                        printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t   [*] THE PRODUCT CODE ALREADY EXIST.\n");
                        printf(ANSI_COLOR_GREEN"\n\t\t\t\t   Press any key to continue...\n"ANSI_COLOR_RESET);
                        getch();
                        add_elec_graphics();
                        goto I;
                    }
                    while(ID =! st.productid);
                }
            }
            st.productid = ID;
        }

        else
        {
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Product Code: "ANSI_COLOR_RESET);
            scanf("%d", &st.productid);
        }

        do
        {
            fflush(stdin);
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Name: "ANSI_COLOR_RESET);
            fflush(stdin);
            scanf("%[^\n]s", &st.productname);
            st.productname[0]=toupper(st.productname[0]);
            for (index=0; index < strlen(st.productname); ++index)
            {
                if(isalpha(st.productname[index]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf(ANSI_COLOR_RED"\nName contain invalid character. Please 'Enter' again"ANSI_COLOR_RESET);
                getch();
            }
        }
        while(!valid);


        printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Price: "ANSI_COLOR_RESET);
        scanf("%d",&st.price);

        fp=fopen("elec.dat","a");
        fprintf(fp,"\n%s %d %d", st.productname, st.price, st.productid);
        fclose(fp);
        printf(ANSI_COLOR_GREEN"\n\n\t\t\t\tPress 'Enter' to add more item or any other key to go back"ANSI_COLOR_RESET);
    }
    while((c = getch()) =='\r');
    add();
}
adddiscount_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD DISCOUNT PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
add_discount()
{
    int index, valid;
    char c;
    int ID;
    int a=0;
    FILE *fp;
    do
    {
        adddiscount_graphics();
        fp = fopen("discount.dat","a+");

        if((fp = fopen("discount.dat","a+"))!=NULL)
        {
I:
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Code: "ANSI_COLOR_RESET);
            scanf("%d",&ID);
            while(fscanf(fp,"%d %s %d %d %d", &st.productid, &st.productname, &st.price, &st.discount, &st.after_discount)!=EOF)
            {
                if(ID == st.productid)
                {
                    do
                    {
                        adddiscount_graphics();
                        printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t   [*] THE PRODUCT CODE ALREADY EXIST.\n");
                        printf(ANSI_COLOR_GREEN"\n\t\t\t\t   Press any key to continue...\n"ANSI_COLOR_RESET);
                        getch();
                        adddiscount_graphics();
                        goto I;
                    }
                    while(ID =! st.productid);
                }
            }
            st.productid = ID;
        }

        else
        {
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Product Code: "ANSI_COLOR_RESET);
            scanf("%d", &st.productid);
        }

        do
        {
            fflush(stdin);
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Name: "ANSI_COLOR_RESET);
            fflush(stdin);
            scanf("%[^\n]s", &st.productname);
            st.productname[0]=toupper(st.productname[0]);
            for (index=0; index < strlen(st.productname); ++index)
            {
                if(isalpha(st.productname[index]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf(ANSI_COLOR_RED"\nName contain invalid character. Please 'Enter' again"ANSI_COLOR_RESET);
                getch();
            }
        }
        while(!valid);


        printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Original Price: "ANSI_COLOR_RESET);
        scanf("%d",&st.price);

        printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Discount Percentage: "ANSI_COLOR_RESET);
        scanf("%d",&st.discount);
        int sum;

        sum = (st.discount*st.price)/100;

        st.after_discount = (st.price - sum);


        fp=fopen("discount.dat","a");
        fprintf(fp,"\n%d %s %d %d %d", st.productid, st.productname, st.price, st.discount, st.after_discount);
        fclose(fp);
        printf(ANSI_COLOR_GREEN"\n\n\t\t\t\tPress 'Enter' to add more item or any other key to go to admin panel"ANSI_COLOR_RESET);
    }
    while((c = getch()) =='\r');
    admin_panel();
}

/////////////////////////////////////////////////// Invoice //////////////////////////////////////////////////////////

void invoice(char a[], int b, int z, int v)
{
    system("cls");
    int n = 1, i;
    printf(ANSI_COLOR_RED "\n\n\n\t\t\t\t*********************  INVENTORY *********************\n" ANSI_COLOR_RESET);
    printf("\t\t\t\t------------------------------------------------------\n");
    printf("\t\t\t\t  S.N.  |    NAME          |    QUANTITY   |   PRICE \n");
    printf("\t\t\t\t------------------------------------------------------\n");
    for (i = 0; i < n; i++)
        printf("\t\t\t\t   %d    -   %s          -       %d      -    %d\n", v, a, z, b*z);

    FILE *invoice;
    invoice = fopen("invoice.txt", "w");
    fprintf(invoice, "\n\n\t\t\t\t*********************** INVOICE ************************\n");
    fprintf(invoice, "\t\t\t\t---------------------------------------------------------\n");
    fprintf(invoice, "\t\t\t\t|  S.N.  |    NAME          |    QUANTITY   |   PRICE   |\n");
    fprintf(invoice, "\t\t\t\t---------------------------------------------------------\n");
    fprintf(invoice, "\t\t\t\t|  %d    -   %s          -       %d      -     %d  |\n", v, a, z, b);
    fclose(invoice);

    printf("\n\n\t\t\t\t\t Press Any Key To Pay The Amount...");
    getch();
    payment();

}

file()
{
    system("cls");
FILE * fPtr;
    char ch;
    fPtr = fopen("invoice.txt", "r");
    if(fPtr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        ch = fgetc(fPtr);
        putchar(ch);
    }
    while(ch != EOF);

    fclose(fPtr);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

payment()
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
        cod();
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
    Sleep(100);
    MessageBox(0, "  Payment Done Successfully\n  Thank you\n  Stay with us", "Payment", MB_ICONINFORMATION | MB_OK);
    shop();
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
    MessageBox(0, "  Payment Done Successfully\n  Thank you\n  Stay with us", "Payment", MB_ICONINFORMATION | MB_OK);
    shop();
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
    MessageBox(0, "  Payment Done Successfully\n  Thank you\n  Stay with us", "Payment", MB_ICONINFORMATION | MB_OK);
    shop();
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
    MessageBox(0, "  Payment Done Successfully\n  Thank you\n  Stay with us", "Payment", MB_ICONINFORMATION | MB_OK);
    shop();
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
    MessageBox(0, "  Product Placed To Your Address Successfully\n  Thank you\n  Stay with us", "Cash On Delivery", MB_ICONINFORMATION | MB_OK);
    shop();
}

/////////////////////////////////////////////// Shop //////////////////////////////////////////////////////

shop()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_YELLOW"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Shop Option \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Clothing & Accessories");
    printf("\n\t\t\t\t\t[2] Electronics");
    printf("\n\t\t\t\t\t[3] ");
    printf(ANSI_COLOR_RED"Discounted Products!!"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[4] <= Back");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        clothing();

    case 2:
        electronics();

    case 3:
        discounts();

    case 4:
        sign_option();

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
}

discounts()
{
    item_view_discount();
    printf(ANSI_COLOR_GREEN"\n\n\t\t[*] Enter '0' to back"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Discounts \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    FILE *buy;
    long int size = sizeof(st);
    int id, z;

    printf("\n\n\t\tEnter item's code to buy: ");
    scanf("%d", &id);

    if(id == 0)
    {
        shop();
    }

    else
    {
        buy = fopen("discount.dat","r+");
        printf("\n\t\tEnter the ammount: ");
        scanf("%d",&z);
        fflush(stdin);
        while(fscanf(buy,"%d %s %d %d %d", &st.productid, &st.productname, &st.price, &st.discount, &st.after_discount)!=EOF)
        {
            if(id == st.productid)
            {
                invoice(st.productname, st.after_discount, z, st.productid);
            }
        }
    }
}
electronics()
{
    elec_item_view();
    FILE *buy;
    long int size = sizeof(st);
    int id, z;
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t[*] Enter '0' to back"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\tEnter item's code to buy: ");
    scanf("%d", &id);

    if(id == 0)
    {
        shop();
    }

    else
    {
        buy = fopen("elec.dat","r+");
        printf("\n\t\t\t\tEnter the ammount: ");
        scanf("%d",&z);
        fflush(stdin);
        while(fscanf(buy,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                invoice(st.productname, st.price, z, st.productid);
            }
        }
    }
}

clothing()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_BLUE"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Clothing & Accessories \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t\t[1] Male Products");
    printf("\n\t\t\t\t\t\t[2] Female Products");
    printf("\n\t\t\t\t\t\t[3] Children Products");
    printf("\n\t\t\t\t\t\t[4] <= Back");
    printf("\n\t\t\t\t_______________________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    case 1:
        male();

    case 2:
        female();

    case 3:
        children();

    case 4:
        shop();

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
}

male()
{
    male_item_view();
    FILE *buy;
    long int size = sizeof(st);
    int id, z;
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t[*] Enter '0' to back"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\tEnter item's code to buy: ");
    scanf("%d", &id);

    if(id == 0)
    {
        clothing();
    }

    else
    {
        buy = fopen("male.dat","r+");
        printf("\n\t\t\t\tEnter the ammount: ");
        scanf("%d",&z);
        fflush(stdin);
        while(fscanf(buy,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                invoice(st.productname, st.price, z, st.productid);
            }
        }
    }
}
female()
{
    female_item_view();
    FILE *buy;
    long int size = sizeof(st);
    int id, z;
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t[*] Enter '0' to back"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\tEnter item's code to buy: ");
    scanf("%d", &id);

    if(id == 0)
    {
        clothing();
    }

    else
    {
        buy = fopen("female.dat","r+");
        printf("\n\t\t\t\tEnter the ammount: ");
        scanf("%d",&z);
        fflush(stdin);
        while(fscanf(buy,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                invoice(st.productname, st.price, z, st.productid);
            }
        }
    }
}
children()
{
    child_item_view();
    FILE *buy;
    long int size = sizeof(st);
    int id, z;
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t[*] Enter '0' to back"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\tEnter item's code to buy: ");
    scanf("%d", &id);

    if(id == 0)
    {
        clothing();
    }

    else
    {
        buy = fopen("child.dat","r+");
        printf("\n\t\t\t\tEnter the ammount: ");
        scanf("%d",&z);
        fflush(stdin);
        while(fscanf(buy,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                invoice(st.productname, st.price, z, st.productid);
            }
        }
    }
}

/////////////////////////////////////////////// Main //////////////////////////////////////////////////////

int main()
{
    graphics();
    Sleep(300);
    menu();
    getch();
}

