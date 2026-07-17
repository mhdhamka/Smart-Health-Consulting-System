
/*Class Hospital header file*/
#ifndef HOSPITAL_H
#define HOSPITAL_H

#include<iostream>
#include<string>
#include "user.h"
using namespace std;

class Hospital : public User
{
	private:
		/*Private attributes only in class Hospital*/
		string hospitalName;
		string receiptID;
		string patientID;
		string patientName;
		string patientAge;
		string receiptdate;
		string receipttime;
		string drugID;
		string drugName;
		string drugDes;
		string illness;
		string diagnosis;
        
        
        
	public:
		//Public methods
		
		//Constructor
		Hospital();
		
		/*Setter*/
		void sethospitalName(string hn);
		void setreceiptID(string rid);
		void setpatientID(string pid);
		void setpatientName(string pn) ;
		void setpatientAge(string pa);
		void setreceiptdate(string rd);
		void setreceipttime(string rt) ;
		void setdrugID(string did);
		void setdrugName(string dn) ;
		void setdrugDes(string dd) ;
		void setillness(string ill);
		void setdiagnosis(string di);

        
        
        /*Getter*/
        string gethospitalName();
		string getreceiptID() ;
		string getpatientID() ;
		string getpatientName(); 
		string getpatientAge(); 
		string getreceiptdate(); 
		string getreceipttime(); 
		string getdrugID() ;
		string getdrugName(); 
		string getdrugDes();
		string getillness();
		string getdiagnosis(); 

      
        
        
        //Public function
        void login();
        void hospitalMenu();
        void generateReceipt();
        void viewReceipt();
        
};

#endif
