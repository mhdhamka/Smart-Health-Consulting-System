/*
 * Patient Class Implementation
 * Smart Health Consulting System
 */

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

#include "patient.h"
#include "bool.h"
#include "appointment.h"
#include "payment.h"
#include "record.h"

using namespace std;


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

    string usernameCheck;

    cout
    << "\n=====================================================\n";

    cout
    << " SMART HEALTH CONSULTING SYSTEM\n";

    cout
    << " Patient Registration\n";

    cout
    << "=====================================================\n";

    cin.ignore();

    /*
     * Username validation
     */
    while(true)
    {

        cout
        << "\nUsername : ";

        getline(
            cin,
            username
        );

        ifstream checkFile(
            "data/PatientRegistration.txt"
        );

        bool exist = false;

        string line;


        while(getline(checkFile,line))
        {

            if(line == username)
            {

                exist = true;

                break;

            }

            // skip remaining 8 fields

            for(int i=0;i<8;i++)
            {

                getline(checkFile,line);

            }

        }

        checkFile.close();

        if(exist)
        {

            cout
            << "\nUsername already exists. Try another one.";

        }

        else
        {

            break;

        }

    }


    cout
    << "Password : ";

    getline(
        cin,
        password
    );

    cout
    << "Patient ID : ";

    getline(
        cin,
        patientID
    );

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
    << "Address : ";

    getline(
        cin,
        patientAddress
    );


    /*
     * Email validation
     */
    while(true)
    {

        cout
        << "Email : ";

        getline(
            cin,
            email
        );

        if(checkEmail(email))
        {

            break;

        }

        cout
        << "\nInvalid email format.\n";

    }


    /*
     * Phone validation
     */


    while(true)
    {

        cout
        << "Phone Number : ";

        getline(
            cin,
            phone
        );


        if(
            checkMobile(
                phone,
                phone.length()
            )
          )
        {

            break;

        }

        cout
        << "\nInvalid phone number.\n";

    }

    cout
    << "Medical History : ";

    getline(
        cin,
        medicalHistory
    );


    ofstream patientFile(
        "data/PatientRegistration.txt",
        ios::app
    );

    if(!patientFile)
    {
        cout
        << "\nUnable to save registration.";

        return;

    }

    patientFile

    << username << endl
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

    cout
    << "\nRegistration successful.";

}


/*
 * Patient Login
 */

void Patient::login()
{
    cout
    << "\n=====================================================\n";

    cout
    << " SMART HEALTH CONSULTING SYSTEM\n";

    cout
    << " Patient Login\n";

    cout
    << "=====================================================\n";


    cin.ignore();

    cout
    << "\nUsername : ";


    getline(
        cin,
        username
    );

    cout
    << "Password : ";


    getline(
        cin,
        password
    );


    if(
        !validateLogin(
            username,
            password
        )
      )
    {

        cout
        << "\nInvalid username or password.";

        system("pause");

        return;

    }


    /*
     * Load patient information
     */
    ifstream patientFile(
        "data/PatientRegistration.txt"
    );

    string user;

    while(getline(patientFile,user))
    {

        string pass;


        getline(
            patientFile,
            pass
        );

        if(
            user == username &&
            pass == password
          )
        {
            getline(patientFile,patientID);
            getline(patientFile,patientName);
            getline(patientFile,patientAge);
            getline(patientFile,patientAddress);
            getline(patientFile,email);
            getline(patientFile,phone);
            getline(patientFile,medicalHistory);

            break;

        }

        else
        {
            // skip current user data
            for(int i=0;i<7;i++)
            {

                getline(
                    patientFile,
                    user
                );

            }

        }

    }


    patientFile.close();

    cout
    << "\nWelcome "
    << username
    << "! Login successful.";

    system("pause");
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


        system("cls");

        cout
        << "\n=================================================\n";

        cout
        << " SMART HEALTH CONSULTING SYSTEM\n";

        cout
        << " Patient Menu\n";

        cout
        << "=================================================\n";

        cout
        << "\nWelcome "
        << username
        << "!";

        cout
        << "\n\n1. View Profile";

        cout
        << "\n2. Edit Profile";

        cout
        << "\n3. Set Appointment";

        cout
        << "\n4. View Medical Record";

        cout
        << "\n5. Make Payment";

        cout
        << "\n6. Logout";

        cout
        << "\n\nSelect option: ";

        cin
        >> option;

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

            system("cls");
            re.viewpatientRecord();
            system("pause");
            break;

        case 5:
        {

            system("cls");
            pay.makePayment();
            system("pause");
            break;

        }

        case 6:
        {

            char confirm;

            cout
            << "\nLogout? (Y/N): ";

            cin
            >> confirm;

            if(
                confirm == 'Y' ||
                confirm == 'y'
              )
            {

                return;

            }

            break;

        }

        default:

            cout
            << "\nInvalid option.";

            system("pause");

        }

    }

}


