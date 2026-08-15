/*
 * Payment Class Implementation
 * SmartHealth System 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <conio.h>

#include "payment.h"

using namespace std;

// ANSI Color Palette (Modern Dark Theme Styling)
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string DIM = "\033[2m";
const string CYAN = "\033[36m";
const string BLUE = "\033[34m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string RED = "\033[31m";
const string MAGENTA = "\033[35m";

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
    cout << "\n  " << DIM << "Press [ENTER] to continue..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Modern Dashboard Header Card
void displayHeader(string subtitle)
{
    cout << CYAN << BOLD << "\n  ======================================================\n";
    cout << "   SMARTHEALTH CLINICAL MANAGEMENT SYSTEM v2.6          \n";
    cout << "   " << BLUE << left << setw(50) << subtitle << CYAN << " |\n";
    cout << "  ======================================================\n" << RESET;
}

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
    ifstream appointmentFile("data/Appointment.txt");

    if(!appointmentFile.is_open())
    {
        clearScreen();
        displayHeader("PROCESS PAYMENT");
        cout << "\n  " << RED << "[ERROR]" << RESET << " No appointment record found.\n";
        pauseScreen();
        return;
    }

    ofstream paymentFile("data/Payment.txt", ios::app);

    if(!paymentFile.is_open())
    {
        clearScreen();
        displayHeader("PROCESS PAYMENT");
        cout << "\n  " << RED << "[ERROR]" << RESET << " Unable to open payment file.\n";
        appointmentFile.close();
        pauseScreen();
        return;
    }

    clearScreen();
    displayHeader("PROCESS PAYMENT / CHECKOUT");

    /*
        Read appointment details
    */
    getline(appointmentFile, paymentAppointmentID);
    getline(appointmentFile, paymentDate);
    getline(appointmentFile, paymentTime);
    getline(appointmentFile, paymentIllness);
    getline(appointmentFile, paymentDoctor);
    getline(appointmentFile, paymentSpecialization);

    // Fixed appointment price
    paymentTotalPrice = 100.00;

    cout << "\n  " << BOLD << "Retrieved Appointment Details:" << RESET << "\n";
    cout << "  " << CYAN << "Appointment ID : " << RESET << paymentAppointmentID << "\n";
    cout << "  " << CYAN << "Date & Time    : " << RESET << paymentDate << " at " << paymentTime << "\n";
    cout << "  " << CYAN << "Illness        : " << RESET << paymentIllness << "\n";
    cout << "  " << CYAN << "Doctor         : " << RESET << paymentDoctor << " (" << paymentSpecialization << ")\n";
    cout << "  " << GREEN << "Total Payment  : RM " << fixed << setprecision(2) << paymentTotalPrice << RESET << "\n";

    /*
        Save payment record
    */
    paymentFile << paymentAppointmentID << endl
                << paymentDate << endl
                << paymentTime << endl
                << paymentIllness << endl
                << paymentDoctor << endl
                << paymentSpecialization << endl
                << paymentTotalPrice << endl
                << endl;

    appointmentFile.close();
    paymentFile.close();

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Payment completed successfully.\n";
    pauseScreen();
}

/*
 * View payment records
 */
void Payment::viewPayment()
{
    ifstream paymentFile("data/Payment.txt");

    if(!paymentFile.is_open())
    {
        clearScreen();
        displayHeader("PAYMENT RECORDS ARCHIVE");
        cout << "\n  " << RED << "[INFO]" << RESET << " No payment records found.\n";
        pauseScreen();
        return;
    }

    clearScreen();
    displayHeader("PAYMENT RECORDS ARCHIVE");

    int count = 1;

    while(getline(paymentFile, paymentAppointmentID))
    {
        if(paymentAppointmentID.empty())
        {
            continue;
        }

        getline(paymentFile, paymentDate);
        getline(paymentFile, paymentTime);
        getline(paymentFile, paymentIllness);
        getline(paymentFile, paymentDoctor);
        getline(paymentFile, paymentSpecialization);

        string price;
        getline(paymentFile, price);

        cout << "\n  " << BOLD << "--- PAYMENT RECORD #" << count << " ---" << RESET << "\n";
        cout << "  " << CYAN << "Appointment ID : " << RESET << paymentAppointmentID << "\n";
        cout << "  " << CYAN << "Date / Time    : " << RESET << paymentDate << " at " << paymentTime << "\n";
        cout << "  " << CYAN << "Illness        : " << RESET << paymentIllness << "\n";
        cout << "  " << CYAN << "Doctor         : " << RESET << paymentDoctor << " (" << paymentSpecialization << ")\n";
        cout << "  " << GREEN << "Amount Paid    : RM " << price << RESET << "\n";

        count++;
    }

    paymentFile.close();
    pauseScreen();
}
