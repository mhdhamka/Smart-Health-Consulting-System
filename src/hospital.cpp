/*
 * Hospital Class Implementation
 * SmartHealth System
 */

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "hospital.h"
#include "appointment.h"

using namespace std;

// Constructor

Hospital::Hospital()
{

    username = "Marc Cucurella";
    password = "10024";

    hospitalName = "Nurulain Basirah";


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

    cout
    << "\n=====================================================\n";

    cout
    << " SMARTHEALTH SYSTEM\n";

    cout
    << " Hospital Administrator Login\n";

    cout
    << "=====================================================\n";

    cout
    << "\nHospital ID : ";

    cin
    >> hosID;

    cout
    << "Password    : ";

    cin
    >> hosPassword;

    if(
        hosID == username &&
        hosPassword == password
      )
    {

        cout
        << "\nWelcome "
        << hospitalName
        << "! Login successful.\n";

        system("pause");
        hospitalMenu();

    }

    else
    {
        cout
        << "\nInvalid hospital ID or password.";
    }

}


/*
 * Hospital Admin Menu
 */
void Hospital::hospitalMenu()
{
    int option;

    while(true)
    {

        system("cls");

        cout
        << "\n=====================================================\n";

        cout
        << " SMARTHEALTH SYSTEM\n";

        cout
        << " Hospital Administrator Menu\n";

        cout
        << "=====================================================\n";

        cout
        << "\n1. Generate Receipt";

        cout
        << "\n2. View Receipt";

        cout
        << "\n3. Logout";

        cout
        << "\n\nSelect option: ";

        cin
        >> option;

        switch(option)
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

            cout
            << "\nInvalid option.";
            system("pause");

        }
    }
}


/*
 * Generate Receipt
 */
void Hospital::generateReceipt()
{
    system("cls");

    cout
    << "\n=====================================================\n";

    cout
    << " Generate Receipt\n";

    cout
    << "=====================================================\n";

    cout
    << "\nReceipt ID : ";

    cin
    >> receiptID;

    cout
    << "Patient ID : ";

    cin
    >> patientID;

    cin.ignore();

    cout
    << "Patient Name : ";

    getline(
        cin,
        patientName
    );

    cout
    << "Patient Age : ";

    getline(
        cin,
        patientAge
    );

    cout
    << "Receipt Date : ";

    getline(
        cin,
        receiptdate
    );

    cout
    << "Receipt Time : ";

    getline(
        cin,
        receipttime
    );

    cout
    << "\nDrug ID : ";

    getline(
        cin,
        drugID
    );

    cout
    << "Drug Name : ";

    getline(
        cin,
        drugName
    );

    cout
    << "Drug Description : ";

    getline(
        cin,
        drugDes
    );

    cout
    << "\nIllness : ";

    getline(
        cin,
        illness
    );

    cout
    << "Diagnosis : ";

    getline(
        cin,
        diagnosis
    );


    ofstream receiptFile(
        "data/Receipt.txt",
        ios::app
    );

    if(!receiptFile)
    {

        cout
        << "\nUnable to save receipt.";

        return;

    }

    receiptFile

    << receiptID << endl
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

    cout
    << "\nReceipt successfully generated.";

    system("pause");
}


/*
 * View Receipt
 */
void Hospital::viewReceipt()
{

    ifstream receiptFile(
        "data/Receipt.txt"
    );



    if(!receiptFile)
    {

        cout
        << "\nNo receipt found.";

        system("pause");

        return;

    }

    system("cls");



    cout
    << "\n=====================================================\n";

    cout
    << " Receipt List\n";

    cout
    << "=====================================================\n";



    int count = 1;



    while(getline(receiptFile, receiptID))
    {


        if(receiptID.empty())
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

        cout
        << "\nReceipt "
        << count
        << "\n";

        cout
        << "Receipt ID : "
        << receiptID
        << endl;

        cout
        << "Patient ID : "
        << patientID
        << endl;

        cout
        << "Patient Name : "
        << patientName
        << endl;

        cout
        << "Patient Age : "
        << patientAge
        << endl;

        cout
        << "Date : "
        << receiptdate
        << endl;

        cout
        << "Time : "
        << receipttime
        << endl;

        cout
        << "Drug : "
        << drugName
        << endl;

        cout
        << "Description : "
        << drugDes
        << endl;

        cout
        << "Illness : "
        << illness
        << endl;

        cout
        << "Diagnosis : "
        << diagnosis
        << endl;

        cout
        << "\n---------------------------------\n";

        count++;
    }

    receiptFile.close();
    system("pause");
}

