/*
 * Record Class Implementation
 * SmartHealth System 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>

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

/*
 * Constructor
 */
Record::Record()
{
    patientID = "";
    patientName = "";
    patientAge = "";
    Date = "";
    Time = "";
    drugID = "";
    drugName = "";
    drugDes = "";
    illness = "";
    diagnosis = "";
}

/*
 * Setter Functions
 */
void Record::setpatientID(string pid)
{
    patientID = pid;
}

void Record::setpatientName(string pn)
{
    patientName = pn;
}

void Record::setpatientAge(string pa)
{
    patientAge = pa;
}

void Record::setDate(string d)
{
    Date = d;
}

void Record::setTime(string t)
{
    Time = t;
}

void Record::setdrugID(string did)
{
    drugID = did;
}

void Record::setdrugName(string dn)
{
    drugName = dn;
}

void Record::setdrugDes(string dd)
{
    drugDes = dd;
}

void Record::setillness(string ill)
{
    illness = ill;
}

void Record::setdiagnosis(string dia)
{
    diagnosis = dia;
}

/*
 * Getter Functions
 */
string Record::getpatientID()
{
    return patientID;
}

string Record::getpatientName()
{
    return patientName;
}

string Record::getpatientAge()
{
    return patientAge;
}

string Record::getDate()
{
    return Date;
}

string Record::getTime()
{
    return Time;
}

string Record::getdrugID()
{
    return drugID;
}

string Record::getdrugName()
{
    return drugName;
}

string Record::getdrugDes()
{
    return drugDes;
}

string Record::getillness()
{
    return illness;
}

string Record::getdiagnosis()
{
    return diagnosis;
}

/*
 * Check Patient ID Exists
 */
bool checkExistPatientID(string patientID)
{
    ifstream file("data/Record.txt");

    if(!file)
    {
        return false;
    }

    string id;

    while(getline(file, id))
    {
        if(id == patientID)
        {
            file.close();
            return true;
        }

        for(int i = 0; i < 9; i++)
        {
            getline(file, id);
        }
    }

    file.close();
    return false;
}

/*
 * Add Medical Record
 */
void Record::addRecord()
{
    clearScreen();
    displayHeader("ADD PATIENT MEDICAL RECORD");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n  " << BOLD << "Enter Patient & Medical Details:" << RESET << "\n";
    cout << "  " << CYAN << "> Patient ID       : " << RESET;
    getline(cin, patientID);

    cout << "  " << CYAN << "> Patient Name     : " << RESET;
    getline(cin, patientName);

    cout << "  " << CYAN << "> Patient Age      : " << RESET;
    getline(cin, patientAge);

    cout << "  " << CYAN << "> Record Date      : " << RESET;
    getline(cin, Date);

    cout << "  " << CYAN << "> Record Time      : " << RESET;
    getline(cin, Time);

    cout << "\n  " << BOLD << "Enter Prescription Details:" << RESET << "\n";
    cout << "  " << CYAN << "> Drug ID          : " << RESET;
    getline(cin, drugID);

    cout << "  " << CYAN << "> Drug Name        : " << RESET;
    getline(cin, drugName);

    cout << "  " << CYAN << "> Drug Description : " << RESET;
    getline(cin, drugDes);

    cout << "\n  " << BOLD << "Enter Clinical Details:" << RESET << "\n";
    cout << "  " << CYAN << "> Patient Illness  : " << RESET;
    getline(cin, illness);

    cout << "  " << CYAN << "> Patient Diagnosis: " << RESET;
    getline(cin, diagnosis);

    ofstream recordFile("data/Record.txt", ios::app);

    if(!recordFile)
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Unable to save record file.\n";
        pauseScreen();
        return;
    }

    recordFile << patientID << endl
               << patientName << endl
               << patientAge << endl
               << Date << endl
               << Time << endl
               << drugID << endl
               << drugName << endl
               << drugDes << endl
               << illness << endl
               << diagnosis << endl
               << endl;

    recordFile.close();

    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Patient record saved successfully.\n";
    pauseScreen();
}

/*
 * Remove Medical Record
 */
