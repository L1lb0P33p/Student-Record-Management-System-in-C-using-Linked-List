#include "student.h"

void stud_save(void)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.txt", "w");

    if(fp == NULL)
    {
        printf("Unable to Open File\n");
        return;
    }

    temp = hptr;

    while(temp)
    {
        fprintf(fp,"%d %s %.2f\n",
                temp->rollno,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }

    fclose(fp);

    printf("\nRecords Saved Successfully\n");
}