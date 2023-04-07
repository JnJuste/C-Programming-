#include<stdio.h>
struct Employee
{
    int id,exp;
    char name[15];
}emp;
void record()
{
    FILE *p;
    printf("Enter ID, Name and Experience:...");
    scanf("%d%s%d",&emp.id,emp.name,&emp.exp);
    p=fopen("EmployeesC.txt","a");
    fprintf(p,"%d\t%s\t%d\n",emp.id,emp.name,emp.exp);
    fclose(p);
}
void display()
{
    FILE *p;
    p=fopen("EmployeesC.txt","r");
    printf("\nID\tName\tExperience\n==\t====\t==========\n");
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%d\n",&emp.id,emp.name,&emp.exp);
        printf("%d\t%s\t%d\n",emp.id,emp.name,emp.exp);
    }
    fclose(p);
}
void search()
{
    FILE *p;
    int key;
    printf("Enter the ID to search:...");
    scanf("%d",&key);
    p=fopen("EmployeesC.txt","r");
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%d\n",&emp.id,emp.name,&emp.exp);
        if(emp.id==key)
        {
            printf("Her/His name is: %s and she/he has %dyears of experience\n",emp.name,emp.exp);
            fclose(p);
            return;
        }

    }
    printf("ID not found");
    fclose(p);
}
void sort()
{
    FILE *p;
    int c=0,i,j,min,imin;
    struct Employee e[100],temp;
    p=fopen("EmployeesC.txt","r");
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%d\n",&e[c].id,e[c].name,&e[c].exp);
        c++;
    }
    if(c==0)
    {
        printf("The file is empty");
    }
    else
    {
        for(i=0;i<c-1;i++)
        {
            min=e[i].exp;
            imin=i;
            for(j=i+1;j<c;j++)
            {
                if(e[j].id<min)
                {
                    min=e[j].exp;
                    imin=j;
                }
            }
            temp=e[i];
            e[i]=e[imin];
            e[imin]=temp;
        }
        printf("\nID\tName\tExperience\n==\t====\t==========\n");
        for(i=0;i<c;i++)
        {
            printf("%d\t%s\t%d\n",e[i].id,e[i].name,e[i].exp);
        }
    }
    fclose(p);
}
main()
{
    int c;
    do
    {
        printf("\nChoose:\n1. Record\n2. Display\n3. Search\n4. Sort\n0. Exit\nMake a choice:...");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            record();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;
        case 0:
            printf("Bye");
            break;
        default:
            printf("Wrong choice...\n");
        }
    }while(c!=0);

}
