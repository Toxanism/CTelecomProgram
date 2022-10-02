#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

FILE * fptr;
FILE * fptr2;

#define MAX 256

char buff[100];

struct custInfo
{
    int ID;
    char name[50];
    char phone[50];
    double billing;
};

void add()
{
    fptr = fopen ("{User directory}", "a");
    struct custInfo user;
    printf("ID:\n");
    scanf ("%d", &user.ID);
    getchar();
    printf("Name:\n");
    gets (user.name);
    printf("Phone:\n");
    scanf ("%s", user.phone);
    getchar();
    printf("Billing:\n");
    scanf ("%lf", &user.billing);
    getchar();
    fprintf (fptr, "%d %s %s %.2lf \n", user.ID, user.name, user.phone, user.billing);
    fclose (fptr);
}


void search()
{

    fptr = fopen ("{User directory}", "r");
    while (fgets(buff, sizeof(buff), fptr))
    {
        printf("%s\n", buff);
    }
    fclose(fptr);
    getchar();

}

void deleteData()
{
    char fname[MAX];
    char str[MAX];
    char ch;
    int loca, ctr = 0;
    fptr = fopen ("{User directory}", "r");
    fptr2 = fopen ("{User directory}", "w");
    printf("Line: ");
    scanf("%d", &loca);
    getchar();
    while (!feof(fptr))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr);
            if (!feof(fptr))
            {
                ctr++;
                if (ctr != loca)
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
    fclose(fptr);
    fclose(fptr2);
    remove("{User directory}");
    rename("{User directory}", "{User directory}");
}

int main()
{
    int exit = 0;
    while (exit != 1)
    {
        system("cls");
        printf(" A - Add \n S - Search \n D - Delete \n X - Leave \n");
        printf ("Enter Command: ");
        char dec = 'X';
        scanf("%c", &dec);
        getchar();
        switch(toupper(dec))
        {
        case 'A':
            add();
            break;
        case 'S':
            search();
            break;
        case 'D':
            deleteData();
            break;
        case 'X':
            exit = 1;
            break;
        default :
            printf ("%c: Is an unknown command", dec);
            sleep(1);
            continue;
        }

    }
    return 0;
}
