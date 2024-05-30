#include<iostream>
#include "eventManager.cpp"
#include "menu.h"
#include "fileHandling.h"
#include<stdlib.h>
using namespace std;
int main(void)
{
    EventManager eventlist;
    ascii1();
    while(true){
        menu();
        cout<<"\n\nEnter Your Choice : ";
        int  choice;
        cin>>choice;
        system("clear");
        if(choice==1){
            Event event = eventlist.createEvent();

            eventlist.appendEvent(event);
            fileWrite(event.getEventID(),event.getTitle(),event.getDescription(),event.getDate(),event.getTime() ,event.getLocation());
            system("clear");
            cout<<"EVENT CREATED SUCCESSFULLY\n";
            cout<<"\nPress '0' to go back to 'Main Menu'"<<endl;
            int decision;
            cin>>decision;
            if(decision==0){
                system("clear");
                continue;
            }     
        }
        else if(choice==2){
            eventlist.updateEvent();
        }
        else if(choice==3){
            cout<<"Enter the eventID that you want to delete : ";
            int idNumber;
            cin>>idNumber;
            eventlist.deleteEventByID(idNumber);
            cout<<"Press '0' to go back to 'Main Menu'"<<endl;
            int decision;
            cin>>decision;
            if(decision==0){
                system("clear");
                continue;
            }     
        }
        else if(choice==4){
            eventlist.displayEvents();
            cout<<"\nPress '0' to go back to 'Main Menu'"<<endl;
            int decision;
            cin>>decision;
            if(decision==0){
                system("clear");
                continue;
            }     
               
        }
        else if(choice==5){
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please Enter The Title of your Event : ";
            string title;
            getline(cin,title);
            
            eventlist.searchEventByTitle(title);
            cout<<"\nPress '0' to go back to 'Main Menu'"<<endl;
            int decision;
            cin>>decision;
            if(decision==0){
                system("clear");
                continue;
            }     
        }
        cout<<"\n";
    }
    
}