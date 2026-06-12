#include "student.h"

void stud_read(void)
{
    FILE *fp;
    struct student *newnode, *temp;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
        return;

    while(1)
    {
        newnode = malloc(sizeof(struct student));

        if(fread(newnode, sizeof(struct student), 1, fp) != 1)
        {
            free(newnode);
            break;
        }

        newnode->next = NULL;

        if(hptr == NULL)
            hptr = newnode;
        else
        {
            temp = hptr;

            while(temp->next)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    fclose(fp);
}
