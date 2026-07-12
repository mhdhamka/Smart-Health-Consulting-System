/******************************
Class Patient
Implemented by Mohammad Hamka Izzuddin Bin Mohamad Yahya (73571)
******************************/

/*Class Patient implementation file*/
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

#include "patient.h"
#include "bool.h"  
#include "appointment.h"
#include "payment.h"
#include "record.h"
using namespace std;

Appointment app;
Payment pay;
Record re;

/*Constructor*/
Patient::Patient(){} 

/*Setter*/
void Patient::setpatientID(string pid){patientID = pid;}
void Patient::setpatientName(string pn){patientName = pn;}
void Patient::setpatientAge(string pa) {patientAge = pa;}
void Patient::setpatientAddress(string padd){patientAddress = padd;}
void Patient::setphone(string ph) {phone = ph;}
void Patient::setmedicalHistory(string mh) {medicalHistory = mh;}

/*Getter*/
string Patient::getpatientID() {return patientID;}
string Patient::getpatientName() {return patientName;}
string Patient::getpatientAge() {return patientAge;}
string Patient::getpatientAddress() {return patientAddress;}
string Patient::getphone() {return phone;}
string Patient::getmedicalHistory() {return medicalHistory;}


//Function to let patient register in Smart Health Consulting System
void Patient::registration()
{
	//variable declaration
	char key;
	
    system("cls");
    system("Color F0");
    cout << "=====================================================" << endl;
	cout << "SMART HEALTH CONSULTING SYSTEM (Patient Registration)" << endl;
	cout << "=====================================================" << endl;
    cout << "Please fill in required personal details." << endl;
    cout << "Enter any key to continue or '0' to cancel: " << endl;
	key = getch();
	
	if(key == '0')
	{
		return;
	}
	
	//loop is added to make sure that the user wont enter the same user name
	while(1)
	{
		cout << "--------------------------------------------------------\n";
		fflush(stdin);
		cout << "\n   Enter new username";
		cout << "\n   >> ";
		getline(cin, username);
		
		ifstream patReg("PatientRegistration.txt");
		if (!patReg.is_open()) {patReg.close(); break;}
		
		if(!checkExistUsername(username))
		{
			cerr << "  This username has been used. Please enter a new username to proceed." << endl;
		}
		else{break;}
	}

	fflush(stdin);
	cout << "\n   Enter new password";
	cout << "\n   >> ";
	getline(cin, password);
	
	fflush(stdin);
	cout << "\n   Enter patient ID";
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
	cout << "\n   Enter patient home address";
	cout << "\n   >> ";
	getline(cin, patientAddress);
	
	//loop is added to make sure that user will input according to the correct format
	while(1)
	{
		fflush(stdin);
		cout << "\n   Enter patient email address";
		cout << "\n   >> ";
		getline(cin, email);
		
		bool ans = checkEmail(email);
		
		if(!ans)
		{
			cerr << "\n  You have entered an invalid email format. Please enter a correct format email to proceed." << endl;
		}
		else{break;}
	}

	while(1)
	{
		fflush(stdin);
		cout << "\n   Enter patient phone number";
		cout << "\n   >> ";
		getline(cin, phone);
		
		int len2 = phone.size();
		
		bool ans3 = checkMobile(phone, len2);
		
		if(!ans3)
		{
			cerr << "\n  You have entered an invalid phone number format. Please enter a correct phone number format." << endl;
		}
		else{break;}
	}
		
	fflush(stdin);
	cout << "\n   Enter patient medical History";
	cout << "\n   >> ";
	getline(cin, medicalHistory);

	ofstream patReg;
	patReg.open("PatientRegistration.txt", ofstream::app);
	patReg << getname() << endl;
	patReg << getpassword() << endl;
	patReg << getpatientID() << endl;
	patReg << getpatientName() << endl;
	patReg << getpatientAge() << endl;
	patReg << getpatientAddress() << endl;
	patReg << getemail() << endl;
	patReg << getphone() << endl;
	patReg << getmedicalHistory() << endl;
	
	patReg.close();
	
    cout << "\n--------------------------------------------------------";
    cout << "\n";
	cout << "  Your registration is successful and your personal information has been saved successfully. " << endl;
	cout << "  You may edit and modify it later on at Patient Menu :) ";
	cout << "\n";
	system("  pause");

}


