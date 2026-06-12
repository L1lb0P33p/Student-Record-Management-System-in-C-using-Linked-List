#include "student.h"

void stud_reverse(void)
{
    struct student *prev = NULL;
    struct student *curr = hptr;
    struct student *next;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    hptr = prev;

    printf("\nList Reversed Successfully\n");

    stud_show();
}
