//
// Created by Ridwain Islam on 19/6/24.
//

#include<iostream>

using namespace std;

class Event{
private:
int eventID;
string title;
string description;
string date;
string time;
string location;

public:
Event() {

}
Event(int id, string t, string desc, string d, string tme, string loc)
        : eventID(id), title(t), description(desc), date(d), time(tme), location(loc) {};

int getEventID(){
    return eventID;
}

string getTitle(){
    return title;
}
string getDescription(){
    return description;
}
string getDate(){
    return date;
}
string getTime(){
    return time;
}
string getLocation(){
    return location;
}
void setId(int id){
    this->eventID = id;
}
void setDescription(string description){
    this->description = description;
}
void setTitle(string t){
    this->title = t;
}
void setTime(string t){
    this->time = t;
}
void setDate(string d){
    this->date = d;
}
void setLoc(string loc){
    this->location = loc;
}

// void Event::addAttendee(string attendee) {
//         attendees.push_back(attendee);
// }

// void Event::removeAttendee(string attendee) {
//     for (auto it = attendees.begin(); it != attendees.end(); ++it) {
//         if (*it == attendee) {
//             attendees.erase(it);
//             break;
//         }
//     }
// }
};
