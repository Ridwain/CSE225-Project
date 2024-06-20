#include "eventNode.cpp"
//#include<cstdlib>
#include<chrono>
#include<random>
// Linked list class
class EventManager {
private:
    EventNode* head;
    

public:
    EventManager() : head(nullptr) {}

    // Destructor to free memory
    ~EventManager() {
        EventNode* current = head;
        while (current) {
            EventNode* next = current->next;
            delete current;
            current = next;
        }
    }

    // Method to append an event to the linked list
    void appendEvent(Event e) {  // O(n)
        EventNode* newNode = new EventNode(e);
        if (!head) {
            head = newNode;
        } else {
            EventNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Method to display all events
    void displayEvents() const { //O(n)
        EventNode* current = head;
        if(current==NULL){
            cout<<"SORRY , THERE IS NO EVENT RIGHT NOW \n"<<endl;
        }
        else{
            cout<<"All Events Are : \n";
            while (current) {
                cout << "Event ID       : " << current->event.getEventID() << endl;
                cout << "Title          : " << current->event.getTitle() << endl;
                cout << "Description    : " << current->event.getDescription() << endl;
                cout << "Date           : " << current->event.getDate() << endl;
                cout << "Time           : " << current->event.getTime() << endl;
                cout << "Location       : " << current->event.getLocation() << endl;
                cout << "Attendees      : ";
                cout << endl << "-----------------------------" << endl;
                current = current->next;
            }
        }
    }

    // Method to search for events by title
    void searchEventByTitle(string title) const {  //O(n)
        EventNode* current = head;
        bool found = false;
        while (current!=NULL) {
            if (current->event.getTitle() == title) {
                cout << "Event found:" << endl;
                cout << "Event ID    : " << current->event.getEventID() << endl;
                cout << "Title       : " << current->event.getTitle() << endl;
                cout << "Description : " << current->event.getDescription() << endl;
                cout << "Date        : " << current->event.getDate() << endl;
                cout << "Time        : " << current->event.getTime() << endl;
                cout << "Location    : " << current->event.getLocation() << endl;
                cout << "Attendees   : ";
                // for (const auto& attendee : current->event.getAttendees()) {
                //     cout << attendee << ", ";
                // }
                cout << endl << "-----------------------------" << endl;
                found = true;
            }
            current = current->next;
        }
        if (found==false) {
            cout << "Event with title \"" << title << "\" not found." << endl;
        }
    }
    

    // Method to delete an event by ID
    void deleteEventByID(int id) { //O(n)
        if (!head) {
            cout << "Event list is empty." << endl;
            return;
        }

        EventNode* current = head;
        EventNode* prev = nullptr;

        // If head node itself holds the event to be deleted
        if (current != nullptr && current->event.getEventID() == id) {
            head = current->next;
            delete current;
            cout << "Event with ID " << id << " deleted successfully." << endl;
            return;
        }

        // Search for the event to be deleted
        while (current != nullptr && current->event.getEventID() != id) {
            prev = current;
            current = current->next;
        }

        // If the event was not found
        if (current == nullptr) {
            cout << "Event with ID " << id << " not found." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = current->next;
        delete current;
        cout << "Event with ID " << id << " deleted successfully." << endl;
    }

    // Function To Check If A Room Is Already Occupied by any event
    int checkSchedule(string location,int id){ //O(n)
        EventNode* current = head;
        bool found = false;
        
        while(current){
            if(current->event.getEventID()!=id && current->event.getLocation() == location){
                return 1;
            }
            current = current->next;
        }
        return 0;
    }

    // Function to create event Node 
    Event createEvent(){ //O(1)
        Event ev;
        int id; string t; string desc; string d; string time; string loc;

        auto timeNow = std::chrono::system_clock::now().time_since_epoch().count();

        // Using the time as a seed for the random number generator
        mt19937 generator(timeNow);

        // Defining the range for the random number
        uniform_int_distribution<int> distribution(10000, 90000);

        // Generating a unique random number
        id = distribution(generator);
        
        ev.setId(id);
        cout<<"Your Event ID           : "<<id<<endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"\nEnter Event Title       : ";
        getline(cin, t);
        ev.setTitle(t);
        
        cout<<"\nEnter Event Description : ";
        getline(cin, desc);
        ev.setDescription(desc);
        

        cout<<"\nEnter Event Date        : ";
        cin>>d;
        ev.setDate(d);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout<<"\nEnter Event Time        : ";
        getline(cin, time);
        ev.setTime(time);
        int result = 1;
       
        while(true){
            cout<<"\nEnter Event Location    : ";
            getline(cin, loc); 
            
            result = checkSchedule(loc,id);
            if(result==1){
                cout<<"SORRY , There is another event on that location .\nPlease Choose Another Venue .:) \n";
            }
            else if(result==0){
                break;
            }
        }
        ev.setLoc(loc);
        
        return ev;
    }
    
    // Function to Update Event Info
    void updateEvent(){ //O(n)
        int choice1;
        //Event ev;
        cout<<"Please Enter The Event Id To Update : ";
        cin>>choice1;
        system("clear");
        EventNode* current = head;
        bool found = false;
        if(head==NULL){
            cout << "Event with ID \"" << choice1 << "\" not found." << endl;
            cout<<"\nPress '0' to go back to menu : ";
            int goBack;
            cin>>goBack;
            system("clear");
        }
        else{
            while (current!=NULL) {
                if (current->event.getEventID() == choice1) {
                    int doAgain=1;
                    while(doAgain!=0){
                        cout<<"Please Enter Your Choice To Update the event : ";
                        cout<<"\n1. Event title \n"<<"2. Event Description \n"<<"3. Event Date \n"<<"4. Event Time \n"<<"5. Event Location \n";
                        cout<<"Please Enter Your Choice To Update the event : ";
                        int option;
                        cin>>option;
                        
                        system("clear");
                        if(option==1){
                            cout<<"Please Enter The Updated Title For Your Event : ";
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            string updatedEventTitle;
                            getline(cin, updatedEventTitle);
                            current->event.setTitle(updatedEventTitle);
                        }
                        else if(option==2){
                            cout<<"Please Enter The Updated Description For Your Event : ";
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            string updatedEventDescription;
                            getline(cin, updatedEventDescription); 
                            current->event.setDescription(updatedEventDescription);
                        }
                        else if(option==3){
                            cout<<"Please Enter The Updated Date For Your Event : ";
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            string updatedEventDate;
                            getline(cin, updatedEventDate); 
                            current->event.setDate(updatedEventDate);
                        }
                        else if(option==4){
                            cout<<"Please Enter The Updated Time For Your Event : ";
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            string updatedEventTime;
                            getline(cin, updatedEventTime); 
                            current->event.setTime(updatedEventTime);
                        }
                        else if(option==5){
                            int result = 1;
                            string updatedEventLocation;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            while(true){
                                cout<<"\nEnter Event Location    : ";
                                getline(cin, updatedEventLocation); 
                                //loc.erase(remove(loc.begin(), loc.end(), ' '), loc.end());
                                result = checkSchedule(updatedEventLocation,choice1);
                                if(result==1){
                                    cout<<"SORRY , There is another event on that location .\nPlease Choose Another Venue .:) \n";
                                }
                                else if(result==0){
                                    break;
                                }
                            }
                            current->event.setLoc(updatedEventLocation);
                        }
                        system("clear");
                        cout<<"Do You Want to Continue Updating This Event : \nIf 'Yes' Then Press '1' ,\nOtherwise Press '0'\n";
                        
                        cin>>doAgain;
                        if(doAgain==1){
                            system("clear");
                            continue;
                        }else if(doAgain==0){
                            break;
                        } else{
                            continue;
                        }
                    }
                    found = true;
                    break;
                }
                current = current->next;
            }
            if(found==true){
                system("clear");
                cout<<"EVENT UPDATED \n";
                cout<<"\nPress '0' to go back to menu : ";
                int goBack;
                cin>>goBack;
                system("clear");
                
            }
            else if (found==false) {
                //system("clear");
                cout << "Event with ID \"" << choice1 << "\" not found." << endl;
                cout<<"\nPress '0' to go back to menu : ";
                
                int goBack;
                cin>>goBack;
                system("clear");
            }
        }

    }
    
};