/*Function to let customer login to Smart Health Consulting System*/
void Patient::login()
{
	system("cls");
	system("Color F0");
	fflush(stdin);
	cout << "=====================================================" << endl;
	cout << "     SMART HEALTH CONSULTING SYSTEM (PatientLogin)   " << endl;
	cout << "=====================================================" << endl;
	cout << "To exit, just press enter key twice. " << endl << endl;
	cout << "--------------------------------------------------------\n";
	cout << "   Please enter your username";
	cout << "\n   >> ";
	getline(cin, username);
	cout << "\n   Please enter your password";
	cout << "\n   >> ";
	getline(cin, password);
	
	bool patLog = validateLogin(username, password);
	
	if(!patLog)
	{
		cout << "--------------------------------------------------------\n";
		cerr << "\n Sorry but you have entered a Wrong username or password. Please try again.\n" << endl;
		system("  pause");
	}
	else
	{
		int i = 0;
		int j = 0;
		string data[100][8];
		ifstream readFile("PatientRegistration.txt"); 
		while(getline(readFile,data[i][j])){
			j++;
			if(j>7){
				if(username==data[i][0]){
					patientID = data[i][2];
					patientName = data [i][3];
					patientAge = data [i][4];
					patientAddress = data [i][5];
					email = data[i][6];
					phone = data[i][7];
					medicalHistory = data[i][8];
					cout << "--------------------------------------------------------\n";
					cout << "\n  Welcome " << username << " to Smart Health Consulting System! You have successfully login." << endl;
					cout << "\n";
					system("  pause");
					patientPlatform();
				}
				i++;
				j=0;
			}
		}
		readFile.close();
	
	}
	
}


//function for patient menu
void Patient::patientPlatform()
{
	//variable declaration
	string receiptID, patientID, patientName, patientAge, receipttime, receiptdate, drugID, drugName, drugDes, illness, diagnosis;
	int i = 1, n = 1;
	char patOption = '0';
	char key;

	fflush(stdin);

	system("cls");
	system("Color F0");
	cout << "  Welcome " << username << "!" << endl;
	cout << "\n";
	cout << "=================================================" << endl;
    cout << "  SMART HEALTH CONSULTING SYSTEM (Patient Menu)  " << endl;
    cout << "=================================================" << endl;
    cout << "|         1. View Profile                       |" << endl;
    cout << "|         2. Edit Profile                       |" << endl;
    cout << "|         3. Set Appointment                    |" << endl;
    cout << "|         4. View Record                        |" << endl;
    cout << "|         5. Make Payment                       |" << endl;
    cout << "|         6. Logout                             |" << endl;
    cout << "================================================="<<endl;
    cout << "\n";
    cout << "  Please enter your option (1/2/3/4/5/6)";
    cout << "\n  >> ";
    cin >> patOption;
    
    switch(patOption)
    {
    	case '1':
    		fflush(stdin);
			viewProfile();
    		getname();
    		patientPlatform();
    		break;
    		
    	case '2':
    		fflush(stdin);
			editProfile();
    		getname();
    		patientPlatform();
    		break;
    		
    	case '3':
    		app.appMenu();
    		getname();
		    patientPlatform();
			break;
			
		case '4':
			
			system("cls");
			re.viewpatientRecord();
			getname();
    		patientPlatform();
			break;
		
		
		case '5':
			{
				system("cls");
				app.payment();
				ifstream patreg("Receipt.txt");
				if(!patreg)
				{
					cout << "\n Sorry but there is no receipt recorded in the system. ";
					cout << "\n The receipt will be generated once you have done with your payment. ";
		            system("\n  pause");
		            patreg.close();
				}
				else
				{
					while(!patreg.eof())
		            {
		             	getline(patreg, receiptID);
			            getline(patreg, receiptdate);
		             	getline(patreg, receipttime);
			            getline(patreg, patientName);
			            getline(patreg, patientAge);
			            getline(patreg, patientID);
		            	getline(patreg, drugID);
			            getline(patreg, drugName);
			            getline(patreg, drugDes);
		             	getline(patreg, illness);
			            getline(patreg, diagnosis);
			
			            cout << "\n";
			            cout << "    (" << n <<") Receipt ID " << i << " : " << receiptID << endl;
			            cout << "        Patient ID : " << patientID << endl;
			            cout << "        Patient Name : " << patientName << endl;
			            cout << "        Patient Age : " << patientAge << endl;
		            	cout << "        Receipt Date: " << receiptdate << endl;
			            cout << "        Receipt Time : " << receipttime << endl;
			            cout << "        Drug ID : " << drugID << endl;
			            cout << "        Drug Name : " << drugName << endl;
			            cout << "        Drug Description : " << drugDes << endl;
			            cout << "        Illness : " << illness << endl;
			            cout << "        Diagnosis : " << diagnosis << endl;
                        cout << "\n";
            
		            }
		            
	            patreg.close();
				}
				getname();
				patientPlatform();
				break;
			}
			
		case '6':
			cout << "\n  Are you sure that you want to logout? (Please enter any key to logout or '0' to cancel)";
			cout << "\n  >> ";
			key = getch();
			
			if(key == '0')
			{patientPlatform();}
			
			else
			{
				return;
			}
						
		default:
		    patientPlatform();
			break;
	}
	return ;
}


