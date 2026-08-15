/*
 * Hospital Class Implementation
 * SmartHealth System 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <conio.h>

#include "hospital.h"
#include "appointment.h"

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

// Constructor
Hospital::Hospital()
{
    username = "Marc Cucurella";
    password = "10024";

    hospitalName = "Green Valley Medical Centre";

    receiptID = "";
    patientID = "";
    patientName = "";
    patientAge = "";

    receiptdate = "";
    receipttime = "";

    drugID = "";
    drugName = "";
    drugDes = "";

    illness = "";
    diagnosis = "";
}

// Setter functions
void Hospital::sethospitalName(string hn)
{
    hospitalName = hn;
}

void Hospital::setreceiptID(string rid)
{
    receiptID = rid;
}

void Hospital::setpatientID(string pid)
{
    patientID = pid;
}

void Hospital::setpatientName(string pn)
{
    patientName = pn;
}

void Hospital::setpatientAge(string pa)
{
    patientAge = pa;
}

void Hospital::setreceiptdate(string rd)
{
    receiptdate = rd;
}

void Hospital::setreceipttime(string rt)
{
    receipttime = rt;
}

void Hospital::setdrugID(string did)
{
    drugID = did;
}

void Hospital::setdrugName(string dn)
{
    drugName = dn;
}

void Hospital::setdrugDes(string dd)
{
    drugDes = dd;
}

void Hospital::setillness(string ill)
{
    illness = ill;
}

void Hospital::setdiagnosis(string di)
{
    diagnosis = di;
}

// Getter functions
string Hospital::gethospitalName()
{
    return hospitalName;
}

string Hospital::getreceiptID()
{
    return receiptID;
}

string Hospital::getpatientID()
{
    return patientID;
}

string Hospital::getpatientName()
{
    return patientName;
}

string Hospital::getpatientAge()
{
    return patientAge;
}

string Hospital::getreceiptdate()
{
    return receiptdate;
}

string Hospital::getreceipttime()
{
    return receipttime;
}

string Hospital::getdrugID()
{
    return drugID;
}

string Hospital::getdrugName()
{
    return drugName;
}

string Hospital::getdrugDes()
{
    return drugDes;
}

string Hospital::getillness()
{
    return illness;
}

string Hospital::getdiagnosis()
{
    return diagnosis;
}

/*
 * Hospital Administrator Login
 */
void Hospital::login()
{
    string hosID;
    string hosPassword;

    clearScreen();
    displayHeader("HOSPITAL ADMINISTRATOR AUTHENTICATION");

    cout << "\n  " << BOLD << "Please enter your administrative credentials:" << RESET << "\n";
    cout << "  " << CYAN << "> Hospital ID : " << RESET;
    cin >> hosID;

    cout << "  " << CYAN << "> Password    : " << RESET;
    cin >> hosPassword;

    if (hosID == username && hosPassword == password)
    {
        cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Welcome " << BOLD << hospitalName << RESET << "! Login successful.\n";
        pauseScreen();
        hospitalMenu();
    }
    else
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid hospital ID or password.\n";
        pauseScreen();
    }
}

/*
 * Hospital Admin Menu
 */
void Hospital::hospitalMenu()
{
    int option;

    while (true)
    {
        clearScreen();
        displayHeader("PORTAL / HOSPITAL ADMINISTRATOR");

        cout << "\n  " << BOLD << "ADMIN OPTIONS:" << RESET << "\n";
        cout << "  " << MAGENTA << "[1]" << RESET << " Generate Medical Receipt\n";
        cout << "  " << MAGENTA << "[2]" << RESET << " View Stored Receipts\n";
        cout << "\n  " << DIM << "[3] Logout / Return" << RESET << "\n";

        option = getChoice();

        switch (option)
        {
        case 1:
            generateReceipt();
            break;

        case 2:
            viewReceipt();
            break;

        case 3:
            return;

        default:
            cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid option. Please choose [1-3].\n";
            pauseScreen();
        }
    }
}

/*
 * Generate Receipt
 */
