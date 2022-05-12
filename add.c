#include <stdio.h>
#include <stdlib.h>

struct Name
    {
        char firstName[20];
        char secondName[20];
        char otherName[20];
    };
struct congregation
{
    int personID;
    struct Name name;
    int age;
    char gender[8];
    char marital[8];
    char address[20];
    char tel[10];
    char email[35];
}cong[250];

struct employee
{
    int personID;
    struct Name name;
    char role[10];
    int age;
    char gender[8];
    char marital[8];
    char address[20];
    char tel[10];
    char email[35];
    int salary;
}emp[80];

int main()
{
  //  int treasury = 5000000;
    for(int i=0;i<80;i++)
    {
        emp[i].personID = 0;
    }
    FILE*ptr;
    ptr=fopen("adding.dat","r");
    fread(&emp,sizeof(struct employee),40,ptr);
    fclose(ptr);

    int n;beginning:
    //system("cls");
 printf("SOROTI PENTACOSTAL CHURCH MINISTRY:\n1 client information\n2 payments & bills\n3 beneficiary claims\n4 staff salaries\n0 exit.\n");
  scanf("%d",&n);
  switch(n)
  {
    add1:
  case 1:
      system("CLS");
      int go;
      printf("Do you want to... \n 1. Add a new member of the congregation? \n2. View one of the member records\n 3. Delete a member record?\n4. To go back to the main menu?");
      scanf("%d", &go);
      if(go==1){goto add;}
      else if(go==2){system("CLS");goto view;}
      else if(go==3){goto del;}
        //goto del;
        else if(go==4){system("CLS");goto beginning;}
        else{ system("CLS");goto add1;}
      break;

   case 2:

   case 3:

   case 4:

   case 0:
       exit(1);
       default:
    printf("you have entered invalid option:");

  }
     add:
{
    //Adding block for employees

    int i;

   // printf("%s\n", emp[0].name.firstName);
    for(i=0;i<80;i++)
    {
        if(emp[i].personID==0)
        {
            printf("The iterator is %d\n", i);
            break;
        }
    }
    printf("Enter your first Name: ");
    scanf("%s",emp[i].name.firstName);
    printf("Enter your second name: ");
    scanf("%s", emp[i].name.secondName);
    emp[i].personID=2101000+i+1;
    printf("Your Id is %d\n", emp[i].personID);
    printf("Enter your age");
    scanf("%d", &emp[i].age);
    printf("Enter your address");
    scanf("%s", emp[i].address);
    printf("What role are you given in the church");
    scanf("%s", emp[i].role);
    printf("Are you Male or Female?");
    scanf("%s", emp[i].gender);
    printf("What is your marital status? ");
    scanf("%s", emp[i].marital);
    printf("Enter your email");
    scanf("%s", emp[i].email);
    printf("Enter your telephone number: ");
    scanf("%s", emp[i].tel);
    //fclose(ptr);
    FILE*fp;
    fp = fopen("adding.dat","w+");
    fwrite(&emp, sizeof(struct employee),i+1,fp);
    fclose(fp);
    //system("cls");
    int checker;
    repeat1:
    printf("\n\n 1. To add another record. \n 2. To return to main menu\n 3. exit the program.");
    scanf("%d", &checker);
    if(checker==1)
    {
        goto add;
    }
    else if(checker==2)
    {
        system("CLS");
        goto beginning;
    }
    else if(checker == 3)
    {
        exit(1);
    }
    else
    {
        goto repeat1;
    }

/*switch(checker)
    {
    case 'y':
        goto beginning;
    case 'n':
        printf("Pleasure seeing you!!!");
        exit(1);
    }*/
    view:
    {
        printf("Viewing menu:\n 1.View all records\n 2.View one record");
        int testid;
        scanf("%d", &testid);
        switch(testid)
        {
        case 1:
            goto part1;
        case 2:
            goto part2;
        }
        part1:
        for(int i=0; i<80;i++)
        {
            if(emp[i].personID==0)
            {
                printf("That's all");
                goto beginning;
            }
            if(emp[i].personID==3000)
            {
                continue;
            }
            printf("personID: %d\n Name: %s %s \n Role: %s\n Age: %d\nGender: %s\nMarital: %s \nAddress: %s\nTelephone Number: %d\nEmail: %s\nSalary: ",emp[i].personID,emp[i].name.firstName,emp[i].name.secondName,emp[i].role,emp[i].age,emp[i].gender,emp[i].marital,emp[i].address,emp[i].tel,emp[i].email,emp[i].salary);
            goto start;
        }
        part2:
        printf("Enter the Id of the person you want to view");
        scanf("%d", &testid);
        for(int i=0; i<80;i++)
        {
            if(testid == emp[i].personID)
            {
                system("cls");
                printf("person's ID: %d\n Name: %s %s \n Role: %s\n Age: %d\nGender: %s\nMarital: %s \nAddress: %s\nTelephone Number: %d\nEmail: %s\nSalary: ",emp[i].personID,emp[i].name.firstName,emp[i].name.secondName,emp[i].role,emp[i].age,emp[i].gender,emp[i].marital,emp[i].address,emp[i].tel,emp[i].email,emp[i].salary);
                break;
            }
            else
            {
                system("cls");
                printf("invalid ID:enter the correct ID..\n");
                goto part2;
                break;
            }
        }
        int c;
        start:
        printf("\n\n 1. Go back to main menu. \n 2. Exit.");
        scanf("%d", &c);
        if(c==1)
        {
            system("CLS");
            goto beginning;
        }
        else if(c==2)
        {
            exit(1);
        }
        else
        {
            goto start;
        }
    }
}

del:
    {
        system("cls");
        int delid;
        printf("To return to main menu. Enter 1.\n");
        printf("Enter the ID of the record you wish to delete: ");
        scanf("%d", &delid);
        if(delid == 1){goto beginning;}
        if(delid<2101000 || delid>2101081)
        {
            printf("%d does not exist", delid);
            goto del;
        }
        for(int i;i<80;i++)
        {
            if(emp[i].personID == 0)
            {
                printf("This ID does not exist.");
                goto del;
            }
            if(delid == emp[i].personID)
            {
                emp[i].personID = 3000;
                printf("%s\'s record has been deleted!", emp[i].name.firstName);
                break;
            }
        }
    FILE*fl;
    fl = fopen("adding.dat","w+");
    fwrite(&emp, sizeof(struct employee),40,fl);
    fclose(fl);

    }
return 0;
}
