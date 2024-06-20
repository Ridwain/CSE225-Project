#ifndef FILEHANDLING_H_INCLUDING
#define FILEHANDLING_H_INCLUDING


#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
const int MAX_LINES = 10000;



void fileWrite(int eventID,string title,string description,string date,string time,string location)
{
    ofstream out("eventInfo.txt",ios::app);
    //out<<"\n";
    out<<"Event ID : "<<eventID<<"\n"<<"Event Title : "<<title<<"\n"<<"Event Description : "<<description<<"\n"<<"Event Date : "<<date<<"\n"<<"Event time : "<<time<<"\n"<<"Event Location : "<<location<<"\n\n";
    out.close();
}

void updatedFileWrite(int eventID,string title,string description,string date,string time,string location)
{
    ofstream out("eventInfo.txt",ios::app);
    //out<<"\n";
    out<<"--->Updated<---\n";
    out<<"Event ID : "<<eventID<<"\n"<<"Event Title : "<<title<<"\n"<<"Event Description : "<<description<<"\n"<<"Event Date : "<<date<<"\n"<<"Event time : "<<time<<"\n"<<"Event Location : "<<location<<"\n\n";
    out.close();
}



#endif //FILEHANDLING_H_INCLUDING