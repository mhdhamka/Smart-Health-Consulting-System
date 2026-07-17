/*
 * User Class Implementation
 * Smart Health Consulting System
 */

#include <iostream>
#include <string>
#include <fstream>

#include "user.h"

using namespace std;

// Constructor
User::User()
{
    username = "";
    password = "";
    email = "";
}


// Setter functions
void User::setname(string name)
{
    username = name;
}

void User::setpassword(string p)
{
    password = p;
}

void User::setemail(string e)
{
    email = e;
}



// Getter functions
string User::getname()
{
    return username;
}

string User::getpassword()
{
    return password;
}

string User::getemail()
{
    return email;
}

/*
 * Function:
 * Validate patient login using PatientRegistration.txt
 *
 * File format:
 *
 * username
 * password
 * email
 * ...
 *
 */


bool User::validateLogin(string name, string pass)
{

    ifstream patientFile(
        "data/PatientRegistration.txt"
    );


    if(!patientFile.is_open())
    {
        cout << "\nRegistration file cannot be found.";
        return false;
    }

    string fileUsername;
    string filePassword;
    string fileEmail;

    while(getline(patientFile, fileUsername))
    {

        getline(patientFile, filePassword);

        getline(patientFile, fileEmail);

        if(fileUsername == name &&
           filePassword == pass)
        {

            patientFile.close();

            return true;

        }

    }

    patientFile.close();
    return false;

}
