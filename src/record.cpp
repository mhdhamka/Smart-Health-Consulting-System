

/*
 * Record Class Implementation
 * Smart Health Consulting System
 */


#include <iostream>
#include <fstream>
#include <string>


#include "record.h"


using namespace std;





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

    ifstream file(
        "data/Record.txt"
    );



    if(!file)
    {

        return false;

    }




    string id;



    while(getline(file,id))
    {


        /*
         * Skip remaining 9 fields
         */

        if(id == patientID)
        {

            file.close();

            return true;

        }



        for(int i=0;i<9;i++)
        {

            getline(file,id);

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

    system("cls");



    cout
    << "\n=====================================================\n";


    cout
    << " SMART HEALTH CONSULTING SYSTEM\n";


    cout
    << " Add Patient Medical Record\n";


    cout
    << "=====================================================\n";






    cout
    << "\nPatient ID : ";


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
    << "Record Date : ";


    getline(
        cin,
        Date
    );





    cout
    << "Record Time : ";


    getline(
        cin,
        Time
    );







    /*
     * Prescription
     */


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








    /*
     * Medical information
     */


    cout
    << "\nPatient Illness : ";


    getline(
        cin,
        illness
    );




    cout
    << "Patient Diagnosis : ";


    getline(
        cin,
        diagnosis
    );








    ofstream recordFile(
        "data/Record.txt",
        ios::app
    );




    if(!recordFile)
    {

        cout
        << "\nUnable to save record.";

        return;

    }







    recordFile

    << patientID << endl

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






    cout
    << "\nPatient record saved successfully.";


    system("pause");

}

//function for doctor to view record
void Record::viewRecord()
{
    string pid, pn, pa, rd, rt, did, dn, dd, ill, dia;

    system("cls");
    system("Color F0");

    cout << "=====================================================" << endl;
    cout << "     SMART HEALTH CONSULTING SYSTEM (Doctor View)    " << endl;
    cout << "=====================================================" << endl;
    cout << "\n";
    cout << "------------------View Record----------------------" << endl;
    cout << "\n";


    ifstream patrecord("Record.txt");

    if(!patrecord)
    {
        cout << "\n Sorry but there is no record in the system.\n";
        system("pause");
        return;
    }


    int count = 1;


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


        cout << "\n-----------------------------------------------\n";
        cout << "       Record " << count << endl;
        cout << "-----------------------------------------------\n";

        cout << "Patient ID          : " << pid << endl;
        cout << "Patient Name        : " << pn << endl;
        cout << "Patient Age         : " << pa << endl;
        cout << "Record Date         : " << rd << endl;
        cout << "Record Time         : " << rt << endl;
        cout << "Drug ID             : " << did << endl;
        cout << "Drug Name           : " << dn << endl;
        cout << "Drug Description    : " << dd << endl;
        cout << "Illness             : " << ill << endl;
        cout << "Diagnosis           : " << dia << endl;


        count++;
    }


    patrecord.close();

    cout << "\n-----------------------------------------------------" << endl;
    system("pause");
}

//function for patient to view their own record
void Record::viewpatientRecord()
{
    string searchID;

    string pid, pn, pa, rd, rt, did, dn, dd, ill, dia;

    char cont;


    do
    {

        system("cls");
        system("Color F0");


        cout << "=====================================================" << endl;
        cout << "    SMART HEALTH CONSULTING SYSTEM (Patient View)    " << endl;
        cout << "=====================================================" << endl;

        cout << "\n------------------View My Record--------------------\n";


        cout << "\nEnter your Patient ID";
        cout << "\n>> ";
        cin >> searchID;



        ifstream patrecord("Record.txt");


        if(!patrecord)
        {
            cout << "\nSorry but there is no record available.\n";
            system("pause");
            return;
        }



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



            if(pid == searchID)
            {

                found = true;


                cout << "\n-----------------------------------------------\n";
                cout << "             My Medical Record                 ";
                cout << "\n-----------------------------------------------\n";


                cout << "Patient ID          : " << pid << endl;
                cout << "Patient Name        : " << pn << endl;
                cout << "Patient Age         : " << pa << endl;
                cout << "Record Date         : " << rd << endl;
                cout << "Record Time         : " << rt << endl;
                cout << "Drug ID             : " << did << endl;
                cout << "Drug Name           : " << dn << endl;
                cout << "Drug Description    : " << dd << endl;
                cout << "Illness             : " << ill << endl;
                cout << "Diagnosis           : " << dia << endl;


                break;
            }

        }


        patrecord.close();



        if(!found)
        {
            cout << "\nSorry, no record found for Patient ID: "
                 << searchID << endl;
        }



        cout << "\n\nDo you want to continue? [Y/N]";
        cout << "\n>> ";
        cin >> cont;



    }while(cont == 'Y' || cont == 'y');



    system("pause");
}

bool checkExistpatientID(const string& patientID)
{
    ifstream patrecord("Record.txt");

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


        if(pid == patientID)
        {
            patrecord.close();
            return true;
        }

    }


    patrecord.close();

    return false;
}
