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
struct Account
{
    int accountbalance;

}account;

int write(int group);

int main()
{
    account.accountbalance = 6000000;
    FILE*acc;
    acc=fopen("accountinformation.dat","r");
    if(acc==NULL)
    {
        printf("File does not exist.");
    }
    else
    {
        fread(&account,sizeof(struct Account),1,acc);
        fclose(acc);
    }
  //  int treasury = 5000000;
    for(int i=0;i<80;i++)
    {
        emp[i].personID = 0;
    }
    for(int i=0;i<250;i++)
    {
        cong[i].personID=0;
    }
    FILE*ptr;
    if(ptr==NULL)
    {
        goto beginning;
    }
    ptr=fopen("adding.dat","r");
    fread(&emp,sizeof(struct employee),80,ptr);
    fclose(ptr);
    FILE*yes;
    if(yes==NULL)
    {
        goto beginning;
    }
    yes=fopen("congregation.dat","r");
    fread(&cong,sizeof(struct congregation),250,yes);
    fclose(yes);
    int u;

    beginning://system("cls");
 printf("\tSOROTI PENTACOSTAL CHURCH MINISTRY:\n\t\t1. Church information\n\t\t2. Payments & Bills\n\t\t3. Beneficiary claims\n\t\t4. Staff salaries\n\t\t0. exit.\n");
  int n;int role;
  scanf("%d",&n);
  switch(n)
  {
    add1:
  case 1:
      system("CLS");
      printf("Are you checking...\n\t1. Staff\n\t2.Congregation\nPress 0 to return to main menu.");
      scanf("%d", &role);
      if(role==0){goto beginning;}
      if(role!=1&&role!=2)
      {
          //system("cls");
          //printf("Invalid option\n");
          goto add1;
      }
      system("cls");
      int go;
      printf("Do you want to... \n\t\t1. Add a new member? \n\t\t2. View a member's/members' records\n\t\t3. Delete a member?\n\t\t4. Go back to the main menu?\n\t\t5. Modify a member's record?");
      scanf("%d", &go);
      if(go==1){goto add;}
      else if(go==2){system("CLS");goto view;}
      else if(go==3){goto del;}
        //goto del;
        else if(go==4){system("CLS");goto beginning;}
        else if(go==5){system("cls");goto modify;}
        else{ system("CLS");printf("\a");goto add1;}
      break;

   case 2:
        goto payments;
   case 3:

   case 4:

   case 0:
       exit(0);
       default:
           system("cls");
    printf("you have entered invalid option:");
    goto beginning;


  }
     add:
{
    //Adding block for employees
    int mode;
    mode = write(role);
    switch(mode)
    {
    case 0:
        goto beginning;

    case 1:
        goto add;

    case 2:
        exit(0);


    }



    view:
    {
        if(role==1)
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
                printf("\tPerson's ID: %d\n\tName: %s %s \n\tRole: %s\n\tAge: %d\n\tGender: %s\n\tMarital: %s \n\tAddress: %s\n\tTelephone Number: %d\n\tEmail: %s\n\tSalary: \n",emp[i].personID,emp[i].name.firstName,emp[i].name.secondName,emp[i].role,emp[i].age,emp[i].gender,emp[i].marital,emp[i].address,emp[i].tel,emp[i].email,emp[i].salary);
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
                   "\n\tEmail: %25s        Email: %s"
                   "\n\tSalary:                      \t\tSalary: \n\n",
                   emp[i].personID,emp[i+1].personID,emp[i].name.firstName,emp[i].name.secondName,emp[i+1].name.firstName,emp[i+1].name.secondName,emp[i].role,emp[i+1].role,emp[i].age,emp[i+1].age,emp[i].gender,emp[i+1].gender,emp[i].marital,emp[i+1].marital,emp[i].address,emp[i+1].address,emp[i].tel,emp[i+1].tel,emp[i].email,emp[i+1].email,emp[i].salary,emp[i+1].salary);



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
    else if(role == 2)
    {
        printf("Viewing menu:\n\t\t1.View all records\n\t\t2.View one record");
        int testid;
        scanf("%d", &testid);
        switch(testid)
        {
        case 1:
            goto part3;
        case 2:
            goto part4;
        }
        part3:
        for(int i=0; i<80;i=i+2)
        {
            if(cong[i].personID==0)
            {
                printf("That's all\n\n");
                goto start2;
            }
            if (cong[i].personID!=0 && cong[i+1].personID==0)
            {
                printf("\tPerson's ID: %d\n\tName: %s %s \n\tAge: %d\n\tGender: %s\n\tMarital: %s \n\tAddress: %s\n\tTelephone Number: %d\n\tEmail: %s\n",cong[i].personID,cong[i].name.firstName,cong[i].name.secondName,cong[i].age,cong[i].gender,cong[i].marital,cong[i].address,cong[i].tel,cong[i].email);
                printf("\n\n\t That's all\n\n");
                goto start2;
            }
            if(cong[i].personID==3000||cong[i+1].personID==3000)
            {
                i--;
                continue;
            }
            printf("\n\tPerson's ID: %d              \tPerson's ID: %d \n"
                   "\tName: %s %s                  \t\tName: %s %s \n"
                   "\tAge: %d                      \t\tAge: %d\n"
                   "\tGender: %s                   \t\tGender: %s\n"
                   "\tMarital: %s                  \t\tMarital: %s\n"
                   "\tAddress: %s                  \t\tAddress: %s\n"
                   "\tTelephone Number: %d         \tTelephone Number: %d\n"
                   "\tEmail: %30s   Email: %s\n\n",
                   cong[i].personID,cong[i+1].personID,cong[i].name.firstName,cong[i].name.secondName,cong[i+1].name.firstName,cong[i+1].name.secondName,cong[i].age,cong[i+1].age,cong[i].gender,cong[i+1].gender,cong[i].marital,cong[i+1].marital,cong[i].address,cong[i+1].address,cong[i].tel,cong[i+1].tel,cong[i].email,cong[i+1].email);



        }goto start2;
        part4:
        printf("Enter the Id of the person you want to view: ");
        scanf("%d", &testid);
        for(int i=0; i<80;i++)
        {
            if(testid == cong[i].personID)
            {
                system("cls");
                printf("\t\tPerson's ID: %d\n\t\tName: %s %s \n\t\tAge: %d\n\t\tGender: %s\n\t\tMarital: %s \n\t\tAddress: %s\n\t\tTelephone Number: %d\n\t\tEmail: %s\n",cong[i].personID,cong[i].name.firstName,cong[i].name.secondName,cong[i].age,cong[i].gender,cong[i].marital,cong[i].address,cong[i].tel,cong[i].email);
                break;
            }
            else if(cong[i].personID==0)
            {
                system("cls");
                printf("ID does not exist!!! Try again incase there was a typo.\n");
                goto part4;
                break;
            }
        }
        int c;
        start2:
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
            goto start2;
        }
    }
        }

}

