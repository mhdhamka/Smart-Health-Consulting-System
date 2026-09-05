/*
 * Patient Class Implementation
 * SmartHealth System 
 */

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <limits>

#include "patient.h"
#include "bool.h"
#include "appointment.h"
#include "payment.h"
#include "record.h"

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

// Global objects
Appointment app;
Payment pay;
Record re;

/*
 * Constructor
 */
Patient::Patient()
{
    patientID = "";
    patientName = "";
    patientAge = "";
    patientAddress = "";
    phone = "";
    medicalHistory = "";
}

/*
 * Setter Functions
 */
void Patient::setpatientID(string pid)
{
    patientID = pid;
}

void Patient::setpatientName(string pn)
{
    patientName = pn;
}

void Patient::setpatientAge(string pa)
{
    patientAge = pa;
}

void Patient::setpatientAddress(string padd)
{
    patientAddress = padd;
}

void Patient::setphone(string ph)
{
    phone = ph;
}

void Patient::setmedicalHistory(string mh)
{
    medicalHistory = mh;
}

/*
 * Getter Functions
 */
string Patient::getpatientID()
{
    return patientID;
}

string Patient::getpatientName()
{
    return patientName;
}

string Patient::getpatientAge()
{
    return patientAge;
}

string Patient::getpatientAddress()
{
    return patientAddress;
}

string Patient::getphone()
{
    return phone;
}

string Patient::getmedicalHistory()
{
    return medicalHistory;
}

/*
 * Patient Registration
 */
void Patient::registration()
{
    clearScreen();
    displayHeader("PATIENT REGISTRATION");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /*
     * Username validation
     */
    while(true)
    {
        cout << "\n  " << CYAN << "> Username     : " << RESET;
        getline(cin, username);

        ifstream checkFile("data/PatientRegistration.txt");
        bool exist = false;
        string line;

        while(getline(checkFile, line))
        {
            if(line == username)
            {
                exist = true;
                break;
            }

            // skip remaining 8 fields
            for(int i = 0; i < 8; i++)
            {
                getline(checkFile, line);
            }
        }

        checkFile.close();

        if(exist)
        {
            cout << "  " << RED << "[ERROR]" << RESET << " Username already exists. Try another one.\n";
        }
        else
        {
            break;
        }
    }

    cout << "  " << CYAN << "> Password     : " << RESET;
    getline(cin, password);

    cout << "  " << CYAN << "> Patient ID   : " << RESET;
    getline(cin, patientID);

    cout << "  " << CYAN << "> Patient Name : " << RESET;
    getline(cin, patientName);

    cout << "  " << CYAN << "> Patient Age  : " << RESET;
    getline(cin, patientAge);

    cout << "  " << CYAN << "> Address      : " << RESET;
    getline(cin, patientAddress);

    /*
     * Email validation
     */
    while(true)
    {
        cout << "  " << CYAN << "> Email        : " << RESET;
        getline(cin, email);

        if(checkEmail(email))
        {
            break;
        }

        cout << "  " << RED << "[ERROR]" << RESET << " Invalid email format.\n";
    }

    /*
     * Phone validation
     */
    while(true)
    {
        cout << "  " << CYAN << "> Phone Number : " << RESET;
        getline(cin, phone);

        if(checkMobile(phone, phone.length()))
        {
            break;
        }

        cout << "  " << RED << "[ERROR]" << RESET << " Invalid phone number.\n";
    }

    cout << "  " << CYAN << "> Medical Hist : " << RESET;
    getline(cin, medicalHistory);

    ofstream patientFile("data/PatientRegistration.txt", ios::app);

    if(!patientFile)
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Unable to save registration data.\n";
        pauseScreen();
        return;
    }

    patientFile << username << endl
                << password << endl
                << patientID << endl
                << patientName << endl
                << patientAge << endl
                << patientAddress << endl
                << email << endl
                << phone << endl
                << medicalHistory << endl
                << endl;

    patientFile.close();

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Patient registration successful.\n";
    pauseScreen();
}

/*
 * Patient Login
 */
void Patient::login()
{
    clearScreen();
    displayHeader("PATIENT AUTHENTICATION");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n  " << BOLD << "Please enter your portal credentials:" << RESET << "\n";
    cout << "  " << CYAN << "> Username : " << RESET;
    getline(cin, username);

    cout << "  " << CYAN << "> Password : " << RESET;
    getline(cin, password);

    if(!validateLogin(username, password))
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid username or password.\n";
        pauseScreen();
        return;
    }

    /*
     * Load patient information
     */
    ifstream patientFile("data/PatientRegistration.txt");
    string user;

    while(getline(patientFile, user))
    {
        string pass;
        getline(patientFile, pass);

        if(user == username && pass == password)
        {
            getline(patientFile, patientID);
            getline(patientFile, patientName);
            getline(patientFile, patientAge);
            getline(patientFile, patientAddress);
            getline(patientFile, email);
            getline(patientFile, phone);
            getline(patientFile, medicalHistory);
            break;
        }
        else
        {
            // skip current user data
            for(int i = 0; i < 7; i++)
            {
                getline(patientFile, user);
            }
        }
    }

    patientFile.close();

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Welcome " << BOLD << username << RESET << "! Login successful.\n";
    pauseScreen();
    patientPlatform();
}

/*
 * Patient Menu
 */
