#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void enteremployeeinfo(struct emp e);
void listemployeeinfo(struct emp e);
void modemployeeinfo(struct emp e);
void delemployeeinfo(struct emp e);

FILE *fp, *ft;
    int i;

    struct emp
    {
        char name[40]; ///name of employee
        int age; /// age of employee
        float bs; /// basic salary of employee
    };

    struct emp e;
    char empname[40];
    long int recsize; /// size of each record of employee

    recsize = sizeof(e);

    fp = fopen("EMPREC.txt","r");
    if(fp == NULL)
    {
        fp = fopen("EMPREC.txt","w");
        if(fp == NULL)
        {
            printf("Cannot open file");
        }
        else{
            exit(1);
        }
    }

void menu(){

    int choice;

    do{
        printf("\n ***** EMPLOYEE DATA *****");
        printf("\n\n\n\t 1. Add Record \n");
        printf("\n\n\n\t 2. List Records \n");
        printf("\n\n\n\t 3. Modify Records \n");
        printf("\n\n\n\t 4. Delete Records \n");
        printf("\n\n\n\t 5. Exit \n");
        printf("Your Choice: ");
        scanf("%c", &choice);

        switch(choice)
        {
    case '1':
        printf("\n  Add Record ");
        enteremployeeinfo(e);
        break;

    case '2':
        printf("\n  List Record ");
        listemployeeinfo(e);
        break;

    case '3':
        printf("\n  Modify Record ");
        modemployeeinfo(e);
        break;

    case '4':
        printf("\n  Delete Record ");
        delemployeeinfo(e);
        break;

    case '5':
            exit(0);
            break;

    default:
            printf("\n Invalid choice...");
            break;
        }
    }while(choice != 5);
}

void enteremployeeinfo(struct emp e){
    /*FILE *fp, *ft;
    int i;

    struct emp
    {
        char name[40]; ///name of employee
        int age; /// age of employee
        float bs; /// basic salary of employee
    };

    struct emp e;
    char empname[40];
    long int recsize; /// size of each record of employee

    fp = fopen("EMPREC.txt","r");
    if(fp == NULL)
    {
        fp = fopen("EMPREC.txt","w");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }

    recsize = sizeof(e);*/

               for (i=0;i<2;i++){
                printf("\nEnter name: ");
                scanf("%s",e.name);
                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\nEnter basic salary: ");
                scanf("%f", &e.bs);
               }
                fwrite(&e,recsize,1,fp);

            }

void listemployeeinfo(struct emp e){
            while(fread(&e,recsize,1,fp)==1)
            {

                printf("\n Employee Name : %s ",e.name);   /// print the name
                printf("\n Employee Age : %d ",e.age);     /// print the age
                printf("\n Employee Basic Salary : %.2f ",e.bs); /// print the basic salary
        }
    }

void modemployeeinfo(struct emp e){

                 printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.name,empname) == 0)
                    {
                        printf("\nEnter new name,age and bs: ");
                        scanf("%s%d%f",e.name,&e.age,&e.bs);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);

 }
                }
 }

void delemployeeinfo(struct emp e){

                printf("\nEnter name of employee to delete: ");
                scanf("%s",empname);
                ft = fopen("Temp.text","w");
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)
                {
                    if(strcmp(e.name,empname) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMPREC.txt");
                rename("Temp.txt","EMPREC.txt");
                fp = fopen("EMPREC.txt", "r");
 }


int main()
{
    menu();
    return 0;
}


