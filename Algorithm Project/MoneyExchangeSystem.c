#include<stdio.h>
int choice;
int br_point;
int value;
int coins[9]= {500,200,100,50,20,10,5,2,1};
int ans[1000];
int N[9];

FILE *file;
void projectName()
{
    system("cls");
    system("color b1");
    printf("\n\t\t\t\t*******************************************");
    printf("\n\t\t\t\t*******************************************");
    printf("\n\t\t\t\t**                                       **");
    printf("\n\t\t\t\t**         Money Exchange System         **");
    printf("\n\t\t\t\t**                                       **");
    printf("\n\t\t\t\t*******************************************");
    printf("\n\t\t\t\t*******************************************\n");
}

void submittedBy()
{
    projectName();
    system("color b1");
    printf("\n\t\t\t    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  ||          Name               |       ID            ||");
    printf("\n\t\t\t  ||***************************************************||");
    printf("\n\t\t\t  ||    1. Pronoy Kumar Mondal   | ID: 212-15-14744    ||");
    printf("\n\t\t\t  ||    2. Washik Wali Faieaz    | ID: 212-15-14763    ||");
    printf("\n\t\t\t  ||    3. Kawshik Ahmed Ornob   | ID: 212-15-14750    ||");
    printf("\n\t\t\t  ||    4. Md. Masud Rana        | ID: 212-15-14760    ||");
    printf("\n\t\t\t  ||    5. Bibakananda Roy Shuvo | ID: 212-15-14747    ||");
    printf("\n\t\t\t    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t\t    Enter any key to continue.....\n");
    getch();
}

void submittedTo()
{
    projectName();
    system("color b1");
    printf("\n\t\t\t\t   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t ||           Samia Nawshin             ||");
    printf("\n\t\t\t\t ||*************************************||");
    printf("\n\t\t\t\t ||        Assistant Professor          ||");
    printf("\n\t\t\t\t ||           Dept. of CSE              ||");
    printf("\n\t\t\t\t ||  Daffodil International University  ||");
    printf("\n\t\t\t\t   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t\t\t   Enter any key to continue.....\n");
    getch();
}

void menu()
{
    system("cls");
    projectName();
    system("color b1");
    while(1)
    {

        printf("\n\n\t\t\t\t  Welcome to the Money Exchange System!!\n\n");
        printf("\n\n\t\t\t\t ****** Press 0 to quit the program ******\n\n");
        printf("\t\t\t\tEnter 1 for show the notes that the machine have\n");
        printf("\t\t\t\tEnter 2 for Exchange Taka\n");
        printf("\t\t\t\tEnter 3 for Exchange other currency\n");

        scanf("%d",&choice);
        if(choice==1)
        {
            ShowNotes();
        }
        else if(choice==2)
        {
            Taka();
        }
        else if(choice==3)
        {
            Other();
        }
        else if(choice==0)
        {
            printf("\n\t\t\t\t.............................\n");
            printf("\t\t\t\t.............................\n");
            printf("\t\t\t\t..\t1. continue        ..\n");
            printf("\t\t\t\t..\t0. exit            ..\n");
            printf("\t\t\t\t.............................\n");
            printf("\t\t\t\t.............................\n");

            scanf("%d",&br_point);

            if(br_point==0)
            {
                break;
            }
        }

    }
}

void ShowNotes()
{
    system("cls");
    system("color b1");
    printf("1. 500\n");
    printf("2. 200\n");
    printf("3. 100\n");
    printf("4. 50\n");
    printf("5. 20\n");
    printf("6. 10\n");
    printf("7. 5\n");
    printf("8. 2\n");
    printf("9. 1\n");
    printf("\n\n\t\t\t    Enter any key to continue.....\n");
    getch();

}

