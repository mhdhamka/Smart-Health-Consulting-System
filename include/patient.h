#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;


class Patient
{
private:

    string username;
    string password;

    string patientID;
    string patientName;
    string patientAge;
    string patientAddress;
    string email;
    string phone;
    string medicalHistory;


public:

    Patient();

    void setpatientID(string);
    void setpatientName(string);
    void setpatientAge(string);
    void setpatientAddress(string);
    void setphone(string);
    void setmedicalHistory(string);

    string getpatientID();
    string getpatientName();
    string getpatientAge();
    string getpatientAddress();
    string getphone();
    string getmedicalHistory();

    void registration();
    void login();
    void patientPlatform();

    void viewProfile();
    void editProfile();

};

#endif