void Record::removeRecord()
{
    clearScreen();
    displayHeader("REMOVE PATIENT RECORD");

    string searchID;
    cout << "\n  " << CYAN << "> Enter Patient ID to remove: " << RESET;
    cin >> searchID;

    ifstream file("data/Record.txt");
    ofstream temp("data/tempRecord.txt");

    if(!file)
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " No record available.\n";
        pauseScreen();
        return;
    }

    string pid, pn, pa, rd, rt, did, dn, dd, ill, dia;
    bool found = false;

    while(getline(file, pid))
    {
        getline(file, pn);
        getline(file, pa);
        getline(file, rd);
        getline(file, rt);
        getline(file, did);
        getline(file, dn);
        getline(file, dd);
        getline(file, ill);
        getline(file, dia);

        string emptyLine;
        getline(file, emptyLine);

        if(pid == searchID)
        {
            found = true;
            continue;
        }

        temp << pid << endl
             << pn << endl
             << pa << endl
             << rd << endl
             << rt << endl
             << did << endl
             << dn << endl
             << dd << endl
             << ill << endl
             << dia << endl
             << endl;
    }

    file.close();
    temp.close();

    remove("data/Record.txt");
    rename("data/tempRecord.txt", "data/Record.txt");

    if(found)
    {
        cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Record deleted successfully.\n";
    }
    else
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Patient ID not found.\n";
    }

    pauseScreen();
}

/*
 * Edit Medical Record
 */
void Record::editRecord()
{
    clearScreen();
    displayHeader("EDIT PATIENT RECORD");

    string searchID;
    cout << "\n  " << CYAN << "> Enter Patient ID to edit: " << RESET;
    cin >> searchID;

    ifstream file("data/Record.txt");
    ofstream temp("data/tempRecord.txt");

    if(!file)
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " No record found.\n";
        pauseScreen();
        return;
    }

    string pid, pn, pa, rd, rt, did, dn, dd, ill, dia;
    bool found = false;

    while(getline(file, pid))
    {
        getline(file, pn);
        getline(file, pa);
        getline(file, rd);
        getline(file, rt);
        getline(file, did);
        getline(file, dn);
        getline(file, dd);
        getline(file, ill);
        getline(file, dia);

        string emptyLine;
        getline(file, emptyLine);

        if(pid == searchID)
        {
            found = true;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\n  " << BOLD << "Enter New Details for Patient " << CYAN << searchID << RESET << ":\n";
            cout << "  " << CYAN << "> New Patient Name   : " << RESET;
            getline(cin, pn);

            cout << "  " << CYAN << "> New Patient Age    : " << RESET;
            getline(cin, pa);

            cout << "  " << CYAN << "> New Date           : " << RESET;
            getline(cin, rd);

            cout << "  " << CYAN << "> New Time           : " << RESET;
            getline(cin, rt);

            cout << "  " << CYAN << "> New Drug ID        : " << RESET;
            getline(cin, did);

            cout << "  " << CYAN << "> New Drug Name      : " << RESET;
            getline(cin, dn);

            cout << "  " << CYAN << "> New Drug Des       : " << RESET;
            getline(cin, dd);

            cout << "  " << CYAN << "> New Illness        : " << RESET;
            getline(cin, ill);

            cout << "  " << CYAN << "> New Diagnosis      : " << RESET;
            getline(cin, dia);
        }

        temp << pid << endl
             << pn << endl
             << pa << endl
             << rd << endl
             << rt << endl
             << did << endl
             << dn << endl
             << dd << endl
             << ill << endl
             << dia << endl
             << endl;
    }

    file.close();
    temp.close();

    remove("data/Record.txt");
    rename("data/tempRecord.txt", "data/Record.txt");

    if(found)
    {
        cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " Record updated successfully.\n";
    }
    else
    {
        cout << "\n  " << RED << "[ERROR]" << RESET << " Patient ID not found.\n";
    }

    pauseScreen();
}

/*
 * Doctor View Record
 */