/*
 * View Patient Profile
 */
void Patient::viewProfile()
{
    system("cls");


    cout
    << "\n=================================================\n";

    cout
    << " Patient Profile\n";

    cout
    << "=================================================\n";

    cout
    << "\nUsername          : "
    << username;

    cout
    << "\nPassword          : "
    << password;

    cout
    << "\nPatient ID        : "
    << patientID;

    cout
    << "\nPatient Name      : "
    << patientName;

    cout
    << "\nPatient Age       : "
    << patientAge;

    cout
    << "\nAddress           : "
    << patientAddress;

    cout
    << "\nEmail             : "
    << email;

    cout
    << "\nPhone             : "
    << phone;

    cout
    << "\nMedical History   : "
    << medicalHistory;

    cout
    << "\n=================================================\n";

    system("pause");

}


/*
 * Edit Patient Profile
 */
void Patient::editProfile()
{

    system("cls");

    cout
    << "\n=================================================\n";

    cout
    << " Edit Patient Profile\n";

    cout
    << "=================================================\n";


    string newName;
    string newAge;
    string newAddress;
    string newEmail;
    string newPhone;
    string newHistory;

    cout
    << "\nEnter new patient name: ";

    cin.ignore();

    getline(
        cin,
        newName
    );

    cout
    << "Enter new patient age: ";

    getline(
        cin,
        newAge
    );


    cout
    << "Enter new address: ";

    getline(
        cin,
        newAddress
    );


    /*
     * Email validation
     */


    while(true)
    {

        cout
        << "Enter new email: ";


        getline(
            cin,
            newEmail
        );


        if(
            checkEmail(newEmail)
          )
        {

            break;

        }



        cout
        << "\nInvalid email format.\n";

    }


    /*
     * Phone validation
     */


    while(true)
    {

        cout
        << "Enter new phone number: ";


        getline(
            cin,
            newPhone
        );


        if(
            checkMobile(
                newPhone,
                newPhone.length()
            )
          )
        {

            break;

        }


        cout
        << "\nInvalid phone number.\n";

    }


    cout
    << "Enter medical history: ";


    getline(
        cin,
        newHistory
    );


    char confirm;



    cout
    << "\nConfirm update? (Y/N): ";


    cin
    >> confirm;


    if(
        confirm != 'Y' &&
        confirm != 'y'
      )
    {


        cout
        << "\nUpdate cancelled.";


        system("pause");


        return;

    }


    /*
     * Read old file
     */
    ifstream oldFile(
        "data/PatientRegistration.txt"
    );


    ofstream tempFile(
        "data/tempPatient.txt"
    );

    string line;

    while(getline(oldFile,line))
    {


        string oldUsername = line;

        string oldPassword;
        string oldID;
        string oldName;
        string oldAge;
        string oldAddress;
        string oldEmail;
        string oldPhone;
        string oldHistory;


        getline(oldFile,oldPassword);
        getline(oldFile,oldID);
        getline(oldFile,oldName);
        getline(oldFile,oldAge);
        getline(oldFile,oldAddress);
        getline(oldFile,oldEmail);
        getline(oldFile,oldPhone);
        getline(oldFile,oldHistory);

        if(oldUsername == username)
        {


            tempFile

            << username << endl
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

            tempFile

            << oldUsername << endl
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


    remove(
        "data/PatientRegistration.txt"
    );

    rename(
        "data/tempPatient.txt",
        "data/PatientRegistration.txt"
    );


    cout
    << "\nProfile updated successfully.";

    system("pause");

}
