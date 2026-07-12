/******************************
Class Doctor
Implemented by Azreen Shafieqah Binti Asri (74251)
******************************/

/*Class Doctor implementation file*/
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

#include "record.h"
#include "doctor.h"
#include "appointment.h"
using namespace std;

//classes
Appointment App;
Record Rec;

/*Constructor*/
Doctor::Doctor()
{
	//preset username for doctor login
	username = "PDC1365";
	password = "74251";
	doctorName = "Azreen Shafieqah";
    doctorSpecialization = "Paediatric ";	
    
}

/*Setter*/
void Doctor::setDoctorName(string dn){doctorName = dn;}
void Doctor::setDoctorSpecialization(string ds){doctorSpecialization = ds;}


/*Getter*/
string Doctor::getDoctorName() {return doctorName;}
string Doctor::getDoctorSpecialization() {return doctorSpecialization;}


//Function to let doctor login
void Doctor::login()
{
	//variable declaration
	string docId, docPass;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "    SMART HEALTH CONSULTING SYSTEM (Doctor Login)    " << endl;
	cout << "=====================================================" << endl;
	fflush(stdin);
	
	cout << "--------------------------------------------------------\n";
	
	//doctor username = PDC1365
	cout << "\n   Please enter your  Doctor ID";		
	cout << "\n   >> ";
	getline(cin, docId);
	
	//password = 74251
	cout << "\n   Please enter your password";    
	cout << "\n   >> ";
	getline(cin, docPass);
	
	cout << "\n--------------------------------------------------------";
	
	if(docId == username && docPass == password )
	{
		cout << "\n  Welcome Doctor " << doctorName << "!  You have successfully login to the system.\n" << endl;
		system("  pause");
		fflush(stdin);
		doctorMenu();
	}
	else
	{
		cout << "\n  Sorry but you have entered an invalid doctor username or password! Please try again.\n" << endl;
		system("  pause");
	}
}


//Function to doctor menu 
void Doctor::doctorMenu()
{
	//variable declaration
	char docOption = '0';
	char key;

	fflush(stdin);

	system("cls");
	system("Color F0");
	cout << "===============================================" << endl;
  	cout << "  SMART HEALTH CONSULTING SYSTEM (Doctor Menu)  " << endl;
    cout << "===============================================" << endl;
    cout << "|      1. View Appointment                    |" << endl;
    cout << "|      2. Add Record                          |" << endl;
    cout << "|      3. Delete Record                       |" << endl;
    cout << "|      4. Edit Record                         |" << endl;
    cout << "|      5. View Record                         |" << endl;
    cout << "|      6. Logout                              |" << endl;
    cout << "==============================================="<<endl;
    cout << "\n  Please enter your option (1/2/3/4/5/6) " ;
    cout << "\n  >> ";
    cin >> docOption;
    
    switch(docOption)
    {
    	case '1':
    		App.viewAppointment();
    		doctorMenu();
    		break;

        case '2':
    		Rec.addRecord();
			doctorMenu();
			break;  
			
		case '3':
    		Rec.removeRecord();
			doctorMenu();
			break;  

    	case '4':
    		Rec.editRecord();
			doctorMenu();
			break; 
			
		case '5':
    		Rec.viewRecord();
			doctorMenu();
			break; 

    	case '6':
        	cout << "\n  Are you sure you want to logout? (Please enter any key to logout or '0' to cancel)";
        	cout << "\n  >> ";
			key = getch();
			
			if(key == '0')
			{doctorMenu();}
			
			else 
			{break;}

    	default:
        	doctorMenu();
    }
}
