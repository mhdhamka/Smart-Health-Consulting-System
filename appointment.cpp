/******************************
Class Appointment
Implemented by Mohammad Amir Alam Bin Rahim Omar (73563)
******************************/

/*Class Appointment implementation file*/
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "appointment.h"
#include "record.h"
#include "patient.h"
#include "doctor.h"
#include "payment.h"
using namespace std;

//Classes
Payment paym;
Patient pa;

/*Constructor*/
Appointment::Appointment(){}

/*Setter*/
void Appointment::setAppointmentID(string apid){AppointmentID = apid;}
void Appointment::setAppointmentDate(string apd){AppointmentDate = apd;}
void Appointment::setAppointmentTime(string apt) {AppointmentTime = apt;}
void Appointment::setAppointmentIllness(string apil) {AppointmentIllness = apil;}
void Appointment::setAppointmentDoctor(string apdoc) {AppointmentDoctor = apdoc;}
void Appointment::setAppointmentSpecialization(string apspe) {AppointmentSpecialization = apspe;}


/*Getter*/
string Appointment::getAppointmentID() {return AppointmentID;}
string Appointment::getAppointmentDate() {return AppointmentDate;}
string Appointment::getAppointmentTime() {return AppointmentTime;}
string Appointment::getAppointmentIllness() {return AppointmentIllness;}
string Appointment::getAppointmentDoctor() {return AppointmentDoctor;}
string Appointment::getAppointmentSpecialization() {return AppointmentSpecialization;}


//function for appointment menu
void Appointment::appMenu()
{
	//variable declaration
	char appOption = '0';
	char key;

	fflush(stdin);

	system("cls");
	system("Color F0");
	cout << "\n";
	cout << "=================================================" << endl;
    cout << "        SMART HEALTH CONSULTING SYSTEM           " << endl;
    cout << "=================================================" << endl;
    cout << "-------------Patient Appointment Menu------------" << endl;
    cout << "|                                               |\n";
    cout << "|           1. Add Appointment                  |" << endl;
    cout << "|           2. Remove Appointment               |" << endl;
    cout << "|           3. Edit Appointment                 |" << endl;
    cout << "|           4. View Appointment                 |" << endl;
    cout << "|           5. Return to Patient Menu           |" << endl;
    cout << "|                                               |\n";
    cout << "-------------------------------------------------"<<endl;
    cout << "\n";
    cout << "  Please enter your option (1/2/3/4/5)";
    cout << "\n  >> ";
    cin >> appOption;
    
    switch(appOption)
    {
    	case '1':
			addAppointment();
    		appMenu();
    		break;
    		
    	case '2':
    		removeAppointment();
		    appMenu();
			break;
			
		case '3':
			editAppointment();
			appMenu();
			break;
			
		case '4':
			viewAppointment();
			appMenu();
			break;
			
		case '5':
		    pa.patientPlatform();
		    break;
			
		default:
		    appMenu();
			break;
	}
	return ;
}


