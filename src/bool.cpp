#include "bool.h"

#include <fstream>
#include <regex>
#include <cctype>

using namespace std;

// Check username duplication during registration
bool checkExistUsername(const string& username)
{
    ifstream file("PatientRegistration.txt");


    if(!file)
    {
        // File does not exist, so username is available
        return true;
    }

    string u;

    while(getline(file, u))
    {
        // Compare username (first line of every patient record)
        if(u == username)
        {
            file.close();
            return false; // username already exists
        }

        // Skip remaining patient information:
        // password
        // patientID
        // name
        // age
        // address
        // email
        // phone
        // medical history

        for(int i = 0; i < 8; i++)
        {
            getline(file, u);
        }
    }

    file.close();

    return true;
}

// Email validation
bool checkEmail(const string& email)
{
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"
    );

    return regex_match(email, pattern);
}

// Phone validation
bool checkMobile(string input, int size)
{
    const regex pattern1("(01[0-9])[0-9]{7,8}");
    const regex pattern2("(011)[0-9]{8}");

    if(regex_match(input, pattern1) ||
       regex_match(input, pattern2))
    {
        return true;
    }

    return false;
}


// Login validation
bool validateLogin(string username,string password)
{
    ifstream file("PatientRegistration.txt");


    if(!file)
    {
        return false;
    }


    string u,p,temp;

    while(getline(file,u))
    {
        getline(file,p);


        if(u == username && p == password)
        {
            file.close();
            return true;
        }

        // Skip patient details
        for(int i=0;i<7;i++)
        {
            getline(file,temp);
        }
    }

    file.close();

    return false;
}
