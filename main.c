#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

void Add_Student();
void show_record();
void searchstudent();

struct student{
     char FirstName[20];
     char lastName[20];
     int RollNo;
     int Class;
     char Address[50];
     int percentage;
};

int main(){
    int choice;
    while(choice != 3)
    {
        choice:
        printf("\n\n\tSTUDENT INFORMATION\n\nPRESS 1 : Add Student detail\nPRESS 2 : Show All Student detail\nPRESS 3 : search Any Student\nPRESS 4: Exit\n");
        scanf("%i",&choice);
        switch(choice)
        {
        case 1:
            system("cls");
            Add_Student();
            system("cls");
            break;
        case 2:
            system("cls");
            show_record();
            getch();
            system("cls");
            break;
        case 3:
            system("cls");
            searchstudent();
             getch();
            system("cls");
            break;
        default :
         system("cls");
         printf("\n\t\t\t\t\tEnter a valid number\n\n");
         printf("\t\t\t\tPress any key to continue.......");
       // system("cls");
         goto choice;
        }
    }
}

void Add_Student(){
    char str[20];
    int n,i;
    FILE *fptr;
    struct student info[50];
    //do{
    printf("how many student enter: ");
    scanf("%i",&n);
     printf("\n--------------\n");
     fptr = fopen("student.txt","w+");

     for(i = 0;i<n ;i++)
        {
        printf("\nEnter First Name:");
        scanf("%s",&info[i].FirstName);
        printf("Enter Last Name:");
        scanf("%s",&info[i].lastName);
        printf("Enter Roll No:");
        scanf("%i",&info[i].RollNo);
        printf("Enter Class:");
        scanf("%i",&info[i].Class);
        printf("Enter Address: \n");
        scanf ("%s",&info[i].Address);
       // fgets(info.Address, sizeof(info.Address), stdin);
        printf("Enter percentage:");
        scanf("%i",&info[i].percentage);
        printf("-------------------------------\n");
        if (fptr == NULL)
        {
            fprintf(stderr,"file not open!");
        }
        else
        {
            printf("Save Information!\n");
        }
        fwrite(&info[i],sizeof(struct student),1,fptr);
        }
        fclose(fptr);
}


void show_record(){
FILE *fptr;
struct student info;
fptr = fopen("student.txt","r");
printf("Show All Student\n");
if(fptr == NULL)
{
    fprintf(stderr,"file Error!");
}
else
{
    printf("RECORDS");
}
while(fread(&info,sizeof(struct student),1,fptr))
//fread(&info,sizeof(struct student),1,fptr);
{
    printf("Student Name : %s %s \n",info.FirstName,info.FirstName);
    printf("Student Roll No : %i\n",info.RollNo);
}
fclose(fptr);
getch();
}


void searchstudent(){
       struct student info;
      FILE *fp;
      int roll_no,found=0;
    fp=fopen("student.txt","r");
    printf("SEARCH STUDENTS RECORD\n");
    printf("Enter the roll no : ");
    scanf("%i",&roll_no);
    while(fread(&info,sizeof(struct student),1,fp)>0)
        {
        if(info.RollNo==roll_no)
        {
        found=1;
        printf("\nStudent Name : %s %s",info.FirstName,info.lastName);
        printf("\nRoll NO        : %d",info.RollNo);
        printf("\nClass          : %s",info.Class);
        printf("\nAddress        : %s",info.Address);
        printf("\nPercentage     : %i%",info.percentage);
        printf("\n---------------\n");
         }
         }
    if(!found)
    {
       printf("\n\t\t\tRecord not found\n");
    }
    fclose(fp);
    getch();
}