del:
    {
        if(role == 1)
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
        else if(role == 2)
        {

            system("cls");
        int delid;
        printf("To return to main menu. Enter 1.\n");
        printf("Enter the ID of the record you wish to delete: ");
        scanf("%d", &delid);
        if(delid == 1){goto beginning;}
        if(delid<5454000 || delid>5454251)
        {
            printf("%d does not exist", delid);
            goto del;
        }
        for(int i;i<80;i++)
        {
            if(cong[i].personID == 0)
            {
                printf("This ID does not exist.");
                goto del;
            }
            if(delid == cong[i].personID)
            {
                cong[i].personID = 3000;
                printf("%s\'s record has been deleted!", cong[i].name.firstName);
                break;
            }
        }
    FILE*fl;
    fl = fopen("adding.dat","w+");
    fwrite(&cong, sizeof(struct congregation),250,fl);
    fclose(fl);
        }

    }

modify:
    {
        if(role==1)
        {
                    printf("\tEnter the ID of the member you want to edit.\n\tPress 1 to return to main menu.");
        int testid;
        scanf("%d", &testid);
        if(testid==1)
        {
            system("cls");
            goto beginning;
        }
        int i;
        for(i=0;i<80;i++)
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
        edit:
        printf("What would you like to edit"
               "\n\t1. Name"
               "\n\t2. Age"
               "\n\t3. Address"
               "\n\t4. Telephone number \n\t5. Email \n\t6. Role \n\t7. Marital Status \n\t8. Gender \n\t9. Entire record\n\t0. Go back to main menu");
               int field;
               scanf("%d",&field);
               switch(field)
               {
               case 1:
                printf("Enter First Name");
                scanf("%s", emp[i].name.firstName);
                printf("Enter Second Name");
                scanf("%s", emp[i].name.secondName);
                printf("\n\t%s %s edited successfully",emp[i].name.firstName,emp[i].name.secondName);
                break;
               case 2:
                printf("Enter Correct Age");
                scanf("%d", emp[i].age);
                printf("\n\tAge %d edited successfully", emp[i].age);

               case 3:
                printf("Enter Correct Address");
                gets(emp[i].address);
                printf("\n\tAddress %s edited successfully", emp[i].address);

               case 4:
                printf("Enter Correct Telephone Number");
                scanf("%s",emp[i].tel);
                printf("\n\tTelephone number %s edited successfully", emp[i].tel);
                break;

               case 5:
                printf("Enter Correct Email");
                scanf("%s",emp[i].email);
                printf("\n\tEmail %s edited successfully", emp[i].email);
                break;

               case 6:
                printf("Enter Correct Role");
                scanf("%s",emp[i].role);
                printf("\n\tMarital status changed to %s successfully", emp[i].marital);
                break;
               case 7:
                printf("Enter Correct Marital Status");
                scanf("%s",emp[i].marital);
                printf("\n\tAddress %s edited successfully", emp[i].gender);
                break;
               case 8:
                printf("Enter Correct Gender");
                scanf("%s",emp[i].gender);
                printf("\n\tAddress %s edited successfully", emp[i].gender);
                break;

               case 9:
                    printf("\tEnter your first Name: ");
                    scanf("%s",emp[i].name.firstName);
                    printf("\tEnter your second name: ");
                    scanf("%s", emp[i].name.secondName);
                    printf("\tYour Id is still %d.\n", emp[i].personID);
                    printf("\tEnter your age: ");
                    scanf("%d", &emp[i].age);
                    printf("\tEnter your address: ");
                    scanf("%s", emp[i].address);
                    printf("\tWhat role are you given in the church? ");
                    scanf("%s", emp[i].role);
                    printf("\tAre you Male or Female? ");
                    scanf("%s", emp[i].gender);
                    printf("\tWhat is your marital status? ");
                    scanf("%s", emp[i].marital);
                    printf("\tEnter your email: ");
                    scanf("%s", emp[i].email);
                    printf("\tEnter your telephone number: ");
                    scanf("%s", emp[i].tel);
                    break;

               case 0:
                system("cls");
                goto beginning;

               default:
                system("cls");
                printf("Invalid option!!! Try again\n");
                goto edit;
               }
    FILE*h;
    h = fopen("adding.dat","w+");
    fwrite(&emp, sizeof(struct employee),80,h);
    fclose(h);

    goto start;
        }
        else if(role==2)
        {
        printf("\tEnter the ID of the member you want to edit.\n\tPress 1 to return to main menu.");
        int testid;
        scanf("%d", &testid);
        if(testid==1)
        {
            system("cls");
            goto beginning;
        }
        int i;
        for(i=0;i<250;i++)
        {
            if(testid<5454000||testid>5454251)
            {
                system("cls");
                printf("\tThis ID does not exist.\n\n");
                goto modify;
            }
            if(cong[i].personID==3000)
            {
                continue;
            }
            if(testid==cong[i].personID)
            {
                break;
            }
            if(testid==0)
            {
                printf("This ID doesn't exist\n\nTry again\n");
                goto modify;
            }

        }
        edit2:
        printf("What would you like to edit"
               "\n\t1. Name"
               "\n\t2. Age"
               "\n\t3. Address"
               "\n\t4. Telephone number \n\t5. Email \n\t6. Marital Status \n\t7. Gender \n\t8. Entire record\n\t0. Go back to main menu");
               int field;
               scanf("%d",&field);
               switch(field)
               {
               case 1:
                printf("Enter First Name");
                scanf("%s", cong[i].name.firstName);
                printf("Enter Second Name");
                scanf("%s", cong[i].name.secondName);
                printf("\n\t%s %s edited successfully",cong[i].name.firstName,cong[i].name.secondName);
                break;
               case 2:
                printf("Enter Correct Age");
                scanf("%d", cong[i].age);
                printf("\n\tAge %d edited successfully", cong[i].age);

               case 3:
                printf("Enter Correct Address");
                gets(cong[i].address);
                printf("\n\tAddress %s edited successfully", cong[i].address);

               case 4:
                printf("Enter Correct Telephone Number");
                scanf("%s",cong[i].tel);
                printf("\n\tTelephone number %s edited successfully", cong[i].tel);
                break;

               case 5:
                printf("Enter Correct Email");
                scanf("%s",cong[i].email);
                printf("\n\tEmail %s edited successfully", cong[i].email);
                break;

               case 6:
                printf("Enter Correct Marital Status");
                scanf("%s",cong[i].marital);
                printf("\n\tMarital status changed to %s successfully", cong[i].marital);
                break;
               case 7:
                printf("Enter Correct Gender");
                scanf("%s",cong[i].gender);
                printf("\n\tAddress %s edited successfully", cong[i].gender);
                break;
               case 8:
                    printf("\tEnter your first Name: ");
                    scanf("%s",cong[i].name.firstName);
                    printf("\tEnter your second name: ");
                    scanf("%s", cong[i].name.secondName);
                    printf("\tYour Id is still %d.\n", cong[i].personID);
                    printf("\tEnter your age: ");
                    scanf("%d", &cong[i].age);
                    printf("\tEnter your address: ");
                    scanf("%s", cong[i].address);
                    printf("\tAre you Male or Female? ");
                    scanf("%s", cong[i].gender);
                    printf("\tWhat is your marital status? ");
                    scanf("%s", cong[i].marital);
                    printf("\tEnter your email: ");
                    scanf("%s", cong[i].email);
                    printf("\tEnter your telephone number: ");
                    scanf("%s", cong[i].tel);
                    break;

               case 0:
                system("cls");
                goto beginning;

               default:
                system("cls");
                printf("Invalid option!!! Try again\n");
                goto edit2;
               }
    FILE*h;
    h = fopen("congregation.dat","w+");
    fwrite(&cong, sizeof(struct congregation),250,h);
    fclose(h);

    goto start;
        }

    }
