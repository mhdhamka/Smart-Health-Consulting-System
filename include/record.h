#ifndef RECORD_H
#define RECORD_H

#include <string>

using namespace std;


class Record
{

private:

    string patientID;
    string patientName;
    string patientAge;

    string Date;
    string Time;

    string drugID;
    string drugName;
    string drugDes;

    string illness;
    string diagnosis;


public:

    Record();


    void addRecord();
    void viewRecord();
    void viewpatientRecord();
    void editRecord();       
    void removeRecord();     

    void setpatientID(string);
    void setpatientName(string);
    void setpatientAge(string);

    void setDate(string);
    void setTime(string);

    void setdrugID(string);
    void setdrugName(string);
    void setdrugDes(string);

    void setillness(string);
    void setdiagnosis(string);


    string getpatientID();
    string getpatientName();
    string getpatientAge();

    string getDate();
    string getTime();

    string getdrugID();
    string getdrugName();
    string getdrugDes();

    string getillness();
    string getdiagnosis();


};


#endif
