/*****************************
Class Record
Implemented by Iman Tarmizi Rosalina (73496)
*****************************/

/*Class Record implementation file*/
#include<stdbool.h>
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include<cstring>
#include<regex>
#include<string.h>

#include "appointment.h"
#include "record.h"
#include "patient.h"
#include "doctor.h"

using namespace std;


/*Constructor*/
Record::Record(){}

/*Setter*/
void Record::setpatientID(string pid){patientID = pid;}
void Record::setpatientName(string pn){patientName = pn;}
void Record::setpatientAge(string pa){patientAge = pa;}
void Record::setDate(string d){Date = d;}
void Record::setTime(string t){Time = t;}
void Record::setdrugID(string did){drugID = did;}
void Record::setdrugName(string dn){drugName = dn;}
void Record::setdrugDes(string dd) {drugDes = dd;}
void Record::setillness(string ill) {illness = ill;}
void Record::setdiagnosis(string dia){diagnosis = dia;}


/*Getter*/
string Record::getpatientID() {return patientID;}
string Record::getpatientName() {return patientName;}
string Record::getpatientAge() {return patientAge;}
string Record::getDate() {return Date;}
string Record::getTime() {return Time;}
string Record::getdrugID() {return drugID;}
string Record::getdrugName() {return drugName;}
string Record::getdrugDes() {return drugDes;}
string Record::getillness() {return illness;}
string Record::getdiagnosis() {return diagnosis;}


//bool function to check the existence of patient ID
bool checkExistpatientID(const string& patientID)
{
	ifstream patReg("Record.txt");
	
	//variable declaration
	int i = 0, j = 0;
    string data[50][7];
    
    while(getline(patReg, data[i][j]))
    {
        j++;
        if(j>7){i++; j = 0;}
    }
        
    patReg.close();

    for(int x=0; x<=i; x++)
    {
        if(data[x][0] == patientID)
        {
        	return false;
        }
        else
        {
            if(x==i)
            {
            	return true;
            }
        }
    }
}


//function for patient to add record
void Record::addRecord()
{
	string pid, pn, pa, rd, rt, did, dn, dd, ill, dia, space;
	
	string cost;
	string kosong;
	char key;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "-------------------Add Record----------------------" << endl;
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n|               Record System (Record will have two record that will be combine)                      |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n|     (i) Prescription Record                      |";              
	cout << "\n|          - Drug ID (eg: A1438)                   |";
	cout << "\n|          - Drug Name (eg: Adruxin)               |";
	cout << "\n|          - Drug Description (eg: Eat once a day) |";
	cout << "\n|                                                  |";
	cout << "\n|     (i) Medical Record                           |";              
	cout << "\n|          - Patient Illness                       |";
	cout << "\n|          - Patient Diagnosis                     |";
	cout << "\n|          - Drug Description (eg: Eat once a day) |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n  Note: Record will have two record that will be combine \n";
	
	cout << "Please enter any key to continue or '0' to cancel: " << endl;
	key = getch();
	
	if(key == '0')
	{
		return;
	}
	
	fflush(stdin);
	cout << "\n   Enter patient ID ";
	cout << "\n   >> ";
	getline(cin, patientID);
	
	fflush(stdin);
	cout << "\n   Enter patient name";
	cout << "\n   >> ";
	getline(cin, patientName);
	
	fflush(stdin);
	cout << "\n   Enter patient age";
	cout << "\n   >> ";
	getline(cin, patientAge);
	
	fflush(stdin);
	cout << "\n   Enter patient record date (In DD/MM/YY format)";
	cout << "\n   >> ";
	getline(cin, Date);
	
	fflush(stdin);
	cout << "\n   Enter patient record time (In 24-Hour format)";
	cout << "\n   >> ";
	getline(cin, Time);
		
	//prescription record
	fflush(stdin);
	cout << "\n   Enter patient drug ID";
	cout << "\n   >> ";
	getline(cin, drugID);
	
	fflush(stdin);
	cout << "\n   Enter patient drug name";
	cout << "\n   >> ";
	getline(cin, drugName);
	
	fflush(stdin);
	cout << "\n   Enter patient drug description";
	cout << "\n   >> ";
	getline(cin, drugDes);
	
	//medical record
	fflush(stdin);
	cout << "\n   Enter patient illness";
	cout << "\n   >> ";
	getline(cin, illness);
	
	fflush(stdin);
	cout << "\n   Enter patient diagnosis";
	cout << "\n   >> ";
	getline(cin, diagnosis);

	ofstream patrecord;
	patrecord.open("Record.txt", ofstream::app);
	patrecord <<      getpatientID() << endl;
	patrecord <<      getpatientName() << endl;
	patrecord <<      getpatientAge() << endl;
	patrecord <<      getDate() << endl;
	patrecord <<      getTime() << endl;
	patrecord <<      getdrugID() << endl;
	patrecord <<      getdrugName() << endl;
	patrecord <<      getdrugDes() << endl;
	patrecord <<      getillness() << endl;
	patrecord <<      getdiagnosis() << endl;
	
	patrecord.close();
    cout << "\n---------------------------------------------------";
    cout << "\n";
	cout << "The patient record has been saved successfully in the system." << endl;
	cout << "\n";
	system("  pause");


}


