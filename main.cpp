//
//  main.cpp
//  ZazuFinal
//
//  Created by Urmika Kasi on 21/11/18.
//  Copyright © 2018 Urmika Kasi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cmath>
using namespace std;
void page3(int);
void page2();
void page1();
//void loginPage();
//void signupPage();
int fcount=-1;
int ncount=-1;
class logger;
char names[10][20];
char username[20];
char password[20];

void SignupPage();
void loginPage();

class logger//user info
{
protected:
    char lname[20];
    
public:
    static int totallogger;
    
    void loggerstatus()
    {
        if(totallogger>0)
            cout<<"You owe Rs."<<totallogger;
        else if(totallogger<0)
            cout<<"You are owed Rs."<<-totallogger;
        else
            cout<<"All settled up!";
    }
    void entername(char s[20])
    {
        strcpy(lname,s);
        //strcpy(password, p);
    }
    
    
    
};
//void page2();
int logger::totallogger;
struct category
{
    char cname[20];
    float amt;
    float ctotal;
    
};
class fren:public logger
{
public:
    float ftotal;
    char fname[20];
    category cat[20];
    int catno;//keep track of no. of categories/entries
    
public:
    fren()
    {
        catno=0;
        
    }
    void add1plus()//enter fren object
    {
        
        
        
        //ofstream file("Names.txt",ios_base::app);
    
        int flag=0;
        
        cout<<"\n\t\tAdd bill with you and ";
        cin>>fname;
        for(int i=0;i<fcount;i++)
        {
            if(strcmp(names[i],fname)==0)
            {flag=1;
                break;}
        }
        if(flag==1)
        {
            cout<<"Friend already present! Add to their existing dues!";
            system("cls");
            page2();
        }
        if(flag==0)
        {
            ncount++;
            strcpy(names[ncount],fname);
            //file<<fname<<"\n";
        }
        //file.close();
        
        cout<<"\n\n\t\tEnter a description: \t";
        cin>>cat[catno].cname;
        cout<<"\n\n\t\tINR ";
        cin>>cat[catno].amt;
        
        int billchoice;//how was the bill paid?
        cout<<"\n\t\tHow was this bill split?\n1.Paid by you and split equally\n2.You owe "<<fname<<" Rs."<<cat[catno].amt<<"\n3."<<fname<<" owes you Rs."<<cat[catno].amt<<"\n4.Paid by "<<fname<<" and split equally\n";
        cin>>billchoice;
        switch(billchoice)
        {
            case 1: ftotal+= -(cat[catno].amt/2);
                
                totallogger-=cat[catno].amt/2;
                break;
            case 2: ftotal+= cat[catno].amt;
                totallogger+=cat[catno].amt;
                break;
            case 3:ftotal+= -cat[catno].amt;
                totallogger-=cat[catno].amt;
                break;
            case 4:ftotal+= cat[catno].amt/2;
                totallogger+=cat[catno].amt/2;
        }
        cat[catno].ctotal=ftotal;
        
        //catno++;
        //writetofile(f);
        page2();
        
    }
    
    void settle()
    {
        int set;
        
        cout<<"\nEnter amount you want to settle up!\n\n";
        cin>>set;
        //confirmation
        if(ftotal<0)
        {
            cout<<fname<<" is paying "<<lname<<" Rs."<<set;
        }
        else if(ftotal>0)
        {
            cout<<lname<<" is paying "<<fname<<" Rs."<<set;
        }
        else
            cout<<"You're both already settled up!";
        //update ftotal and totallogger
        if(set==fabs(ftotal))
        {
            
                totallogger-=fabs(ftotal);
            ftotal=0;
            catno=-1;
        }
        else if(set<fabs(ftotal))
        {
            if(ftotal<0)
            {ftotal+=set; totallogger+=set;}
            else
            {ftotal-=set; totallogger-=set;}
        }
        else if(set>fabs(ftotal))//THIS ISNT WORKING EITHER????
        {
            if(ftotal>0)
                ftotal=set-fabs(ftotal);
            else
                ftotal=fabs(ftotal)-set;
            
            totallogger+=-ftotal;
        }
    }
}f[5];



