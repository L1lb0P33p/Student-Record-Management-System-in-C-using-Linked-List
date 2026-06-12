#include "student.h"
#include <unistd.h>

int generate_rollno()
{
    int roll = 1;
    struct student *temp;

    while(1)
    {
        int found = 0;
        temp = hptr;

        while(temp)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found == 0)
            return roll;

        roll++;
    }
}

void stud_add(void)
{
    struct student *newnode, *temp;
    char op;
    do
    {
    newnode = (struct student *)malloc(sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    newnode->rollno = generate_rollno();

    printf("Enter Name : ");
    scanf(" %[^\n]", newnode->name);
    while(1)
    {

    printf("Enter Percentage : ");
    scanf("%f", &newnode->percentage);
    if(newnode->percentage >= 0 && newnode->percentage <= 100)
	    break;
   printf("Invalid percentage!\n");
  printf("percentage must be between 0 and 100 \n"); 
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
    printf("\t\t\t\t\t\tUpdating..............\n");
    sleep(1);
    system("clear");

    printf("\nRecord Added Successfully\n");
    printf("Generated Roll No : %d\n", newnode->rollno);
     printf("\nDo you want to add another record (y/n): ");
        scanf(" %c", &op);
	system("clear");

    }while(op == 'Y' || op == 'y');
}