//function for doctor to remove appointment
void Record::removeRecord()
{
	//variable declaration
	char yes_no, key;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "--------------------Remove Record--------------------" << endl; 
	
	cout << "\n  Do you want remove record ?";
	cout << "\n  Note: All record will be removed if you choose still want to proceed";
	cout << "\n  Enter any key to continue or '0' to cancel: ";
	
	key = getch();
	
	if(key == '0')
	{
		return;
	}
	else
	{
	
	ifstream patrecord;
	patrecord.open("Record.txt");
	if(!patrecord)
	{
		cout << "\n Sorry but there is no record in the system. \n";
		system("  pause");
		
		patrecord.close();
		
		return;
	}
	
	patrecord.close();
	viewRecord();
	
	fflush(stdin);
	
	cout << " \n  Enter any key to cancel all appointments/'X' to exit: ";
	yes_no = getch();
		
	if(yes_no == 'X' || yes_no == 'x')
	{
		cout << endl;
		system("  pause");
		
		return;
	}
	
	else
	{
		fflush(stdin);
		ofstream deleterecord;
		deleterecord.open("Record.txt", ofstream::out | ofstream::trunc);
		deleterecord.close();
		remove("Record.txt");
    }
	    cout << "\n\n  All records have been successfully deleted from the system. ";
    }
    
	system("\n  pause");		
	
}


//function for doctor to edit record
void Record::editRecord() {

    //variable declaration
	string rd, rt, pid, pn, pa, did, dn, dd, ill, dia, space, find, line;
	int choice;
	char key;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
    cout << "\n";
    cout << "------------------Edit Record----------------------" << endl;
	cout << "\n  Do you want to edit the record?"<< endl;
	cout << "  Enter any key to continue or '0' to cancel: ";
	key = getch();
	
	if(key == '0')
	{
		return;
	}
	else
	{
		fflush(stdin);
		cout << "\n\n     Please enter a Patient ID that you want to update"<<endl;
		cout << "     >> ";
   		cin >> find;
   		
   		ifstream patrecord; //for reading records
  		patrecord.open("Record.txt");
  		
	    ofstream tempRecord;
	    tempRecord.open("tempRecord.txt");
	    
	    while (getline(patrecord, line))
	    {
	      if (line != find)
	        tempRecord << line << endl;
	    }
	    
	    patrecord.close();
	    tempRecord.close();
	    
	    remove("Record.txt"); //remove the previous record
	    rename("tempRecord.txt", "Record.txt");  //rename the previous record
		
		cout << "\n-----------------------------------------------------" << endl; 
		
		fflush(stdin);
		cout << "\n     New patient ID" << endl;
		cout << "     >> ";
		getline(cin, patientID);
		
		fflush(stdin);
		cout << "\n     New patient record name" << endl;
		cout << "     >> ";
		getline(cin, patientName);
		
		fflush(stdin);
		cout << "\n     New patient record age" << endl;
		cout << "     >> ";
		getline(cin, patientAge);
		
		fflush(stdin);
		cout << "\n     New patient record date (In DD/MM/YY format)" << endl;
		cout << "     >> ";
		getline(cin, Date);
		
		fflush(stdin);
		cout << "\n     New patient record time (In 24-hour format)" << endl;
		cout << "     >> ";
		getline(cin, Time);
		
		// prescription record
		fflush(stdin);
		cout << "\n     New patient record drug ID" << endl;
		cout << "     >> ";
		getline(cin, drugID);
		
		fflush(stdin);
		cout << "\n     New patient record drug name" << endl;
		cout << "     >> ";
	    getline(cin, drugName);
		
		fflush(stdin);
		cout << "\n     New patient record drug description" << endl;
		cout << "     >> ";
		getline(cin, drugDes);
		
		//medical record
		fflush(stdin);
		cout << "\n     New patient record ilness " << endl;
		cout << "     >> ";
		getline(cin, illness);
		
		fflush(stdin);
		cout << "\n     New patient record diagnosis " << endl;
		cout << "     >> ";
		getline(cin, diagnosis);
		
		cout << "\n-----------------------------------------------------" << endl;
        cout << "\n";
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "               **Updated Record**                    " << endl;
	    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
		cout << "     " << patientID << endl;
		cout << "     " << patientName << endl;
		cout << "     " << patientAge << endl;
		cout << "     " << Date << endl;
		cout << "     " << Time << endl;
		cout << "     " << drugID << endl;
		cout << "     " << drugName << endl;
		cout << "     " << drugDes << endl;
		cout << "     " << illness << endl;
		cout << "     " << diagnosis << endl;
		cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			
		cout << "\n  Confirmation (Yes [1]/ Cancel [0])" << endl;
		cout << "  >> ";
		cin >> choice;

		if (choice == 0)
		{
			cout << "  Sorry but there is no update is done! Please try again." << endl;
		}
		else
		{

			ofstream patrecord;
		    patrecord.open("Record.txt", ios::app | ios::out);
		    patrecord << patientID << endl;
		    patrecord << patientName << endl;
		    patrecord << patientAge << endl;
		    patrecord << Date << endl;
		    patrecord << Time << endl;
		    patrecord << drugID << endl;
		    patrecord << drugName << endl;
		    patrecord << drugDes << endl;
		    patrecord << illness << endl;
		    patrecord << diagnosis << endl << endl;

			
			cout << "  Record have been successfully updated in the system." << endl;
			viewRecord();
		}
	}
}


