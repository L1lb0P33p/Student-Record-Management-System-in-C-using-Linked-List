#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

struct student *hptr;

void stud_add(void);
void stud_del(void);
void stud_show(void);
void stud_mod(void);
void stud_save(void);
void stud_read(void);
void stud_load(void);
void stud_sort(void);
void stud_reverse(void);
void stud_deleteall(void);


