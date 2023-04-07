#include<stdio.h>
#include<string.h>

struct worker
{
    int id;
    char name[20];
    int nberofexp;
    char add[20];

}wo;
void worker_record()
{
    FILE *b;
    b=fopen("worker.txt","a");
    printf("Enter Worker ID, Worker Name, Number of Experience and Address:\n");
    scanf("%d%s%d%s",&wo.id,&wo.name,&wo.nberofexp,&wo.add);

    fprintf(b,"%d\t%s\t%d\t%s\n",wo.id,wo.name,wo.nberofexp,wo.add);
    fclose(b);
    printf("Worker details entered successfuly\n");
    int back;
    printf("Return to Main Menu by pressing any number:");
    scanf("%d",&back);
    main(back);

}
void worker_display()
{
    FILE *b;
    b=fopen("worker.txt","r");
    printf("\n\t\t\t\tAll Workers of The Company:\n");
    printf("\n\t\t\t\t____________________________\n");
    while(!feof(b))
    {
        fscanf(b,"%d\t%s\t%d\t%s\t",&wo.id,&wo.name,&wo.nberofexp,&wo.add);
        printf("%d\t%s\t%d\t%s\t\n",wo.id,wo.name,wo.nberofexp,wo.add);
    }
    fclose(b);
    int back;
    printf("Return to Main Menu by pressing any number:");
    scanf("%d",&back);
    main(back);
}
void worker_search()
{
    FILE *b;
    int sis;
    printf("\n\t\t\t\tEnter Worker ID:\n");
    scanf("%d",&sis);
    b=fopen("worker.txt","r");
    while(!feof(b))
    {
        fscanf(b,"%d\t%s\t%d\t%s\t",&wo.id,&wo.name,&wo.nberofexp,&wo.add);
        if(wo.id==sis)
        {
            printf("\n\t\t\t\tThe Worker is:\n");
            printf("%d\t%s\t%d\t%s\t\n",wo.id,wo.name,wo.nberofexp,wo.add);
        }
    }
    fclose(b);
    if(wo.id!=sis)
    {
        printf("\n\t\t\t\THE Worker with ID [%d] is not found\n",sis);
    }
    int back;
    printf("Return to Main Menu by pressing any number:");
    scanf("%d",&back);
    main(back);

}
void worker_delete()
{
  struct worker clear;
  FILE *b;
  FILE *d;
  b=fopen("worker.txt","r");
  int del;
  int rel=0;
  printf("Enter the Worker ID to Delete:\n");
  scanf("%d",&del);
  d=fopen("clear.txt","w");
  while(!feof(b))
  {
    fscanf(b,"%d\t%s\t%d\t%s\t\n",&wo.id,&wo.name,&wo.nberofexp,&wo.add);
    if(wo.id!=del)
    {
        fprintf(d,"%d\t%s\t%d\t%s\t\n",wo.id,wo.name,wo.nberofexp,wo.add);
    }
    else
    {
        rel=1;
    }
  }
  fclose(b);
  fclose(d);
  if (rel==1)
  {
      b=fopen("worker.txt","w");
      d=fopen("clear.txt","r");
      while(!feof(d))
      {
          fscanf(d,"%d\t%s\t%d\t%s\t\n",&wo.id,&wo.name,&wo.nberofexp,&wo.add);
          fprintf(b,"%d\t%s\t%d\t%s\t\n",wo.id,wo.name,wo.nberofexp,wo.add);

      }
      fclose(b);
      fclose(d);
      printf("WORKER INFOS DELETED\n");
  }
  else if(rel==0)
  {
      printf("The Worker is not found\n");
  }
    int back;
    printf("Return to Main Menu by pressing any number:");
    scanf("%d",&back);
    main(back);
}
void worker_sort()
{
 FILE *b;
 struct worker so[100],sw;
 int p,q,on,off,c=0;
 b=fopen("worker.txt","r");
 while(!feof(b))
 {
    fscanf(b,"%d\t%s\t%d\t%s\t\n",&so[c].id,&so[c].name,&so[c].nberofexp,&so[c].add);
    c++;
 }
 if(c==0)
 {
     printf("NOTHING TO SORT");
 }
 else
    {
        for(p=0;p<c-1;p++)
        {
            on=so[p].nberofexp;
            off=p;
            for(q=p+1;q<c;q++)
            {
                if(so[q].nberofexp<on)
                {
                    on=so[q].nberofexp;
                    off=q;
                }
            }
            sw=so[p];
            so[p]=so[off];
            so[off]=sw;
        }
        for(p=0;p<c;p++)
        {
            printf("%d\t%s\t%d\t%s\t\n",so[p].id,so[p].name,so[p].nberofexp,so[p].add);
        }
    }
    fclose(b);
    int back;
    printf("Return to Main Menu by pressing any number:");
    scanf("%d",&back);
    main(back);
}
void worker_update()
{
    FILE *b;
    FILE *f;
    b=fopen("worker.txt","r");
    printf("Enter ID of the Worker you want to update:\n");
    int x;
    int z=0;
    scanf("%d",&x);
    f=fopen("update.txt","w");
    while(!feof(b))
    {
        fscanf(b,"%d\t%s\t%d\t%s\t\n",&wo.id,&wo.name,&wo.nberofexp,&wo.add);
        if(wo.id!=x)
        {
            fprintf(f,"%d\t%s\t%d\t%s\t\n",wo.id,wo.name,wo.nberofexp,wo.add);
        }
        else
            {
             z=1;
            }
    }
     fclose(b);
    fclose(f);
    if(z==1)
    {
          b=fopen("worker.txt","w");
          f=fopen("update.txt","r");

        while(!feof(f))
      {
          fscanf(f,"%d\t%s\t%d\t%s\t\n",&wo.id,&wo.name,&wo.nberofexp,&wo.add);
          fprintf(b,"%d\t%s\t%d\t%s\t\n",wo.id,wo.name,wo.nberofexp,wo.add);

      }
      fclose(b);
      fclose(f);
    }
    b=fopen("worker.txt","w");
     printf("Enter New Worker ID, New Worker Name, New Number of Experience and New Address:\n");
     scanf("%d%s%d%s",&wo.id,&wo.name,&wo.nberofexp,&wo.add);

     fprintf(b,"%d\t%s\t%d\t%s\n",wo.id,wo.name,wo.nberofexp,wo.add);
     printf("SUCCESSFULY UPDATED\n");

     fclose(b);
     int back;
    printf("Return to Main Menu by pressing any number:");
    scanf("%d",&back);
    main(back);
}
main ()
{
    int a;
    do
    {
    printf(" MANAGEMENT SYSTEM \n");
    printf("\n\n\n");
    printf("CHOOSE A NUMBER TO CONTINUE:\n\n");
    printf("Press 1. Record Worker\n" );
    printf("Press 2. Display All Workers\n");
    printf("Press 3. Search Worker\n");
    printf("Press 4. Delete Worker\n");
    printf("Press 5. Sort Worker\n");
    printf("Press 6. Update Worker Infos\n");
    printf("Press 0. Exit The System\n\t\t\t\t\t");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        worker_record();
        break;
    case 2:
        worker_display();
        break;
    case 3:
        worker_search();
        break;
    case 4:
        worker_delete();
        break;
    case 5:
        worker_sort();
        break;
    case 6:
        worker_update();
        break;
    case 0:
        printf("\n\n\t\t HOPE YOU ARE GOING BACK FOR USING OUR SYSTEM\n");
    default:
        printf("\n\n\t\t\t\tWrong Choice");

     }
  }while(a=0);

}
