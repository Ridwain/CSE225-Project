#ifndef UNSORTEDTYPE_H_INCLUDED
#define UNSORTEDTYPE_H_INCLUDED
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
    Event();
    Event(int id, string t, string desc, string d, string tme, string loc);
    int getEventID();
    string getTitle();
    string getDescription();
    string getDate();
    string getTime();
    string getLocation();
    void setId(int id);
    void setTitle(string t);
    void setDescription(string description);
    void setDate(string d);
    void setTime(string t);
    void setLoc(string loc);
    void addAttendee(string attendee);
    void removeAttendee(string attendee);
    //Event createEvent();
};
#endif