void Taka()
{
    system("cls");


    file=fopen("SavedNotes.txt","a");

    printf("Enter your ammount you want to exchange:  ");

    scanf("%d",&value);

    system("cls");

    int i, count = 0;

    for(i=0; i<9; i++)
    {
        fscanf(file,"%d",&N[i]);
    }

    for(i = 0; i < 9; i++)
    {
        if(value == 0)
        {
            break;
        }

        while(value >= coins[i])
        {

            value -= coins[i];

            ans[count] = coins[i];
            count++;
        }



        fprintf(file,"%d",(N[i]-1));
        fclose(file);

    }
    printf("Total notes need to exchange: %d\n",count);
    printf("The Notes are: ");
    for(i=0; i<count; i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n\n\n");
    printf("\t\t\t\t..\t1. continue        ..\n");
    printf("\t\t\t\t..\t0. exit            ..\n");
    scanf("%d",&br_point);
    if(br_point==1)
    {
        system("cls");
        Taka();
    }
    else
    {
        system("cls");
        return;
    }


}


void Other()
{
    system("cls");
    printf("***USD 1 = 100 BDT\tEURO 1= 105***\n");
    printf("Select your currency: \n");
    printf("1. USD\n");
    printf("2. Euro\n");
    scanf("%d",&br_point);
    system("cls");
    if(br_point==1)
    {
        printf("Enter your ammount you want to exchange:  ");
        scanf("%d",&value);
        long long int v=value*100;
        int i, count = 0;

        for(i = 0; i < 9; i++)
        {
            if(v == 0)
                break;

            while(v>= coins[i])
            {

                v -= coins[i];
                ans[count] = coins[i];
                count++;
            }


        }
        printf("Total notes need to exchange: %d\n",count);
        printf("The Notes are: ");
        for(i=0; i<count; i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n\n\n");
        printf("\t\t\t\t..\t1. continue        ..\n");
        printf("\t\t\t\t..\t0. exit            ..\n");
        scanf("%d",&br_point);
        if(br_point==1)
        {
            system("cls");
            Taka();
        }
        else
        {
            system("cls");
            return;
        }



    }
    else
    {
        system("cls");

        printf("Enter your ammount you want to exchange:  ");
        scanf("%d",&value);
        long long int v=value*105;
        int i, count = 0;

        for(i = 0; i < 9; i++)
        {
            if(v == 0)
                break;
            //take as much from coins[i]
            while(v>= coins[i])
            {
                //after taking the coin, reduce the value.
                v -= coins[i];
                ans[count] = coins[i];
                count++;
            }


        }
        printf("Total notes need to exchange: %d\n",count);
        printf("The Notes are: ");
        for(i=0; i<count; i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n\n\n");
        printf("\t\t\t\t..\t1. continue        ..\n");
        printf("\t\t\t\t..\t0. exit            ..\n");
        scanf("%d",&br_point);
        if(br_point==1)
        {
            system("cls");
            Taka();
        }
        else
        {
            system("cls");
            return;
        }


    }

}

int main()
{
    system("cls");
    projectName();
    system("color b1");
    while(1)

    {
        printf("\n\t\t\t\t*******************************************\n");
        printf("\t\t\t\t*******************************************\n");
        printf("\t\t\t\t**\t.....Select your option.....     **\n");
        printf("\t\t\t\t**                               \t **\n");
        printf("\t\t\t\t**\t      1. Submitted By            **\n");
        printf("\t\t\t\t**\t      2. Submitted To            **\n");
        printf("\t\t\t\t**\t      3. Money Exchange System   **\n");
        printf("\t\t\t\t**                          \t         **\n");
        printf("\t\t\t\t**                               \t **\n");
        printf("\t\t\t\t*******************************************\n");
        printf("\t\t\t\t*******************************************\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            submittedBy();
        }
        else if(choice==2)
        {
            submittedTo();
        }
        else if(choice==3)
        {
            menu();
        }
        printf("\n\t\t\t\t.............................\n");
        printf("\t\t\t\t.............................\n");
        printf("\t\t\t\t..\t1. continue        ..\n");
        printf("\t\t\t\t..\t0. exit            ..\n");
        printf("\t\t\t\t.............................\n");
        printf("\t\t\t\t.............................\n");
        scanf("%d",&br_point);
        if(br_point==0)
        {
            break;
        }
        system("cls");
        return 0;
    }

}
