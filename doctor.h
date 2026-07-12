/******************************
Class Doctor
Implemented by Azreen Shafieqah Binti Asri (74251)
******************************/

/*Class Doctor header file*/
#ifndef DOCTOR_H
#define DOCTOR_H

#include<iostream>
#include<string>
#include "user.h"
using namespace std;

class Doctor : public User
{
	private:
		/*Private attributes only in class Doctor*/
		string doctorName;
        string doctorSpecialization;
        
        
	public:
		//Public methods
		
		//Constructor
		Doctor();
		
		/*Setter*/
		void setDoctorName(string dn);
        void setDoctorSpecialization(string ds);
        
        /*Getter*/
        string getDoctorName();
        string getDoctorSpecialization();
        
        
        //Public function
        void login();
        void doctorMenu();
        void checkApp();
        void checkPatient(); 
};

#endif
