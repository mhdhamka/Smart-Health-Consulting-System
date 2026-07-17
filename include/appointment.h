#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>


using namespace std;


class Appointment
{

private:

    string AppointmentID;
    string AppointmentDate;
    string AppointmentTime;
    string AppointmentIllness;
    string AppointmentDoctor;
    string AppointmentSpecialization;


public:

    Appointment();


    void setAppointmentID(string);
    void setAppointmentDate(string);
    void setAppointmentTime(string);
    void setAppointmentIllness(string);
    void setAppointmentDoctor(string);
    void setAppointmentSpecialization(string);


    string getAppointmentID();
    string getAppointmentDate();
    string getAppointmentTime();
    string getAppointmentIllness();
    string getAppointmentDoctor();
    string getAppointmentSpecialization();


    void appMenu();
    void addAppointment();
    void editAppointment();
    void deleteAppointment();
	void removeAppointment();
    void viewAppointment();
    void payment();

};


#endif