//function for user to add appointment
void Appointment::addAppointment()
{
	//variable declaration
	string apid, apd, apt, apil, apdoc, apspe, space;;
	char key;
	string cost;
	string kosong;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "------------------Set Appointment------------------" << endl;
	
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n|               Doctor's Schedule                  |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n|     (i)  - Appointment ID: APP 01                |";              
	cout << "\n|          - Appointment Date: 5/1/2022            |";
	cout << "\n|          - Appointment Time: 1400                |";
	cout << "\n|          - Doctor: Azreen Shafieqah              |";
	cout << "\n|          - Specialization: Paediatric (PDC)      |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n|     (ii) - Appointment ID: APP 02                |";              
	cout << "\n|          - Appointment Date: 6/1/2022            |";
	cout << "\n|          - Appointment Time: 1500                |";
	cout << "\n|          - Doctor: Mohammad Amir                 |";
	cout << "\n|          - Specialization: Cardiologist (CAR)    |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n|    (iii) - Appointment ID: APP 03                |";              
	cout << "\n|          - Appointment Date: 7/1/2022            |";
	cout << "\n|          - Appointment Time: 1600                |";
	cout << "\n|          - Doctor: Henry Zaynal                  |";
	cout << "\n|          - Specialization: Dermatologist (DRT)   |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n|     (iv) - Appointment ID: APP 04                |";              
	cout << "\n|          - Appointment Date: 10/1/2022           |";
	cout << "\n|          - Appointment Time: 1800                |";
	cout << "\n|          - Doctor: Azreen Shafieqah              |";
	cout << "\n|          - Specialization: Paediatric (PDC)      |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n|     (v)  - Appointment ID: APP 05                |";              
	cout << "\n|          - Appointment Date: 11/1/2022           |";
	cout << "\n|          - Appointment Time: 1400                |";
	cout << "\n|          - Doctor: Mohammad Amir                 |";
	cout << "\n|          - Specialization: Cardiologist (CAR)    |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n|     (vi) - Appointment ID: APP 06                |";              
	cout << "\n|          - Appointment Date: 12/1/2022           |";
	cout << "\n|          - Appointment Time: 1700                |";
	cout << "\n|          - Doctor: Henry Zaynal                  |";
	cout << "\n|          - Specialization: Dermatologist (DRT)   |";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n  Note: Please choose the doctor based on the appointment ID\n";
	
	cout << "  Please enter any key to continue or '0' to cancel: " << endl;
	key = getch();
	
	if(key == '0')
	{
		return;
	}

	fflush(stdin);
	cout << "\n   Enter new appointment ID (eg: PDC 01, CAR 02, DRT 03)";
	cout << "\n   [ Note: Please enter appointment ID according on the table above.]";
	cout << "\n   >> ";
	getline(cin, AppointmentID);
	
	fflush(stdin);
	cout << "\n   Enter appointment date (In DD/MM/YY format)";
	cout << "\n   [ Note: Please enter appointment date according on the table above.]";
	cout << "\n   >> ";
	getline(cin, AppointmentDate);
		
	fflush(stdin);	
	cout << "\n   Enter appointment time (In 24-Hour format)";
	cout << "\n   [ Note: Please enter appointment time according on the table above.]";
	cout << "\n   >> ";
	getline(cin, AppointmentTime);
		
	fflush(stdin);	
	cout << "\n   Enter illness";
	cout << "\n   >> ";
	getline(cin, AppointmentIllness);
	
	fflush(stdin);	
	cout << "\n   Enter the doctor that you which to set an appointment ";
	cout << "\n   [Azreen/ Mohammad Amir/ Henry Zaynal] ";
	cout << "\n   >> ";
	getline(cin, AppointmentDoctor);
	
	fflush(stdin);	
	cout << "\n   Enter the doctor specialization or their specialization code";
	cout << "\n   [(PDC) Paediatric/ (CAR) Cardiologist/ (DRT) Dermatologist] ";
	cout << "\n   >> ";
	getline(cin, AppointmentSpecialization);

	ofstream patApp;
	patApp.open("Appointment.txt", ofstream::app);
	patApp << getAppointmentID() << endl;
	patApp << getAppointmentDate() << endl;
	patApp << getAppointmentTime() << endl;
	patApp << getAppointmentIllness() << endl;
	patApp << getAppointmentDoctor() << endl;
	patApp << getAppointmentSpecialization() << endl;
	
	patApp.close();
    cout << "\n---------------------------------------------------";
    cout << "\n";
	cout << "Thank you! Your appointment has been set up. " << endl;
	cout << "\n";
	system("  pause");

}


//function for user to remove appointment
void Appointment::removeAppointment()
{
	
	//variable declaration
	char yes_no, key;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "-----------------Remove Appointment-----------------" << endl; 
	
	cout << "\n  Do you want remove Appointment ?";
	cout << "\n  Note: All appointment will be removed if you choose still want to proceed";
	cout << "\n  Enter any key to continue or '0' to cancel: ";
	
	key = getch();
	
	if(key == '0')
	{
		return;
	}
	else
	{
	
	ifstream patApp;
	patApp.open("Appointment.txt");
	if(!patApp)
	{
		cout << "\n Sorry but there is no appointment recorded in the system. \n";
		system("  pause");
		patApp.close();
		return;
	}
	patApp.close();
	viewAppointment();
	fflush(stdin);
	char yes_no;
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
		ofstream deleteAppointment;
		deleteAppointment.open("Appointment.txt", ofstream::out | ofstream::trunc);
		deleteAppointment.close();
		remove("Appointment.txt");
    }
	    cout << "\n  All appointment are deleted. ";
    }
    
	system("\n  pause");		
	
}


