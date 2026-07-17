/*
 * Appointment Class Implementation
 * SmartHealth System
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


#include "appointment.h"
#include "record.h"
#include "patient.h"
#include "doctor.h"
#include "payment.h"

using namespace std;

Payment paym;
Patient pa;


// Constructor
Appointment::Appointment()
{

    AppointmentID = "";
    AppointmentDate = "";
    AppointmentTime = "";
    AppointmentIllness = "";
    AppointmentDoctor = "";
    AppointmentSpecialization = "";

}

// Setter
void Appointment::setAppointmentID(string id)
{
    AppointmentID = id;
}

void Appointment::setAppointmentDate(string date)
{
    AppointmentDate = date;
}

void Appointment::setAppointmentTime(string time)
{
    AppointmentTime = time;
}

void Appointment::setAppointmentIllness(string illness)
{
    AppointmentIllness = illness;
}

void Appointment::setAppointmentDoctor(string doctor)
{
    AppointmentDoctor = doctor;
}

void Appointment::setAppointmentSpecialization(string spec)
{
    AppointmentSpecialization = spec;
}


// Getter
string Appointment::getAppointmentID()
{
    return AppointmentID;
}


string Appointment::getAppointmentDate()
{
    return AppointmentDate;
}


string Appointment::getAppointmentTime()
{
    return AppointmentTime;
}


string Appointment::getAppointmentIllness()
{
    return AppointmentIllness;
}


string Appointment::getAppointmentDoctor()
{
    return AppointmentDoctor;
}


string Appointment::getAppointmentSpecialization()
{
    return AppointmentSpecialization;
}


/*
 * Appointment Menu
 */
