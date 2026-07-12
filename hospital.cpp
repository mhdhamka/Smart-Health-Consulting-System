/**********
Class Hospital
Implemented by Nurulain Basirah Binti Hamid (73779)
**********/

/*Class Hospital implementation file*/
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

#include "hospital.h"
#include "appointment.h"
using namespace std;

Hospital hos;

/*Constructor*/
Hospital::Hospital()
{
	username = "ain2022";
	password = "73779";
	hospitalName = "Nurulain Basirah";
}

/*Setter*/
void Hospital::sethospitalName(string hn) {hospitalName = hn;}
void Hospital::setreceiptID(string rid) {receiptID = rid;}
void Hospital::setpatientID(string pid){patientID = pid;}
void Hospital::setpatientName(string pn) {patientName = pn;}
void Hospital::setpatientAge(string pa){patientAge = pa;}
void Hospital::setreceiptdate(string rd){receiptdate = rd;}
void Hospital::setreceipttime(string rt) {receipttime = rt;}
void Hospital::setdrugID(string did){drugID = did;}
void Hospital::setdrugName(string dn) {drugName = dn;}
void Hospital::setdrugDes(string dd) {drugDes = dd;}
void Hospital::setillness(string ill){illness = ill;}
void Hospital::setdiagnosis(string di){diagnosis = di;}


/*Getter*/
string Hospital::gethospitalName() {return hospitalName;}
string Hospital::getreceiptID() {return receiptID;}
string Hospital::getpatientID() {return patientID;}
string Hospital::getpatientName() {return patientName;}
string Hospital::getpatientAge() {return patientAge;}
string Hospital::getreceiptdate() {return receiptdate;}
string Hospital::getreceipttime() {return receipttime;}
string Hospital::getdrugID() {return drugID;}
string Hospital::getdrugName() {return drugName;}
string Hospital::getdrugDes() {return drugDes;}
string Hospital::getillness() {return illness;}
string Hospital::getdiagnosis() {return diagnosis;}


//function for hospital administrator to login
void Hospital::login()
{
	string hosId, hosPass;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "SMART HEALTH CONSULTING SYSTEM (Hospital Admin Login)" << endl;
	cout << "=====================================================" << endl;
	cout << "--------------------------------------------------------\n";
	fflush(stdin);
	cout << "\n";
	cout << "   Please enter your Hospital Administrator ID";		
	//Hospital administrator username = ain2022
	cout << "\n   >> ";
	getline(cin, hosId);
	cout << "\n";
	cout << "   Please enter your password : ";		
	//Admin password = 73779
	cout << "\n   >> ";
	getline(cin, hosPass);
	
	cout << "\n--------------------------------------------------------\n";
	
	if(hosId == username && hosPass == password )
	{
		cout << "\n  Welcome " << hospitalName << "!. You have successfully login to the system.\n" << endl;
		system("pause");
		fflush(stdin);
		hospitalMenu();
	}
	else
	{
		cout << "  Invalid admin username or password!!" << endl;
		system("pause");
	}
}


//Function of hospital administrator
void Hospital::hospitalMenu()
{
	char hosOption = '0';
	char key;

	fflush(stdin);

	system("cls");
	system("Color F0");
	cout << "====================================================" << endl;
    cout << "SMART HEALTH CONSULTING SYSTEM (Hospital Admin Menu)" << endl;
    cout << "====================================================" << endl;
    cout << "|        1. Generate Receipt                       |" << endl;
    cout << "|        2. View Receipt                           |" << endl;
    cout << "|        3. Logout                                 |" << endl;
    cout << "===================================================="<<endl;
    cout << "\n  Please enter your option (1/2/3)";
    cout <<"\n  >> ";
    cin >> hosOption;
    
    switch(hosOption)
    {
    	case '1':
    		generateReceipt();
    		hospitalMenu();
    		break;

    	case '2':
    		viewReceipt();
			hospitalMenu();
			break;  

    	case '3':
        	cout << "\n  Are you sure to logout? (Please enter any key to logout or '0' to cancel)";
        	cout << "\n  >> ";
			key = getch();
			
			if(key == '0')
			{hospitalMenu();}
			
			else 
			{break;}

    	default:
        	hospitalMenu();
    }
}