void page2()//shows friend list, totallogger, add new frens
{
    
    cout<<"\t\t\t\nTOTAL BALANCE: \t";
    f[0].loggerstatus();
    
    for(int i=0;i<=ncount;i++)
    {
        cout<<"\n"<<i+1<<names[i];
        
       
    }
    
        
    
    cout<<"\nEnter '+' to add a new friend!\nEnter the corresponding number to see friend details!\n";
    char ch;
    cin>>ch;
    if(ch=='+')
    {
    
        fcount++;
        
    f[fcount].add1plus();//call write to file
    }
    else if(ch>='1'&& ch<='9')
    {
        page3(ch-'0');
    }
    
}
void page3(int cho)
{
    int i=cho-1;
    
    //system("cls");
update:
    cout<<"\n\n"<<f[i].fname<<"\n";
    if(f[i].ftotal<0)
        cout<<f[i].fname<<" owes you Rs."<<-f[i].ftotal<<"\n\n";
    else if(f[i].ftotal>0)
        cout<<"You owe "<<f[i].fname<<" Rs."<<f[i].ftotal<<"\n\n";
    else
        cout<<"All settled up!\n";
    for(int j=0;j<=f[i].catno+1;j++)
    {
        if(f[i].cat[j].ctotal>0)
            cout<<"\n"<<f[i].cat[j].cname<<"\t\t\tYou borrowed Rs."<<f[i].cat[j].ctotal;
        else if(f[i].cat[j].ctotal<0)
            cout<<"\n"<<f[i].cat[j].cname<<"\t\t\tYou lent Rs."<<-f[i].cat[j].ctotal;
        
    }
    cout<<"\n\n";
    cout<<"Enter + to add a new bill!\nEnter 'H' to go back to Home!\nEnter - to settle up!\n";
    char ch;
    cin>>ch;
    if(ch=='+')
    {
        f[i].catno++;
        cout<<"\n\n\t\tEnter a description: \t";
        cin>>f[i].cat[f[i].catno].cname;
        cout<<"\n\n\t\tINR ";
        cin>>f[i].cat[f[i].catno].amt;
        
        int billchoice;//how was the bill paid?
        cout<<"\n\t\tHow was this bill split?\n1.Paid by you and split equally\n2.You owe "<<f[i].fname<<" Rs."<<f[i].cat[f[i].catno].amt<<"\n3."<<f[i].fname<<" owes you Rs."<<f[i].cat[f[i].catno].amt<<"\n4.Paid by "<<f[i].fname<<" and split equally\n";
        cin>>billchoice;
        switch(billchoice)
        {
            case 1: f[i].ftotal+= -(f[i].cat[f[i].catno].amt/2);
                f[i].cat[f[i].catno].ctotal=f[i].ftotal;
                f[i].totallogger-=f[i].cat[f[i].catno].amt/2;
                break;
            case 2: f[i].ftotal+= f[i].cat[f[i].catno].amt;
                f[i].cat[f[i].catno].ctotal=f[i].ftotal;
                f[i].totallogger+=f[i].cat[f[i].catno].amt;
                break;
            case 3:f[i].ftotal+= -f[i].cat[f[i].catno].amt;
                f[i].cat[f[i].catno].ctotal=f[i].ftotal;
                f[i].totallogger-=f[i].cat[f[i].catno].amt;
                break;
            case 4:f[i].ftotal+= f[i].cat[f[i].catno].amt/2;
                f[i].cat[f[i].catno].ctotal=f[i].ftotal;
                f[i].totallogger+=f[i].cat[f[i].catno].amt/2;
        }
        
        goto update;
        
    }
    else if(ch=='h'||ch=='H')
        page2();
    else if(ch=='-')
    {
        f[i].settle();
        page2();
    }
        
    
}
int main(int argc, const char * argv[]) {
    page1();
    return 0;
}
void page1()
{
    char ch;
    
    cout<<"\t\t\t\t\tWELCOME TO SettleUp!\n";
    /*for(int i=0;i<100;i++)
     for(int j=0;i<200;j++){}*/
    cout<<"\t\t\t\t\tSplit bills with ease and the clear all debts\n";
    //delay
    /*for(int i=0;i<800;i++)
     for(int j=0;j<800;j++){}*/
    
    
RETRY:
    cout<<"\t\t\t\tWould you like to a)Login\n\t\t\t\tb)SignUp\n";
    cin>>ch;
    switch(ch)
    {
        case 'a':
        case 'A': //loginPage();
            loginPage();
            break;
            
        case 'b':
        case 'B': SignupPage();
            break;
            
        default:cout<<"\nOh no! Looks like we don't have that option. Please try again";
            goto RETRY;
            
    }
    
    
}


void loginPage()
{
    
    char Uquery[20]; char pass[20];
    char Pquery[20];
    int fl=0;
AAA:
    cout<<" \nPlease tell us your Username and Password :";
    cout<<"\nUsername :";
    cin>>Uquery;
    
    
    //int choice;
PAS:
    cout<<"\nPassword :";
    
    cin>>Pquery;
    
    ifstream in("Password.txt",ios::in);
    
    in.seekg(0,ios::beg);
    while(!in.eof())
    {
        in>>pass;
        if(strcmp(pass,Pquery)==0)
        {    fl=1;
            break;}
    }
    in.close();
    
    
    if(fl==1)
    {cout<<"Successfuly logged in\n\n\n\n";
        f[0].entername(Uquery);
        page2();}
    else{
    LAB:
        int choice;
        cout<<"\ndo you want to \n1.enter the pass again or 2.make a new account";
        cin>>choice;
        switch(choice)
        {
            case 1: goto PAS; break;
            case 2: SignupPage(); break;
            default :
                cout<<"Oops looks like we dont have that option. PLease try again.";
                goto LAB; break;
        }
    }
}







void SignupPage()
{
    //struct UandP ins;
    
    char Uquery[20], email[20], mob[15];
    char Pquery[20],pass2[20];
    cout<<"\nOkay so let's make you a member of SettleUp!\nFor this we will need your following details:\n";
    
    cout<<"Username :\n";
    cin>>Uquery;
    cout<<"\nEmail :";
    cin>>email;
MOB:
    cout<<"\nMobile Number :";
    cin>>mob;
    if(strlen(mob)!=10)
    {cout<<"\nInvalid number. Please enter again.";
        goto MOB;
    }
    cout<<"\nEnter password :";
    
    cin>>Pquery;
    
PASS:
    cout<<"\nRe-type the password :";
    
    cin>>pass2;
    int flag=1;
    
    if(strcmp(Pquery,pass2)==0)
        flag=0;
    if(flag==1) goto PASS;
    
    
    strcpy(username,Uquery);
    
    ofstream out("Password.txt", ios::out);
    out.seekp(0,ios::beg);
    
    out<<Pquery<<"\n";
    out.close();
    page1();
    
    
}