void Patient::patientPlatform()
{
    int option;
    Appointment app;
    Payment pay;
    Record re;

    while(true)
    {
        clearScreen();
        displayHeader("PORTAL / PATIENT DASHBOARD");

        cout << "\n  " << BOLD << "Welcome back, " << CYAN << username << RESET << "!\n";
        cout << "\n  " << BOLD << "PATIENT OPTIONS:" << RESET << "\n";
        cout << "  " << MAGENTA << "[1]" << RESET << " View Profile\n";
        cout << "  " << MAGENTA << "[2]" << RESET << " Edit Profile\n";
        cout << "  " << MAGENTA << "[3]" << RESET << " Set Appointment\n";
        cout << "  " << MAGENTA << "[4]" << RESET << " View Medical Record\n";
        cout << "  " << MAGENTA << "[5]" << RESET << " Make Payment\n";
        cout << "\n  " << DIM << "[6] Logout / Return" << RESET << "\n";

        option = getChoice();

        switch(option)
        {
        case 1:
            viewProfile();
            break;

        case 2:
            editProfile();
            break;

        case 3:
            app.appMenu();
            break;

        case 4:
            clearScreen();
            displayHeader("PATIENT MEDICAL RECORD");
            re.viewpatientRecord();
            pauseScreen();
            break;

        case 5:
            clearScreen();
            displayHeader("PROCESS PAYMENT");
            pay.makePayment();
            pauseScreen();
            break;

        case 6:
        {
            char confirm;
            cout << "\n  " << YELLOW << "-> Logout? (Y/N): " << RESET;
            cin >> confirm;

            if(confirm == 'Y' || confirm == 'y')
            {
                return;
            }
            break;
        }

        default:
            cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid option. Please choose [1-6].\n";
            pauseScreen();
        }
    }
}

/*
 * View Patient Profile
 */
void Patient::viewProfile()
{
    clearScreen();
    displayHeader("PATIENT PROFILE DETAILS");

    cout << "\n  " << BOLD << "ACCOUNT INFORMATION:" << RESET << "\n";
    cout << "  " << CYAN << "Username        : " << RESET << username << "\n";
    cout << "  " << CYAN << "Password        : " << RESET << password << "\n";
    cout << "  " << CYAN << "Patient ID      : " << RESET << patientID << "\n";

    cout << "\n  " << BOLD << "PERSONAL INFORMATION:" << RESET << "\n";
    cout << "  " << CYAN << "Patient Name    : " << RESET << patientName << "\n";
    cout << "  " << CYAN << "Patient Age     : " << RESET << patientAge << "\n";
    cout << "  " << CYAN << "Address         : " << RESET << patientAddress << "\n";
    cout << "  " << CYAN << "Email           : " << RESET << email << "\n";
    cout << "  " << CYAN << "Phone Number    : " << RESET << phone << "\n";
    cout << "  " << CYAN << "Medical History : " << RESET << medicalHistory << "\n";

    pauseScreen();
}

/*
 * Edit Patient Profile
 */
void Patient::editProfile()
{
    clearScreen();
    displayHeader("EDIT PATIENT PROFILE");

    string newName, newAge, newAddress, newEmail, newPhone, newHistory;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "  " << CYAN << "> Enter new patient name: " << RESET;
    getline(cin, newName);

    cout << "  " << CYAN << "> Enter new patient age : " << RESET;
    getline(cin, newAge);

    cout << "  " << CYAN << "> Enter new address     : " << RESET;
    getline(cin, newAddress);

    /*
     * Email validation
     */
    while(true)
    {
        cout << "  " << CYAN << "> Enter new email       : " << RESET;
        getline(cin, newEmail);

        if(checkEmail(newEmail))
        {
            break;
        }

        cout << "  " << RED << "[ERROR]" << RESET << " Invalid email format.\n";
    }

    /*
     * Phone validation
     */
    while(true)
    {
        cout << "  " << CYAN << "> Enter new phone number: " << RESET;
        getline(cin, newPhone);

        if(checkMobile(newPhone, newPhone.length()))
        {
            break;
        }

        cout << "  " << RED << "[ERROR]" << RESET << " Invalid phone number.\n";
    }

    cout << "  " << CYAN << "> Enter medical history : " << RESET;
    getline(cin, newHistory);

    char confirm;
    cout << "\n  " << YELLOW << "-> Confirm profile update? (Y/N): " << RESET;
    cin >> confirm;

    if(confirm != 'Y' && confirm != 'y')
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " Update cancelled.\n";
        pauseScreen();
        return;
    }

    /*
     * Read old file
     */
    ifstream oldFile("data/PatientRegistration.txt");
    ofstream tempFile("data/tempPatient.txt");
    string line;

    while(getline(oldFile, line))
    {
        string oldUsername = line;
        string oldPassword, oldID, oldName, oldAge, oldAddress, oldEmail, oldPhone, oldHistory;

        getline(oldFile, oldPassword);
        getline(oldFile, oldID);
        getline(oldFile, oldName);
        getline(oldFile, oldAge);
        getline(oldFile, oldAddress);
        getline(oldFile, oldEmail);
        getline(oldFile, oldPhone);
        getline(oldFile, oldHistory);

        if(oldUsername == username)
        {
            tempFile << username << endl
                     << password << endl
                     << patientID << endl
                     << newName << endl
                     << newAge << endl
                     << newAddress << endl
                     << newEmail << endl
                     << newPhone << endl
                     << newHistory << endl
                     << endl;

            // update current object
            patientName = newName;
            patientAge = newAge;
            patientAddress = newAddress;
            email = newEmail;
            phone = newPhone;
            medicalHistory = newHistory;
        }
        else
        {
            tempFile << oldUsername << endl
                     << oldPassword << endl
                     << oldID << endl
                     << oldName << endl
                     << oldAge << endl
                     << oldAddress << endl
                     << oldEmail << endl
                     << oldPhone << endl
                     << oldHistory << endl
                     << endl;
        }
    }

    oldFile.close();
    tempFile.close();

    remove("data/PatientRegistration.txt");
    rename("data/tempPatient.txt", "data/PatientRegistration.txt");

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Profile updated successfully.\n";
    pauseScreen();
}
