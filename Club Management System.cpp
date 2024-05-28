#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>

void password();
void mainmenu(void);
void addmember(void);
void deletemember(void);
void searchmember(void);
void viewmember(void);
void editmember(void);
void closeapp(void);
void returnfunc(void);
void event(void);
int t(void);



void addevent(void);
void vieweevent(void);
void deleteevent(void);

///list of global files
FILE *fp,*ft,*fs;
COORD coord = {0, 0};

int fm;

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct member{
    int ID;
    char name[20];
    char add[20];
    char dept[20];
    int Phone_no;

    int no;
    char title[20];
    char z[100];
    char date[20];

};

struct member stu;




int main(){
password();
getch();
return 0;
}

void mainmenu(){
    int choice;
    system("cls");
    gotoxy(20,3);
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MAIN MENU \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,5);printf("1. Add Members\n");
gotoxy(20,7);printf("2. Delete Members\n");
gotoxy(20,9);printf("3. Search Members\n");
gotoxy(20,11);printf("4. View Members\n");
gotoxy(20,13);printf("5. Event\n");
gotoxy(20,15);printf("6. Edit Members Information\n");
gotoxy(20,17);printf("7. Close application\n");
gotoxy(20,18);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,19);t();
gotoxy(20,23);
printf("Enter Your Choice: ");

switch(getch()){
case '1':
addmember();
break;
case '2':
deletemember();
break;
case '3':
searchmember();
break;
case '4':
viewmember();
break;
case '5':
event();
break;
case'6':
editmember();
case '7':{
system("cls");
gotoxy(16,3);
printf("\t CLUB Management System\n");
gotoxy(16,5);
printf("\n\n*****************************************************************************");

exit(0);
}
default:{
gotoxy(20,22);printf("Wrong!!Correct Option");
if (getch())
mainmenu();

}
}


}
void addmember(void){
system("cls");

      gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Add MEMBER INFO \xcd\xcd\xcd");
    int print = 25;
    FILE *fp;
    fp = fopen("record_nxt.txt","ab+");
//    SetColor(45);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }
    else

    {
        ///fflush(stdin);
        gotoxy(print,6);printf("Member ID: ");scanf("%d",&stu.ID);
        //here you can confirms the ID
        fflush(stdin);
        gotoxy(print,8);printf("Name: ");gets(stu.name);
        gotoxy(print,10);printf("Address: ");gets(stu.add);
        gotoxy(print,12);printf("Department name: ");gets(stu.dept);
        gotoxy(print,14);printf("Phone Number: ");scanf("%d",&stu.Phone_no);
        ///gotoxy(print,20);printf("Phone Number: ");scanf("%d",&stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);

    }

    fclose(fp);
    gotoxy(40,17); printf("The record is sucessfully added");
     gotoxy(40,18);printf("Save any more Y/N");
    if(getch()=='n')
    mainmenu();
    else
    system("cls");
    addmember();
}




void deletemember( ){
system ("cls");
gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Delete MEMBER  \xcd\xcd\xcd");






int d;
char another='y';
while(another=='y')
{
    system("cls");
    gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Delete MEMBER  \xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to  delete:");
scanf("%d",&d);
fp=fopen("record_nxt.txt","rb+");
rewind(fp);
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==d)
{


gotoxy(10,8);
printf("Member name is %s",stu.name);
gotoxy(10,9);

fm='Z';
}
}
if(fm!='Z')
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())
mainmenu();
}
if(fm=='Z' )
{
gotoxy(10,7);
printf("The Member is available");
gotoxy(10,10);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.txt","wb+");
rewind(fp);
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID!=d)
{

fwrite(&stu,sizeof(stu),1,ft);
}
}
fclose(ft);
fclose(fp);
remove("record_nxt.txt");
rename("test.txt","record_nxt.txt");
fp=fopen("record_nxt.txt","rb+");
if(fm=='Z')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
mainmenu();
///returnfunc();

}


void searchmember(void){
system("cls");
int s;
gotoxy(10,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd SEARCH MEMBER \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to  search:");
scanf("%d",&s);
fp=fopen("record_nxt.txt","rb+");
rewind(fp);
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==s)
{

gotoxy(10,7);
printf("The Member is available");

gotoxy(10,9);
printf("ID: %d",stu.ID);
gotoxy(10,10);
printf("Name: %s",stu.name);
gotoxy(10,11);
printf("Address: %s",stu.add);
gotoxy(10,12);
printf("Department name: %s",stu.dept);
gotoxy(10,13);
printf("Phone nO: %d",stu.Phone_no);

fm='Z';
}
}
if(fm!='Z')
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())

mainmenu();
}

{
gotoxy(10,9);
printf("");
fclose(fp);
returnfunc();
getch();
}}

