#include "student.h"

void stud_mod(void)
{
    struct student *temp, *ptr = NULL;
    int roll;
    float per;
    char name[50];
    char ch, op;

    if(hptr == NULL)
    {
        printf("\nNo Records Available\n");
        return;
    }

    printf("\nEnter which record to search for modification\n");
    printf("R/r : To search Rollno\n");
    printf("N/n : To search Name\n");
    printf("P/p : To search Percentage\n");
    printf("Enter Your Choice : ");
    scanf(" %c", &ch);

    switch(ch)
    {
        case 'R':
        case 'r':
            printf("Enter Roll No : ");
            scanf("%d", &roll);

            temp = hptr;
            while(temp)
            {
                if(temp->rollno == roll)
                {
                    ptr = temp;
                    break;
                }
                temp = temp->next;
            }
            break;

        case 'N':
        case 'n':
            printf("Enter Name : ");
            scanf(" %[^\n]", name);

            temp = hptr;
            while(temp)
            {
                if(strcmp(temp->name, name) == 0)
                    printf("%d\t%s\t%.2f\n",
                           temp->rollno,
                           temp->name,
                           temp->percentage);

                temp = temp->next;
            }

            printf("Enter Rollno to Modify : ");
            scanf("%d", &roll);

            temp = hptr;
            while(temp)
            {
                if(temp->rollno == roll)
                {
                    ptr = temp;
                    break;
                }
                temp = temp->next;
            }
            break;

        case 'P':
        case 'p':
            printf("Enter Percentage : ");
            scanf("%f", &per);

            temp = hptr;
            while(temp)
            {
                if(temp->percentage == per)
                    printf("%d\t%s\t%.2f\n",
                           temp->rollno,
                           temp->name,
                           temp->percentage);

                temp = temp->next;
            }

            printf("Enter Rolno to Modify : ");
            scanf("%d", &roll);

            temp = hptr;
            while(temp)
            {
                if(temp->rollno == roll)
                {
                    ptr = temp;
                    break;
                }
                temp = temp->next;
            }
            break;

        default:
            printf("Invalid Choice\n");
            return;
    }

    if(ptr == NULL)
    {
        printf("Record Not Found\n");
        return;
    }

    printf("\nEnter which record to modify\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice : ");
    scanf(" %c", &op);

    switch(op)
    {
        case 'N':
        case 'n':
            printf("Enter New Name : ");
            scanf(" %[^\n]", ptr->name);
            break;

        case 'P':
        case 'p':
            printf("Enter New Percentage : ");
            scanf("%f", &ptr->percentage);
            break;

        default:
            printf("Invalid Choice\n");
            return;
    }

    printf("\nRecord Modified Successfully\n");
}
