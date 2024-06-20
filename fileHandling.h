#ifndef FILEHANDLING_H_INCLUDING
#define FILEHANDLING_H_INCLUDING


#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;




void fileWrite(int eventID,string title,string description,string date,string time,string location)
{
    ofstream out("eventInfo.txt",ios::app);
    out<<"\n";
    out<<"Event ID : "<<eventID<<"\n"<<"Event Title : "<<title<<"\n"<<"Event Description : "<<description<<"\n"<<"Event Date : "<<date<<"\n"<<"Event time : "<<time<<"\n"<<"Event Location : "<<location<<"\n";
    out.close();
}

// void fileRead()



#endif //FILEHANDLING_H_INCLUDING