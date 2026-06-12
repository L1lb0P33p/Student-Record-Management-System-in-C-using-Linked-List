#include "student.h"

void stud_show(void)
{
    struct student *temp;

    if(hptr == NULL)
    {
        printf("\nNo Records Available\n");
        return;
    }

    printf("\n+-------------------------------------------------+\n");
    printf("|Roll No\tName\t\tPercentage                       \n");
    printf("+-------------------------------------------------+\n");

    temp = hptr;

    while(temp)
    {
        printf("|%d\t\t%-15s\t%.2f\n",
               temp->rollno,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("+-------------------------------------------------+\n");
}