//function for patient to edit their appointment
void Appointment::editAppointment(){
	
	//variable declaration
	string find, line, apid, apd, apt, api;
	int choice;
	char key;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
    cout << "\n";
    cout << "-----------------Edit Appointment--------------------" << endl;
	cout << "\n  Do you want to edit your appointment?"<< endl;
	cout << "  Enter any key to continue or '0' to cancel: ";
	key = getch();
	
	if(key == '0')
	{
		return;
	}
	else
	{
		fflush(stdin);
		cout << "\n\n     Please enter your patient ID to update your appointment"<<endl;
		cout << "     >> ";
   		cin >> find;
   		
   		ifstream patApp; //for reading records
  		patApp.open("Appointment.txt");
  		
	    ofstream tempApp;
	    tempApp.open("tempApp.txt");
	    
	    while (getline(patApp, line))
	    {
	      if (line != find)
	        tempApp << line << endl;
	    }
	    
	    patApp.close();
	    tempApp.close();
	    
	    remove("Appointment.txt"); //remove the previous appointment
	    rename("tempApp.txt", "Appointment.txt");  //rename the previous appointment
		
		cout << "\n-----------------------------------------------------" << endl; 
		
		fflush(stdin);
		cout << "\n     Enter your new appointment ID (eg: PDC 2001, CAR 3001, DRT 4001)" << endl;
		cout << "     >> ";
		getline(cin, AppointmentID);
		
		fflush(stdin);
		cout << "\n     Enter your new appointment date (In DD/MM/YY format" << endl;
		cout << "     >> ";
		getline(cin, AppointmentDate);

        fflush(stdin);
		cout << "\n     Enter your new appointment time (In 24-Hour format)" << endl;
		cout << "     >> ";
		getline(cin, AppointmentTime);
		
		fflush(stdin);
		cout << "\n     Enter your new illness" << endl;
		cout << "     >> ";
		getline(cin, AppointmentIllness);
		
		fflush(stdin);	
	    cout << "\n   Enter  a new doctor that you which to set an appointment ";
	    cout << "\n   [Azreen/ Mohammad Amir/ Henry Zaynal] ";
	    cout << "\n   >> ";
	    getline(cin, AppointmentDoctor);
	
    	fflush(stdin);	
	    cout << "\n   Enter a new doctor specialization or their specialization code";
	    cout << "\n   [(PDC) Paediatric/ (CAR) Cardiologist/ (DRT) Dermatologist] ";
	    cout << "\n   >> ";
	    getline(cin, AppointmentSpecialization);
		
		
		cout << "\n-----------------------------------------------------" << endl;
        
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "             ***Updated Appointment***               " << endl;
	    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
		cout << "          " << AppointmentID << endl;
		cout << "          " << AppointmentDate << endl;
		cout << "          " << AppointmentTime << endl;
		cout << "          " << AppointmentIllness << endl;
		cout << "          " << AppointmentDoctor << endl;
		cout << "          " << AppointmentSpecialization << endl;
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

		    ofstream patApp;
		    patApp.open("Appointment.txt", ios::app | ios::out);
		    patApp << AppointmentID << endl;
		    patApp << AppointmentDate << endl;
		    patApp << AppointmentTime << endl;
		    patApp << AppointmentIllness << endl;
		    patApp << AppointmentDoctor << endl;
		   patApp << AppointmentSpecialization << endl;
			
			cout << "  Your appointment have been successfully updated in the system." << endl;
			viewAppointment();
		}
	}
}


//function for patient to view appointment
void Appointment::viewAppointment()
{
	//variable declaration
	string apid, apd, apt, apil, apdoc, apspe, space;
	
	int i = 1, n = 1;
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "---------------------Appointment---------------------" << endl;
	
	ifstream patApp;
	patApp.open("Appointment.txt");
	if(!patApp)
	{
		cout << "\n  Sorry but there is no appointment recorded in the system. ";
		system("\n  pause");
		patApp.close();
	}
	else
	{
		
		while(!patApp.eof())
		{
			getline(patApp, AppointmentID);
			getline(patApp, AppointmentDate);
			getline(patApp, AppointmentTime);
			getline(patApp, AppointmentIllness);
			getline(patApp, AppointmentDoctor);
			getline(patApp, AppointmentSpecialization);
			
			getline(patApp, space);
			fflush(stdin);
			cout << "\n";
			cout << "    (" << n <<") AppointmentID " << i << " : " << AppointmentID << endl;
			cout << "        Appointment Date: " << AppointmentDate << endl;
			cout << "        Appointment Time : " << AppointmentTime << endl;
			cout << "        Ilness : " << AppointmentIllness << endl;
			cout << "        Doctor : " << AppointmentDoctor << endl;
			cout << "        Specialization : " << AppointmentSpecialization << endl;
            cout << "\n";
            
			cout << space;
			
			i++;
			n++;
		}
		
	}
	patApp.close();
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	system("\n  pause");	
}


//function for patient to go ro the payment page after already setting up their appointment
void Appointment::payment()
{
	ifstream patApp;
	patApp.open("Appointment.txt");
	if(!patApp)
	{
		cout << " \n  Sorry but there is no appointment set in the system. Please set up an appointment first before you make payment\n";
		system("  pause");
		patApp.close();
		return;
	}
	
	patApp.close();
	system("cls");
	system("Color F0");
	viewAppointment();
	int opt; 
	
	cout << "\n  Do you want to proceed with payment?( [Y] = 1 | [N] = 0) : ";
	cout << "\n  >> ";
	cin >> opt;
	
	if (opt == 1) //proceed with payment
	{
		system("cls");
		paym.makePayment();
		system("  pause");
		return;
		
	}
	else if (opt == 0) //return to patient menu page
	{
		return;
	}
	else
	{
		cout << "  You have entered an invalid input! Please try again." << endl;
		system("cls");
		payment();
	}
}
