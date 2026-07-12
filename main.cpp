/*******************************
Class Main
Implemented by Mohammad Hamka Izzuddin Bin Mohamad Yahya (73571)
*****************************/

/*Class Main implementation file*/
#include <iostream>   // it is an object-oriented library that provides input & output function using streams
#include <string>     // for string
#include <stdlib.h>
#include <windows.h>  //windows.h is a Windows-specific header file,  this header file contains declarations for all of the functions in the Windows API
#include <iomanip>    //header file that helps us in manipulating the output of any C++ program
#include <conio.h>    //header file used mostly by MS-DOS compilers to provide console input/output
#include <string.h>   //header file used for string handling
#include <stdio.h>    // a file which contain declaration of many functions and Macros which required to get input from input devices and show output on output screen of C Program
#include <limits>     //this header file determines various properties of the various variable types
#define WINWIDTH 113  //used for welcome function
#define WINHEIGHT 15  //used for welcome function

/*Header files*/
#include "user.h"
#include "patient.h"
#include "doctor.h"
#include "hospital.h"

using namespace std;

//method/function declaration to welcome the user
void filler();
void liner();
void welcome();

//function for main menu and patient menu
void mainMenu();
void menuPatient();

//Classes uses to access other file 
Patient pat;
Doctor doc;
User u;
Hospital h;
 
 
 //main functiom
int main()
{
	
	welcome();
	
	cout << "\n\n\n\n\t\t\t\t\t  Press Enter to continue"; //Please press the enter button to go to the main menu
    getch();  //feedback to change page
	
	system("CLS");
	cout<<"\n==================================================================";
	cout << " \n\t\tSMART HEALTH CONSULTING SYSTEM " << endl;
	cout<<"==================================================================\n";
    cout << "\n Program author: " << endl;
    cout << "    1) Azreen Shafieqah binti Asri (74251)" << endl;
    cout << "    2) Mohammad Hamka Izzudin bin  Mohammad Yahya (73571) " << endl;
    cout << "    3) Mohammad Amir Alam bin Rahim Omar (73563) " << endl;
    cout << "    4) Nurulain Basirah binti Hamid (73779) " << endl;
    cout << "    5) Iman Tarmizi Rosalina (73496) " << endl;
    cout << "\n";
	system("  pause");

	mainMenu();
	return 0;
}


//main menu for patient, doctor and hospital
void mainMenu(){
	char option = '0';
	
	system("cls");
	system("Color F0");
	cout << "=====================================================" << endl;
	cout << "     SMART HEALTH CONSULTING SYSTEM (Main Menu)      " << endl;
	cout << "=====================================================" << endl;
	cout << "    1) Login as a Doctor " << endl;
	cout << "    2) Login as a Patient" << endl;
	cout << "    3) Login as a Hospital Administrator" << endl;
	cout << "    4) Exit from System " << endl;
	cout << "=====================================================" << endl;
	cout << endl;
    cout << "  Enter your option (1/2/3/4)";
    cout << "\n  >> ";
    cin >> option;
    switch(option)
    {
    	case '1':
    		/*Proceed to admin login page*/
	    	doc.login();
			mainMenu();
        	break;

    	case '2':
    		/*Proceed to patient login page*/
        	menuPatient();
        	mainMenu();
        	break;
    
   	 	case '3':
    		/*Proceed to hospital login page*/
        	h.login();
        	mainMenu();
        	break;
    
    	case '4':
    		/*Terminate the program*/
    		system("cls");
        	cout << "\n\n Thank you for using Smart Health Consulting System ." << endl;
        	exit(0); 
		  
    	default:
    		/*When user enter invalid key, program will refresh*/
        	mainMenu();
    }//end switch option
}//end void mainMenu


//let patient choose to register or log in
void menuPatient(){
	
	fflush (stdin);
	char patOption = '0';
	
	system ("cls");
	system("Color F0");
		        cout << "=====================================================" << endl;
				cout << "     SMART HEALTH CONSULTING SYSTEM (Patient Login)   " << endl;
				cout << "=====================================================" << endl;
				cout << "    1) Register as new patient " << endl;
				cout << "    2) Login as existing patient" << endl;
				cout << "    3) Return to Main Menu " << endl;
				cout << "=====================================================" << endl;
				cout << endl;
    cout << "  Please enter your option (1/2/3)";
    cout << "\n  >> ";
    cin >> patOption;
	
	switch(patOption)
    {
    	case '1':
    		pat.registration();
        	menuPatient();
        	break;

    	case '2':
    		pat.login();
			menuPatient();
			break;       

    	case '3':
        	return;

    	default:
        	menuPatient();
    }
}


//filler method/function definiton 
void filler()
{
	//for loop
    for(int i = 0 ; i < WINWIDTH ; i++) //with initialization of i = 0, and condition that winwidth is more than i, and incremented of i
    {
        cout << "*";
    }
    cout << "\a" << endl;
} //end of filler method/function


//liner method/function definition
void liner()
{
	//body of liner method/function
    for(int i = 0 ; i < WINHEIGHT ; i++)
        cout << endl;
} //end of liner method/function


// Method/function definition used to welcome the user
void welcome()
{
	//body of welcome method/function
	system("Color F0");
    liner();  // system will go to the liner function/method  definition then back to the welcome function
    
    cout << "Loading..." << endl;      //this output will be displayed before the welcoming page
    Sleep(500);   //suspends the execution of the program for a specified period of time
    
    system("Color F0");
    
    //variable declaration
    char msg[] = "WELCOME TO SMART HEALTH CONSULTING SYSTEM";  //this message will be displayed in welcome page
    int len = strlen(msg);
    int x;
    
    x = (WINWIDTH/2) - (len/2);   //x value calculation
    
    //for loop
    for(int i = 0 ; i < WINWIDTH ; i++) //with initialization of i = 0, and condition that winwidth is more than i, and incremented of i
    {
    	//body of loo[
        printf("%c",177);
        Sleep(55);  //suspends the execution of the program for a specified period of time
    } //end for loop
    
    cout << endl;
    
    system("CLS");  //change page to the welcome page
    liner();   // system will go to the liner function/method  definition then back to the welcome function
    filler();  // system will go to the filler function/method  definition then back to the exit function
    
    cout << setw(len+x) << msg << endl;   //an output will be displayed 
    
    filler();  // system will go to the filler function/method  definition then back to the welcome function
    
} //end of welcome method/function defintion


