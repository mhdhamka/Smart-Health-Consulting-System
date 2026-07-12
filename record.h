/******************************
Class Record
Implemented by Iman Tarmizi Rosalina (73496)
******************************/

/*Class Record header file*/
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>

#include "record.h"
using namespace std;

class Record
{
	private:
		/*Private attributes only in class Record*/
		string Date;
		string Time;
		string patientID;
		string patientName;
		string patientAge;
		string drugID;
		string drugName;
		string drugDes;
		string illness;
		string diagnosis;
	
	
	public:
		//Public methods
		
		//Constructor
		Record();
		
		/*Setter*/
		void setDate(string d);
		void setTime(string t);
		void setpatientID(string pid);
		void setpatientName(string pn);
		void setpatientAge(string pa);
		void setdrugID(string did);
		void setdrugName(string dn);
		void setdrugDes(string dd);
		void setillness(string ill);
		void setdiagnosis(string dia);
	
	
		
		/*Getter*/
		string getDate();
		string getTime();
		string getpatientID();
		string getpatientName();
		string getpatientAge();
		string getdrugID();
		string getdrugName();
		string getdrugDes();
		string getillness();
		string getdiagnosis();
	
		
		// Public function
		void addRecord();
		void removeRecord();
		void editRecord();
		void viewRecord(); //view record for doctor
		void viewpatientRecord(); //view record for patient
		

	
};

#endif