//function  for hospital to generate receipt
void Hospital::generateReceipt()
{
	string rid, rd, rt, pn, pa, pid, did, dn, dd, ill, di, space;
	char key;
	string cost;
	string kosong;
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "------------------Generate Receipt ------------------" << endl;
	cout << "Please enter any key to continue or '0' to cancel: ";
	key = getch();
	
	if(key == '0')
	{
		return;
	}

	fflush(stdin);
	cout << "\n\n     Enter Receipt ID";
	cout << "\n     >> ";
	getline(cin, receiptID);
	
	fflush(stdin);
	cout << "\n     Enter Patient ID";
	cout << "\n     >> ";
	getline(cin, patientID);
	
	fflush(stdin);
	cout << "\n     Enter Patient Name";
	cout << "\n     >> ";
	getline(cin, patientName);
	
	fflush(stdin);
	cout << "\n     Enter Patient Age";
	cout << "\n     >> ";
	getline(cin, patientAge);
	
	fflush(stdin);
	cout << "\n     Enter Receipt  Date (In DD/MM/YY format)";
	cout << "\n     >> ";
	getline(cin, receiptdate);
		
	fflush(stdin);
	cout << "\n     Enter Receipt Time (In 24-Hour format)";
	cout << "\n     >> ";
	getline(cin, receipttime);
	
	//prescription record
	fflush(stdin);
	cout << "\n     Enter Drug ID";
	cout << "\n     >> ";
	getline(cin, drugID);
	
	fflush(stdin);	
	cout << "\n     Enter Drug Name";
	cout << "\n     >> ";
	getline(cin, drugName);
		
	fflush(stdin);
	cout << "\n     Enter Drug Description";
	cout << "\n     >> ";
	getline(cin, drugDes);
	
	
	//medical record
	fflush(stdin);
	cout << "\n     Enter Ilness";
	cout << "\n     >> ";
	getline(cin, illness);
	
	fflush(stdin);
	cout << "\n     Enter Diagnosis";
	cout << "\n     >> ";
	getline(cin, diagnosis);

	ofstream hosRe;
	hosRe.open("Receipt.txt", ofstream::app);
	fflush(stdin);
	hosRe << getreceiptID() << endl;
	hosRe << getpatientID() << endl;
	hosRe << getreceiptdate() << endl;
	hosRe << getreceipttime() << endl;
	hosRe << getpatientName() << endl;
	hosRe << getpatientAge() << endl;
	hosRe << getdrugID() << endl;
	hosRe << getdrugName() << endl;
	hosRe << getdrugDes() << endl;
	hosRe << getillness() << endl;
	hosRe << getdiagnosis() << endl;
	
	hosRe.close();
    cout << "\n\n---------------------------------------------------";
    cout << "\n";
	cout << "  Thank you! Your receipt has been set up. " << endl;
	cout << "\n";
	system("pause");

}


//function to view receipt in the system
void Hospital::viewReceipt()
{
	string rid, pid, pn, pa, rd, rt, did, dn, dd, ill, di, space;
	int i = 1, n = 1;
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "          SMART HEALTH CONSULTING SYSTEM             " << endl;
	cout << "=====================================================" << endl;
	cout << "\n";
	cout << "---------------------Receipt---------------------" << endl;
	
	ifstream hosRe;
	hosRe.open("Receipt.txt");
	if(!hosRe)
	{
		cout << "\n Sorry but there is no receipt recorded in the system. ";
		system("\npause");
		hosRe.close();
	}
	else
	{
		
		while(!hosRe.eof())
		{
			getline(hosRe, receiptID);
			getline(hosRe, patientID);
			getline(hosRe, patientName);
			getline(hosRe, patientAge);
			getline(hosRe, receiptdate);
			getline(hosRe, receipttime);
			getline(hosRe, drugID);
			getline(hosRe, drugName);
			getline(hosRe, drugDes);
			getline(hosRe, illness);
			getline(hosRe, diagnosis);
			
			
			getline(hosRe, space);
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
            
			cout << space;
			
			i++;
			n++;
		}
		
	}
	
	hosRe.close();
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	system("\npause");	
}


