/******************************
Class Appointment
Implemented by Mohammad Amir Alam Bin Rahim Omar (73563)
******************************/

/*Class Appointment header file*/
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>

#include "user.h"
#include "record.h"
using namespace std;

class Appointment
{
	private:
		/*Private attributes only in class Appointment*/
		string AppointmentID;
		string AppointmentDate;
		string AppointmentTime;
		string AppointmentIllness;
		string AppointmentDoctor;
		string AppointmentSpecialization;
	
	
	public:
		//Public methods
		
		//Constructor
		Appointment();
		
		/*Setter*/
		void setAppointmentID(string apid);
		void setAppointmentDate(string apd);
		void setAppointmentTime(string apt);
		void setAppointmentIllness(string apil);
		void setAppointmentDoctor(string apdoc);
		void setAppointmentSpecialization(string apspe);
		
		/*Getter*/
		string getAppointmentID();
		string getAppointmentDate();
		string getAppointmentTime();
		string getAppointmentIllness();
		string getAppointmentDoctor();
		string getAppointmentSpecialization();
	
		// Public function
		void appMenu();
		void addAppointment();
		void removeAppointment();
		void editAppointment();
		void viewAppointment();
		void payment();
		
	
};

#endif
