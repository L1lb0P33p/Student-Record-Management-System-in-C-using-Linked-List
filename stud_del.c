#include "student.h"
#include <unistd.h>
void stud_del(void)
{
    char choice;
    int roll;
    char name[50];

    struct student *temp, *prev;

    printf("\nR/r : Enter Rollno to Delete\n");
    printf("N/n : Enter Name to Delete\n");
    printf("Enter Your Choice : ");
    scanf(" %c", &choice);

    if(choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number : ");
        scanf("%d", &roll);

        temp = hptr;
        prev = NULL;

        while(temp)
        {
            if(temp->rollno == roll)
            {
                if(prev == NULL)
                    hptr = temp->next;
                else
                    prev->next = temp->next;

                free(temp);
		system("clear");
		printf("Deleting.........\n");
		sleep(1);
                system("clear");
                printf("Record Deleted Successfully\n");
		system("clear");
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        printf("Roll Number Not Found\n");
    }

    else if(choice == 'N' || choice == 'n')
    {
        printf("Enter Name : ");
        scanf(" %[^\n]", name);

        temp = hptr;

        printf("\nMatching Records:\n");
        printf("---------------------------------\n");
        printf("RollNo\tName\t\tPercentage\n");
        printf("---------------------------------\n");

        while(temp)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("%d\t%s\t\t%.2f\n",
                        temp->rollno,
                        temp->name,
                        temp->percentage);
            }
            temp = temp->next;
        }

        printf("\nEnter Roll Number To Delete : ");
        scanf("%d", &roll);

        temp = hptr;
        prev = NULL;

        while(temp)
        {
            if(temp->rollno == roll)
            {
                if(prev == NULL)
                    hptr = temp->next;
                else
                    prev->next = temp->next;

                free(temp);
		system("clear");
		printf("Deleting...........\n");
		sleep(1);
		system("clear");

                printf("Record Deleted Successfully\n");
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        printf("Record Not Found\n");
    }

    else
    {
        printf("Invalid Choice\n");
    }
}