void Appointment::appMenu()
{

    int option;



    while(true)
    {


        system("cls");


        cout
        << "\n=================================================\n";

        cout
        << "      SMARTHEALTH SYSTEM\n";

        cout
        << "------------- Appointment Menu -----------------\n";

        cout
        << "\n1. Add Appointment";

        cout
        << "\n2. Remove Appointment";

        cout
        << "\n3. Edit Appointment";

        cout
        << "\n4. View Appointment";

        cout
        << "\n5. Payment";

        cout
        << "\n6. Return";

        cout
        << "\n\nSelect option: ";

        cin
        >> option;

        switch(option)
        {

        case 1:
            addAppointment();
            break;

        case 2:
            removeAppointment();
            break;

        case 3:
            editAppointment();
            break;

        case 4:
            viewAppointment();
            break;

        case 5:
            payment();
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

/*
 * Add Appointment
 */
void Appointment::addAppointment()
{

    system("cls");

    cout
    << "\n=================================================\n";

    cout
    << " Available Doctor Schedule\n";

    cout
    << "=================================================\n";

    cout
    << "\nAPP01"
    << "\nDate : 5/1/2022"
    << "\nTime : 1400"
    << "\nDoctor : Azreen Shafieqah"
    << "\nSpecialization : PDC\n";

    cout
    << "\nAPP02"
    << "\nDate : 6/1/2022"
    << "\nTime : 1500"
    << "\nDoctor : Mohammad Amir"
    << "\nSpecialization : CAR\n";

    cout
    << "\nAPP03"
    << "\nDate : 7/1/2022"
    << "\nTime : 1600"
    << "\nDoctor : Henry Zaynal"
    << "\nSpecialization : DRT\n";

    cin.ignore();


    cout
    << "\nAppointment ID : ";

    getline(
        cin,
        AppointmentID
    );


    cout
    << "Appointment Date : ";

    getline(
        cin,
        AppointmentDate
    );


    cout
    << "Appointment Time : ";

    getline(
        cin,
        AppointmentTime
    );


    cout
    << "Illness : ";

    getline(
        cin,
        AppointmentIllness
    );


    cout
    << "Doctor : ";

    getline(
        cin,
        AppointmentDoctor
    );


    cout
    << "Specialization : ";

    getline(
        cin,
        AppointmentSpecialization
    );


    ofstream appointmentFile(
        "data/Appointment.txt",
        ios::app
    );


    if(!appointmentFile)
    {

        cout
        << "\nUnable to save appointment.";

        return;

    }

    appointmentFile

    << AppointmentID << endl
    << AppointmentDate << endl
    << AppointmentTime << endl
    << AppointmentIllness << endl
    << AppointmentDoctor << endl
    << AppointmentSpecialization << endl

    << endl;



    appointmentFile.close();



    cout
    << "\nAppointment successfully created.";

    system("pause");

}

/*
 * Remove Appointment
 */


void Appointment::removeAppointment()
{

    ifstream appointmentFile(
        "data/Appointment.txt"
    );


    if(!appointmentFile)
    {

        cout
        << "\nNo appointment record found.";

        system("pause");

        return;

    }



    appointmentFile.close();



    char confirm;


    cout
    << "\nAre you sure you want to remove all appointments? (Y/N): ";

    cin
    >> confirm;



    if(confirm != 'Y' && confirm != 'y')
    {

        cout
        << "\nRemove cancelled.";

        system("pause");

        return;

    }



    ofstream clearFile(
        "data/Appointment.txt",
        ios::trunc
    );



    clearFile.close();



    cout
    << "\nAll appointments removed successfully.";

    system("pause");

}


/*
 * Edit Appointment
 */
void Appointment::editAppointment()
{

    string searchID;

    cout
    << "\nEnter Appointment ID to edit: ";

    cin
    >> searchID;

    ifstream appointmentFile(
        "data/Appointment.txt"
    );


    if(!appointmentFile)
    {

        cout
        << "\nNo appointment found.";

        system("pause");

        return;

    }

    vector<string> records;
    string line;

    while(getline(appointmentFile,line))
    {

        records.push_back(line);

    }

    appointmentFile.close();

    bool found = false;


    for(size_t i = 0; i < records.size(); i++)
    {

        if(records[i] == searchID)
        {

            found = true;

            cin.ignore();

            cout
            << "\nNew Appointment Date : ";

            getline(
                cin,
                AppointmentDate
            );


            cout
            << "New Appointment Time : ";

            getline(
                cin,
                AppointmentTime
            );


            cout
            << "New Illness : ";

            getline(
                cin,
                AppointmentIllness
            );


            cout
            << "New Doctor : ";

            getline(
                cin,
                AppointmentDoctor
            );


            cout
            << "New Specialization : ";

            getline(
                cin,
                AppointmentSpecialization
            );

            records[i+1] = AppointmentDate;
            records[i+2] = AppointmentTime;
            records[i+3] = AppointmentIllness;
            records[i+4] = AppointmentDoctor;
            records[i+5] = AppointmentSpecialization;

            break;

        }

    }

    if(!found)
    {
        cout
        << "\nAppointment ID not found.";

        system("pause");
        return;
    }

    ofstream updateFile(
        "data/Appointment.txt",
        ios::trunc
    );

    for(string data : records)
    {

        updateFile
        << data
        << endl;

    }

    updateFile.close();

    cout
    << "\nAppointment updated successfully.";

    system("pause");

}


/*
 * View Appointment
 */
void Appointment::viewAppointment()
{

    ifstream appointmentFile(
        "data/Appointment.txt"
    );

    if(!appointmentFile)
    {
        cout
        << "\nNo appointment record found.";

        system("pause");

        return;

    }

    system("cls");

    cout
    << "\n=================================================\n";

    cout
    << " Appointment List\n";

    cout
    << "=================================================\n";

    int count = 1;

    while(getline(appointmentFile, AppointmentID))
    {
        if(AppointmentID.empty())
        {
            continue;
        }

        getline(
            appointmentFile,
            AppointmentDate
        );

        getline(
            appointmentFile,
            AppointmentTime
        );

        getline(
            appointmentFile,
            AppointmentIllness
        );

        getline(
            appointmentFile,
            AppointmentDoctor
        );

        getline(
            appointmentFile,
            AppointmentSpecialization
        );

        string emptyLine;

        getline(
            appointmentFile,
            emptyLine
        );


        cout
        << "\nAppointment "
        << count
        << endl;

        cout
        << "ID             : "
        << AppointmentID
        << endl;

        cout
        << "Date           : "
        << AppointmentDate
        << endl;

        cout
        << "Time           : "
        << AppointmentTime
        << endl;

        cout
        << "Illness        : "
        << AppointmentIllness
        << endl;

        cout
        << "Doctor         : "
        << AppointmentDoctor
        << endl;

        cout
        << "Specialization : "
        << AppointmentSpecialization
        << endl;

        cout
        << "---------------------------------\n";

        count++;

    }

    appointmentFile.close();
    system("pause");

}


/*
 * Payment Process
 */
void Appointment::payment()
{

    ifstream appointmentFile(
        "data/Appointment.txt"
    );


    if(!appointmentFile)
    {

        cout
        << "\nPlease create an appointment first.";

        system("pause");

        return;

    }

    appointmentFile.close();
    viewAppointment();

    int option;

    cout
    << "\nProceed to payment?";

    cout
    << "\n1. Yes";

    cout
    << "\n0. No";

    cout
    << "\nChoice: ";

    cin
    >> option;


    if(option == 1)
    {

        Payment paymentSystem;
        paymentSystem.makePayment();

        system("pause");

    }

}
