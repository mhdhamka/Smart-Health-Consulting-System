/*
 * Appointment Class Implementation
 * SmartHealth System 
 */

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>

#include "appointment.h"
#include "record.h"
#include "patient.h"
#include "doctor.h"
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

static void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void pauseScreen()
{
    cout << "\n  " << DIM << "Press [ENTER] to continue..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Modern Dashboard Header Card
static void displayHeader(string subtitle)
{
    cout << CYAN << BOLD << "\n  ======================================================\n";
    cout << "   SMARTHEALTH CLINICAL MANAGEMENT SYSTEM v2.6          \n";
    cout << "   " << BLUE << left << setw(50) << subtitle << CYAN << " |\n";
    cout << "  ======================================================\n" << RESET;
}

static int getChoice()
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

Payment paym;
Patient pa;

/*
 * Constructor
 */
Appointment::Appointment()
{
    AppointmentID = "";
    AppointmentDate = "";
    AppointmentTime = "";
    AppointmentIllness = "";
    AppointmentDoctor = "";
    AppointmentSpecialization = "";
}

/*
 * Setter Functions
 */
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

/*
 * Getter Functions
 */
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
        clearScreen();
        displayHeader("APPOINTMENT MANAGEMENT PORTAL");

        cout << "\n  " << BOLD << "APPOINTMENT OPTIONS:" << RESET << "\n";
        cout << "  " << MAGENTA << "[1]" << RESET << " Add Appointment\n";
        cout << "  " << MAGENTA << "[2]" << RESET << " Remove Appointment\n";
        cout << "  " << MAGENTA << "[3]" << RESET << " Edit Appointment\n";
        cout << "  " << MAGENTA << "[4]" << RESET << " View Appointment\n";
        cout << "  " << MAGENTA << "[5]" << RESET << " Make Payment\n";
        cout << "\n  " << DIM << "[6] Return to Main Menu" << RESET << "\n";

        option = getChoice();

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
            cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid option. Please choose [1-6].\n";
            pauseScreen();
        }
    }
}

/*
 * Add Appointment
 */
void Appointment::addAppointment()
{
    clearScreen();
    displayHeader("AVAILABLE DOCTOR SCHEDULE");

    cout << "\n  " << BOLD << "ACTIVE DOCTOR ROSTER:" << RESET << "\n";
    cout << "  " << CYAN << "------------------------------------------------------" << RESET << "\n";
    cout << "  " << BOLD << "APP01" << RESET << " | Date: 05/01/2026 | Time: 09:00\n";
    cout << "          Doctor: Jude Bellingham | Spec: ORT\n";
    cout << "  " << CYAN << "------------------------------------------------------" << RESET << "\n";
    cout << "  " << BOLD << "APP02" << RESET << " | Date: 06/01/2026 | Time: 10:00\n";
    cout << "          Doctor: Kylian Mbappe | Spec: CAR\n";
    cout << "  " << CYAN << "------------------------------------------------------" << RESET << "\n";
    cout << "  " << BOLD << "APP03" << RESET << " | Date: 07/01/2026 | Time: 11:00\n";
    cout << "          Doctor: Erling Haaland | Spec: DER\n";
    cout << "  " << CYAN << "------------------------------------------------------" << RESET << "\n";
    cout << "  " << BOLD << "APP04" << RESET << " | Date: 08/01/2026 | Time: 13:00\n";
    cout << "          Doctor: Vinicius Junior | Spec: PED\n";
    cout << "  " << CYAN << "------------------------------------------------------" << RESET << "\n";
    cout << "  " << BOLD << "APP05" << RESET << " | Date: 09/01/2026 | Time: 14:00\n";
    cout << "          Doctor: Jamal Musiala | Spec: ENT\n";
    cout << "  " << CYAN << "------------------------------------------------------" << RESET << "\n";
    cout << "  " << BOLD << "APP06" << RESET << " | Date: 10/01/2026 | Time: 15:00\n";
    cout << "          Doctor: Lamine Yamal | Spec: NEU\n";
    cout << "  " << CYAN << "------------------------------------------------------" << RESET << "\n";
    cout << "  " << BOLD << "APP07" << RESET << " | Date: 11/01/2026 | Time: 16:00\n";
    cout << "          Doctor: Cole Palmer | Spec: GEN\n";
    cout << "  " << CYAN << "------------------------------------------------------" << RESET << "\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n  " << BOLD << "Enter Appointment Details:" << RESET << "\n";
    cout << "  " << CYAN << "> Appointment ID   : " << RESET;
    getline(cin, AppointmentID);

    cout << "  " << CYAN << "> Appointment Date : " << RESET;
    getline(cin, AppointmentDate);

    cout << "  " << CYAN << "> Appointment Time : " << RESET;
    getline(cin, AppointmentTime);

    cout << "  " << CYAN << "> Illness          : " << RESET;
    getline(cin, AppointmentIllness);

    cout << "  " << CYAN << "> Doctor           : " << RESET;
    getline(cin, AppointmentDoctor);

    cout << "  " << CYAN << "> Specialization   : " << RESET;
    getline(cin, AppointmentSpecialization);

    ofstream appointmentFile("data/Appointment.txt", ios::app);

    if(!appointmentFile)
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Unable to save appointment file.\n";
        pauseScreen();
        return;
    }

    appointmentFile << AppointmentID << endl
                    << AppointmentDate << endl
                    << AppointmentTime << endl
                    << AppointmentIllness << endl
                    << AppointmentDoctor << endl
                    << AppointmentSpecialization << endl
                    << endl;

    appointmentFile.close();

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Appointment successfully created.\n";
    pauseScreen();
}

