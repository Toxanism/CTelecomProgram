#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

FILE * fptr;

struct customerDate
{
    int ID;
    char name[50];
    char phoneNumber[50];
    double billing;
};

void addRecord()
{
    fptr = fopen("/home/toxan/CTelecom/data/UserData.txt", "a");
    system("clear");
    printf("Enter the ID, name, phone-number, and billing of the customer: ");
    struct customerDate * user = malloc (sizeof(user));
    printf("\nID: ");
    scanf("%d", &user->ID);
    getchar();
    printf("\nName: ");
    gets(user->name);
    printf("\nPhone-Number: ");
    gets(user->phoneNumber);
    printf("\nBilling: ");
    gets(user->billing);
    printf("\nSave changes? (y/N): ");
    char decision = getchar();
    getchar();
    if (toupper(decision) == 'Y')
    {
        fprintf(fptr, "%d %s %s %f\n",  user->ID, user->name, user->phoneNumber, user->billing);
        fclose(fptr);
    }
    else
    {
        return;
    }
    free(user);
}

void dataModify()
{
    printf("dataModify");
}

void dataSearch()
{
    printf("dataSearch");
}

void dataDelete()
{
    printf("dataDelete");
}

int main()
{
    printf("################### C-Telecom Mini Project ###################\n\n\n");
    printf("Press enter to continue\n");
    getchar();
    int quit = 0;
    while(quit != 1)
    {
        system("clear");
        printf(" A - Add record \n M - Modify record \n S - Search record \n D - Delete record \n X - Exit \n\n\n\n");
        printf("Enter command: ");
        char decision = getchar();
        switch(toupper(decision))
        {
        case 'A':
            addRecord();
            break;
        case 'M':
            dataModify();
            break;
        case 'S':
            dataSearch();
            break;
        case 'D':
            dataDelete();
            break;
        case 'X':
            quit = 1;
            exit(1);
        default:
            printf("%c : Is an unknown command \n", decision);
            sleep(1);
            system("clear");
            continue;
        }
    }
    return 0;
}
