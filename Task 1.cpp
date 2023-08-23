#include<iostream>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include <ctime>
using namespace std;
int main()
{
    int x;
    char input[150];
    cout<<"---------------------------WELCOME TO ALICE CHATBOT!----------------------------"<<endl;
    cout<<"What can  I help you with?"<<endl;
    while(1)
    {
        gets(input);
        if(strcmp(input,"Hey!")==0)
        {
            cout<<"Hi!";
        }
        if(strcmp(input,"How are you?")==0)
        {
            cout<<"I am perfectly fine.";
        }
        if(strcmp(input,"What is going on?")==0)
        {
            cout<<"Nothing much,just practicing few things.";
        }
        if(strcmp(input,"sum")==0)
        {
            cout<<"Enter both numbers: "<<endl;
            int a,b;
            cin>>a>>b;
            cout<<a+b;
        }
         if(strcmp(input,"difference")==0)
        {
            cout<<"Enter both numbers: "<<endl;
            int a,b;
            cin>>a>>b;
            cout<<a-b;
        }
        if(strcmp(input,"multiply")==0)
        {
            cout<<"Enter both numbers: "<<endl;
            int a,b;
            cin>>a>>b;
            cout<<a*b;
        }
        if(strcmp(input,"divide")==0)
        {
            cout<<"Enter both numbers: "<<endl;
            int a,b;
            cin>>a>>b;
            cout<<a/b;
        }
        if(strcmp(input,"modulo")==0)
        {
            cout<<"Enter both numbers: "<<endl;
            int a,b;
            cin>>a>>b;
            cout<<a%b;
        }
        if(strcmp(input,"Thank you")==0)
        {
            cout<<"I am always there to help you.You can ask me questions whenever you wish like."<<endl;
        }
        if(strcmp(input,"What is your name?")==0)
        {
            cout<<"My name is ALICE.";
        }
        if(strcmp(input,"Tell me a joke")==0)
        {
            cout<<" How do you measure a snake? In inches—they don’t have feet.";
        }
        if(strcmp(input,"Tell me about yourself?")==0)
        {
            cout<<"I am an AI chatbot.I am here to answer your questions and give you suggestions.I don't possess consciousness, emotions, or personal experiences. I work by predicting the most likely next word or phrase based on the patterns I've learned during my training. If you have any questions or need assistance, feel free to ask!.";
        }
        if(strcmp(input,"I am feeling sad.")==0)
        {
            cout<<"'m sorry to hear that you're feeling sad.I would suggest you to talk with your family and friends regarding this and share with them what is bothering you.It might you feel better."<<endl;
        }
        if(strcmp(input,"TAlice,cheer me up!")==0)
        {
            cout<<"What's an egg's favorite vacation spot? New Yolk City.";
        }
        if(strcmp(input,"What is the date today?")==0)
        {

               std::time_t currentTime = std::time(nullptr);

                std::tm *currentTm = std::localtime(&currentTime);

            std::cout << "Today's date is : " << (currentTm->tm_year + 1900) << "-"<< (currentTm->tm_mon + 1) << "-" << currentTm->tm_mday << std::endl;

        }
        if(strcmp(input,"bye")==0)
        {
           cout<<"Goodbye!Have a nice day."<<endl;
        }

        if(strcmp(input,"exit")==0)
        {
            break;
        }
    }
}
