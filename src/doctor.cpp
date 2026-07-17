/*
 * Doctor Class Implementation
 * Smart Health Consulting System
 */


#include <iostream>
#include <string>
#include <conio.h>


#include "record.h"
#include "doctor.h"
#include "appointment.h"


using namespace std;

Appointment App;
Record Rec;

/*
 * Constructor
 */


Doctor::Doctor()
{

    username = "PDC1365";

    password = "74251";

    doctorName = "Azreen Shafieqah";

    doctorSpecialization = "Paediatric";

}







/*
 * Setter
 */


void Doctor::setDoctorName(string dn)
{
    doctorName = dn;
}


void Doctor::setDoctorSpecialization(string ds)
{
    doctorSpecialization = ds;
}







/*
 * Getter
 */


string Doctor::getDoctorName()
{
    return doctorName;
}


string Doctor::getDoctorSpecialization()
{
    return doctorSpecialization;
}








/*
 * Doctor Login
 */


void Doctor::login()
{

    string docID;

    string docPassword;



    cout
    << "\n=====================================================\n";


    cout
    << " SMART HEALTH CONSULTING SYSTEM\n";


    cout
    << " Doctor Login\n";


    cout
    << "=====================================================\n";




    cout
    << "\nDoctor ID : ";

    cin
    >> docID;



    cout
    << "Password  : ";

    cin
    >> docPassword;




    if(
        docID == username &&
        docPassword == password
      )
    {


        cout
        << "\nWelcome Doctor "
        << doctorName
        << "! Login successful.\n";


        system("pause");


        doctorMenu();


    }

    else
    {

        cout
        << "\nInvalid doctor ID or password.";


        system("pause");

    }

}

/*
 * Doctor Menu
 */
void Doctor::doctorMenu()
{

    int option;



    Appointment appointmentSystem;

    Record recordSystem;




    while(true)
    {


        system("cls");



        cout
        << "\n==============================================\n";


        cout
        << " SMART HEALTH CONSULTING SYSTEM\n";


        cout
        << " Doctor Menu\n";


        cout
        << "==============================================\n";



        cout
        << "\n1. View Appointment";


        cout
        << "\n2. Add Medical Record";


        cout
        << "\n3. Delete Medical Record";


        cout
        << "\n4. Edit Medical Record";


        cout
        << "\n5. View Medical Record";


        cout
        << "\n6. Logout";




        cout
        << "\n\nSelect option: ";


        cin
        >> option;




        switch(option)
        {


        case 1:

            appointmentSystem.viewAppointment();
            break;


        case 2:

            recordSystem.addRecord();
            break;


        case 3:

            recordSystem.removeRecord();
            break;

        case 4:

            recordSystem.editRecord();
            break;


        case 5:

            recordSystem.viewRecord();
            break;


        case 6:

            return;


        default:

            cout
            << "\nInvalid option.";

            system("pause");

        }
    }


}
