#include "student.h"

void stud_deleteall(void)
{
    struct student *temp;

    while(hptr)
    {
        temp = hptr;
        hptr = hptr->next;
        free(temp);
    }

    printf("\nAll Records Deleted Successfully\n");
}
