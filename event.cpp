#include<iostream>
using namespace std;
const int MAX_PARTICIPANTS = 100;
int participantsCount=0;
class Event{
private:
int eventID;
string title;
string description;
string date;
string time;
string location;
string participants[MAX_PARTICIPANTS];


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
int getParticipantsCount(){
    return participantsCount;
}
string getParticipants(int index) {
    
    if(index >= 0 && index < participantsCount) {
        return participants[index]; 
    }
    return "";
}

void addParticipants(string participant){
    if(participantsCount<MAX_PARTICIPANTS){
        participants[participantsCount++]=participant;
    } else{
        cout<<"Maximum Limit Reached. Can't Add More ."<<endl;
    }
}

void removeParticipants(string participant){
    bool remove = false;
    for (int i = 0; i < participantsCount; i++) {
        if (participants[i] == participant) {
            for (int j = i; j < participantsCount - 1; j++) {
                participants[j] = participants[j + 1];
            }
            --participantsCount;
            remove = true;
            cout<<"SuccessFully Removed\n"<<endl;
            return;
        }
    }
    if(remove == false){
        cout<<"No Participant Found With this Name . '"<<participant<<"'"<<endl;
        return;
    }
}

};
