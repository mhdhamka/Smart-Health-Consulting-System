/*
 * Payment Class Implementation
 * SmartHealth System
 */

#include <iostream>
#include <string>
#include <fstream>

#include "payment.h"

using namespace std;


// Constructor
Payment::Payment()
{
    paymentAppointmentID = "";
    paymentDate = "";
    paymentTime = "";
    paymentIllness = "";
    paymentDoctor = "";
    paymentSpecialization = "";
    paymentTotalPrice = 0;
}


// Setter functions
void Payment::setPaymentAppointmentID(string aid)
{
    paymentAppointmentID = aid;
}


void Payment::setPaymentDate(string pd)
{
    paymentDate = pd;
}


void Payment::setPaymentTime(string pt)
{
    paymentTime = pt;
}


void Payment::setPaymentIllness(string pi)
{
    paymentIllness = pi;
}


void Payment::setPaymentDoctor(string pdoc)
{
    paymentDoctor = pdoc;
}


void Payment::setPaymentSpecialization(string ps)
{
    paymentSpecialization = ps;
}


void Payment::setPaymentTotalPrice(double price)
{
    paymentTotalPrice = price;
}



// Getter functions

string Payment::getPaymentAppointmentID()
{
    return paymentAppointmentID;
}


string Payment::getPaymentDate()
{
    return paymentDate;
}


string Payment::getPaymentTime()
{
    return paymentTime;
}


string Payment::getPaymentIllness()
{
    return paymentIllness;
}


string Payment::getPaymentDoctor()
{
    return paymentDoctor;
}


string Payment::getPaymentSpecialization()
{
    return paymentSpecialization;
}


double Payment::getPaymentTotalPrice()
{
    return paymentTotalPrice;
}




/*
 * Patient make payment
 */

void Payment::makePayment()
{

    ifstream appointmentFile(
        "data/Appointment.txt"
    );


    if(!appointmentFile.is_open())
    {
        cout << "\nNo appointment record found.";
        return;
    }



    ofstream paymentFile(
        "data/Payment.txt",
        ios::app
    );


    if(!paymentFile.is_open())
    {
        cout << "\nUnable to open payment file.";
        return;
    }

    cout << "\n=====================================================\n";
    cout << "          SMARTHEALTH SYSTEM\n";
    cout << "----------------------Payment------------------------\n";


    /*
       Read appointment details
    */
    getline(
        appointmentFile,
        paymentAppointmentID
    );

    getline(
        appointmentFile,
        paymentDate
    );

    getline(
        appointmentFile,
        paymentTime
    );

    getline(
        appointmentFile,
        paymentIllness
    );

    getline(
        appointmentFile,
        paymentDoctor
    );

    getline(
        appointmentFile,
        paymentSpecialization
    );


    // Fixed appointment price
    paymentTotalPrice = 100.00;

    cout
    << "\nAppointment ID      : "
    << paymentAppointmentID;

    cout
    << "\nAppointment Date    : "
    << paymentDate;

    cout
    << "\nAppointment Time    : "
    << paymentTime;

    cout
    << "\nIllness             : "
    << paymentIllness;

    cout
    << "\nDoctor              : "
    << paymentDoctor;

    cout
    << "\nSpecialization      : "
    << paymentSpecialization;

    cout
    << "\nTotal Payment       : RM"
    << paymentTotalPrice;


    /*
       Save payment record
    */
    paymentFile
    << paymentAppointmentID << endl
    << paymentDate << endl
    << paymentTime << endl
    << paymentIllness << endl
    << paymentDoctor << endl
    << paymentSpecialization << endl
    << paymentTotalPrice << endl

    << endl;

    appointmentFile.close();
    paymentFile.close();

    cout
    << "\n\nPayment completed successfully.";

}


/*
 * View payment records
 */

void Payment::viewPayment()
{

    ifstream paymentFile(
        "data/Payment.txt"
    );


    if(!paymentFile.is_open())
    {
        cout
        << "\nNo payment record found.";

        return;
    }

    string line;

    cout << "\n=====================================================\n";
    cout << "          SMARTHEALTH SYSTEM\n";
    cout << "--------------------Payment List---------------------\n";

    int count = 1;

    while(getline(paymentFile, paymentAppointmentID))
    {

        if(paymentAppointmentID.empty())
        {
            continue;
        }

        getline(paymentFile,paymentDate);
        getline(paymentFile,paymentTime);
        getline(paymentFile,paymentIllness);
        getline(paymentFile,paymentDoctor);
        getline(paymentFile,paymentSpecialization);


        string price;

        getline(paymentFile,price);



        cout
        << "\nPayment "
        << count
        << "\n";


        cout
        << "Appointment ID : "
        << paymentAppointmentID
        << endl;

        cout
        << "Date           : "
        << paymentDate
        << endl;

        cout
        << "Time           : "
        << paymentTime
        << endl;

        cout
        << "Illness        : "
        << paymentIllness
        << endl;

        cout
        << "Doctor         : "
        << paymentDoctor
        << endl;

        cout
        << "Specialization : "
        << paymentSpecialization
        << endl;

        cout
        << "Amount         : RM"
        << price
        << endl;

        cout
        << "-------------------------------------\n";



        count++;

    }

    paymentFile.close();

}
