#include "student.h"

void stud_load(void)
{
    FILE *fp;
    struct student *newnode, *temp;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("No Database File Found\n");
        return;
    }

    while(1)
    {
        newnode = malloc(sizeof(struct student));

        if(newnode == NULL)
        {
            printf("Memory Allocation Failed\n");
            fclose(fp);
            return;
        }

        if(fscanf(fp,"%d %s %f",&newnode->rollno,newnode->name,&newnode->percentage) != 3)
        {
            free(newnode);
            break;
        }

        newnode->next = NULL;

        if(hptr == NULL)
        {
            hptr = newnode;
        }
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
