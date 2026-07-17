/*
 * SmartHealth System
 * Main Application
 */


#include <iostream>
#include <limits>
#include <windows.h>

#include "doctor.h"
#include "patient.h"
#include "hospital.h"

using namespace std;


void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void pauseScreen()
{
    cout << "\nPress ENTER to continue...";

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    cin.get();
}

void displayHeader(string title)
{
    cout << "\n==================================================\n";
    cout << "        SMARTHEALTH SYSTEM\n";
    cout << "              " << title << "\n";
    cout << "==================================================\n";
}


void welcome()
{
    clearScreen();

    cout << "\nLoading system...";

    Sleep(800);

    clearScreen();

    displayHeader(
        "Welcome"
    );
}



void patientMenu()
{
    Patient patient;

    int choice;


    while(true)
    {
        clearScreen();

        displayHeader(
            "Patient Menu"
        );


        cout
        << "\n1. Register Patient"
        << "\n2. Patient Login"
        << "\n3. Back";


        cout<<"\n\nChoice: ";
        cin>>choice;



        switch(choice)
        {

        case 1:

            patient.registration();

            pauseScreen();

            break;



        case 2:

            patient.login();

            pauseScreen();

            break;



        case 3:

            return;



        default:

            cout<<"\nInvalid choice";

            pauseScreen();

        }

    }

}



void mainMenu()
{

    Doctor doctor;
    Hospital hospital;


    int choice;



    while(true)
    {

        clearScreen();

        displayHeader(
            "Main Menu"
        );


        cout
        << "\n1. Doctor Login"
        << "\n2. Patient"
        << "\n3. Hospital Admin"
        << "\n4. Exit";

        cout<<"\n\nChoice: ";
        cin>>choice;

        switch(choice)
        {

        case 1:

            doctor.login();
            pauseScreen();
            break;

        case 2:

            patientMenu();
            break;


        case 3:

            hospital.login();
            break;

        case 4:

            return;

        default:

            cout<<"\nInvalid option";
            pauseScreen();
        }
    }
}

int main()
{

    welcome();
    pauseScreen();
    mainMenu();


    cout
    << "\nThank you for using SmartHealth System";


    return 0;

}
