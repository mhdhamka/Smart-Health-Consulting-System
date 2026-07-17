#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>

using namespace std;


class Doctor
{

private:

    string username;
    string password;

    string doctorName;
    string doctorSpecialization;


public:

    Doctor();


    void setDoctorName(string);
    void setDoctorSpecialization(string);


    string getDoctorName();
    string getDoctorSpecialization();


    void login();
    void doctorMenu();


};


#endif