void Record::viewRecord()
{
    clearScreen();
    displayHeader("DOCTOR VIEW - ALL MEDICAL RECORDS");

    ifstream patrecord("data/Record.txt");

    if(!patrecord)
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " Sorry, but there is no record in the system.\n";
        pauseScreen();
        return;
    }

    string pid, pn, pa, rd, rt, did, dn, dd, ill, dia;
    int count = 1;
    bool hasRecords = false;

    while(getline(patrecord, pid))
    {
        if(pid.empty())
        {
            continue;
        }

        hasRecords = true;

        getline(patrecord, pn);
        getline(patrecord, pa);
        getline(patrecord, rd);
        getline(patrecord, rt);
        getline(patrecord, did);
        getline(patrecord, dn);
        getline(patrecord, dd);
        getline(patrecord, ill);
        getline(patrecord, dia);

        string emptyLine;
        getline(patrecord, emptyLine);

        cout << "\n  " << BOLD << MAGENTA << "--- Record #" << count << " ---" << RESET << "\n";
        cout << "  " << CYAN << "Patient ID         : " << RESET << pid << "\n";
        cout << "  " << CYAN << "Patient Name       : " << RESET << pn << "\n";
        cout << "  " << CYAN << "Patient Age        : " << RESET << pa << "\n";
        cout << "  " << CYAN << "Record Date        : " << RESET << rd << "\n";
        cout << "  " << CYAN << "Record Time        : " << RESET << rt << "\n";
        cout << "  " << CYAN << "Drug ID            : " << RESET << did << "\n";
        cout << "  " << CYAN << "Drug Name          : " << RESET << dn << "\n";
        cout << "  " << CYAN << "Drug Description   : " << RESET << dd << "\n";
        cout << "  " << CYAN << "Illness            : " << RESET << ill << "\n";
        cout << "  " << CYAN << "Diagnosis          : " << RESET << dia << "\n";

        count++;
    }

    patrecord.close();

    if(!hasRecords)
    {
        cout << "\n  " << RED << "[INFO]" << RESET << " No active records found.\n";
    }

    pauseScreen();
}

/*
 * Patient View Record
 */
void Record::viewpatientRecord()
{
    string searchID;
    char cont;

    do
    {
        clearScreen();
        displayHeader("PATIENT VIEW - MY MEDICAL RECORD");

        cout << "\n  " << CYAN << "> Enter your Patient ID: " << RESET;
        cin >> searchID;

        ifstream patrecord("data/Record.txt");

        if(!patrecord)
        {
            cout << "\n  " << RED << "[ERROR]" << RESET << " Sorry, but there is no record available.\n";
            pauseScreen();
            return;
        }

        string pid, pn, pa, rd, rt, did, dn, dd, ill, dia;
        bool found = false;

        while(getline(patrecord, pid))
        {
            getline(patrecord, pn);
            getline(patrecord, pa);
            getline(patrecord, rd);
            getline(patrecord, rt);
            getline(patrecord, did);
            getline(patrecord, dn);
            getline(patrecord, dd);
            getline(patrecord, ill);
            getline(patrecord, dia);

            string emptyLine;
            getline(patrecord, emptyLine);

            if(pid == searchID)
            {
                found = true;

                cout << "\n  " << BOLD << MAGENTA << "--- My Medical Record ---" << RESET << "\n";
                cout << "  " << CYAN << "Patient ID         : " << RESET << pid << "\n";
                cout << "  " << CYAN << "Patient Name       : " << RESET << pn << "\n";
                cout << "  " << CYAN << "Patient Age        : " << RESET << pa << "\n";
                cout << "  " << CYAN << "Record Date        : " << RESET << rd << "\n";
                cout << "  " << CYAN << "Record Time        : " << RESET << rt << "\n";
                cout << "  " << CYAN << "Drug ID            : " << RESET << did << "\n";
                cout << "  " << CYAN << "Drug Name          : " << RESET << dn << "\n";
                cout << "  " << CYAN << "Drug Description   : " << RESET << dd << "\n";
                cout << "  " << CYAN << "Illness            : " << RESET << ill << "\n";
                cout << "  " << CYAN << "Diagnosis          : " << RESET << dia << "\n";

                break;
            }
        }

        patrecord.close();

        if(!found)
        {
            cout << "\n  " << RED << "[ERROR]" << RESET << " Sorry, no record found for Patient ID: " << searchID << "\n";
        }

        cout << "\n  " << YELLOW << "-> Do you want to continue? [Y/N]: " << RESET;
        cin >> cont;

    } while(cont == 'Y' || cont == 'y');

    pauseScreen();
}

/*
 * Check Exist Patient ID (Const version)
 */
bool checkExistpatientID(const string& patientID)
{
    ifstream patrecord("data/Record.txt");

    if(!patrecord)
    {
        return false;
    }

    string pid;
    string temp;

    while(getline(patrecord, pid))
    {
        for(int i = 0; i < 9; i++)
        {
            getline(patrecord, temp);
        }

        string emptyLine;
        getline(patrecord, emptyLine);

        if(pid == patientID)
        {
            patrecord.close();
            return true;
        }
    }

    patrecord.close();
    return false;
}