return 0;

//writing the code for payments...
payments:
    {
        int choice;
        printf("\t1. Payments.\n\t2. Offerings\n\t3. Go back to previous menu.\n\t0. Go back to main menu");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("\n\t1.Utilities \n\t2. Others.\n\t3.Back\n\t4.Go back to main menu.");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1://utilities

                printf("\nAre you paying for... \n\t1. Electricity \n\t2. Water\n\t3. Back\n\t4. Go back to main menu.");
                int util;
                scanf("%d",&util);
                if(util==1)
                {
                    printf("How much are you paying for electricity?\n");
                    scanf("%d",&util);
                    account.accountbalance=account.accountbalance - util;
                    FILE*elec;
                    elec = fopen("payments.txt","a+");
                    fprintf(elec,"\n%d shillings was paid to electricity.\n\t Money left in account: %d",util,account.accountbalance);
                    printf("Electricity bill has been paid successfully");
                    fclose(elec);
                    FILE*don;
                    don=fopen("accountinformation.dat","w+");
                    fwrite(&account,sizeof(struct Account),1,don);
                    fclose(don);
                    int check;
                    printf("\n\t1.Return to the main previous menu\n\t2. Return to the main menu");

                    }

                    //goto payments;

                else if(util==2)
                {
                    printf("How much are you paying for water?\n");
                    scanf("%d",&util);
                    account.accountbalance=account.accountbalance - util;
                    FILE*wat;
                    wat = fopen("payments.txt","a+");
                    fprintf(wat,"%d shillings was paid to water.\n\t Money left in account: %d",util,account.accountbalance);
                    printf("Water bill has been paid successfully");
                    fclose(wat);
                    FILE*yon;
                    yon=fopen("accountinformation.dat","w+");
                    fwrite(&account,sizeof(struct Account),1,yon);
                    fclose(yon);
                    goto payments;
                }
                else{goto payments;}

            case 2://working on others... Utilities.
                {
                  printf("What are you paying for?");
                    char item[30];
                    scanf("%s",item);
                    printf("How much are you paying for %s", item);
                    scanf("%d",&util);
                    account.accountbalance=account.accountbalance - util;
                    FILE*oth;
                    oth = fopen("payments.txt","a+");
                    fprintf(oth,"%d shillings was paid for %s.\n\t Money left in account: %d",util,item,account.accountbalance);
                    printf("%s has been paid successfully",item);
                    fclose(oth);
                    FILE*fon;
                    fon=fopen("accountinformation.dat","w+");
                    fwrite(&account,sizeof(struct Account),1,fon);
                    fclose(fon);
                    goto payments;
                }
            case 0:
                goto beginning;


            //default:

           // default:

            }
        case 2:
            {
                printf("\t1.Offertory/Thanksgiving\n\t2.Tithe\n\t3.Back\n\t0.Go back to main menu.");
               scanf("%d", &choice);
              printf("Offerings.\n\t1. Offertory\n\t2.Tithe");
                int offer,offertory;
                scanf("%d",&offer);
                tithe:
                if(offer==1)//option for paying offertory
                {
                    printf("How much has been collected from offertory? ");
                    scanf("%d",&offertory);
                    account.accountbalance=account.accountbalance + offertory;
                    FILE*off;
                    off = fopen("payments.txt","a+");
                    fprintf(off,"%d shillings were received from offertory.\n\t Money left in account: %d",offertory,account.accountbalance);
                    printf("%s has been recorded successfully",offertory);
                    fclose(off);
                    FILE*ton;
                    ton=fopen("accountinformation.dat","w+");
                    fwrite(&account,sizeof(struct Account),1,ton);
                    fclose(ton);
                    goto payments;
                }
                if(offer==2)//option for paying tithe
                {
                    printf("Enter the ID of the member paying tithe: ");
                    int newid,money;
                    scanf("%d", &newid);
                    printf("How much was paid by member in tithe?");
                    scanf("%d", &money);
                    for(int i=0; i<80;i++)
        {
            if(newid == cong[i].personID)
            {
                system("cls");
                printf("\t\t\t%s %s has paid %d in tithe.",cong[i].name.firstName,cong[i].name.secondName,money);
                break;
            }
            else if(cong[i].personID==0)
            {
                system("cls");
                printf("ID does not exist!!! Try again incase there was a typo.\n");
                goto tithe;
                break;
            }
            account.accountbalance=account.accountbalance+money;
            FILE*thes;
                    thes = fopen("payments.txt","a+");
                    fprintf(thes,"%d shillings were received from offertory.\n\t Money left in account: %d",offertory,account.accountbalance);
                    printf("%s has been recorded successfully",offertory);
                    fclose(thes);
                    FILE*won;
                    won=fopen("accountinformation.dat","w+");
                    fwrite(&account,sizeof(struct Account),1,won);
                    fclose(won);
                    goto payments;
        }
            }

                }

        case 3:
        {
            goto payments;
        }
        case 0:
        {
            goto beginning;
        }
        default:
            {
                system("cls");
                printf("Invalid Choice\n\a");
                goto payments;
            }

        }


    }