//Function to let patient view his/her profile in Smart Health Consulting System
void Patient::viewProfile()
{
	system("cls");
	system("Color F0");
	cout << "=================================================" << endl;
    cout << "  SMART HEALTH CONSULTING SYSTEM (Your profile)  " << endl;
    cout << "=================================================\n" << endl;
	cout << "--------------------------------------------------------\n";
	cout << "     -Username >> " << getname() << endl;
	cout << "     -Password >> " << getpassword() << endl;
	cout << "     -Patient ID >> " << getpatientID() << endl;
	cout << "     -Patient Name >> " << getpatientName() << endl;
	cout << "     -Patient Age >> " << getpatientAge() << endl;
	cout << "     -Patient Home Address >> " << getpatientAddress() << endl;
	cout << "     -Email >> " << getemail() << endl;
	cout << "     -Patient Phone Number >> " << getphone() << endl;
	cout << "     Patient Medical History >> " << getmedicalHistory() << endl;
	cout << "--------------------------------------------------------\n";
	cout << "\n";

	system("  pause");
}


void Patient::editProfile(){
	
	//variable declaration
	string find, line;
	int choice;
	char key;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
    cout << "\n";
    cout << "------------------Edit Profile----------------------" << endl;
	cout << "\n  Do you want to edit your profile?"<< endl;
	cout << "  Enter any key to continue or '0' to cancel: ";
	key = getch();
	
	if(key == '0')
	{
		return;
	}
	else
	{
		fflush(stdin);
		cout << "\n\n     Please enter your username to update your profile"<<endl;
		cout << "     >> ";
   		cin >> find;
   		
   		ifstream patreg; //for reading records
  		patreg.open("PatientRegsitration.txt");
  		
	    ofstream tempProfile;
	    tempProfile.open("tempProfile.txt");
	    
	    while (getline(patreg, line))
	    {
	      if (line != find)
	        tempProfile << line << endl;
	    }
	    
	    patreg.close();
	    tempProfile.close();
	    
	    remove("PatientRegsitration.txt"); //remove the previous profile
	    rename("tempProfile.txt", "PatientRegistration.txt");  //rename the previous profile
		
		cout << "\n-----------------------------------------------------" << endl; 
		
		fflush(stdin);
		cout << "\n     Enter new patient ID" << endl;
		cout << "     >> ";
		getline(cin, patientID);
		
		fflush(stdin);
		cout << "\n     Enter new patient name" << endl;
		cout << "     >> ";
		getline(cin, patientName);

        fflush(stdin);
		cout << "\n     Enter new patient age" << endl;
		cout << "     >> ";
		getline(cin, patientAge);
		
		fflush(stdin);
		cout << "\n     Enter new patient home address" << endl;
		cout << "     >> ";
		getline(cin, patientAddress);
		
		//loop is added to make sure that user will input according to the correct format
	    while(1)
	    {
		    fflush(stdin);
		    cout << "\n     Enter new patient email address";
		    cout << "\n     >> ";
		    getline(cin, email);
		
		    bool ans = checkEmail(email);
		
		    if(!ans)
		    {
			    cerr << "\n  You have entered an invalid email format. Please enter a correct format email to proceed." << endl;
		    }
		    else{break;}
	    }
	    
	    while(1)
	   {
		    fflush(stdin);
		    cout << "\n     Enter new patient phone number";
		    cout << "\n     >> ";
		    getline(cin, phone);
		
		    int len2 = phone.size();
		
		    bool ans3 = checkMobile(phone, len2);
		
		    if(!ans3)
		    {
			    cerr << "\n  You have entered an invalid phone number format. Please enter a correct phone number format." << endl;
		    }
		    else{break;}
	    }
		
	    fflush(stdin);
	    cout << "\n     Enter new patient medical History ";
	    cout << "\n     [ Note: if you do not have any medical history, just enter none but if you have please state it.";
	    cout << "\n     >> ";
	    getline(cin, medicalHistory);
		
		cout << "\n-----------------------------------------------------" << endl;
        
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "               ***Updated Profile***                    " << endl;
	    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
	    cout << "          " << username << endl;
	    cout << "          " << password << endl;
		cout << "          " << patientID << endl;
		cout << "          " << patientName << endl;
		cout << "          " << patientAge << endl;
		cout << "          " << patientAddress << endl;
		cout << "          " << email << endl;
		cout << "          " << phone << endl;
		cout << "          " << medicalHistory << endl;
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

		    ofstream patreg;
		    patreg.open("PatientRegistration.txt", ios::app | ios::out);
		    patreg << patientID << endl;
		    patreg << patientName << endl;
		    patreg << patientAge << endl;
		    patreg << patientAddress << endl;
		    patreg << email << endl;
		    patreg << phone << endl;
		    patreg << medicalHistory << endl;
			
			cout << "Your profile have been successfully updated in the system." << endl;
			viewProfile();
		}
	}
}

