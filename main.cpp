#include<iostream>
#include "eventManager.cpp"
#include "menu.h"
#include "fileHandling.h"
#include<stdlib.h>
using namespace std;
int main()
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
        else if(choice==6){
            cout<<"Enter The Event ID : ";
            int eventID;
            cin>>eventID;
            EventNode* eventNode = eventlist.findEventByID(eventID);
            system("clear");
            cout<<"1. Add Participants \n2.Remove Participants\n";
            int decision;
            cin>>decision;
            system("clear");
            if(decision == 1){
                cout<<"Enter The Name Of The Participant : ";
                string name;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                getline(cin,name);
                eventNode->event.addParticipants(name);
                system("clear");

                cout<<"SuccessFully Added\n"<<endl;
                cout<<"\nPress '0' to go back to 'Main Menu'"<<endl;
                int goBack;
                cin>>goBack;
                if(goBack==0){
                    system("clear");
                    continue;
                }

            }
            

            
        }
        cout<<"\n";
    }
    
}