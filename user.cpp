/******************************
Class User
Implemented by Mohammad Hamka Izzuddin Bin Mohamad Yahya (73571)
******************************/

/*Class User implementation file*/
#include <iostream>
#include <string>
#include <fstream>

#include "user.h"
using namespace std;

/*Constructor*/
User::User(){}

/*Setter*/
void User::setname(string name){username = name;}
void User::setpassword(string p){password = p;}
void User::setemail(string e){email = e;}

/*Getter*/
string User::getname(){return username;}
string User::getpassword(){return password;}
string User::getemail() {return email;}

/*Function to validate login by enter username and password*/
bool User::validateLogin(string name, string password)
{
    ifstream patreg("PatientRegistration.txt");
    if(!patreg.is_open())
    {
        cout << "\n Sorry but there is no any registration file. ";
        patreg.close();
    }
    else
    {
        int i = 0, j = 0;
        string data[50][7];
        while(getline(patreg, data[i][j]))
        {
            j++;
            if(j>7){i++; j = 0;}
        }
        
        patreg.close();

        for(int x=0; x<=i; x++)
        {
            if(data[x][0]==getname())
            {
                if(data[x][1]==getpassword())
                {
                    return true;
                    break;
                }
            }
            else
            {
                if(x==i)
                {
                    return false;
                    break;
                }
            }
        }
    }
}