void viewmember(void){

system("cls");

FILE *fp;
int i=0,j;
system("cls");
gotoxy(15,1);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Members List \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(2,3);
printf(" MEM_ID    MEMBER NAME    ADDRESS     DEPARTMENT     PHONE_NO    ");
j=5;
fp=fopen("record_nxt.txt","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{
gotoxy(3,j);
printf("%d",stu.ID);
gotoxy(14,j);
printf("%s",stu.name);
gotoxy(28,j);
printf("%s",stu.add);
gotoxy(40,j);
printf("%s",stu.dept);
gotoxy(55,j);
printf("%d",stu.Phone_no);

gotoxy(69,j);

printf("\n\n");
j++;
i=i+1;
}
gotoxy(3,25);
printf("Total Members =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
getch();
}

void event(void){

system("cls");
int i;
gotoxy(20,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd EVENT MENU \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,5);
printf("1. Add Event   ");
gotoxy(20,7);
printf("2. View Event");
gotoxy(20,9);
printf("3. Delete Event");
gotoxy(20,11);
printf("4. Mainmenu");
gotoxy(20,12);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,15);printf("Enter Your Choice");
switch(getch()){
case '1':
addevent();
break;
case '2':
vieweevent();
break;
case '3':
deleteevent();
case'4':
mainmenu();
default:{
gotoxy(20,22);printf("Wrong!!Correct Option\a");
if (getch())
mainmenu();

}
}
}

void addevent(){
    system("cls");
gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Add Event \xcd\xcd\xcd");
    int print = 25;
    fp = fopen("record.dat","ab+");
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        gotoxy(print,5);printf("event date:");gets(stu.date);
        gotoxy(print,6);printf("Event name: ");gets(stu.title);
        gotoxy(print,7);printf("Details: ");gets(stu.z);
        fwrite(&stu, sizeof(stu), 1, fp);
        gotoxy(40,12); printf("The record is sucessfully added");
    }

    fclose(fp);
gotoxy(40,13);printf("Save any more Y/N");
    if (getch()=='n')
    mainmenu();
    else
    system("cls");
    addevent();

gotoxy(25,20);
returnfunc();
getch();
}

void deleteevent()
{
    system("cls");
    char date[20];
   fflush(stdin);

    printf("\n\n\tDELETE event\n\t==========================\n\tEnter the date to delete:");

    gets(date);
    fp=fopen("record.dat","r");
    ft=fopen("temp.dat","w");
    while(fread(&stu,sizeof(stu),1,fp)!=0)
    if (stricmp(date,stu.date)!=0)
    fwrite(&stu,sizeof(stu),1,ft);
    fclose(fp);
    fclose(ft);
    remove("record.dat");
    rename("temp.dat","record.dat");
    printf("\n\t\tRecord is delete");

gotoxy(25,25);
returnfunc();
getch();
}



void vieweevent()
{
    system("cls");

int j=5;
gotoxy(1,1);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd view events \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(1,3);printf("Event date         event name               Details");

fp=fopen("record.dat","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{

gotoxy(1,j);
printf("%s",stu.date);
gotoxy(18,j);
printf("%s",stu.title);
gotoxy(46,j);
printf("%s",stu.z);
j++;
}
fclose(fp);

gotoxy(25,25);
returnfunc();
getch();
}


void editmember(void){
system("cls");

int s,print=37;
gotoxy(15,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd Edit MEMBER info \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to edit:");
scanf("%d",&s);
fp=fopen("record_nxt.txt","rb+");

while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==s)
{

gotoxy(10,7);
printf("The Member is available");

        fflush(stdin);
        gotoxy(print,12);printf("Name: ");gets(stu.name);
        gotoxy(print,14);printf("Address: ");gets(stu.add);
        gotoxy(print,16);printf("Department name: ");gets(stu.dept);
        gotoxy(print,18);printf("Phone Number: ");scanf("%d",&stu.Phone_no);
        gotoxy(print,22);printf("The record is modified");
        fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);

fm=1;
break;
}
}
if(fm!=1)
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())
mainmenu();
}

fclose(fp);

gotoxy(37,22);
returnfunc();
getch();
}



void returnfunc(void){{
    gotoxy(25,25);
printf("Press ENTER to return the main menu");
}
if(getch()==13)
mainmenu();
}
int t(void){
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


void password(void){
system("cls");
char pass[10],ch,password[10]="12345";
int i=0;
gotoxy(25,2);
printf("==== CLUB MANAGEMENT SYSTEM ====");
gotoxy(20,5);
printf("Enter the password to Login:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';


if(strcmp(pass,password)==0){
gotoxy(13,8);
    printf("Password Matched!!");
    gotoxy(14,9);
    printf("Loading ");
for(i=0;i<=6;i++)
        {
            fordelay(100000000);

            printf(".");
        }
                system("cls");
            mainmenu();
        }
        else
        gotoxy(15,13);
        printf("Password is invalid!!\a");
        printf("\tENTER correct password");
        getch();
        main();
}