void Hospital::generateReceipt()
{
    clearScreen();
    displayHeader("GENERATE NEW RECEIPT");

    cout << "  " << BOLD << "Enter receipt & patient details:" << RESET << "\n";
    cout << "  " << CYAN << "> Receipt ID   : " << RESET;
    cin >> receiptID;

    cout << "  " << CYAN << "> Patient ID   : " << RESET;
    cin >> patientID;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "  " << CYAN << "> Patient Name : " << RESET;
    getline(cin, patientName);

    cout << "  " << CYAN << "> Patient Age  : " << RESET;
    getline(cin, patientAge);

    cout << "  " << CYAN << "> Receipt Date : " << RESET;
    getline(cin, receiptdate);

    cout << "  " << CYAN << "> Receipt Time : " << RESET;
    getline(cin, receipttime);

    cout << "\n  " << BOLD << "Enter prescription details:" << RESET << "\n";
    cout << "  " << CYAN << "> Drug ID      : " << RESET;
    getline(cin, drugID);

    cout << "  " << CYAN << "> Drug Name    : " << RESET;
    getline(cin, drugName);

    cout << "  " << CYAN << "> Drug Desc    : " << RESET;
    getline(cin, drugDes);

    cout << "\n  " << BOLD << "Enter clinical notes:" << RESET << "\n";
    cout << "  " << CYAN << "> Illness      : " << RESET;
    getline(cin, illness);

    cout << "  " << CYAN << "> Diagnosis    : " << RESET;
    getline(cin, diagnosis);

    ofstream receiptFile("data/Receipt.txt", ios::app);

    if (!receiptFile)
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Unable to save receipt file.\n";
        pauseScreen();
        return;
    }

    receiptFile << receiptID << endl
                << patientID << endl
                << patientName << endl
                << patientAge << endl
                << receiptdate << endl
                << receipttime << endl
                << drugID << endl
                << drugName << endl
                << drugDes << endl
                << illness << endl
                << diagnosis << endl
                << endl;

    receiptFile.close();

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Receipt successfully generated and saved.\n";
    pauseScreen();
}

/*
 * View Receipt
 */
void Hospital::viewReceipt()
{
    ifstream receiptFile("data/Receipt.txt");

    if (!receiptFile)
    {
        clearScreen();
        displayHeader("RECEIPT ARCHIVE");
        cout << "\n  " << RED << "[INFO]" << RESET << " No receipt archives found.\n";
        pauseScreen();
        return;
    }

    clearScreen();
    displayHeader("RECEIPT RECORDS ARCHIVE");

    int count = 1;

    while (getline(receiptFile, receiptID))
    {
        if (receiptID.empty())
        {
            continue;
        }

        getline(receiptFile, patientID);
        getline(receiptFile, patientName);
        getline(receiptFile, patientAge);
        getline(receiptFile, receiptdate);
        getline(receiptFile, receipttime);
        getline(receiptFile, drugID);
        getline(receiptFile, drugName);
        getline(receiptFile, drugDes);
        getline(receiptFile, illness);
        getline(receiptFile, diagnosis);

        cout << "\n  " << BOLD << "--- RECEIPT RECORD #" << count << " ---" << RESET << "\n";
        cout << "  " << CYAN << "Receipt ID   : " << RESET << receiptID << "\n";
        cout << "  " << CYAN << "Patient ID   : " << RESET << patientID << "\n";
        cout << "  " << CYAN << "Patient Name : " << RESET << patientName << "\n";
        cout << "  " << CYAN << "Patient Age  : " << RESET << patientAge << "\n";
        cout << "  " << CYAN << "Date / Time  : " << RESET << receiptdate << " at " << receipttime << "\n";
        cout << "  " << CYAN << "Medication   : " << RESET << drugName << " (" << drugID << ") - " << drugDes << "\n";
        cout << "  " << CYAN << "Illness      : " << RESET << illness << "\n";
        cout << "  " << CYAN << "Diagnosis    : " << RESET << diagnosis << "\n";

        count++;
    }

    receiptFile.close();
    pauseScreen();
}
