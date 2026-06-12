#include "student.h"

struct student *hptr = NULL;

int main()
{
    char op;

    stud_load();

    while(1)
    {
	printf("\t\t\t\t\t+---------------------------+\n");
        printf("\t\t\t\t\t|*** STUDENT RECORD MENU ***|\n");
	printf("\t\t\t\t\t+---------------------------|\n");
        printf("\t\t\t\t\t|A/a : Add New Record       |\n");
        printf("\t\t\t\t\t|D/d : Delete A Record      |\n");
        printf("\t\t\t\t\t|S/s : Show the List        |\n");
        printf("\t\t\t\t\t|M/m : Modify A Record      |\n");
        printf("\t\t\t\t\t|V/v : Save                 |\n");
        printf("\t\t\t\t\t|T/t : Sort the List        |\n");
        printf("\t\t\t\t\t|L/l : Delete All Records   |\n");
        printf("\t\t\t\t\t|R/r : Reverse the List     |\n");
        printf("\t\t\t\t\t|E/e : Exit                 |\n");
	printf("\t\t\t\t\t+---------------------------+\n");
        printf("\nEnter Your Choice: ");
        scanf(" %c", &op);

        switch(op)
        {
            case 'A':
            case 'a':
                stud_add();
                break;

            case 'D':
            case 'd':
                stud_del();
                break;

            case 'S':
            case 's':
                stud_show();
                break;

            case 'M':
            case 'm':
                stud_mod();
                break;

            case 'V':
            case 'v':
                stud_save();
                break;

            case 'T':
            case 't':
                stud_sort();
                break;

            case 'L':
            case 'l':
                stud_deleteall();
                break;

            case 'R':
            case 'r':
                stud_reverse();
                break;

            case 'E':
            case 'e':
            {
                char ch;

                printf("\t\t\t\tS/s : Save and Exit\n");
                printf("\t\t\t\tE/e : Exit Without Saving\n");
                printf("\t\t\t\tEnter Your Choice: ");
                scanf(" %c", &ch);

                if(ch=='S' || ch=='s')
                {
                    stud_save();
                    return 0;
                }
                else if(ch=='E' || ch=='e')
                {
                    return 0;
                }
                break;
            }

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