/*
 * Remove Appointment
 */
void Appointment::removeAppointment()
{
    clearScreen();
    displayHeader("REMOVE APPOINTMENT RECORDS");

    ifstream appointmentFile("data/Appointment.txt");

    if(!appointmentFile)
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " No appointment records found.\n";
        pauseScreen();
        return;
    }

    appointmentFile.close();

    char confirm;
    cout << "\n  " << YELLOW << "-> Are you sure you want to remove all appointments? (Y/N): " << RESET;
    cin >> confirm;

    if(confirm != 'Y' && confirm != 'y')
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " Removal cancelled.\n";
        pauseScreen();
        return;
    }

    ofstream clearFile("data/Appointment.txt", ios::trunc);
    clearFile.close();

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " All appointments removed successfully.\n";
    pauseScreen();
}

/*
 * Edit Appointment
 */
void Appointment::editAppointment()
{
    clearScreen();
    displayHeader("EDIT APPOINTMENT RECORD");

    string searchID;
    cout << "\n  " << CYAN << "> Enter Appointment ID to edit: " << RESET;
    cin >> searchID;

    ifstream appointmentFile("data/Appointment.txt");

    if(!appointmentFile)
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " No appointment records found.\n";
        pauseScreen();
        return;
    }

    vector<string> records;
    string line;

    while(getline(appointmentFile, line))
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

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\n  " << BOLD << "Enter New Details for " << CYAN << searchID << RESET << ":\n";
            cout << "  " << CYAN << "> New Date          : " << RESET;
            getline(cin, AppointmentDate);

            cout << "  " << CYAN << "> New Time          : " << RESET;
            getline(cin, AppointmentTime);

            cout << "  " << CYAN << "> New Illness       : " << RESET;
            getline(cin, AppointmentIllness);

            cout << "  " << CYAN << "> New Doctor        : " << RESET;
            getline(cin, AppointmentDoctor);

            cout << "  " << CYAN << "> New Specialization: " << RESET;
            getline(cin, AppointmentSpecialization);

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
        cout << "\n  " << RED << "[ERROR]" << RESET << " Appointment ID not found.\n";
        pauseScreen();
        return;
    }

    ofstream updateFile("data/Appointment.txt", ios::trunc);

    for(string data : records)
    {
        updateFile << data << endl;
    }

    updateFile.close();

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Appointment updated successfully.\n";
    pauseScreen();
}

/*
 * View Appointment
 */
void Appointment::viewAppointment()
{
    clearScreen();
    displayHeader("APPOINTMENT RECORDS LIST");

    ifstream appointmentFile("data/Appointment.txt");

    if(!appointmentFile)
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " No appointment record found.\n";
        pauseScreen();
        return;
    }

    int count = 1;
    bool hasRecords = false;

    while(getline(appointmentFile, AppointmentID))
    {
        if(AppointmentID.empty())
        {
            continue;
        }

        hasRecords = true;

        getline(appointmentFile, AppointmentDate);
        getline(appointmentFile, AppointmentTime);
        getline(appointmentFile, AppointmentIllness);
        getline(appointmentFile, AppointmentDoctor);
        getline(appointmentFile, AppointmentSpecialization);

        string emptyLine;
        getline(appointmentFile, emptyLine);

        cout << "\n  " << BOLD << MAGENTA << "--- Appointment #" << count << " ---" << RESET << "\n";
        cout << "  " << CYAN << "ID             : " << RESET << AppointmentID << "\n";
        cout << "  " << CYAN << "Date           : " << RESET << AppointmentDate << "\n";
        cout << "  " << CYAN << "Time           : " << RESET << AppointmentTime << "\n";
        cout << "  " << CYAN << "Illness        : " << RESET << AppointmentIllness << "\n";
        cout << "  " << CYAN << "Doctor         : " << RESET << AppointmentDoctor << "\n";
        cout << "  " << CYAN << "Specialization : " << RESET << AppointmentSpecialization << "\n";

        count++;
    }

    appointmentFile.close();

    if(!hasRecords)
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " No active appointments found in records.\n";
    }

    pauseScreen();
}

/*
 * Payment Process
 */
void Appointment::payment()
{
    clearScreen();
    displayHeader("PAYMENT PROCESSING");

    ifstream appointmentFile("data/Appointment.txt");

    if(!appointmentFile)
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Please create an appointment first.\n";
        pauseScreen();
        return;
    }

    appointmentFile.close();

    viewAppointment();

    int option;
    cout << "\n  " << BOLD << "Proceed to payment?" << RESET << "\n";
    cout << "  " << MAGENTA << "[1]" << RESET << " Yes\n";
    cout << "  " << MAGENTA << "[0]" << RESET << " No\n";

    option = getChoice();

    if(option == 1)
    {
        Payment paymentSystem;
        paymentSystem.makePayment();
    }
    else
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " Payment cancelled.\n";
        pauseScreen();
    }
}
