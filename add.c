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
    if(ptr==NULL)
    {
        goto beginning;
    }
    ptr=fopen("adding.dat","r");
    fread(&emp,sizeof(struct employee),40,ptr);
    fclose(ptr);

    int n;beginning:
    //system("cls");
 printf("\tSOROTI PENTACOSTAL CHURCH MINISTRY:\n\t\t1. Church information\n\t\t2. Payments & Bills\n\t\t3. Beneficiary claims\n\t\t4. Staff salaries\n\t\t0. exit.\n");
  scanf("%d",&n);
  switch(n)
  {
    add1:
  case 1:
      system("CLS");
      int go;
      printf("Do you want to... \n\t\t1. Add a new member? \n\t\t2. View a member's/members' records\n\t\t3. Delete a member?\n\t\t4. Go back to the main menu?\n\t\t5. Modify a member's record?");
      scanf("%d", &go);
      if(go==1){goto add;}
      else if(go==2){system("CLS");goto view;}
      else if(go==3){goto del;}
        //goto del;
        else if(go==4){system("CLS");goto beginning;}
        else if(go==5){system("cls");goto modify;}
        else{ system("CLS");goto add1;}
      break;

   case 2:

   case 3:

   case 4:

   case 0:
       exit(0);
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
    printf("Your Id is %d.\n", emp[i].personID);
    printf("Enter your age: ");
    scanf("%d", &emp[i].age);
    printf("Enter your address: ");
    scanf("%s", emp[i].address);
    printf("What role are you given in the church? ");
    scanf("%s", emp[i].role);
    printf("Are you Male or Female? ");
    scanf("%s", emp[i].gender);
    printf("What is your marital status? ");
    scanf("%s", emp[i].marital);
    printf("Enter your email: ");
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
        printf("Viewing menu:\n\t\t1.View all records\n\t\t2.View one record");
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
        for(int i=0; i<80;i=i+2)
        {
            if(emp[i].personID==0)
            {
                printf("That's all\n\n");
                goto start;
            }
            if (emp[i].personID!=0 && emp[i+1].personID==0)
            {
                printf("\tPerson's ID: %d\n\tName: %s %s \n\t\tRole: %s\n\tAge: %d\n\tGender: %s\n\tMarital: %s \n\tAddress: %s\n\tTelephone Number: %d\n\tEmail: %s\n\tSalary: \n",emp[i].personID,emp[i].name.firstName,emp[i].name.secondName,emp[i].role,emp[i].age,emp[i].gender,emp[i].marital,emp[i].address,emp[i].tel,emp[i].email,emp[i].salary);
                printf("\n\n\t That's all\n\n");
                goto start;
            }
            if(emp[i].personID==3000||emp[i+1].personID==3000)
            {
                i--;
                continue;
            }
            printf("\n\tPerson's ID: %d              \tPerson's ID: %d "
                   "\n\tName: %s %s                  \tName: %s %s "
                   "\n\tRole: %s                     \tRole: %s"
                   "\n\tAge: %d                      \t\tAge: %d"
                   "\n\tGender: %s                   \t\tGender: %s"
                   "\n\tMarital: %s                  \tMarital: %s"
                   "\n\tAddress: %s                  \tAddress: %s"
                   "\n\tTelephone Number: %d         \tTelephone Number: %d"
                   "\n\tEmail: %s                    \tEmail: %s"
                   "\n\tSalary:                      \t\tSalary: \n\n",
                   emp[i].personID,emp[i+1].personID,emp[i].name.firstName,emp[i].name.secondName,emp[i+1].name.firstName,emp[i+1].name.secondName,emp[i].role,emp[i+1].role,emp[i].age,emp[i+1].age,emp[i].gender,emp[i+1].gender,emp[i].marital,emp[i+1].marital,emp[i].address,emp[i+1].address,emp[i].tel,emp[i+1].tel,emp[i+1].email,emp[i+1].email,emp[i].salary,emp[i+1].salary);



        }goto start;
        part2:
        printf("Enter the Id of the person you want to view: ");
        scanf("%d", &testid);
        for(int i=0; i<80;i++)
        {
            if(testid == emp[i].personID)
            {
                system("cls");
                printf("\t\tPerson's ID: %d\n\t\tName: %s %s \n\t\tRole: %s\n\t\tAge: %d\n\t\tGender: %s\n\t\tMarital: %s \n\t\tAddress: %s\n\t\tTelephone Number: %d\n\t\tEmail: %s\n\t\tSalary: \n",emp[i].personID,emp[i].name.firstName,emp[i].name.secondName,emp[i].role,emp[i].age,emp[i].gender,emp[i].marital,emp[i].address,emp[i].tel,emp[i].email,emp[i].salary);
                break;
            }
            else if(emp[i].personID==0)
            {
                system("cls");
                printf("ID does not exist!!! Try again incase there was a typo.\n");
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

modify:
    {
        printf("\tEnter the ID of the member you want to edit.\n\tPress 1 to return to main menu.");
        int testid;
        scanf("%d", &testid);
        if(testid==1)
        {
            system("cls");
            goto beginning;
        }
        for(int i=0;i<80;i++)
        {
            if(testid<2101000||testid>2101081)
            {
                system("cls");
                printf("\tThis ID does not exist.\n\n");
                goto modify;
            }
            if(testid==emp[i].personID)
            {
                break;
            }
            if(emp[i].personID==3000)
            {
                continue;
            }
        }
        printf("What would you like to edit"
               "\n\t1. Name"
               "\n\t2. Age"
               "\n\t3. Address"
               "\n\t4. Telephone \n\t5. Email \n\t6. Role \n\t7. Marital Status \n\t8. Gender \n\t9. Entire record");
    }
return 0;
}