//function for doctor to view record
void Record::viewRecord()
{
	string rd, rt, pid, pn, pa, did, dn, dd, ill, dia, space;
	int i = 1, n = 1;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "     SMART HEALTH CONSULTING SYSTEM (Doctor View)    " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "------------------View Record----------------------" << endl;
	cout << "\n";
	ifstream patrecord;
	patrecord.open("Record.txt");
	if(!patrecord)
	{
		cout << "\n Sorry but there is no record in the system. ";
		system("  pause");
		patrecord.close();
	}
	else
	{
		while(!patrecord.eof())
		{
		getline(patrecord,pid);
		getline(patrecord,pn);
		getline(patrecord,pa);
		getline(patrecord,rd);
		getline(patrecord,rt);
		getline(patrecord,did);
		getline(patrecord,dn);
		getline(patrecord,dd);
		getline(patrecord,ill);
		getline(patrecord,dia);	
			
			getline(patrecord, space);
			fflush(stdin);
			cout << "     (" << n << ") Patient ID: " << pid << "\n";
			cout << "     Name: " << pn << "\n";
			cout << "     Age: " << pa << "\n";
			cout << "     Date: " << rd << "\n";
			cout << "     Time: " << rt << "\n";
			cout << "     Drug ID: " << did << "\n";
			cout << "     Drug Name: " << dn << "\n";
			cout << "     Drug Description: " << dd << "\n";
			cout << "     Illness: " << ill << "\n";
			cout << "     Diagnosis: " << dia << "\n";
			cout << space;
			
			i++;
		}
		
	}
	patrecord.close();
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	system("\n  pause");
}

//function for patient to view the record from the patient menu 
void Record::viewpatientRecord()
{
	string rd, rt, pid, pn, pa, did, dn, dd, ill, dia, space;
	char cont;
	
	int i = 1;
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "    SMART HEALTH CONSULTING SYSTEM (Patient View)    " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "------------------View Record----------------------" << endl;
	cout << "\n";
	
	//do-while loop
	do{
	
	fflush(stdin);
	cout << "     Please enter your patient ID";
	cout << "\n     >> ";
	cin >> patientID;
	
		
	ifstream patrecord("Record.txt");
	patrecord.open("Record.txt");
		
	if(!checkExistpatientID(patientID))
	{
			cerr << "\n  Sorry but this patient ID is not exist in the record. Please enter other patient ID." << endl;
    }
	else if(!patrecord)
	{
		cout << "\n Sorry but there is no record in the system. \n";
		system("  pause");
		patrecord.close();
	}	
	else
	{
		while(!patrecord.eof())
		{
		getline(patrecord,pid);
		getline(patrecord,pn);
		getline(patrecord,pa);
		getline(patrecord,rd);
		getline(patrecord,rt);
		getline(patrecord,did);
		getline(patrecord,dn);
		getline(patrecord,dd);
		getline(patrecord,ill);
		getline(patrecord,dia);
			
			
			
			getline(patrecord, space);
			cout<<"     Patient ID: "<<pid<<"\n";
			cout<<"     Name: "<<pn<<"\n";
			cout<<"     Age: "<<pa<<"\n";
			cout<<"     Date: "<<rd<<"\n";
			cout<<"     Time: "<<rt<<"\n";
			cout<<"     Drug ID: "<<did<<"\n";
			cout<<"     Drug Name: "<<dn<<"\n";
			cout<<"     Drug Description: "<<dd<<"\n";
			cout<<"     Illness: "<<ill<<"\n";
			cout<<"     Diagnosis: "<<dia<<"\n";
			cout << space;
			
			i++;
		}
		
	}
	patrecord.close();
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	
	cout << "\n  Do you want to continue? [Y/N]";
	cout << "\n  >> ";
	cin >> cont;
		
    	}while( cont == 'Y' || cont == 'y');	

	system("\n\n  pause");
}

