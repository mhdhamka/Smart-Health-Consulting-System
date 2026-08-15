/*
 * Doctor Class Implementation
 * SmartHealth System 
 */

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <conio.h>

#include "record.h"
#include "doctor.h"
#include "appointment.h"

using namespace std;

Appointment App;
Record Rec;

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

int getChoice()
{
    int choice;
    cout << "\n  " << YELLOW << "-> Enter selection: " << RESET;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}

/*
 * Constructor
 */
Doctor::Doctor()
{
    username = "PDC1365";
    password = "74251";
    doctorName = "Lamine Hamka";
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

    clearScreen();
    displayHeader("DOCTOR AUTHENTICATION");

    cout << "\n  " << BOLD << "Please enter your professional credentials:" << RESET << "\n";
    cout << "  " << CYAN << "> Doctor ID : " << RESET;
    cin >> docID;

    cout << "  " << CYAN << "> Password  : " << RESET;
    cin >> docPassword;

    if (docID == username && docPassword == password)
    {
        cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Welcome Doctor " << BOLD << doctorName << RESET << "! Login successful.\n";
        pauseScreen();
        doctorMenu();
    }
    else
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid doctor ID or password.\n";
        pauseScreen();
    }
}

/*
 * Doctor Menu
 */
void Doctor::doctorMenu()
{
    Appointment appointmentSystem;
    Record recordSystem;

    while (true)
    {
        clearScreen();
        displayHeader("PORTAL / DOCTOR MANAGEMENT");

        cout << "\n  " << BOLD << "CLINICAL OPTIONS:" << RESET << "\n";
        cout << "  " << MAGENTA << "[1]" << RESET << " View Appointments\n";
        cout << "  " << MAGENTA << "[2]" << RESET << " Add Medical Record\n";
        cout << "  " << MAGENTA << "[3]" << RESET << " Delete Medical Record\n";
        cout << "  " << MAGENTA << "[4]" << RESET << " Edit Medical Record\n";
        cout << "  " << MAGENTA << "[5]" << RESET << " View Medical Record\n";
        cout << "\n  " << DIM << "[6] Logout / Return" << RESET << "\n";

        int option = getChoice();

        switch (option)
        {
        case 1:
            clearScreen();
            displayHeader("APPOINTMENTS LIST");
            appointmentSystem.viewAppointment();
            pauseScreen();
            break;

        case 2:
            clearScreen();
            displayHeader("ADD MEDICAL RECORD");
            recordSystem.addRecord();
            pauseScreen();
            break;

        case 3:
            clearScreen();
            displayHeader("DELETE MEDICAL RECORD");
            recordSystem.removeRecord();
            pauseScreen();
            break;

        case 4:
            clearScreen();
            displayHeader("EDIT MEDICAL RECORD");
            recordSystem.editRecord();
            pauseScreen();
            break;

        case 5:
            clearScreen();
            displayHeader("VIEW MEDICAL RECORD");
            recordSystem.viewRecord();
            pauseScreen();
            break;

        case 6:
            return;

        default:
            cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid option. Please choose [1-6].\n";
            pauseScreen();
        }
    }
}
