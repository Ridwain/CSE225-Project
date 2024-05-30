
#include<iostream>
#include "event.h"
using namespace std;
Event::Event(){

}
Event::Event(int id, string t, string desc, string d, string tme, string loc)
        : eventID(id), title(t), description(desc), date(d), time(tme), location(loc) {};
        
int Event::getEventID(){
    return eventID;
}

string Event::getTitle(){ 
    return title; 
}
string Event::getDescription(){ 
    return description; 
}
string Event::getDate(){ 
    return date; 
}
string Event::getTime(){
    return time; 
}
string Event::getLocation(){ 
    return location; 
}
void Event::setId(int id){
    this->eventID = id;
}
void Event:: setDescription(string description){
    this->description = description;
}
void Event::setTitle(string t){
    this->title = t;
}
void Event::setTime(string t){
    this->time = t;
}
void Event::setDate(string d){
    this->date = d;
}
void Event::setLoc(string loc){
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
 
