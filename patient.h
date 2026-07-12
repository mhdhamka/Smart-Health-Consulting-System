/******************************
Class Patient
Implemented by Mohammad Hamka Izzuddin Bin Mohamad Yahya (73571)
******************************/

/*Class patient header file*/
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

#include "user.h"

using namespace std;

class Patient : public User
{
    private: 
    	//Private attributes only in class Patient
   	   string patientID;        
	   string patientName;      
	   string patientAge;       
	   string patientAddress;   
	   string phone;            
	   string medicalHistory;   

    public:
    	//Public methods
		
		//Constructor
        Patient();

		/*Setter*/
        void setpatientID(string pid);
        void setpatientName(string pn);
        void setpatientAge(string pa);
        void setpatientAddress(string padd);
        void setphone(string ph);
        void setmedicalHistory(string mh);
		
		/*Getter*/
        string getpatientID();
        string getpatientName();
        string getpatientAge();
        string getpatientAddress();
        string getphone();
        string getmedicalHistory();
		
		//Public function
        void registration();
        void login();
        void patientPlatform();
        void viewProfile();
        void editProfile();
};

#endif
