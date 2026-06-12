#include "student.h"

void stud_sort(void)
{
    struct student *p1, *p2;
    struct student temp;
    char ch;

    if(hptr == NULL || hptr->next == NULL)
    {
        printf("Not enough records to sort\n");
        return;
    }

    printf("\nEnter\n");
    printf("N/n : Sort with Name\n");
    printf("P/p : Sort with Percentage\n");
    printf("Enter Your Choice : ");
    scanf(" %c", &ch);

    switch(ch)
    {
        case 'N':
        case 'n':

            for(p1 = hptr; p1; p1 = p1->next)
            {
                for(p2 = p1->next; p2; p2 = p2->next)
                {
                    if(strcmp(p1->name, p2->name) > 0)
                    {
                        temp.rollno = p1->rollno;
                        strcpy(temp.name, p1->name);
                        temp.percentage = p1->percentage;

                        p1->rollno = p2->rollno;
                        strcpy(p1->name, p2->name);
                        p1->percentage = p2->percentage;

                        p2->rollno = temp.rollno;
                        strcpy(p2->name, temp.name);
                        p2->percentage = temp.percentage;
                    }
                }
            }

            printf("Sorted by Name Successfully\n");
	    stud_show();
            break;

        case 'P':
        case 'p':

            for(p1 = hptr; p1; p1 = p1->next)
            {
                for(p2 = p1->next; p2; p2 = p2->next)
                {
                    if(p1->percentage < p2->percentage)
		    {
                        temp.rollno = p1->rollno;
                        strcpy(temp.name, p1->name);
                        temp.percentage = p1->percentage;

                        p1->rollno = p2->rollno;
		       	strcpy(p1->name, p2->name);
                        p1->percentage = p2->percentage;

                        p2->rollno = temp.rollno;
                        strcpy(p2->name, temp.name);
                        p2->percentage = temp.percentage;
                    }
                }
            }

            printf("Sorted by Percentage Successfully\n");
	    stud_show();
	    break;

        default:
            printf("Invalid Choice\n");
    }
}