int write(int group)
{
    if(group==1)
    {
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
    scanf("%s",emp[i].address);
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
    printf("\n\n\t 1. To add another record. \n\t 2. To return to main menu\n\t 3. exit the program.");
    scanf("%d", &checker);
    if(checker==1)
    {
        system("cls");
        return 1;
    }
    else if(checker==2)
    {
        system("CLS");
        return 0;
       // goto beginning;
    }
    else if(checker == 3)
    {
        return 2;
    }
    else
    {
        system("cls");
        printf("\tInvalid Option!!! Try again\n");
        goto repeat1;
    }
    }
    else if(group==2)
    {

    int i;

   // printf("%s\n", emp[0].name.firstName);
    for(i=0;i<80;i++)
    {
        if(cong[i].personID==0)
        {
            printf("The iterator is %d\n", i);
            break;
        }
    }
    printf("Enter your first Name: ");
    scanf("%s",cong[i].name.firstName);
    printf("Enter your second name: ");
    scanf("%s", cong[i].name.secondName);
    cong[i].personID=5454000+i+1;
    printf("Your Id is %d.\n", cong[i].personID);
    printf("Enter your age: ");
    scanf("%d", &cong[i].age);
    printf("Enter your address: ");
    scanf("%s",cong[i].address);
    //printf("What role are you given in the church? ");
    //scanf("%s", emp[i].role);
    printf("Are you Male or Female? ");
    scanf("%s", cong[i].gender);
    printf("What is your marital status? ");
    scanf("%s", cong[i].marital);
    printf("Enter your email: ");
    scanf("%s", cong[i].email);
    printf("Enter your telephone number: ");
    scanf("%s", cong[i].tel);
    //fclose(ptr);
    FILE*ty;
    ty = fopen("congregation.dat","w+");
    fwrite(&cong, sizeof(struct congregation),i+1,ty);
    fclose(ty);
    //system("cls");
    int checker;
    repeat2:
    printf("\n\n\t 1. To add another record. \n\t 2. To return to main menu\n\t 3. exit the program.");
    scanf("%d", &checker);
    if(checker==1)
    {
        system("cls");
        return 1;
    }
    else if(checker==2)
    {
        system("CLS");
        return 0;
       // goto beginning;
    }
    else if(checker == 3)
    {
        return 2;
    }
    else
    {
        system("cls");
        printf("\tInvalid Option!!! Try again\n");
        goto repeat2;
    }

    }



}

    //dealing with the second part of the code.

        return 0;

}

